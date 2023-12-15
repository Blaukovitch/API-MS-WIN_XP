//[80_PA] ELF, cracklab/exelab, 2023
//FLAG
//#define DEBUG_OUT 1

//THIS FOR Microsoft EDGE only needed (120..77)//


// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")

const TCHAR WIDE_NTDLLDLL[] = L"ntdll.dll";
const char A_NTQSYS[] = "NtQuerySystemInformation";
#pragma code_seg(pop)

//https://learn.microsoft.com/en-us/windows/win32/api/wldp/ne-wldp-wldp_windows_lockdown_mode
typedef enum WLDP_WINDOWS_LOCKDOWN_MODE {
    WLDP_WINDOWS_LOCKDOWN_MODE_UNLOCKED,
    WLDP_WINDOWS_LOCKDOWN_MODE_TRIAL,
    WLDP_WINDOWS_LOCKDOWN_MODE_LOCKED,
    WLDP_WINDOWS_LOCKDOWN_MODE_MAX
}  *PWLDP_WINDOWS_LOCKDOWN_MODE;

typedef enum _SYSTEM_INFORMATION_CLASS {
    SystemBasicInformation = 0,
    SystemPerformanceInformation = 2,
    SystemTimeOfDayInformation = 3,
    SystemProcessInformation = 5,
    SystemProcessorPerformanceInformation = 8,
    SystemInterruptInformation = 23,
    SystemExceptionInformation = 33,
    SystemRegistryQuotaInformation = 37,
    SystemLookasideInformation = 45,
    SystemLOCKDOWNPOLICY = 0xA4
} SYSTEM_INFORMATION_CLASS;

typedef HRESULT(WINAPI api_WldpQueryWindowsLockdownMode)(PWLDP_WINDOWS_LOCKDOWN_MODE lockdownMode);
api_WldpQueryWindowsLockdownMode* farproc_WldpQueryWindowsLockdownMode = 0;

typedef HRESULT(WINAPI api_NtQuerySystemInformation)(SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID                    SystemInformation,
    ULONG                    SystemInformationLength,
    ULONG                   ReturnLength);
api_NtQuerySystemInformation* farproc_NtQuerySystemInformation = 0;

HMODULE pNtdll = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {

        if(!pNtdll)
        {
            pNtdll = ::GetModuleHandle(WIDE_NTDLLDLL);

            if (pNtdll)
            {
                farproc_NtQuerySystemInformation = (api_NtQuerySystemInformation*)::GetProcAddress(pNtdll, A_NTQSYS);
            }//end if (pNtdll)
        }//end if(!pNtdll)

        break; }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C"
{
    EXPORT HRESULT WINAPI _WldpQueryWindowsLockdownMode(PWLDP_WINDOWS_LOCKDOWN_MODE lockdownMode)
    {
        if (!lockdownMode)
        {
            ::SetLastError(ERROR_INVALID_PARAMETER);
            return E_INVALIDARG;
        }//end if (!penInfo)

        if (farproc_NtQuerySystemInformation)
        {
            signed long lockdownsets[8];
            memset(lockdownsets, 0, sizeof(lockdownsets));
            if (farproc_NtQuerySystemInformation(SystemLOCKDOWNPOLICY, lockdownsets, sizeof(lockdownsets), NULL))
            {
                
                
                if ((lockdownsets[0] & 0x20000000) != 0)
                    *lockdownMode = WLDP_WINDOWS_LOCKDOWN_MODE_LOCKED;
                else
                {
                    if(lockdownsets[0] < 0)
                        *lockdownMode = WLDP_WINDOWS_LOCKDOWN_MODE_TRIAL;
                    else
                        *lockdownMode = WLDP_WINDOWS_LOCKDOWN_MODE_UNLOCKED;
                    return S_OK;
                }
            }//end if (farproc_NtQuerySystemInformation(SystemLOCKDOWNPOLICY, lockdownsets, sizeof(lockdownsets), NULL))
        }//end if (farproc_WldpQueryWindowsLockdownMode)

        *lockdownMode = WLDP_WINDOWS_LOCKDOWN_MODE_UNLOCKED;
        return S_OK;
    }
}
