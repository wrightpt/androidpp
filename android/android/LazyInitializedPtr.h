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

#include <functional>
#include <memory>

namespace android {

template<typename T>
class LazyInitializedPtr {
public:
    template<typename F>
    LazyInitializedPtr(F&& constructor, bool initializeNow = false)
        : m_constructor(std::move(constructor))
    {
        if (initializeNow)
            get();
    }
    LazyInitializedPtr(const LazyInitializedPtr&) = delete;
    LazyInitializedPtr& operator=(const LazyInitializedPtr&) = delete;

    T* get() const
    {
        if (!m_isInitialized) {
            m_ptr.reset(m_constructor());
            m_isInitialized = true;
        }

        return m_ptr.get();
    }

    void set(T* ptr)
    {
        m_ptr.reset(ptr);
        m_isInitialized = true;
    }

    T* peek() const
    {
        return m_ptr.get();
    }

    T* operator->() const { return m_ptr.get(); }
    T& operator*() const { return *m_ptr.get(); }

private:
    std::function<T* ()> m_constructor;
    mutable bool m_isInitialized = false;
    mutable std::unique_ptr<T> m_ptr;
};

} // namespace android
