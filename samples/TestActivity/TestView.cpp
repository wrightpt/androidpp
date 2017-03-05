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

#include "TestView.h"

#include <android++/LogHelper.h>

namespace com {
namespace example {

TestView::TestView(Context& context)
    : View(context)
{
}

TestView::~TestView()
{
}

std::shared_ptr<InputConnection> TestView::onCreateInputConnection(EditorInfo& outAttrs)
{
    LOGD("%s", __FUNCTION__);
    return View::onCreateInputConnection(outAttrs);
}

bool TestView::onGenericMotionEvent(MotionEvent& event)
{
    if (event.getSource() == InputDevice::SOURCE_MOUSE &&
        event.getAction() == MotionEvent::ACTION_HOVER_MOVE)
        return false;

    LOGD("%s", __FUNCTION__);
    return View::onGenericMotionEvent(event);
}

bool TestView::onKeyDown(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return View::onKeyDown(keyCode, event);
}

bool TestView::onKeyLongPress(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return View::onKeyLongPress(keyCode, event);
}

bool TestView::onKeyMultiple(int32_t keyCode, int32_t repeatCount, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return View::onKeyMultiple(keyCode, repeatCount, event);
}

bool TestView::onKeyPreIme(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return View::onKeyPreIme(keyCode, event);
}

bool TestView::onKeyShortcut(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return View::onKeyShortcut(keyCode, event);
}

bool TestView::onKeyUp(int32_t keyCode, KeyEvent& event)
{
    LOGD("%s", __FUNCTION__);
    return View::onKeyUp(keyCode, event);
}

void TestView::onWindowFocusChanged(bool hasWindowFocus)
{
    LOGD("%s", __FUNCTION__);
    View::onWindowFocusChanged(hasWindowFocus);
}

void TestView::onAttachedToWindow()
{
    LOGD("%s", __FUNCTION__);
    View::onAttachedToWindow();
}

void TestView::onDetachedFromWindow()
{
    LOGD("%s", __FUNCTION__);
    View::onDetachedFromWindow();
}

void TestView::onSizeChanged(int32_t w, int32_t h, int32_t oldw, int32_t oldh)
{
    LOGD("%s", __FUNCTION__);
    View::onSizeChanged(w, h, oldw, oldh);
}

void TestView::onVisibilityChanged(View* changedView, int32_t visibility)
{
    LOGD("%s=%d", __FUNCTION__, visibility);
    View::onVisibilityChanged(changedView, visibility);
}

void TestView::onWindowVisibilityChanged(int32_t visibility)
{
    LOGD("%s=%d", __FUNCTION__, visibility);
    View::onWindowVisibilityChanged(visibility);
}

void TestView::onFocusChanged(bool gainFocus, int32_t direction, Rect& previouslyFocusedRect)
{
    LOGD("%s", __FUNCTION__);
    View::onFocusChanged(gainFocus, direction, previouslyFocusedRect);
}

void TestView::onLayout(bool changed, int32_t left, int32_t top, int32_t right, int32_t bottom)
{
    LOGD("%s", __FUNCTION__);
    View::onLayout(changed, left, top, right, bottom);
}

void TestView::onMeasure(int32_t widthMeasureSpec, int32_t heightMeasureSpec)
{
    LOGD("%s", __FUNCTION__);
    View::onMeasure(widthMeasureSpec, heightMeasureSpec);
}

void TestView::onConfigurationChanged(Configuration& configuration)
{
    LOGD("%s", __FUNCTION__);
    View::onConfigurationChanged(configuration);
}

} // namespace example
} // namespace com
