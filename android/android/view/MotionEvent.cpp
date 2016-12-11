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

#include "MotionEvent.h"

#include <android/view/MotionEventPrivate.h>

namespace android {
namespace view {

MotionEvent::MotionEvent()
{
}

MotionEvent::MotionEvent(MotionEvent&& other)
{
}

MotionEvent MotionEvent::obtain(std::chrono::milliseconds downTime, std::chrono::milliseconds eventTime, int32_t action, float x, float y, int32_t metaState)
{
    return MotionEvent();
}

MotionEvent MotionEvent::obtain(std::chrono::milliseconds downTime, std::chrono::milliseconds eventTime, int32_t action, float x, float y, float pressure, float size, int32_t metaState, float xPrecision, float yPrecision, int32_t deviceId, int32_t edgeFlags)
{
    return MotionEvent();
}

MotionEvent MotionEvent::obtain(const MotionEvent& other)
{
    return MotionEvent();
}

String MotionEvent::actionToString(int32_t action)
{
    return String();
}

int32_t MotionEvent::axisFromString(String symbolicName)
{
    return 0;
}

String MotionEvent::axisToString(int32_t axis)
{
    return String();
}

int32_t MotionEvent::getAction()
{
    return 0;
}

int32_t MotionEvent::getActionButton()
{
    return 0;
}

float MotionEvent::getAxisValue(int32_t axis, int32_t pointerIndex)
{
    return 0.0f;
}

float MotionEvent::getAxisValue(int32_t axis)
{
    return 0.0f;
}

int32_t MotionEvent::getButtonState()
{
    return 0;
}

int32_t MotionEvent::getDeviceId()
{
    return 0;
}

std::chrono::milliseconds MotionEvent::getDownTime()
{
    return 0ms;
}

std::chrono::milliseconds MotionEvent::getEventTime()
{
    return 0ms;
}

int32_t MotionEvent::getFlags()
{
    return 0;
}

int32_t MotionEvent::getMetaState()
{
    return 0;
}

float MotionEvent::getOrientation()
{
    return 0.0f;
}

float MotionEvent::getOrientation(int32_t pointerIndex)
{
    return 0.0f;
}

int32_t MotionEvent::getPointerCount()
{
    return 0;
}

float MotionEvent::getPressure(int32_t pointerIndex)
{
    return 0.0f;
}

float MotionEvent::getPressure()
{
    return 0.0f;
}

float MotionEvent::getRawX()
{
    return 0.0f;
}

float MotionEvent::getRawY()
{
    return 0.0f;
}

float MotionEvent::getSize(int32_t pointerIndex)
{
    return 0.0f;
}

float MotionEvent::getSize()
{
    return 0.0f;
}

int32_t MotionEvent::getSource()
{
    return 0;
}

float MotionEvent::getX(int32_t pointerIndex)
{
    return 0.0f;
}

float MotionEvent::getX()
{
    return 0.0f;
}

float MotionEvent::getXPrecision()
{
    return 0.0f;
}

float MotionEvent::getY()
{
    return 0.0f;
}

float MotionEvent::getY(int32_t pointerIndex)
{
    return 0.0f;
}

float MotionEvent::getYPrecision()
{
    return 0.0f;
}

bool MotionEvent::isButtonPressed(int32_t button)
{
    return false;
}

void MotionEvent::offsetLocation(float deltaX, float deltaY)
{
}

void MotionEvent::recycle()
{
}

void MotionEvent::setAction(int32_t action)
{
}

void MotionEvent::setLocation(float x, float y)
{
}

void MotionEvent::setSource(int32_t source)
{
}

} // namespace view
} // namespace android
