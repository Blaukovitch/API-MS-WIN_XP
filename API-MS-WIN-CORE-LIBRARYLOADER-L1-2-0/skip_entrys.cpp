#include "pch.h"


//379
extern "C"
{

    //DEFAULT 7
    EXPORT HMODULE WINAPI _LoadLibraryExA(LPCSTR lpLibFileName,
        HANDLE hFile,
        DWORD dwFlags) {
        return ::LoadLibraryExA(lpLibFileName,
            hFile,
            dwFlags);
    }

    EXPORT void WINAPI _FreeLibraryAndExitThread(HMODULE hLibModule,
        DWORD dwExitCode) {
        return ::FreeLibraryAndExitThread(hLibModule,
            dwExitCode);
    }

    EXPORT HMODULE WINAPI _GetModuleHandleW(LPCWSTR lpModuleName) {
        return ::GetModuleHandleW(lpModuleName);
    }

    EXPORT HGLOBAL WINAPI _LoadResource(HMODULE hModule,
        HRSRC hResInfo) {
        return ::LoadResource(hModule, hResInfo);
    }

    EXPORT DWORD WINAPI _SizeofResource(HMODULE hModule,
        HRSRC hResInfo) {
        return ::SizeofResource(hModule,
            hResInfo);
    }

    EXPORT LPVOID WINAPI _LockResource(HGLOBAL hResData) {
        return ::LockResource(hResData);
    }

    EXPORT BOOL WINAPI _FreeLibrary(HMODULE hLibModule)
    {
        return ::FreeLibrary(hLibModule);
    }

    EXPORT FARPROC WINAPI _GetProcAddress(HMODULE hModule,
        LPCSTR lpProcName) {
        return ::GetProcAddress(hModule,
            lpProcName);
    }

    EXPORT HMODULE WINAPI _LoadLibraryExW(LPCWSTR lpLibFileName,
        HANDLE hFile,
        DWORD dwFlags) {
        return ::LoadLibraryExW(lpLibFileName, hFile, dwFlags);
    }

    EXPORT DWORD WINAPI _GetModuleFileNameW(HMODULE hModule,
        LPWSTR lpFilename,
        DWORD nSize) {
        return ::GetModuleFileNameW(hModule,
            lpFilename,
            nSize);
    }

    EXPORT BOOL WINAPI _SetDefaultDllDirectories(DWORD DirectoryFlags) {
        return ::SetDefaultDllDirectories(DirectoryFlags);
    }

    EXPORT BOOL WINAPI _GetModuleHandleExW(DWORD dwFlags,
        LPCWSTR lpModuleName,
        HMODULE* phModule) {
        return ::GetModuleHandleExW(dwFlags,
            lpModuleName,
            phModule);
    }

    EXPORT BOOL WINAPI _LoadStringW(HINSTANCE hInstance,
        UINT uID,
        LPWSTR lpBuffer,
        int cchBufferMax) {
        return ::LoadStringW(hInstance,
            uID,
            lpBuffer,
            cchBufferMax);
    }

    
    EXPORT HMODULE WINAPI _GetModuleHandleA(LPCSTR lpModuleName) {
        return ::GetModuleHandleA(lpModuleName);
    }

    ///////

    EXPORT int WINAPI _zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz_LAST(LPCSTR lpString) {
        return 0x386;
    }


}
