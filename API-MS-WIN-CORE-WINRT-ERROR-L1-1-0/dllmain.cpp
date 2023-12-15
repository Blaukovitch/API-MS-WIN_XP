//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 
//#define DEBUG_OUT 1

//https://learn.microsoft.com/en-us/windows/win32/api/roerrorapi
#define E_STRING_NOT_NULL_TERMINATED     _HRESULT_TYPEDEF_(0x80000017L)
typedef struct HSTRING__ {
    int unused;
} HSTRING__;
typedef HSTRING__* HSTRING;

typedef struct HSTRING_HEADER {
    union {
        PVOID Reserved1;
#if _WIN64
        char  Reserved2[24];
#else
        char  Reserved2[20];
#endif
    } Reserved;
} HSTRING_HEADER;


typedef struct {}*RO_REGISTRATION_COOKIE;

// ------ globals ------ 
BOOL isdp = false;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
#ifdef DEBUG_OUT
        //for OUTPUT DEBUG STRINGS (if needed)
        isdp = ::IsDebuggerPresent();
#endif // DEBUG_OUT
        break; }
    case DLL_THREAD_ATTACH: {
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break; }
    }
    return TRUE;
}

__declspec(dllexport) BOOL RoOriginateError(
    HRESULT error,
    HSTRING message
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoOriginateError()");
#endif // DEBUG_OUT
    return TRUE;
}

__declspec(dllexport) BOOL RoTransformError(
    HRESULT oldError,
    HRESULT newError,
    HSTRING message
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoTransformError()");
#endif // DEBUG_OUT
    return FALSE;
}

__declspec(dllexport) BOOL RoOriginateErrorW(
    HRESULT error,
    UINT    cchMax,
    PCWSTR  message
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoOriginateErrorW()");
#endif // DEBUG_OUT
    return TRUE;

}

__declspec(dllexport) void RoClearError()
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoClearError()");
#endif // DEBUG_OUT
    return;
}

__declspec(dllexport) BOOL IsErrorPropagationEnabled()
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY IsErrorPropagationEnabled()");
#endif // DEBUG_OUT
  
    /*
    Remarks
For Windows 8 apps, this value is FALSE, and errors returned by a delegate registered as a callback function for the asynchronous completion of a Windows Runtime API or for a Windows Runtime API event are ignored. For Windows 8.1 and Windows 10 apps, this value is TRUE, and errors from callback functions that return control to operating system code are propagated to the global error handler.
Use this function only when your code needs to interoperate with both Windows 8 and newer applications by using the same binary.
    */
    return TRUE;
}

__declspec(dllexport) HRESULT RoCaptureErrorContext(
    HRESULT hr)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoCaptureErrorContext()");
#endif // DEBUG_OUT
    return hr;
}

__declspec(dllexport) void RoFailFastWithErrorContext(
    HRESULT hrError)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoFailFastWithErrorContext()");
#endif // DEBUG_OUT
    return;
}
