//[80_PA] ELF, cracklab/exelab, 2023

//FLAG 
#define DEBUG_OUT 1

typedef long NTSTATUS;

#define POWER_PLATFORM_ROLE_V1     (0x00000001)
#define POWER_PLATFORM_ROLE_V1_MAX (PlatformRolePerformanceServer + 1)

#define POWER_PLATFORM_ROLE_V2     (0x00000002)
#define POWER_PLATFORM_ROLE_V2_MAX (PlatformRoleSlate + 1)

#define POWER_PLATFORM_ROLE_VERSION     POWER_PLATFORM_ROLE_V2
#define POWER_PLATFORM_ROLE_VERSION_MAX POWER_PLATFORM_ROLE_V2_MAX

#define S_NTDLL_WIDE L"NTDLL.DLL"
#define S_NTDLL_NtPowerInformation_A "NtPowerInformation"

typedef NTSTATUS(WINAPI ntPWI)(
    POWER_INFORMATION_LEVEL InformationLevel,
    PVOID                   InputBuffer,
    ULONG                   InputBufferLength,
    PVOID                   OutputBuffer,
    ULONG                   OutputBufferLength
    );

// ------ globals ------ 
BOOL isdp = false;


ntPWI* NtPowerInformation;
ntPWI* QUERY_API_STATE1();

BOOL APIENTRY DllMain(HMODULE hModule,
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


__inline ntPWI* QUERY_API_STATE1()
{
   //Native API is present?
    HMODULE hmNTLIB = 0;
    if (!NtPowerInformation)
    {
        hmNTLIB = ::LoadLibrary(S_NTDLL_WIDE);
        if (!hmNTLIB)
            return NULL;
        NtPowerInformation = (ntPWI*)GetProcAddress(hmNTLIB, S_NTDLL_NtPowerInformation_A);

        if (!NtPowerInformation)
            return NULL;
    }//end if (!NtPowerInformation)

    return NtPowerInformation;
}

__declspec(dllexport) POWER_PLATFORM_ROLE WINAPI PowerDeterminePlatformRoleEx(ULONG Version)
{
    
    if (!QUERY_API_STATE1())
        return PlatformRoleUnspecified;

    NTSTATUS result = 0;
    DWORD OutputBuffer = 0;
    if (NtPowerInformation(PowerInformationLevelMaximum, 0, 0, &OutputBuffer, sizeof(DWORD)) < 0)
        result = 1;
    else
        result = OutputBuffer;
    if (Version < POWER_PLATFORM_ROLE_V2 && (DWORD)result == PlatformRoleMaximum)
        return PlatformRoleMobile;
    return (POWER_PLATFORM_ROLE)result;
}


__declspec(dllexport) NTSTATUS WINAPI CallNtPowerInformation(
    POWER_INFORMATION_LEVEL InformationLevel,
    PVOID InputBuffer,
    ULONG InputBufferLength,
    PVOID OutputBuffer,
    ULONG OutputBufferLength)
{
    NTSTATUS Result;
 
    if (!QUERY_API_STATE1())
        return ERROR_SYSTEM_POWERSTATE_TRANSITION;

    DWORD ReturnLength[2];
    Result = 0;
   
    if (InformationLevel == SystemExecutionState)
    {
        struct _TOKEN_PRIVILEGES NewState;
        struct _TOKEN_PRIVILEGES PreviousState;
        HANDLE TokenHandle = 0; 
        BOOL otk = FALSE;
        if (::OpenThreadToken(GetCurrentThread(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, 1, &TokenHandle))
            goto LABEL_6;
        if (::GetLastError() == ERROR_NO_TOKEN && ::ImpersonateSelf(SecurityImpersonation))
        {
            otk = TRUE;
            if (::OpenThreadToken(GetCurrentThread(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, 1, &TokenHandle))
            {
            LABEL_6:
                NewState.Privileges[0].Luid.LowPart = 19;
                NewState.Privileges[0].Luid.HighPart = 0;
                NewState.PrivilegeCount = 2;
                NewState.Privileges[0].Attributes = 2;
                ReturnLength[0] = 28;
                if (!AdjustTokenPrivileges(TokenHandle, FALSE, &NewState, sizeof(_TOKEN_PRIVILEGES), &PreviousState, ReturnLength))
                    PreviousState.PrivilegeCount = 0;
                goto LABEL_8;
            }
            TokenHandle = 0i64;
        }
    LABEL_8:
        Result = NtPowerInformation(InformationLevel, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength);
        if (otk)
        {
            ::RevertToSelf();
        }
        else if (PreviousState.PrivilegeCount)
        {
            ::AdjustTokenPrivileges(TokenHandle, 0, &PreviousState, 0x1Cu, 0, 0);
        }
        if (TokenHandle)
            ::CloseHandle(TokenHandle);
        return Result;
    }

    switch (InformationLevel)
    {
    case 0:
    case 1:
        /// <summary>
        /// 
        /// </summary>
        /// <param name="InformationLevel"></param>
        /// <param name="InputBuffer"></param>
        /// <param name="InputBufferLength"></param>
        /// <param name="OutputBuffer"></param>
        /// <param name="OutputBufferLength"></param>
        /// <returns></returns>
        break;
    case 2:
    case 3:
    case 11:
        return NtPowerInformation(InformationLevel, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength);
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
    case 12:
    case 14:
    case 15:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 65:
      //  goto LABEL_2;
    default:
        return  STATUS_INVALID_PARAMETER;
    }
    return Result;
}

