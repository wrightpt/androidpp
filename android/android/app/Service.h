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

#include <android/content/ContextThemeWrapper.h>
#include <android/content/Intent.h>
#include <android/content/res/Configuration.h>
#include <android/os/IBinder.h>

namespace android {
namespace app {

class ServicePrivate;

class Service : public ContextThemeWrapper {
    NONCOPYABLE(Service);
    friend class ServicePrivate;
public:
    ANDROID_EXPORT Service();
    ANDROID_EXPORT virtual ~Service();

    // Return the communication channel to the service.
    ANDROID_EXPORT virtual std::shared_ptr<IBinder> onBind(Intent& intent) = 0;
    // Called by the system when the device configuration changes while your component is running. 
    ANDROID_EXPORT virtual void onConfigurationChanged(Configuration& newConfig);
    // Called by the system when the service is first created. 
    ANDROID_EXPORT virtual void onCreate();
    // Called by the system to notify a Service that it is no longer used and is being removed.
    ANDROID_EXPORT virtual void onDestroy();
    // This is called when the overall system is running low on memory, and actively running processes should trim their memory usage.
    ANDROID_EXPORT virtual void onLowMemory();
    // Called when new clients have connected to the service, after it had previously been notified that all had disconnected in its onUnbind(Intent). 
    ANDROID_EXPORT virtual void onRebind(Intent& intent);
    // Called by the system every time a client explicitly starts the service by calling startService(Intent), providing the arguments it supplied and a unique integer token representing the start request.
    ANDROID_EXPORT virtual void onStartCommand(Intent& intent, int32_t flags, int32_t startId);
    // This is called if the service is currently running and the user has removed a task that comes from the service's application. 
    ANDROID_EXPORT virtual void onTaskRemoved(Intent& rootIntent);
    // Called when the operating system has determined that it is a good time for a process to trim unneeded memory from its process. 
    ANDROID_EXPORT virtual void onTrimMemory(int32_t level);
    // Called when all clients have disconnected from a particular interface published by the service.
    ANDROID_EXPORT virtual bool onUnbind(Intent& intent);

    // Stop the service, if it was previously started. 
    ANDROID_EXPORT void stopSelf();

private:
    std::unique_ptr<ServicePrivate> m_private;
};

} // namespace app
} // namespace android

using Service = android::app::Service;
