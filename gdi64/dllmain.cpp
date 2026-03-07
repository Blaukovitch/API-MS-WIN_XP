//[80_PA] ELF, cracklab/exelab, 2023-2026
//FLAG 
//#define DEBUG_OUT 1
#include <Windows.h>
#include <usp10.h>
#define WIN32_LEAN_AND_MEAN             
#define EXPORT __declspec( dllexport )
#pragma comment(linker, "/ENTRY:DllMain")
/*
    Important  Starting with Windows 8: To maintain the ability to run on Windows 7, 
    a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.
*/
//#pragma comment(linker, "/NODEFAULTLIB")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "Usp10.lib")
#pragma comment(lib, "gdi32.lib")

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#ifndef __FLTUSED__
#define __FLTUSED__
extern "C" __declspec(selectany) int _fltused = 1;
#endif

extern "C"
{
    /*
        Requirement 	Value
        Minimum supported client 	Windows 2000 Professional [desktop apps only]
        Minimum supported server 	Windows 2000 Server [desktop apps only]
        Target Platform 	Windows
        Header 	usp10.h
        Library 	Usp10.lib
        DLL 	Usp10.dll
        Redistributable 	Internet Explorer 5 or later on Windows Me/98/95
    */
    EXPORT HRESULT WINAPI _ScriptFreeCache(SCRIPT_CACHE* psc) {
        return ::ScriptFreeCache(psc);
    }
}