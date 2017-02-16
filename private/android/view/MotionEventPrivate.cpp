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

#include "MotionEventPrivate.h"

namespace android {
namespace view {

void MotionEventPrivate::setPrivateData(MotionEvent& event, int32_t actionButton, int32_t buttonState, int32_t repeatCount, float wheelDelta)
{
    event.m_wheelDelta = wheelDelta;
    event.m_actionButton = actionButton;
    event.m_buttonState = buttonState;
    event.m_repeatCount = repeatCount;
}

float MotionEventPrivate::getAxisValue(MotionEvent& event, int32_t axis, int32_t pointerIndex)
{
    if (axis == MotionEvent::AXIS_VSCROLL)
        return event.m_wheelDelta;
    return std::numeric_limits<float>::quiet_NaN();
}

float MotionEventPrivate::getOrientation(MotionEvent& event, int32_t pointerIndex)
{
    return std::numeric_limits<float>::quiet_NaN();
}

} // namespace view
} // namespace android
