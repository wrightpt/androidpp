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

#include <android/content/Context.h>
#include <android/content/DialogInterface.h>

namespace android {
namespace app {

class AlertDialogPrivate;

class AlertDialog : public DialogInterface {
    friend class AlertDialogPrivate;
public:
    class Builder {
        NONCOPYABLE(Builder);
    public:
        // Creates a builder for an alert dialog that uses the default alert dialog theme. 
        ANDROID_EXPORT Builder(Context& context);
        ANDROID_EXPORT virtual ~Builder();

        // Set the message to display. 
        ANDROID_EXPORT virtual Builder& setMessage(CharSequence message);
        // Set a listener to be invoked when the negative button of the dialog is pressed. 
        ANDROID_EXPORT virtual Builder& setNegativeButton(CharSequence text, DialogInterface::OnClickListener&& listener);
        // Set a listener to be invoked when the positive button of the dialog is pressed. 
        ANDROID_EXPORT virtual Builder& setPositiveButton(CharSequence text, DialogInterface::OnClickListener&& listener);
        // Creates an AlertDialog with the arguments supplied to this builder and immediately displays the dialog. 
        ANDROID_EXPORT virtual AlertDialog show();

    private:
        std::unique_ptr<AlertDialog> m_dialog;
    };
    friend class Builder;

    ANDROID_EXPORT AlertDialog(Context& context);
    ANDROID_EXPORT AlertDialog(const AlertDialog&);
    ANDROID_EXPORT AlertDialog(AlertDialog&&);
    ANDROID_EXPORT AlertDialog& operator=(const AlertDialog&);
    ANDROID_EXPORT AlertDialog& operator=(AlertDialog&&);
    ANDROID_EXPORT virtual ~AlertDialog();

private:
    std::shared_ptr<AlertDialogPrivate> m_private;
};

} // namespace app
} // namespace android

using AlertDialog = android::app::AlertDialog;
