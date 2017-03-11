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

#include "AlertDialog.h"

#include <android/app/AlertDialogPrivate.h>

namespace android {
namespace app {

AlertDialog::Builder::Builder(Context& context)
    : m_dialog(std::make_unique<AlertDialog>(context))
{
}

AlertDialog::Builder::~Builder()
{
}

AlertDialog::Builder& AlertDialog::Builder::setMessage(CharSequence message)
{
    m_dialog->m_private->setMessage(std::move(message));
    return *this;
}

AlertDialog::Builder& AlertDialog::Builder::setNegativeButton(CharSequence text, DialogInterface::OnClickListener&& listener)
{
    m_dialog->m_private->setNegativeButton(std::move(text), std::move(listener));
    return *this;
}

AlertDialog::Builder& AlertDialog::Builder::setPositiveButton(CharSequence text, DialogInterface::OnClickListener&& listener)
{
    m_dialog->m_private->setPositiveButton(std::move(text), std::move(listener));
    return *this;
}

AlertDialog AlertDialog::Builder::show()
{
    m_dialog->m_private->show();
    return *m_dialog;
}

AlertDialog::AlertDialog(Context& context)
    : m_private(std::make_shared<AlertDialogPrivate>(*this, context))
{
}

AlertDialog::AlertDialog(const AlertDialog& other)
    : m_private(other.m_private)
{
}

AlertDialog::AlertDialog(AlertDialog&& other)
    : m_private(std::move(other.m_private))
{
}

AlertDialog& AlertDialog::operator=(const AlertDialog& other)
{
    m_private = other.m_private;
    return *this;
}

AlertDialog& AlertDialog::operator=(AlertDialog&& other)
{
    m_private = std::move(other.m_private);
    return *this;
}

AlertDialog::~AlertDialog()
{
}

} // namespace app
} // namespace android
