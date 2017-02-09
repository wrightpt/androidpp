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

#include "ServicePrivate.h"

#include <android.h>
#include <android/app/ServiceHostWindow.h>
#include <android/content/ContextPrivate.h>

namespace android {
namespace app {

ServicePrivate::ServicePrivate(Service& service)
    : m_this(service)
{
    content::ContextPrivate::getPrivate(m_this).setAsService();
}

ServicePrivate::~ServicePrivate()
{
}

ServicePrivate& ServicePrivate::getPrivate(Service& service)
{
    return *service.m_private;
}

void ServicePrivate::setPrivate(Service& service, std::unique_ptr<ServicePrivate>&& p)
{
    service.m_private = std::move(p);
}

void ServicePrivate::initialize()
{
    m_hostWindow = ServiceHostWindow::create(m_this);
}

std::shared_ptr<IBinder> ServicePrivate::callOnBind()
{
    return m_this.onBind(content::ContextPrivate::getGlobalContext().getIntent());
}

void ServicePrivate::callOnCreate()
{
    m_this.onCreate();
}

void ServicePrivate::callOnDestroy()
{
    m_this.onDestroy();
}

void ServicePrivate::callOnLowMemory()
{
    m_this.onLowMemory();
}

void ServicePrivate::callOnRebind()
{
    m_this.onRebind(content::ContextPrivate::getGlobalContext().getIntent());
}

void ServicePrivate::callOnStartCommand()
{
    m_this.onStartCommand(content::ContextPrivate::getGlobalContext().getIntent(), 0, 0);
}

void ServicePrivate::callOnTaskRemoved()
{
    m_this.onTaskRemoved(content::ContextPrivate::getGlobalContext().getIntent());
}

void ServicePrivate::callOnTrimMemory()
{
    m_this.onTrimMemory(0);
}

void ServicePrivate::callOnUnbind()
{
    m_this.onUnbind(content::ContextPrivate::getGlobalContext().getIntent());
}

} // namespace app
} // namespace android
