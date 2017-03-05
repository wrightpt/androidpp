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

#include "Service.h"

#include <android/app/ServicePrivate.h>

namespace android {
namespace app {

Service::Service()
    : m_private(new ServicePrivate(*this))
{
    m_private->initialize();
}

Service::~Service()
{
}

void Service::onConfigurationChanged(Configuration& newConfig)
{
}

void Service::onCreate()
{
}

void Service::onDestroy()
{
}

void Service::onLowMemory()
{
}

void Service::onRebind(Intent& intent)
{
}

int32_t Service::onStartCommand(Intent& intent, int32_t flags, int32_t startId)
{
    return START_STICKY;
}

void Service::onTaskRemoved(Intent& rootIntent)
{
}

void Service::onTrimMemory(int32_t level)
{
}

bool Service::onUnbind(Intent& intent)
{
    return false;
}

void Service::stopSelf()
{
}

} // namespace app
} // namespace android
