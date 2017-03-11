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

#include <android/app/ApplicationLoader.h>

namespace android {
namespace content {

class Context;

class ContextPrivate {
    friend class Context;
public:
    ContextPrivate();
    ~ContextPrivate() = default;

    static ContextPrivate& getPrivate(Context&);
    static void setPrivate(Context&, std::unique_ptr<ContextPrivate>&&);

    static ApplicationContext& getGlobalContext();
    static void setGlobalContext(ApplicationContext&);

    void setAsActivity();
    void setAsService();
    void setAsApplicationContext();
    bool isActivity();
    bool isService();
    bool isApplication();
    bool isApplicationContext();

    app::ApplicationLoader* getApplicationLoader();
    void setApplicationLoader(app::ApplicationLoader*);

private:
    bool m_isActivity { false };
    bool m_isService { false };
    bool m_isApplicationContext { false };
    app::ApplicationLoader* m_loader { nullptr };
};

} // namespace content
} // namespace android
