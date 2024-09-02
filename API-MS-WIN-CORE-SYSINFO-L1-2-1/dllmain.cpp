// //[80_PA] ELF, cracklab/exelab, 2023-2024
#include "native.h"

// >>>>>>>>>> FLAG (debug options) <<<<<<<<<<<
//#define DEBUG_OUT 1
//#define COMPATIBLE10_7_MODE 1
#define   EXPORT __declspec(dllexport)
#define EXPORT_END _exported

const TCHAR WIDE_KERNEL32DLL[] = L"kernel32.dll";
const TCHAR WIDE_NTDLLDLL[] = L"ntdll.dll";
const char A_DHTCNEXW[] = "DnsHostnameToComputerNameExW";
const char A_IEALM[] = "InstallELAMCertificateInfo";
const char A_SCNEX2W[] = "SetComputerNameEx2W";
const char A_NTSSI[] = "NtSetSystemInformation";


// ------ globals ------ 
BOOL isdp = false;

typedef BOOL(WINAPI api_DnsHostnameToComputerNameExW)(const WCHAR* hostname, WCHAR* computername,
    DWORD* size
    );

typedef BOOL(WINAPI api_InstallELAMCertificateInfo)(HANDLE ELAMFile);

typedef BOOL(WINAPI api_SetComputerNameEx2W)(COMPUTER_NAME_FORMAT NameType,
    DWORD Flags,
    LPCWSTR lpBuffer);

typedef HRESULT(WINAPI api_NtSetSystemInformation)(SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID SystemInformation,
    ULONG SystemInformationLength);

api_DnsHostnameToComputerNameExW* farproc_DnsHostnameToComputerNameExW = 0;
api_InstallELAMCertificateInfo* farproc_InstallELAMCertificateInfo = 0;
api_SetComputerNameEx2W* farproc_SetComputerNameEx2W = 0;
api_NtSetSystemInformation* farproc_NtSetSystemInformation = 0;

// ----- ABSENT AP -----
HMODULE pKernel32;
HMODULE pNtdll;

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

        if (!pKernel32)
        {
            pKernel32 = ::GetModuleHandle(WIDE_KERNEL32DLL);
            pNtdll = ::GetModuleHandle(WIDE_NTDLLDLL);

            if(pKernel32)
            {
                farproc_DnsHostnameToComputerNameExW = (api_DnsHostnameToComputerNameExW*)::GetProcAddress(pKernel32, A_DHTCNEXW);
                farproc_InstallELAMCertificateInfo = (api_InstallELAMCertificateInfo*)::GetProcAddress(pKernel32, A_IEALM);
                farproc_SetComputerNameEx2W = (api_SetComputerNameEx2W*)::GetProcAddress(pKernel32, A_SCNEX2W);

                if (pNtdll)
                {
                    farproc_NtSetSystemInformation = (api_NtSetSystemInformation*)::GetProcAddress(pNtdll, A_NTSSI);
                }//end  if (pNtdll)
            }//end     if(pKernel32)
        }//end  if (!pKernel32)
        break;}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C"
{

    //https://fossies.org/dox/wine-9.16/dlls_2kernelbase_2registry_8c_source.html
    EXPORT BOOL WINAPI _DnsHostnameToComputerNameExW(const WCHAR* hostname, WCHAR* computername,
        DWORD* size) {
        static const WCHAR allowed[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&')(-_{}";
        WCHAR buffer[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD len = 0;

#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - DnsHostnameToComputerNameExW(%s, %s)", ::GetCurrentThreadId(), hostname, computername);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_DnsHostnameToComputerNameExW)
        {
            //Windows 7
            wcscpys(buffer, MAX_COMPUTERNAME_LENGTH, L"\0\0\0\0");
            if (lstrcpynW(buffer, hostname, MAX_COMPUTERNAME_LENGTH + 1) == NULL)
            {
                ::SetLastError(E_INVALIDARG);
                return FALSE;
            }
            len = lstrlenW(buffer);
            if (*size < len + 1)
            {
                *size = len;
                ::SetLastError(ERROR_MORE_DATA);
                return FALSE;
            }
            *size = len;
            DWORD i = 0;
            if (!computername) return FALSE;
            for (i = 0; i < len; i++)
            {
                if (buffer[i] >= 'a' && buffer[i] <= 'z') computername[i] = buffer[i] + 'A' - 'a';
                else computername[i] = wcschr1(allowed, buffer[i]) ? buffer[i] : '_';
            }
            computername[len] = 0;
            return TRUE;
        }
        else
            return farproc_DnsHostnameToComputerNameExW(hostname, computername, size);
    }

    EXPORT BOOL WINAPI _InstallELAMCertificateInfo(HANDLE ELAMFile) {

#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - InstallELAMCertificateInfo(%x)", ::GetCurrentThreadId(), ELAMFile);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_InstallELAMCertificateInfo)
        {
            //Windows 7

            if (farproc_NtSetSystemInformation)
            {
                HANDLE prohandle = ELAMFile;
               
                HRESULT hr = farproc_NtSetSystemInformation(SecSetEALMInfoHandle,(void*) &prohandle, sizeof(HANDLE));

                if (hr == ERROR_SUCCESS)
                    return TRUE;
                return FALSE;
            }//end if (farproc_NtSetSystemInformation)
            return FALSE;
        }
        else
            return farproc_InstallELAMCertificateInfo(ELAMFile);

        return FALSE;
    }

    EXPORT BOOL WINAPI _SetComputerNameEx2W(COMPUTER_NAME_FORMAT NameType,
        DWORD Flags,
        LPCWSTR lpBuffer)
    {

#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - SetComputerNameEx2W(%x, %x, %p)", ::GetCurrentThreadId(), NameType, Flags, lpBuffer);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_SetComputerNameEx2W)
        {
            //Windows 7

            if (!lpBuffer)
                return FALSE;

            //ignore Flags
            return ::SetComputerNameExW(NameType, lpBuffer);
        }
        else
            return farproc_SetComputerNameEx2W(NameType, Flags, lpBuffer);
    }
}
