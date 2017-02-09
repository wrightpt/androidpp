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

#include "ParcelablePrivate.h"

#include <android/os/ParcelPrivate.h>

namespace android {
namespace os {

static std::shared_ptr<Parcelable> readFromParcel(Parcel& source, StringRef binaryName)
{
    auto creatorClass = ClassLoader::getSystemClassLoader().findClass(binaryName);
    auto creator = std::static_pointer_cast<Parcelable::Creator>(creatorClass->newInstance());
    return creator->createFromParcel(source);
}

std::shared_ptr<Parcelable> ParcelablePrivate::createFromParcel(Parcel& source)
{
    String creatorBinaryName;
    source >> creatorBinaryName;
    return readFromParcel(source, creatorBinaryName);
}

std::shared_ptr<Parcelable> ParcelablePrivate::createFromParcel(Parcel& source, StringRef binaryName)
{
    String creatorBinaryName;
    source >> creatorBinaryName;
    if (binaryName != creatorBinaryName) {
        ParcelPrivate::getPrivate(source).reset();
        return nullptr;
    }
    return readFromParcel(source, creatorBinaryName);
}

} // namespace os
} // namespace android
