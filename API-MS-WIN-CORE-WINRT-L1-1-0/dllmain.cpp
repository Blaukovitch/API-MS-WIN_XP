//[80_PA] ELF, cracklab/exelab, 2023
#include <OAIdl.h>
//FLAG 
#define DEBUG_OUT 1


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

typedef struct _APARTMENT_SHUTDOWN_REGISTRATION_COOKIE {
    INT64 value;
} APARTMENT_SHUTDOWN_REGISTRATION_COOKIE, * PAPARTMENT_SHUTDOWN_REGISTRATION_COOKIE;

typedef enum RO_INIT_TYPE {
    RO_INIT_SINGLETHREADED = 0,
    RO_INIT_MULTITHREADED = 1
};

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



__declspec(dllexport) HRESULT RoActivateInstance(
    HSTRING      activatableClassId,
    //IInspectable** instance
    void** instance
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoActivateInstance()");
#endif // DEBUG_OUT
    return E_ABORT;
}

__declspec(dllexport)HRESULT GetActivationFactory(
    HSTRING activatableClassId,
    void** factory
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY GetActivationFactory()");
#endif // DEBUG_OUT
    return E_ABORT;
}

__declspec(dllexport)HRESULT RoGetActivationFactory(
    HSTRING activatableClassId,
    REFIID  iid,
    void** factory
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoGetActivationFactory()");
#endif // DEBUG_OUT
    return E_ABORT;
}

__declspec(dllexport)HRESULT RoGetApartmentIdentifier(
   UINT64* apartmentIdentifier
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoGetApartmentIdentifier()");
#endif // DEBUG_OUT
    return E_ABORT;
}

__declspec(dllexport)HRESULT RoInitialize(
    RO_INIT_TYPE initType
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoInitialize()");
#endif // DEBUG_OUT
    return S_OK;
}

__declspec(dllexport)HRESULT RoRegisterActivationFactories(
    HSTRING* activatableClassIds,
    IDispatch* activationFactoryCallbacks,
    UINT32                  count,
    RO_REGISTRATION_COOKIE* cookie
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoRegisterActivationFactories()");
#endif // DEBUG_OUT
    return E_ABORT;
}

__declspec(dllexport)HRESULT RoRegisterForApartmentShutdown(
    IApartmentShutdown* callbackObject,
    UINT64* apartmentIdentifier,
    APARTMENT_SHUTDOWN_REGISTRATION_COOKIE* regCookie
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoRegisterForApartmentShutdown()");
#endif // DEBUG_OUT
    return E_ABORT;
}

__declspec(dllexport)HRESULT RoRevokeActivationFactories(
    RO_REGISTRATION_COOKIE cookie
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoRevokeActivationFactories()");
#endif // DEBUG_OUT
    return E_ABORT;
}

__declspec(dllexport)HRESULT RoUninitialize(
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoUninitialize()");
#endif // DEBUG_OUT
    return S_OK;
}

__declspec(dllexport)HRESULT RoUnregisterForApartmentShutdown(
    APARTMENT_SHUTDOWN_REGISTRATION_COOKIE regCookie
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoUnregisterForApartmentShutdown()");
#endif // DEBUG_OUT
    return S_OK;
}

