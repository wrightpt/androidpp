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

#include <java/lang/Package.h>

namespace java {
namespace lang {

class Class {
    NONCOPYABLE(Class)
    friend class ClassLoader;
public:
    ANDROID_EXPORT virtual ~Class();

    // Returns the Class object associated with the class or interface with the given string name. 
    ANDROID_EXPORT static std::passed_ptr<Class> forName(StringRef className);
    // Returns the class loader for the class. 
    ANDROID_EXPORT virtual ClassLoader& getClassLoader();
    // Gets the package for this class. 
    ANDROID_EXPORT virtual Package& getPackage();
    // Returns the name of the entity (class, interface, array class, primitive type, or void) represented by this Class object, as a String.
    ANDROID_EXPORT virtual String getName();
    // Returns the simple name of the underlying class as given in the source code. 
    ANDROID_EXPORT virtual StringRef getSimpleName();
    // Creates a new instance of the class represented by this Class object. 
    ANDROID_EXPORT virtual std::shared_ptr<void> newInstance();

protected:
    ANDROID_EXPORT Class(ClassLoader&, String&&, String&&, std::function<std::shared_ptr<void> ()>&&);

    ClassLoader& m_classLoader;
    Package& m_package;
    String m_name;
    std::function<std::shared_ptr<void> ()> m_constructor;
};

template<typename T> class ClassT final : public Class {
    friend class ClassLoader;
public:
    ClassT(String&& packageName, String&& name)
        : Class(ClassLoader::getSystemClassLoader(), std::move(packageName), std::move(name), [] { return std::make_shared<T>(); })
    {
    }
    ClassT(ClassLoader& classLoader, String&& packageName, String&& name)
        : Class(classLoader, std::move(packageName), std::move(name), [] { return std::make_shared<T>(); })
    {
    }
};

} // namespace lang
} // namespace java

using Class = java::lang::Class;

template<typename T>
Class& classT(const wchar_t* packageName = nullptr, const wchar_t* name = nullptr)
{
    static String binaryName;
    if (packageName && name) {
        assert(binaryName.empty());
        ClassLoader::getSystemClassLoader().definePackage(String(packageName), String(), String(), String(), String(), String(), String(), URL());
        ClassLoader::getSystemClassLoader().resolveClass(std::make_shared<java::lang::ClassT<T>>(String(packageName), String(name)));
        binaryName = String(packageName) + L'.' + String(name);
    }

    return *ClassLoader::getSystemClassLoader().findClass(binaryName);
}
