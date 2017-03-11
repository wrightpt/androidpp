/*
 * Copyright (C) 2016 NAVER Labs. All rights reserved.
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

#if defined(WIN32)
#define COMPILER_EXPORT __declspec(dllexport)
#define COMPILER_IMPORT __declspec(dllimport)
#else
#define COMPILER_EXPORT __attribute__((visibility("default")))
#define COMPILER_IMPORT __attribute__((visibility("default")))
#endif

#if defined(ANDROID_STATIC)
#define ANDROID_EXPORT
#else
#if defined(BUILDING_ANDROID)
#define ANDROID_EXPORT COMPILER_EXPORT
#else
#define ANDROID_EXPORT COMPILER_IMPORT
#endif
#endif
#if !defined(ANDROID_EXTERN)
#if defined(BUILDING_ANDROID_PACKAGE)
#define ANDROID_EXTERN COMPILER_EXPORT
#else
#define ANDROID_EXTERN COMPILER_IMPORT
#endif
#endif

#if defined(__cplusplus)
#define ANDROID_C_EXPORT extern "C" ANDROID_EXPORT
#else
#define ANDROID_C_EXPORT extern ANDROID_EXPORT
#endif

#define NO_EXPORT

#if defined(JNI_STATIC) || defined(JNI_SHARED)
#include <androidjni/JNIExportMacros.h>
#endif
