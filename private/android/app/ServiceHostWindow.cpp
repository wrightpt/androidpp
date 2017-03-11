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

#include "ServiceHostWindow.h"

#include <android/app/ApplicationLoader.h>
#include <android/app/WindowProvider.h>
#include <android/content/ContextPrivate.h>
#include <android/os/Binder.h>
#include <android++/LogHelper.h>

namespace android {
namespace app {

class ServiceWindowProvider : public WindowProvider, public Binder::Client {
public:
    ServiceWindowProvider(ServiceHostWindow&);
    ~ServiceWindowProvider() = default;

    std::passed_ptr<IBinder> getWindowToken() override { return m_binder; }

    // Binder::Client
    void onCreate() override;
    void onDestroy() override;
    void onTimer() override;
    void onTransaction(int32_t code, Parcel& data, Parcel* reply, int32_t flags) override;

protected:
    WindowHandle platformWindowHandle() const override;

    void platformStartInputMethod(bool) override { }
    void platformResetInputMethod() override { }
    void platformSetCursor(std::passed_ptr<view::Cursor>) override { }
    void platformSetWindowFocus(bool) override { }
    void platformSetWindowCaptureMouse(bool) override { }
    void platformSetWindowPosition(int32_t, int32_t, int32_t, int32_t) override { }
    void platformSendWindowMove() override { }
    float platformDeviceScaleFactor() const override { return 1.0f; }

    std::shared_ptr<Binder> m_binder;
};

ServiceWindowProvider::ServiceWindowProvider(ServiceHostWindow& host)
    : WindowProvider(host)
    , m_binder(Binder::create(*this))
{
}

void ServiceWindowProvider::onCreate()
{
    m_host.windowCreated();
}

void ServiceWindowProvider::onDestroy()
{
    m_host.windowDestroyed();
}

void ServiceWindowProvider::onTimer()
{
}

void ServiceWindowProvider::onTransaction(int32_t code, Parcel& data, Parcel* reply, int32_t flags)
{
}

WindowHandle ServiceWindowProvider::platformWindowHandle() const
{
    return reinterpret_cast<WindowHandle>(m_binder->handle());
}

std::unique_ptr<ServiceHostWindow> ServiceHostWindow::create(Service& service)
{
    return std::unique_ptr<ServiceHostWindow>(new ServiceHostWindow(service));
}

ServiceHostWindow::ServiceHostWindow(Service& service)
    : m_service(service)
    , m_handler(std::make_shared<Handler>())
{
    m_handler->post([=] {
        m_windowProvider = std::make_shared<ServiceWindowProvider>(*this);
    });
}

ServiceHostWindow::~ServiceHostWindow()
{
}

ServicePrivate& ServiceHostWindow::service()
{
    return ServicePrivate::getPrivate(m_service);
}

void ServiceHostWindow::windowCreated()
{
    service().callOnCreate();

    auto& context = content::ContextPrivate::getGlobalContext();
    if (context.getAction() == ApplicationLoader::BIND_SERVICE) {
        auto binder = service().callOnBind();
        auto loader = content::ContextPrivate::getPrivate(context).getApplicationLoader();
        assert(loader);
        loader->sendOnBind(m_service, binder);
    }
}

void ServiceHostWindow::windowDestroyed()
{
    service().callOnDestroy();
}

void ServiceHostWindow::windowPositionChanged(int32_t, int32_t)
{
}

void ServiceHostWindow::windowSizeChanged(int32_t, int32_t, Resize)
{
}

void ServiceHostWindow::windowFocused(bool)
{
}

void ServiceHostWindow::windowActivated(bool, bool)
{
}

void ServiceHostWindow::windowIsVisible(bool)
{
}

void ServiceHostWindow::dispatchKeyEvent(KeyEvent&)
{
}

void ServiceHostWindow::dispatchMouseEvent(MotionEvent&)
{
}

WindowProvider* ServiceHostWindow::window() const
{
    return m_windowProvider.get();
}

void ServiceHostWindow::invalidate()
{
}

void ServiceHostWindow::invalidate(Rect&)
{
}

InputConnection* ServiceHostWindow::inputConnection() const
{
    return nullptr;
}

void ServiceHostWindow::dpiChanged(int32_t)
{
}

} // namespace app
} // namespace android
