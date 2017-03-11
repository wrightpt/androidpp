/*
 * Copyright (C) 2016 NAVER Corp. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MessageTarget.h"

#include <android/os/HandlerProvider.h>
#include <android/os/Message.h>
#include <android++/LogHelper.h>

namespace android {
namespace os {

class HandlerMessageTarget : public MessageTarget {
public:
    HandlerMessageTarget(std::passed_ptr<Handler> target);
    ~HandlerMessageTarget();

    std::shared_ptr<IBinder> binder() const override;

    void send(Message&) override;

private:
    std::shared_ptr<Handler> m_target;
};

HandlerMessageTarget::HandlerMessageTarget(std::passed_ptr<Handler> target)
    : m_target(target)
{
}

HandlerMessageTarget::~HandlerMessageTarget()
{
}

std::shared_ptr<IBinder> HandlerMessageTarget::binder() const
{
    return HandlerProvider::getBinder(*m_target);
}

void HandlerMessageTarget::send(Message& message)
{
    m_target->sendMessage(message);
}

std::unique_ptr<MessageTarget> MessageTarget::create(std::passed_ptr<Handler> target)
{
    return std::unique_ptr<MessageTarget>(new HandlerMessageTarget(target));
}

class BinderMessageTarget : public MessageTarget {
public:
    BinderMessageTarget(std::passed_ptr<IBinder> target);
    ~BinderMessageTarget();

    std::shared_ptr<IBinder> binder() const override;

    void send(Message&) override;

private:
    std::shared_ptr<IBinder> m_target;
};

BinderMessageTarget::BinderMessageTarget(std::passed_ptr<IBinder> target)
    : m_target(target)
{
}

BinderMessageTarget::~BinderMessageTarget()
{
}

std::shared_ptr<IBinder> BinderMessageTarget::binder() const
{
    return m_target;
}

void BinderMessageTarget::send(Message& message)
{
    Parcel data;
    message.writeToParcel(data, Parcelable::PARCELABLE_WRITE_RETURN_VALUE);
    if (!m_target->transact(MessageTarget::SEND_MESSAGE, data, nullptr, IBinder::FLAG_ONEWAY)) {
        LOGE("Transaction to IBinder %x failed.", m_target.get());
    }
}

std::unique_ptr<MessageTarget> MessageTarget::create(std::passed_ptr<IBinder> target)
{
    return std::unique_ptr<MessageTarget>(new BinderMessageTarget(target));
}

} // namespace os
} // namespace android
