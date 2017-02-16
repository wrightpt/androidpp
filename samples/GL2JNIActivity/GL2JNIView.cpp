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

#include "GL2JNIView.h"

#include "GL2JNILib.h"
#include <android++/LogHelper.h>

namespace com {
namespace example {

static const String TAG = L"GL2JNIView";
static const bool DEBUG = false;

GL2JNIView::GL2JNIView(Context& context)
    : GLSurfaceView(context)
{
    init(false, 0, 0);
}

GL2JNIView::GL2JNIView(Context& context, bool translucent, int32_t depth, int32_t stencil)
    : GLSurfaceView(context)
{
    init(translucent, depth, stencil);
}

void GL2JNIView::init(bool translucent, int32_t depth, int32_t stencil)
{
    setEGLContextClientVersion(2);

    /* Set the renderer responsible for frame rendering */
    setRenderer(new Renderer());
}

void GL2JNIView::Renderer::onDrawFrame(GL10 gl)
{
    GL2JNILib::step();
}

void GL2JNIView::Renderer::onSurfaceChanged(GL10 gl, int32_t width, int32_t height)
{
    GL2JNILib::init(width, height);
}

void GL2JNIView::Renderer::onSurfaceCreated(GL10 gl)
{
    // Do nothing.
}

} // namespace example
} // namespace com
