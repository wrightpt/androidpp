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

#include "GL2JNIActivity.h"

#include "GL2JNIView.h"
#include <android++/LogHelper.h>

namespace com {
namespace example {

GL2JNIActivity::GL2JNIActivity()
{
}

GL2JNIActivity::~GL2JNIActivity()
{
}

void GL2JNIActivity::onCreate(std::passed_ptr<Bundle> savedInstanceState)
{
    LOGD("%s", __FUNCTION__);
    Activity::onCreate(savedInstanceState);
    mView = std::make_shared<GL2JNIView>(getApplicationContext());
    setContentView(mView);
}

void GL2JNIActivity::onPause()
{
    LOGD("%s", __FUNCTION__);
    Activity::onPause();
    mView->onPause();
}

void GL2JNIActivity::onResume()
{
    LOGD("%s", __FUNCTION__);
    Activity::onResume();
    mView->onResume();
}

} // namespace example
} // namespace com
