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

#include "PlatformFileDescriptor.h"

#include <android++/StringConversion.h>
#include <win/osf.h>

#include <VersionHelpers.h>
#include <Windows.h>
#include <shlwapi.h>

namespace android {
namespace os {

intptr_t PlatformFileDescriptor::adoptFd(int32_t fd)
{
    HANDLE handle = reinterpret_cast<HANDLE>(win32_release_osfhandle(fd));
    // Ensure that the child process inherits the file descriptor handles.
    ::SetHandleInformation(handle, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
    return reinterpret_cast<intptr_t>(handle);
}

int32_t PlatformFileDescriptor::detachFd(int32_t oldFd, intptr_t handle)
{
    return win32_open_osfhandle(handle, 0, oldFd);
}

void PlatformFileDescriptor::encode(Parcel& dest, int32_t fd, intptr_t handle, int32_t flags)
{
    dest << fd;
    dest << handle;

    if (flags == Parcelable::PARCELABLE_WRITE_RETURN_VALUE) {
        // We can now close the file descriptor handles.
        ::CloseHandle((HANDLE)handle);
    }
}

std::pair<int32_t, intptr_t> PlatformFileDescriptor::decode(Parcel& source)
{
    std::pair<int32_t, intptr_t> result;
    source >> result.first;
    source >> result.second;
    return std::move(result);
}

} // namespace os
} // namespace android
