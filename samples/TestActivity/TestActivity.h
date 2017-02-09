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

#pragma once

#include <android.h>
#include <android/app/Activity.h>
#include <android/os/Messenger.h>

namespace com {
namespace example {

class TestActivity : public Activity {
    friend class TestServiceConnection;
public:
    ANDROID_EXTERN TestActivity();
    ANDROID_EXTERN ~TestActivity();

    void sayHello();

    void onAttachedToWindow() override;
    void onBackPressed() override;
    void onConfigurationChanged(Configuration& newConfig) override;
    void onContentChanged() override;
    void onDetachedFromWindow() override;
    bool onGenericMotionEvent(MotionEvent& event) override;
    bool onKeyDown(int32_t keyCode, KeyEvent& event) override;
    bool onKeyLongPress(int32_t keyCode, KeyEvent& event) override;
    bool onKeyMultiple(int32_t keyCode, int32_t repeatCount, KeyEvent& event) override;
    bool onKeyShortcut(int32_t keyCode, KeyEvent& event) override;
    bool onKeyUp(int32_t keyCode, KeyEvent& event) override;
    void onLowMemory() override;
    bool onTouchEvent(MotionEvent& event) override;
    void onTrimMemory(int32_t level) override;

protected:
    void onCreate(std::passed_ptr<Bundle> savedInstanceState) override;
    void onDestroy() override;
    void onPause() override;
    void onPostCreate(std::passed_ptr<Bundle> savedInstanceState) override;
    void onPostResume() override;
    void onRestart() override;
    void onRestoreInstanceState(std::passed_ptr<Bundle> savedInstanceState) override;
    void onResume() override;
    void onSaveInstanceState(std::passed_ptr<Bundle> outState) override;
    void onStart() override;
    void onStop() override;

private:
    std::shared_ptr<Messenger> mService;
    bool mBound { false };
    std::shared_ptr<ServiceConnection> mConnection;
};

} // namespace example
} // namespace com
