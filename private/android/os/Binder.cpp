/*
 * Copyright (C) 2017 Daewoong Jang.
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

#include "Binder.h"

#include <android/os/ParcelPrivate.h>
#include <android++/LogHelper.h>
#include <android++/TemporaryChange.h>

namespace android {
namespace os {

class EmptyBinderClient final : public Binder::Client {
public:
    void onCreate() override { }
    void onDestroy() override { }
    void onTimer() override { }
    void onTransaction(int32_t, Parcel&, Parcel*, int32_t) override { }
};

Binder::Binder(Client* client)
{
    static EmptyBinderClient emptyClient;
    m_client = client ? client : &emptyClient;
}

bool Binder::transact(int32_t code, Parcel& data, Parcel* reply, int32_t flags)
{
    TemporaryChange<Parcel*> replyChange(m_reply, reply);
    return transact(code, data, flags);
}

void Binder::onTransaction(int32_t code, Parcel& data, intptr_t replyTo, int32_t flags)
{
    if (replyTo) {
        Parcel reply;
        m_client->onTransaction(code, data, &reply, 0);
        auto sender = Binder::adopt(replyTo);
        if (!sender->transact(Binder::REPLY_TRANSACTION, reply, nullptr, IBinder::FLAG_ONEWAY)) {
            LOGE("Couldn't send reply");
            return;
        }
    } else {
        if (code == Binder::REPLY_TRANSACTION) {
            assert(m_reply);
            *m_reply = data;
        } else {
            m_client->onTransaction(code, data, nullptr, IBinder::FLAG_ONEWAY);
        }
    }
}

} // namespace os
} // namespace android
