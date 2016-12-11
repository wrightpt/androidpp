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

#include "KeyEvent.h"

namespace android {
namespace view {

KeyEvent::KeyEvent(int32_t action, int32_t code)
{
}

KeyEvent::KeyEvent(std::chrono::milliseconds downTime, std::chrono::milliseconds eventTime, int32_t action, int32_t code, int32_t repeat)
{
}

KeyEvent::KeyEvent(std::chrono::milliseconds downTime, std::chrono::milliseconds eventTime, int32_t action, int32_t code, int32_t repeat, int32_t metaState)
{
}

KeyEvent::KeyEvent(std::chrono::milliseconds downTime, std::chrono::milliseconds eventTime, int32_t action, int32_t code, int32_t repeat, int32_t metaState, int32_t deviceId, int32_t scancode)
{
}

KeyEvent::KeyEvent(std::chrono::milliseconds downTime, std::chrono::milliseconds eventTime, int32_t action, int32_t code, int32_t repeat, int32_t metaState, int32_t deviceId, int32_t scancode, int32_t flags)
{
}

KeyEvent::KeyEvent(std::chrono::milliseconds downTime, std::chrono::milliseconds eventTime, int32_t action, int32_t code, int32_t repeat, int32_t metaState, int32_t deviceId, int32_t scancode, int32_t flags, int32_t source)
{
}

KeyEvent::KeyEvent(std::chrono::milliseconds time, String& characters, int32_t deviceId, int32_t flags)
{
}

KeyEvent::KeyEvent(const KeyEvent& origEvent)
{
}

KeyEvent::KeyEvent(KeyEvent&& origEvent)
{
}

int32_t KeyEvent::getAction()
{
    return 0;
}

int32_t KeyEvent::getDeadChar(int32_t accent, int32_t c)
{
    return 0;
}

std::chrono::milliseconds KeyEvent::getDownTime()
{
    return 0ms;
}

std::chrono::milliseconds KeyEvent::getEventTime()
{
    return 0ms;
}

int32_t KeyEvent::getFlags()
{
    return 0;
}

int32_t KeyEvent::getKeyCode()
{
    return 0;
}

int32_t KeyEvent::getMetaState()
{
    return 0;
}

int32_t KeyEvent::getModifierMetaStateMask()
{
    return 0;
}

int32_t KeyEvent::getModifiers()
{
    return 0;
}

char KeyEvent::getNumber()
{
    return 0;
}

int32_t KeyEvent::getRepeatCount()
{
    return 0;
}

int32_t KeyEvent::getScanCode()
{
    return 0;
}

int32_t KeyEvent::getSource()
{
    return 0;
}

int32_t KeyEvent::getUnicodeChar(int32_t metaState)
{
    return 0;
}

int32_t KeyEvent::getUnicodeChar()
{
    return 0;
}

bool KeyEvent::hasModifiers(int32_t modifiers)
{
    return false;
}

bool KeyEvent::hasNoModifiers()
{
    return false;
}

bool KeyEvent::isAltPressed()
{
    return false;
}

bool KeyEvent::isCanceled()
{
    return false;
}

bool KeyEvent::isCapsLockOn()
{
    return false;
}

bool KeyEvent::isCtrlPressed()
{
    return false;
}

bool KeyEvent::isFunctionPressed()
{
    return false;
}

bool KeyEvent::isGamepadButton(int32_t keyCode)
{
    return false;
}

bool KeyEvent::isLongPress()
{
    return false;
}

bool KeyEvent::isMetaPressed()
{
    return false;
}

bool KeyEvent::isModifierKey(int32_t keyCode)
{
    return false;
}

bool KeyEvent::isNumLockOn()
{
    return false;
}

bool KeyEvent::isPrintingKey()
{
    return false;
}

bool KeyEvent::isScrollLockOn()
{
    return false;
}

bool KeyEvent::isShiftPressed()
{
    return false;
}

bool KeyEvent::isSymPressed()
{
    return false;
}

bool KeyEvent::isSystem()
{
    return false;
}

bool KeyEvent::isTracking()
{
    return false;
}

int32_t KeyEvent::keyCodeFromString(String& symbolicName)
{
    return 0;
}

String& KeyEvent::keyCodeToString(int32_t keyCode)
{
    static String mappedString;
    return mappedString;
}

bool KeyEvent::metaStateHasModifiers(int32_t metaState, int32_t modifiers)
{
    return false;
}

bool KeyEvent::metaStateHasNoModifiers(int32_t metaState)
{
    return false;
}

int32_t KeyEvent::normalizeMetaState(int32_t metaState)
{
    return 0;
}

void KeyEvent::setSource(int32_t source)
{
}

void KeyEvent::startTracking()
{
}

} // namespace view
} // namespace android
