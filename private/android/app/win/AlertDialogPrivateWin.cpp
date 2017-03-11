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

#include <android.h>
#include <android/content/ContextPrivate.h>
#include <android/os/Binder.h>
#include <windows.h>

namespace android {
namespace app {

void AlertDialogPrivate::show()
{
    auto window = std::static_pointer_cast<Binder>(content::ContextPrivate::getGlobalContext().getWindowToken());
    UINT type = MB_OK;
    if (m_positiveButton.first && m_negativeButton.first)
        type = MB_YESNO;

    int result = ::MessageBox(reinterpret_cast<HWND>(window->handle()), m_message.c_str(), L"Alert", type);
    switch (result) {
    case IDYES:
        m_positiveButton.second.second(m_this, DialogInterface::BUTTON_POSITIVE);
        break;
    case IDNO:
        m_negativeButton.second.second(m_this, DialogInterface::BUTTON_NEGATIVE);
        break;
    case IDOK:
    default:
        break;
    }
}

} // namespace app
} // namespace android
