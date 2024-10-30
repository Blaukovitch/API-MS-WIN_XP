//[80_PA] ELF, cracklab/exelab, 2023

#include <powersetting.h>

// ------ globals ------ 
BOOL isdp = false;

#define POWER_PLATFORM_ROLE_V1     (0x00000001)
#define POWER_PLATFORM_ROLE_V1_MAX (PlatformRolePerformanceServer + 1)

#define POWER_PLATFORM_ROLE_V2     (0x00000002)
#define POWER_PLATFORM_ROLE_V2_MAX (PlatformRoleSlate + 1)

#define POWER_PLATFORM_ROLE_VERSION     POWER_PLATFORM_ROLE_V2
#define POWER_PLATFORM_ROLE_VERSION_MAX POWER_PLATFORM_ROLE_V2_MAX

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

extern "C"
{

    __declspec(dllexport) HRESULT _PowerRegisterForEffectivePowerModeNotifications(
        ULONG                         Version,
        EFFECTIVE_POWER_MODE_CALLBACK* Callback,
        PVOID                         Context,
        PVOID* RegistrationHandle
    ) {
        if ((Version > POWER_PLATFORM_ROLE_V2) || (!Callback) || (!Context) || (!RegistrationHandle))
            return E_INVALIDARG;

        return S_OK;
    }

    __declspec(dllexport) HRESULT _PowerUnregisterFromEffectivePowerModeNotifications(
        PVOID RegistrationHandle
    ) {
        return S_OK;
    }
}
