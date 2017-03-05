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

#include <android++/LogHelper.h>
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
    return reinterpret_cast<intptr_t>(handle);
}

int32_t PlatformFileDescriptor::detachFd(int32_t oldFd, intptr_t handle, intptr_t sourcePid, bool close)
{
    HANDLE sourceProcess = ::OpenProcess(PROCESS_DUP_HANDLE, FALSE, sourcePid);
    if (sourceProcess == NULL) {
        LOGA("The source process is invalid");
        return -1;
    }

    HANDLE myHandle = NULL;
    DWORD options = DUPLICATE_SAME_ACCESS | (close ? DUPLICATE_CLOSE_SOURCE : 0);
    if (!DuplicateHandle(sourceProcess, reinterpret_cast<HANDLE>(handle),
        ::GetCurrentProcess(), &myHandle, 0, FALSE, options)) {
        LOGA("Couldn't detach handle from the source process");
        ::CloseHandle(sourceProcess);
        return -1;
    }

    ::CloseHandle(sourceProcess);

    return win32_open_osfhandle(reinterpret_cast<intptr_t>(myHandle), 0, oldFd);
}

void PlatformFileDescriptor::encode(Parcel& dest, int32_t fd, intptr_t handle, int32_t flags)
{
    dest << fd;
    dest << handle;
    dest << static_cast<intptr_t>(::GetCurrentProcessId());

    if (flags == Parcelable::PARCELABLE_WRITE_RETURN_VALUE)
        dest << true;
    else
        dest << false;
}

std::tuple<int32_t, intptr_t, intptr_t, bool> PlatformFileDescriptor::decode(Parcel& source)
{
    std::tuple<int32_t, intptr_t, intptr_t, bool> result;
    source >> std::get<0>(result);
    source >> std::get<1>(result);
    source >> std::get<2>(result);
    source >> std::get<3>(result);
    return result;
}

} // namespace os
} // namespace android
