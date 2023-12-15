//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 
//#define DEBUG_OUT 1


// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_USERENV[] = L"userenv.dll";
const char A_CACP[] = "CreateAppContainerProfile";
const char A_DACSFACN[] = "DeriveAppContainerSidFromAppContainerName";
const char A_GPTYPE[] = "GetProfileType";
const char A_UUP[] = "UnloadUserProfile";

#pragma code_seg(pop)

// ----- ABSENT AP -----
HMODULE pUserenv;

typedef HRESULT(WINAPI api_CreateAppContainerProfile)(PCWSTR              pszAppContainerName,
    PCWSTR              pszDisplayName,
    PCWSTR              pszDescription,
    PSID_AND_ATTRIBUTES pCapabilities,
    DWORD               dwCapabilityCount,
    PSID* ppSidAppContainerSid);

typedef HRESULT(WINAPI api_DeriveAppContainerSidFromAppContainerName)(PCWSTR pszAppContainerName,
    PSID* ppsidAppContainerSid);

typedef BOOL(WINAPI api_GetProfileType)( DWORD* dwFlags);

api_CreateAppContainerProfile* farproc_CreateAppContainerProfile = 0;
api_DeriveAppContainerSidFromAppContainerName* farproc_DeriveAppContainerSidFromAppContainerName = 0;

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
        if (!pUserenv)
        {
            pUserenv = ::GetModuleHandle(WIDE_USERENV);

            if (pUserenv)
            {
                farproc_CreateAppContainerProfile = (api_CreateAppContainerProfile*)::GetProcAddress(pUserenv, A_CACP);
                farproc_DeriveAppContainerSidFromAppContainerName = (api_DeriveAppContainerSidFromAppContainerName*)::GetProcAddress(pUserenv, A_DACSFACN);
            }//end if (pUserenv)
        }//end if (!pUserenv)

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
    /*
    Minimum supported client 	Windows 8 [desktop apps only]
    Minimum supported server 	Windows Server 2012 [desktop apps only]
    Target Platform 	Windows
    Header 	userenv.h
    Library 	Userenv.lib
    DLL 	Userenv.dll
    */
    EXPORT HRESULT WINAPI _CreateAppContainerProfile(PCWSTR              pszAppContainerName,
        PCWSTR              pszDisplayName,
        PCWSTR              pszDescription,
        PSID_AND_ATTRIBUTES pCapabilities,
        DWORD               dwCapabilityCount,
        PSID* ppSidAppContainerSid)
    {

        if (!farproc_CreateAppContainerProfile)
        {
            //Windows 7
            ::SetLastError(E_NOTIMPL);
            return E_NOTIMPL;
        }
        else
            return farproc_CreateAppContainerProfile(pszAppContainerName,
                pszDisplayName,
                pszDescription,
                pCapabilities,
                dwCapabilityCount,
                ppSidAppContainerSid);
    }

    EXPORT HRESULT WINAPI _DeriveAppContainerSidFromAppContainerName(PCWSTR pszAppContainerName,
        PSID* ppsidAppContainerSid)
    {

        if (!farproc_DeriveAppContainerSidFromAppContainerName)
        {
            //Windows 7
            ::SetLastError(E_NOTIMPL);
            return E_NOTIMPL;
        }
        else
            return farproc_DeriveAppContainerSidFromAppContainerName(pszAppContainerName,
                ppsidAppContainerSid);
    }


}
