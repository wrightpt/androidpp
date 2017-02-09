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

#include "TestService.h"

#include <android/os/Handler.h>
#include <android/os/Message.h>
#include <android++/LogHelper.h>

namespace com {
namespace example {

/**
* Handler of incoming messages from clients.
*/
class IncomingHandler : public Handler {
public:
    void handleMessage(Message& msg) override
    {
        switch (msg.what) {
        case TestService::MSG_SAY_HELLO:
            // FIXME: test.
            MessageBoxA(0, "Say Hello!", "Toast", 0);
            break;
        default:
            Handler::handleMessage(msg);
        }
    }
};

TestService::TestService()
    : mMessenger(std::make_shared<Messenger>(std::make_shared<IncomingHandler>()))
{
}

TestService::~TestService()
{
}

std::shared_ptr<IBinder> TestService::onBind(Intent& intent)
{
    LOGD("%s", __FUNCTION__);
    return mMessenger->getBinder();
}

void TestService::onConfigurationChanged(Configuration& newConfig)
{
    LOGD("%s", __FUNCTION__);
}

void TestService::onCreate()
{
    LOGD("%s", __FUNCTION__);
}

void TestService::onDestroy()
{
    LOGD("%s", __FUNCTION__);
}

void TestService::onLowMemory()
{
    LOGD("%s", __FUNCTION__);
}

void TestService::onRebind(Intent& intent)
{
    LOGD("%s", __FUNCTION__);
}

void TestService::onStartCommand(Intent& intent, int32_t flags, int32_t startId)
{
    LOGD("%s", __FUNCTION__);
}

void TestService::onTaskRemoved(Intent& rootIntent)
{
    LOGD("%s", __FUNCTION__);
}

void TestService::onTrimMemory(int32_t level)
{
    LOGD("%s", __FUNCTION__);
}

bool TestService::onUnbind(Intent& intent)
{
    LOGD("%s", __FUNCTION__);
    return true;
}

} // namespace example
} // namespace com
