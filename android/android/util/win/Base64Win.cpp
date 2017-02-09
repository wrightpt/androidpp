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

#include "Base64.h"

#include <android++/StringConversion.h>

#include <windows.h>
#include <wincrypt.h>

namespace android {
namespace util {

static DWORD getCryptAPIFlags(int32_t flags)
{
    DWORD outFlags = CRYPT_STRING_BASE64;
    if (flags & Base64::NO_WRAP)
        outFlags |= CRYPT_STRING_NOCRLF;
    else if (!(flags & Base64::CRLF))
        outFlags |= CRYPT_STRING_NOCR;
    return outFlags;
}

std::vector<char> Base64::decode(StringRef str, int32_t flags)
{
    std::string input = std::ws2s(str);
    DWORD decodeLength = 0;
    if (!CryptStringToBinaryA(input.c_str(), input.size(), CRYPT_STRING_BASE64, NULL, &decodeLength, NULL, NULL))
        return {};

    std::vector<char> data(decodeLength);
    if (!CryptStringToBinaryA(input.c_str(), input.size(), CRYPT_STRING_BASE64, reinterpret_cast<BYTE*>(data.data()), &decodeLength, NULL, NULL))
        return {};

    return std::move(data);
}

std::vector<char> Base64::encode(std::vector<char>& input, int32_t flags)
{
    DWORD encodeLength = 0;
    if (!CryptBinaryToStringA(reinterpret_cast<const BYTE*>(input.data()), input.size(), getCryptAPIFlags(flags), NULL, &encodeLength))
        return {};

    std::vector<char> data(encodeLength);
    if (!CryptBinaryToStringA(reinterpret_cast<const BYTE*>(input.data()), input.size(), getCryptAPIFlags(flags), data.data(), &encodeLength))
        return {};

    return std::move(data);
}

String Base64::encodeToString(std::vector<char>& input, int32_t flags)
{
    std::vector<char> data = encode(input, flags);
    return std::s2ws(std::string(data.data(), data.size()));
}

} // namespace util
} // namespace android
