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

#include "ClassLoader.h"

#include <java/lang/Class.h>
#include <android++/StringConversion.h>

namespace java {
namespace lang {

ClassLoader::ClassLoader()
{
}

ClassLoader::~ClassLoader()
{
}

ClassLoader& ClassLoader::getSystemClassLoader()
{
    static std::unique_ptr<ClassLoader> loader = std::make_unique<ClassLoader>();
    return *loader;
}

std::passed_ptr<Package> ClassLoader::definePackage(StringRef name, StringRef specTitle, StringRef specVersion, StringRef specVendor, StringRef implTitle, StringRef implVersion, StringRef implVendor, URL& sealBase)
{
    if (m_packages.count(name))
        return getPackage(name);

    return m_packages[name] = std::shared_ptr<Package>(new Package(*this, String(name)));
}

std::passed_ptr<Package> ClassLoader::getPackage(StringRef name)
{
    if (!m_packages.count(name))
        return nullptr;

    return m_packages[name];
}

std::passed_ptr<Class> ClassLoader::findClass(StringRef name)
{
    if (!m_classes.count(name))
        return nullptr;

    return m_classes[name];
}

void ClassLoader::resolveClass(std::passed_ptr<Class> c)
{
    if (m_classes.count(c->getName()))
        return;

    m_classes[c->getName()] = c;
}

} // namespace lang
} // namespace java
