/*
 * Copyright (C) 2016 Naver Corp. All rights reserved.
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

#include "HandlerProvider.h"

#include <android/os/Message.h>
#include <android/os/MessageTarget.h>
#include <android/os/ParcelablePrivate.h>

namespace android {
namespace os {

HandlerProvider::HandlerProvider(Handler& handler)
    : m_handler(handler)
    , m_binder(Binder::create(*this))
{
}

std::shared_ptr<IBinder> HandlerProvider::getBinder(Handler& handler)
{
    return handler.m_handler->m_binder;
}

HandlerProvider::~HandlerProvider()
{
    m_binder->close();
}

bool HandlerProvider::start()
{
    return m_binder->start();
}

bool HandlerProvider::startAtTime(std::chrono::milliseconds uptimeMillis)
{
    return m_binder->startAtTime(uptimeMillis);
}

void HandlerProvider::stop()
{
    m_binder->stop();
}

void HandlerProvider::onCreate()
{
}

void HandlerProvider::onDestroy()
{
}

void HandlerProvider::onTimer()
{
    m_handler.performMessages();
}

void HandlerProvider::onTransaction(int32_t code, Parcel& data, Parcel* reply, int32_t flags)
{
    if (code != MessageTarget::SEND_MESSAGE)
        return;

    std::shared_ptr<Parcelable> parcelable = ParcelablePrivate::createFromParcel(data, ParcelableCreator::creator<Message>().binaryName);
    if (!parcelable)
        return;

    m_handler.receivedMessage(*std::static_pointer_cast<Message>(parcelable));
}

} // namespace os
} // namespace android
