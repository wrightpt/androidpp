/*
 * Copyright (C) 2016 Naver Corp. All rights reserved.
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

#include <android/view/View.h>
#include <android/view/MenuItem.h>

#include <platforms/Functional.h>
#include <platforms/Noncopyable.h>

#include <vector>

namespace android {
namespace view {

class ANDROID_EXPORT Menu {
    NONCOPYABLE(Menu);
public:
    static std::unique_ptr<Menu> Menu::create(View& anchor);
    virtual ~Menu() = default;

    typedef std::function<void (int32_t)> OnMenuItemClickListener;

    virtual void setOnMenuItemClickListener(OnMenuItemClickListener listener) { m_menuItemClickListener = std::move(listener); }

    virtual void addItem(const std::shared_ptr<MenuItem>&) = 0;
    virtual void addItems(const std::vector<std::shared_ptr<MenuItem>>&) = 0;
    virtual void addSeparator() = 0;
    virtual std::unique_ptr<Menu> addSubmenu(const std::shared_ptr<MenuItem>&) = 0;

    virtual void show(Point&) = 0;
    virtual void dismiss() = 0;

protected:
    Menu(View& anchor)
        : m_anchor(anchor)
    {
    }

    View& m_anchor;
    std::function<void (int32_t)> m_menuItemClickListener;
};

} // namespace view
} // namespace android

using Menu = android::view::Menu;
