/*
 * Copyright (C) 2016 Naver Corp. All rights reserved.
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

#include "ViewGroup.h"

#include <android/app/WindowProvider.h>
#include <android/view/ViewPrivate.h>
#include <android++/Functional.h>

namespace android {
namespace view {

ViewGroup::ViewGroup(Context& context)
    : View(context)
{
}

ViewGroup::~ViewGroup()
{
}

void ViewGroup::addView(std::passed_ptr<View> view)
{
    if (!view)
        return;

    ViewPrivate& viewPrivate = getPrivate(*view);
    if (!view || viewPrivate.parentView())
        return;

    m_children.insert(m_children.begin(), view);
    getPrivate(*this).childViewAttached(view.get());

    if (!isAttachedToWindow())
        return;

    view->onAttachedToWindow();
}

void ViewGroup::removeView(std::passed_ptr<View> view)
{
    if (!view)
        return;

    ViewPrivate& viewPrivate = getPrivate(*view);
    if (viewPrivate.parentView() != this)
        return;

    auto child = std::find(m_children.begin(), m_children.end(), view);
    m_children.erase(child);
    getPrivate(*this).childViewDetached(view.get());

    if (!isAttachedToWindow())
        return;

    view->onDetachedFromWindow();
}

void ViewGroup::bringChildToFront(std::passed_ptr<View>)
{
}

View* ViewGroup::findFocus()
{
    View* view = View::findFocus();
    if (!view)
        return propagate(m_children, &View::findFocus);

    return view;
}

View* ViewGroup::getChildAt(int index)
{
    if (m_children.size() <= index)
        return this;

    return m_children[index].get();
}

void ViewGroup::setVisibility(int32_t visibility)
{
    View::setVisibility(visibility);
    onVisibilityChanged(this, visibility);
}

bool ViewGroup::onGenericMotionEvent(MotionEvent& event)
{
    if (!propagate(m_children, &View::onGenericMotionEvent, event))
        return View::onGenericMotionEvent(event);

    return true;
}

bool ViewGroup::onKeyDown(int32_t keyCode, KeyEvent& event)
{
    if (!propagate(m_children, &View::onKeyDown, keyCode, event))
        return View::onKeyDown(keyCode, event);

    return true;
}

bool ViewGroup::onKeyUp(int32_t keyCode, KeyEvent& event)
{
    if (!propagate(m_children, &View::onKeyUp, keyCode, event))
        return View::onKeyUp(keyCode, event);

    return true;
}

void ViewGroup::onWindowFocusChanged(bool hasWindowFocus)
{
    View::onWindowFocusChanged(hasWindowFocus);
    propagate(m_children, &View::onWindowFocusChanged, hasWindowFocus);
}

void ViewGroup::onAttachedToWindow()
{
    View::onAttachedToWindow();
    propagate(m_children, &View::onAttachedToWindow);
}

void ViewGroup::onDetachedFromWindow()
{
    View::onDetachedFromWindow();
    propagate(m_children, &View::onDetachedFromWindow);
}

void ViewGroup::onSizeChanged(int32_t w, int32_t h, int32_t oldw, int32_t oldh)
{
    View::onSizeChanged(w, h, oldw, oldh);
    propagate(m_children, &View::onSizeChanged, w, h, oldw, oldh);
}

void ViewGroup::onVisibilityChanged(View* changedView, int32_t visibility)
{
    View::onVisibilityChanged(changedView, visibility);
    propagate(m_children, &View::onVisibilityChanged, changedView, visibility);
}

void ViewGroup::onWindowVisibilityChanged(int32_t visibility)
{
    View::onWindowVisibilityChanged(visibility);
    propagate(m_children, &View::onWindowVisibilityChanged, visibility);
}

void ViewGroup::onFocusChanged(bool gainFocus, int32_t direction, Rect& previouslyFocusedRect)
{
    View::onFocusChanged(gainFocus, direction, previouslyFocusedRect);
    propagate(m_children, &View::onFocusChanged, gainFocus, direction, previouslyFocusedRect);
}

void ViewGroup::onMeasure(int32_t widthMeasureSpec, int32_t heightMeasureSpec)
{
    View::onMeasure(widthMeasureSpec, heightMeasureSpec);
    propagate(m_children, &View::onMeasure, widthMeasureSpec, heightMeasureSpec);
}

void ViewGroup::onLayout(bool changed, int32_t left, int32_t top, int32_t right, int32_t bottom)
{
    View::onLayout(changed, left, top, right, bottom);
    propagate(m_children, &View::onLayout, changed, left, top, right, bottom);
}

void ViewGroup::onConfigurationChanged(Configuration& config)
{
    propagate(m_children, &View::onConfigurationChanged, config);
}

} // namespace view
} // namespace android
