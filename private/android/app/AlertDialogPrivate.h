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

#pragma once

#include <android/app/AlertDialog.h>

namespace android {
namespace app {

class AlertDialogPrivate final {
    friend class AlertDialog;
public:
    AlertDialogPrivate(AlertDialog&, Context&);
    ~AlertDialogPrivate();

    static AlertDialogPrivate& getPrivate(AlertDialog&);
    static void setPrivate(AlertDialog&, std::unique_ptr<AlertDialogPrivate>&&);

    void setMessage(CharSequence message);
    void setNegativeButton(CharSequence text, DialogInterface::OnClickListener&& listener);
    void setPositiveButton(CharSequence text, DialogInterface::OnClickListener&& listener);
    void show();

private:
    AlertDialog& m_this;
    Context& m_context;
    CharSequence m_message;
    using Button = std::pair<bool, std::pair<CharSequence, DialogInterface::OnClickListener>>;
    Button m_positiveButton;
    Button m_negativeButton;
};

} // namespace app
} // namespace android
