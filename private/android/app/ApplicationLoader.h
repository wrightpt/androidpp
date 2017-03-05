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

#include <android.h>
#include <android/app/ApplicationProcess.h>
#include <android/content/Context.h>
#include <android/content/IntentPrivate.h>
#include <android/os/Binder.h>

#include <unordered_map>

namespace android {
namespace app {

class ApplicationLoader final : public Context, public Binder::Client {
    NONCOPYABLE(ApplicationLoader);
public:
    ANDROID_EXPORT ApplicationLoader();
    ANDROID_EXPORT ~ApplicationLoader();

    static const int32_t NO_ACTION = 0x00000001;
    static const int32_t INITIALIZE_APPLICATION = 0x00000001;
    static const int32_t BIND_SERVICE = 0x00000002;
    static const int32_t SERVICE_CONNECTED = 0x00000003;

    ANDROID_EXPORT int32_t start(intptr_t peer, StringRef component, std::unordered_map<String, String>& parameters);

    void sendOnBind(Service&, std::passed_ptr<IBinder>);

    // Context
    Context& getApplicationContext() override;
    StringRef getPackageName() override;
    std::shared_ptr<Object> getSystemService(StringRef name) override;
    Resources& getResources() override;

    bool bindService(Intent& service, std::passed_ptr<ServiceConnection> conn, int32_t flags) override;
    void unbindService(std::passed_ptr<ServiceConnection> conn) override;

private:
    void writeResponseHeader(Parcel& parcel);

    // Binder::Client
    void onCreate() override;
    void onDestroy() override;
    void onTimer() override;
    void onTransaction(int32_t code, Parcel& data, Parcel* reply, int32_t flags) override;

    ApplicationProcess& m_process;
    std::shared_ptr<Binder> m_self;
    std::shared_ptr<Binder> m_peer;
    String m_component;
    Intent m_intent;
    int32_t m_state { 0 };
    int32_t m_flags { 0 };
    std::unique_ptr<ApplicationContext> m_context;
};

} // namespace app
} // namespace android

using ApplicationLoader = android::app::ApplicationLoader;
