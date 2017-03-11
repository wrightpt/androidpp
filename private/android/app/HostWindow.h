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

#pragma once

#include "WindowProvider.h"
#include <android/graphics/Rect.h>
#include <android/view/KeyEvent.h>
#include <android/view/MotionEvent.h>
#include <android/view/inputmethod/InputConnection.h>

namespace android {
namespace app {

class HostWindow {
public:
    virtual ~HostWindow() = default;

    enum State {
        Init,
        Create,
        Restart,
        Start,
        Resume,
        Pause,
        Stop,
        Destroy,
    };

    enum Resize {
        Restored,
        Minimized,
        Maximized,
    };

    virtual void windowCreated() = 0;
    virtual void windowDestroyed() = 0;

    virtual void windowPositionChanged(int32_t, int32_t) = 0;
    virtual void windowSizeChanged(int32_t, int32_t, Resize) = 0;
    virtual void windowFocused(bool) = 0;
    virtual void windowActivated(bool, bool) = 0;
    virtual void windowIsVisible(bool) = 0;

    virtual void dispatchKeyEvent(KeyEvent&) = 0;
    virtual void dispatchMouseEvent(MotionEvent&) = 0;

    virtual WindowProvider* window() const = 0;

    virtual void invalidate() = 0;
    virtual void invalidate(Rect&) = 0;

    virtual InputConnection* inputConnection() const = 0;

    virtual void dpiChanged(int32_t dpi) = 0;

protected:
    HostWindow() = default;
};

} // namespace app
} // namespace android
