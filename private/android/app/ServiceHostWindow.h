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

#include "HostWindow.h"
#include <android/app/ServicePrivate.h>
#include <android/os/Handler.h>

namespace android {
namespace app {

class ServiceHostWindow final : public HostWindow {
public:
    static std::unique_ptr<ServiceHostWindow> create(Service&);
    ~ServiceHostWindow();

    void windowCreated() override;
    void windowDestroyed() override;

    void windowPositionChanged(int32_t, int32_t) override;
    void windowSizeChanged(int32_t, int32_t, Resize) override;
    void windowFocused(bool) override;
    void windowActivated(bool, bool) override;
    void windowIsVisible(bool) override;

    void dispatchKeyEvent(KeyEvent&) override;
    void dispatchMouseEvent(MotionEvent&) override;

    WindowProvider* window() const override;

    void invalidate() override;
    void invalidate(Rect&) override;

    InputConnection* inputConnection() const override;

    void dpiChanged(int32_t dpi) override;

protected:
    ServiceHostWindow(Service&);

    ServicePrivate& service();

    Service& m_service;
    std::shared_ptr<os::Handler> m_handler;
    std::shared_ptr<WindowProvider> m_windowProvider;
};

} // namespace app
} // namespace android
