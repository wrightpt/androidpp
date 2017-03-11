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

#include "AlertDialogPrivate.h"

namespace android {
namespace app {

AlertDialogPrivate::AlertDialogPrivate(AlertDialog& dialog, Context& context)
    : m_this(dialog)
    , m_context(context)
{
}

AlertDialogPrivate::~AlertDialogPrivate()
{
}

AlertDialogPrivate& AlertDialogPrivate::getPrivate(AlertDialog& dialog)
{
    return *dialog.m_private;
}

void AlertDialogPrivate::setPrivate(AlertDialog& dialog, std::unique_ptr<AlertDialogPrivate>&& p)
{
    dialog.m_private = std::move(p);
}

void AlertDialogPrivate::setMessage(CharSequence message)
{
    m_message = std::move(message);
}

void AlertDialogPrivate::setNegativeButton(CharSequence text, DialogInterface::OnClickListener&& listener)
{
    m_negativeButton.first = true;
    m_negativeButton.second.first = std::move(text);
    m_negativeButton.second.second = std::move(listener);
}

void AlertDialogPrivate::setPositiveButton(CharSequence text, DialogInterface::OnClickListener&& listener)
{
    m_negativeButton.first = false;
    m_positiveButton.second.first = std::move(text);
    m_positiveButton.second.second = std::move(listener);
}

} // namespace app
} // namespace android
