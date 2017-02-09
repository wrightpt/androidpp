/*
 * Copyright (C) 2016 Daewoong Jang.
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

#include "TestActivity.h"

#include "TestService.h"
#include <android/os/Message.h>
#include <android++/LogHelper.h>

namespace com {
namespace example {

class TestServiceConnection : public ServiceConnection {
    friend class TestActivity;
public:
    void onServiceConnected(ComponentName& className, std::passed_ptr<IBinder> service) {
        // This is called when the connection with the service has been
        // established, giving us the object we can use to
        // interact with the service.  We are communicating with the
        // service using a Messenger, so here we get a client-side
        // representation of that from the raw IBinder object.
        mThis.mService = std::make_shared<Messenger>(service);
        mThis.mBound = true;
        mThis.sayHello();
    }

    void onServiceDisconnected(ComponentName& className) {
        // This is called when the connection with the service has been
        // unexpectedly disconnected -- that is, its process crashed.
        mThis.mService = nullptr;
        mThis.mBound = false;
    }

private:
    TestServiceConnection(TestActivity& activity)
        : mThis(activity)
    {
    }

    TestActivity& mThis;
};

TestActivity::TestActivity()
    : mConnection(new TestServiceConnection(*this))
{
}

TestActivity::~TestActivity()
{
}

void TestActivity::sayHello()
{
    if (!mBound) return;
    // Create and send a message to the service, using a supported 'what' value
    Message msg = Message::obtain(nullptr, TestService::MSG_SAY_HELLO, 0, 0);
    mService->send(msg);
}

void TestActivity::onAttachedToWindow()
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onBackPressed()
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onConfigurationChanged(Configuration& newConfig)
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onContentChanged()
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onDetachedFromWindow()
{
    LOGD("%s", __FUNCTION__);
}

bool TestActivity::onGenericMotionEvent(MotionEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return false;
}

bool TestActivity::onKeyDown(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return false;
}

bool TestActivity::onKeyLongPress(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return false;
}

bool TestActivity::onKeyMultiple(int32_t keyCode, int32_t repeatCount, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return false;
}

bool TestActivity::onKeyShortcut(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return false;
}

bool TestActivity::onKeyUp(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return false;
}

void TestActivity::onLowMemory()
{
    LOGD("%s", __FUNCTION__);
}

bool TestActivity::onTouchEvent(MotionEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return false;
}

void TestActivity::onTrimMemory(int32_t level)
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onCreate(std::passed_ptr<Bundle> savedInstanceState)
{
    LOGD("%s", __FUNCTION__);
    Activity::onCreate(savedInstanceState);
}

void TestActivity::onDestroy()
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onPause()
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onPostCreate(std::passed_ptr<Bundle> savedInstanceState)
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onPostResume()
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onRestart()
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onRestoreInstanceState(std::passed_ptr<Bundle> savedInstanceState)
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onResume()
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onSaveInstanceState(std::passed_ptr<Bundle> outState)
{
    LOGD("%s", __FUNCTION__);
}

void TestActivity::onStart()
{
    LOGD("%s", __FUNCTION__);
    Activity::onStart();
    // Bind to the service
    bindService(Intent(*this, classT<TestService>()), mConnection,
        Context::BIND_AUTO_CREATE);
}

void TestActivity::onStop()
{
    LOGD("%s", __FUNCTION__);
    Activity::onStop();
    // Unbind from the service
    if (mBound) {
        unbindService(mConnection);
        mBound = false;
    }
}

} // namespace example
} // namespace com
