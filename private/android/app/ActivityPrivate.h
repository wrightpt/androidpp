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
#include <android/view/ViewHostWindow.h>

namespace android {
namespace app {

class ActivityPrivate final {
    friend class Activity;
public:
    ActivityPrivate(Activity&);
    ~ActivityPrivate();

    static ActivityPrivate& getPrivate(Activity&);
    static void setPrivate(Activity&, std::unique_ptr<ActivityPrivate>&&);

    void initialize(Window);

    view::ViewHostWindow* hostWindow() const;

    void callOnCreate(const std::shared_ptr<Bundle>& savedInstanceState);
    void callOnDestroy();
    void callOnPause();
    void callOnPostCreate(const std::shared_ptr<Bundle>& savedInstanceState);
    void callOnPostResume();
    void callOnRestart();
    void callOnRestoreInstanceState(const std::shared_ptr<Bundle>& savedInstanceState);
    void callOnResume();
    void callOnSaveInstanceState(const std::shared_ptr<Bundle>& outState);
    void callOnStart();
    void callOnStop();

private:
    Activity& m_this;
    std::unique_ptr<view::ViewHostWindow> m_hostWindow;
};

} // namespace app
} // namespace android
