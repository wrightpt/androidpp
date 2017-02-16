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

#include <android.h>
#include <android/app/ActivityHostWindow.h>
#include <android/content/ContextPrivate.h>

namespace android {
namespace app {

ActivityPrivate::ActivityPrivate(Activity& activity)
    : m_this(activity)
{
    content::ContextPrivate::getPrivate(m_this).setAsActivity();
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
    m_hostWindow = ActivityHostWindow::create(m_this, topLevelWindow, Rect());
}

ActivityHostWindow* ActivityPrivate::hostWindow() const
{
    return m_hostWindow.get();
}

void ActivityPrivate::callOnCreate()
{
    m_this.onCreate(content::ContextPrivate::getGlobalContext().getInstanceStateBundle());
}

void ActivityPrivate::callOnDestroy()
{
    m_this.onDestroy();
}

void ActivityPrivate::callOnPause()
{
    m_this.onPause();
}

void ActivityPrivate::callOnPostCreate()
{
    m_this.onPostCreate(content::ContextPrivate::getGlobalContext().getInstanceStateBundle());
}

void ActivityPrivate::callOnPostResume()
{
    m_this.onPostResume();
}

void ActivityPrivate::callOnRestart()
{
    m_this.onRestart();
}

void ActivityPrivate::callOnRestoreInstanceState()
{
    m_this.onRestoreInstanceState(content::ContextPrivate::getGlobalContext().getInstanceStateBundle());
}

void ActivityPrivate::callOnResume()
{
    m_this.onResume();
}

void ActivityPrivate::callOnSaveInstanceState()
{
    m_this.onSaveInstanceState(content::ContextPrivate::getGlobalContext().getInstanceStateBundle());
}

void ActivityPrivate::callOnStart()
{
    m_this.onStart();
}

void ActivityPrivate::callOnStop()
{
    m_this.onStop();
}

void ActivityPrivate::callOnContentChanged()
{
    m_this.onContentChanged();
}

bool ActivityPrivate::callOnGenericMotionEvent(MotionEvent& event)
{
    return m_this.onGenericMotionEvent(event);
}

bool ActivityPrivate::callOnKeyDown(int32_t keyCode, KeyEvent& event)
{
    return m_this.onKeyDown(keyCode, event);
}

bool ActivityPrivate::callOnKeyUp(int32_t keyCode, KeyEvent& event)
{
    return m_this.onKeyUp(keyCode, event);
}

} // namespace app
} // namespace android
