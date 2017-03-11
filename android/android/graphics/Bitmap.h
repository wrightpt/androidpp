/*
 * Copyright (C) 2016 NAVER Corp. All rights reserved.
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

#include <android/graphics/Point.h>

#include <vector>

namespace android {
namespace graphics {

class BitmapPrivate;

class Bitmap {
public:
    enum class Config : int32_t {
        ALPHA_8 = 1,
        ARGB_8888 = 5,
        RGB_565 = 3,
        INVALID = -1
    };

    ANDROID_EXPORT static std::shared_ptr<Bitmap> createBitmap(const std::vector<int32_t>& colors, int32_t width, int32_t height, Config config);

    ANDROID_EXPORT Bitmap(const std::vector<int32_t>& colors, int32_t width, int32_t height, Config config);
    ANDROID_EXPORT Bitmap(const Bitmap&);
    ANDROID_EXPORT Bitmap(Bitmap&&);
    ANDROID_EXPORT Bitmap& operator=(const Bitmap&);
    ANDROID_EXPORT Bitmap& operator=(Bitmap&&);
    ANDROID_EXPORT virtual ~Bitmap();

    ANDROID_EXPORT void setPixels(const std::vector<int32_t>& pixels, int32_t offset, int32_t stride, int32_t x, int32_t y, int32_t width, int32_t height);
    ANDROID_EXPORT void getPixels(std::vector<int32_t>& pixels, int32_t offset, int32_t stride, int32_t x, int32_t y, int32_t width, int32_t height);

    ANDROID_EXPORT int32_t getWidth();
    ANDROID_EXPORT int32_t getHeight();
    ANDROID_EXPORT int32_t getRowBytes();
    ANDROID_EXPORT int32_t getByteCount();

private:
    std::shared_ptr<BitmapPrivate> m_private;
};

} // namespace graphics
} // namespace android

using Bitmap = android::graphics::Bitmap;
