//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 
#define DEBUG_OUT 1

// ------ globals ------ 
BOOL isdp = false;
WCHAR Buffer[1024];

STDAPI  DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID FAR* ppv)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"MSVPROC.DllGetClassObject()");
#endif // DEBUG_OUT
    
  
    return E_NOINTERFACE;
};

__control_entrypoint(DllExport)
STDAPI DllCanUnloadNow(VOID)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"MSVPROC.DllCanUnloadNow()");
#endif // DEBUG_OUT
    
    return S_FALSE;
};


STDAPI DllUnregisterServer(VOID)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"MSVPROC.DllUnregisterServer()");
#endif // DEBUG_OUT

    return S_OK;
};


STDAPI DllRegisterServer(VOID)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"MSVPROC.DllRegisterServer()");
#endif // DEBUG_OUT
    return E_NOTIMPL;
};



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
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


