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

#include <crtdbg.h>
#include <shlwapi.h>
#include <windows.h>

#if defined _M_IX86
#define PROCESSORARCHITECTURE "x86"
#elif defined _M_IA64
#define PROCESSORARCHITECTURE "ia64"
#elif defined _M_X64
#define PROCESSORARCHITECTURE "amd64"
#else
#define PROCESSORARCHITECTURE "*"
#endif

#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='" PROCESSORARCHITECTURE "' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <android/app/ApplicationLoader.h>
#include <android++/StringConversion.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpstrCmdLine, int nCmdShow)
{
    std::vector<String> options = std::split(std::wstring(lpstrCmdLine), L'\"');
    std::unordered_map<String, String> parameters;
    parameters[L"hInstance"] = std::to_wstring((uint64_t)hInstance);
    parameters[L"hPrevInstance"] = std::to_wstring((uint64_t)hPrevInstance);
    parameters[L"nCmdShow"] = std::to_wstring(nCmdShow);

    ApplicationLoader loader;
    return loader.start(std::wcstoll(options[0].c_str(), NULL, 10), options[1], parameters);
}
