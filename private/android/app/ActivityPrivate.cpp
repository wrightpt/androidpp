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

#include "ActivityPrivate.h"

namespace android {
namespace app {

ActivityPrivate::ActivityPrivate(Activity& activity)
    : m_this(activity)
{
}

ActivityPrivate::~ActivityPrivate()
{
}

ActivityPrivate& ActivityPrivate::getPrivate(Activity& activity)
{
    return *activity.m_private;
}

void ActivityPrivate::setPrivate(Activity& activity, std::unique_ptr<ActivityPrivate>&& p)
{
    activity.m_private = std::move(p);
}

void ActivityPrivate::initialize(Window topLevelWindow)
{
    m_hostWindow = view::ViewHostWindow::create(m_this, topLevelWindow, Rect());
}

view::ViewHostWindow* ActivityPrivate::hostWindow() const
{
    return 0;
}

void ActivityPrivate::callOnCreate(const std::shared_ptr<Bundle>& savedInstanceState)
{
    m_this.onCreate(savedInstanceState);
}

void ActivityPrivate::callOnDestroy()
{
    m_this.onDestroy();
}

void ActivityPrivate::callOnPause()
{
    m_this.onPause();
}

void ActivityPrivate::callOnPostCreate(const std::shared_ptr<Bundle>& savedInstanceState)
{
    m_this.onPostCreate(savedInstanceState);
}

void ActivityPrivate::callOnPostResume()
{
    m_this.onPostResume();
}

void ActivityPrivate::callOnRestart()
{
    m_this.onRestart();
}

void ActivityPrivate::callOnRestoreInstanceState(const std::shared_ptr<Bundle>& savedInstanceState)
{
    m_this.onRestoreInstanceState(savedInstanceState);
}

void ActivityPrivate::callOnResume()
{
    m_this.onResume();
}

void ActivityPrivate::callOnSaveInstanceState(const std::shared_ptr<Bundle>& outState)
{
    m_this.onSaveInstanceState(outState);
}

void ActivityPrivate::callOnStart()
{
    m_this.onStart();
}

void ActivityPrivate::callOnStop()
{
    m_this.onStop();
}

} // namespace app
} // namespace android
