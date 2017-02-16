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

#pragma once

#include <android/view/View.h>
#include <android/view/MotionEvent.h>

namespace com {
namespace example {

class TestView : public View {
public:
    TestView(Context&);
    ~TestView();

    std::unique_ptr<InputConnection> onCreateInputConnection(EditorInfo& outAttrs) override;
    bool onGenericMotionEvent(MotionEvent& event) override;
    bool onKeyDown(int32_t keyCode, KeyEvent& event) override;
    bool onKeyLongPress(int32_t keyCode, KeyEvent& event) override;
    bool onKeyMultiple(int32_t keyCode, int32_t repeatCount, KeyEvent& event) override;
    bool onKeyPreIme(int32_t keyCode, KeyEvent& event) override;
    bool onKeyShortcut(int32_t keyCode, KeyEvent& event) override;
    bool onKeyUp(int32_t keyCode, KeyEvent& event) override;
    void onWindowFocusChanged(bool hasWindowFocus) override;

protected:
    void onAttachedToWindow() override;
    void onDetachedFromWindow() override;
    void onSizeChanged(int32_t w, int32_t h, int32_t oldw, int32_t oldh) override;
    void onVisibilityChanged(View* changedView, int32_t visibility) override;
    void onWindowVisibilityChanged(int32_t visibility) override;
    void onFocusChanged(bool gainFocus, int32_t direction, Rect& previouslyFocusedRect) override;
    void onLayout(Rect&) override;
    void onMeasure(int32_t, int32_t) override;
    void onConfigurationChanged(Configuration&) override;
};

} // namespace example
} // namespace com
