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

#include <java/lang.h>

namespace android {
namespace util {

class Base64 {
public:
    // Default values for encoder/decoder flags. 
    static const int32_t DEFAULT = 0;
    // Encoder flag bit to omit all line terminators (i.e., the output will be on one long line).  
    static const int32_t NO_WRAP = 1 << 1;
    // Encoder flag bit to indicate lines should be terminated with a CRLF pair instead of just an LF.  
    static const int32_t CRLF = 1 << 2;

    // Decode the Base64-encoded data in input and return the data in a new byte array.
    static std::vector<char> decode(StringRef str, int32_t flags);
    // Base64-encode the given data and return a newly allocated std::vector<char> with the result.
    static std::vector<char> encode(std::vector<char>& input, int32_t flags);
    // Base64-encode the given data and return a newly allocated String with the result. 
    static String encodeToString(std::vector<char>& input, int32_t flags);

private:
    Base64() = default;
};

} // namespace util
} // namespace android

using Base64 = android::util::Base64;
