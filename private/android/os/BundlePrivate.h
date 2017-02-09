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

#include <android/os/Bundle.h>

#include <unordered_set>

namespace android {
namespace os {

class Bundle;

union BundleValue {
    int8_t b;
    wchar_t c;
    int16_t s;
    int32_t i;
    int64_t l { 0 };
    float f;
    double d;
};

class BundlePrivate {
    friend class Bundle;
public:
    BundlePrivate() = default;
    ~BundlePrivate() = default;

    bool findKey(StringRef key);
    void clear();
    void remove(StringRef key);

    BundleValue getValue(StringRef key);
    void putValue(StringRef key, BundleValue value);

    CharSequence getCharSequence(StringRef key);
    void putCharSequence(StringRef key, const CharSequence& value);

    std::shared_ptr<Parcelable> getParcelable(StringRef key);
    void putParcelable(StringRef key, std::passed_ptr<Parcelable> value);

    void writeToParcel(Parcel& dest, int32_t flags);
    void readFromParcel(Parcel& source);

private:
    void removeKey(StringRef key);

    std::unordered_set<String> m_keys;
    std::unordered_map<String, BundleValue> m_values;
    std::unordered_map<String, std::unique_ptr<CharSequence>> m_charSequences;
    std::unordered_map<String, std::shared_ptr<Parcelable>> m_parcelables;
};


} // namespace os
} // namespace android
