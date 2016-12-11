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

#include <android/app/Activity.h>
#include <android/os/Looper.h>

namespace com {
namespace example {

class TestActivity : public Activity {
public:
    TestActivity();
    virtual ~TestActivity();

    virtual void onAttachedToWindow() override;
    virtual void onBackPressed() override;
    virtual void onConfigurationChanged(Configuration& newConfig) override;
    virtual void onContentChanged() override;
    virtual void onDetachedFromWindow() override;
    virtual bool onGenericMotionEvent(MotionEvent& event) override;
    virtual bool onKeyDown(int32_t keyCode, KeyEvent& event) override;
    virtual bool onKeyLongPress(int32_t keyCode, KeyEvent& event) override;
    virtual bool onKeyMultiple(int32_t keyCode, int32_t repeatCount, KeyEvent& event) override;
    virtual bool onKeyShortcut(int32_t keyCode, KeyEvent& event) override;
    virtual bool onKeyUp(int32_t keyCode, KeyEvent& event) override;
    virtual void onLowMemory() override;
    virtual bool onTouchEvent(MotionEvent& event) override;
    virtual void onTrimMemory(int32_t level) override;

protected:
    virtual void onCreate(const std::shared_ptr<Bundle>& savedInstanceState) override;
    virtual void onDestroy() override;
    virtual void onPause() override;
    virtual void onPostCreate(const std::shared_ptr<Bundle>& savedInstanceState) override;
    virtual void onPostResume() override;
    virtual void onRestart() override;
    virtual void onRestoreInstanceState(const std::shared_ptr<Bundle>& savedInstanceState) override;
    virtual void onResume() override;
    virtual void onSaveInstanceState(const std::shared_ptr<Bundle>& outState) override;
    virtual void onStart() override;
    virtual void onStop() override;
};

} // namespace example
} // namespace com
