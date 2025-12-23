//[80_PA] ELF, cracklab/exelab, 2023-2025
//FLAG 
#pragma comment(linker, "/ENTRY:DllMain")
#pragma comment(lib, "ntdll.lib")

#define WIN32_LEAN_AND_MEAN  

#include "kernel64.h"

// >>>>>>>>>> FLAG (debug options) <<<<<<<<<<<
//#define DEBUG_OUT 1
//#define COMPATIBLE10_7_MODE 1

// >>>>>>>>>> FLAG (one of browser) <<<<<<<<<<<
#define CHROME 1
//#define EDGE 1
//#define BRAVE 1
//#define OPERA 1
//#define VIVALDI 1
//#define MAIL 1
//#define SPOOTIFY 1
//#define FIREFOX 1
//#define TRVIEW 1
//#define MAILBIRD 1
//#define DISCORD 1
//#define CIMMCO_EDIT 1


// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_KERNEL32DLL[] = L"kernel32.dll";
const TCHAR WIDE_NTDLLDLL[] = L"ntdll.dll";
const TCHAR WIDE_MPFLAT_386[] = L"XFPlat.DLL";
const TCHAR WIDE_DWRITE[] = L"dwrite.dll";
const TCHAR WIDE_SCS_FONTCACHE_SERVICENAME[] = L"FontCache";
const TCHAR WIDE_WLDP[] = L"wldp.dll\0\0";
const char A_DVM[] = "DiscardVirtualMemory";
const char A_PVM[] = "PrefetchVirtualMemory";
const char A_STI[] = "SetThreadInformation";
const char A_IETS[] = "IsEnclaveTypeSupported";
const char A_GSTPAFT[] = "GetSystemTimePreciseAsFileTime";
const char A_NTSIT[] = "NtSetInformationThread";
const char A_NTSIVM[] = "NtSetInformationVirtualMemory";
const char A_GFT[] = "GetFirmwareType";
const char A_W64GTC[] = "Wow64GetThreadContext";
const char A_SPI[] = "SetProcessInformation";
const char A_GPMP[] = "GetProcessMitigationPolicy";
const char A_SPMP[] = "SetProcessMitigationPolicy";
const char A_GPFN[] = "GetPackageFamilyName";
const char A_NTQIT[] = "NtQueryInformationToken";
const char A_GPAI[] = "GetPackageApplicationIds";
const char A_OPIBFN[] = "OpenPackageInfoByFullName";
const char A_GAUMI[] = "GetApplicationUserModelId";
const char A_GCPFN[] = "GetCurrentPackageFullName";
const char A_GPI[] = "GetProcessInformation";
const char A_GSCSI[] = "GetSystemCpuSetInformation";
const char A_NTQSIEX[] = "NtQuerySystemInformationEx";
const char A_GORE[] = "GetOverlappedResultEx";

#if !defined(BRAVE) && !defined(EDGE) && !defined(OPERA) && !defined(VIVALDI) && !defined(MAIL) && !defined(SPOOTIFY) && !defined(FIREFOX) && !defined(TRVIEW) && !defined(MAILBIRD) && !defined(DISCORD)
const char PRIMARY_EXE[] = "chrome.exe";
#endif

#ifdef BRAVE
const char PRIMARY_EXE[] = "brave.exe";
#endif // BRAVE

#ifdef EDGE
const char PRIMARY_EXE[] = "msedge.exe";
#endif // EDGE

#ifdef OPERA
const char PRIMARY_EXE[] = "opera.exe";
#endif //OPERA

#ifdef VIVALDI
const char PRIMARY_EXE[] = "vivaldi.exe";
#endif //VIVALDI

#ifdef MAIL
const char PRIMARY_EXE[] = "ElectronMail.exe";
#endif //MAIL

#ifdef SPOOTIFY
const char PRIMARY_EXE[] = "Spotify.exe";
#endif //SPOOTIFY

#ifdef FIREFOX
const char PRIMARY_EXE[] = "firefox.exe";
#include <combaseapi.h>
#endif //FIREFOX

#ifdef TRVIEW
const char PRIMARY_EXE[] = "TradingView.exe";
#endif //TRVIEW

#ifdef MAILBIRD
const char PRIMARY_EXE[] = "libcef.dll";
#endif //MAILBIRD

#ifdef DISCORD
const char PRIMARY_EXE[] = "discord.exe";
#endif // DISCORD


const char PRIMARY_EXE_Is_SANDBOXED_SA[] = "IsSandboxedProcess";
const char SERVICE_QUERY_ADVAPI32_DLL[] = "ADVAPI32.DLL";



const WCHAR WIDE_NULL_GUID_PTR[] = L"{00000000-0000-0000-0000-000000000000}";
const WCHAR WIDE_CH_SHARED_SECTION_NAME_TEMPLATE[] = L"CrSharedMem_%lx";


#pragma code_seg(pop)


extern "C" BOOL checkl_stop_option();
extern "C" BOOL checkl_RENDER_opt();
extern "C" void MPFLAT_preloader();
extern "C" void DDRAW_FontCase_Service_SANDBOX_hook();
extern "C" void WLDP_preloader_MSEDGE();
extern "C" UINT Fill_fail_safe_CFMAPPING_Handle();


///////

    EXPORT SC_HANDLE WINAPI hook_OpenServiceW(SC_HANDLE               hSCManager,
        LPCWSTR                lpServiceName,
        DWORD                   dwDesiredAccess)
    {
        return (SC_HANDLE)0x386;
    }


    EXPORT BOOL  WINAPI hook_CloseServiceHandle(SC_HANDLE   hSCObject)
    {
        return TRUE;
    }

    EXPORT SC_HANDLE WINAPI hook_OpenSCManagerW(LPCWSTR                lpMachineName,
        LPCWSTR                lpDatabaseName,
        DWORD                   dwDesiredAccess)
    {
        return (SC_HANDLE)0x386;
    }

    EXPORT BOOL WINAPI hook_StartServiceW(SC_HANDLE            hService,
        DWORD                dwNumServiceArgs,
        LPCWSTR* lpServiceArgVectors)
    {
        return TRUE;
    }

    EXPORT DWORD WINAPI hook_NotifyServiceStatusChangeW(SC_HANDLE               hService,
        DWORD                   dwNotifyMask,
        PSERVICE_NOTIFYW        pNotifyBuffer)
    {
        return 0x1;
    }


    pool_I advapi32_pp[] = {
        {"OpenServiceW", (size_t)hook_OpenServiceW},
        {"CloseServiceHandle",(size_t)hook_CloseServiceHandle },
        {"OpenSCManagerW",(size_t)hook_OpenSCManagerW  },
        {"StartServiceW", (size_t)hook_StartServiceW},
        {"NotifyServiceStatusChangeW", (size_t)hook_NotifyServiceStatusChangeW},
        {0, 0}
    };

constexpr auto MAX_TABLE_SAFE = 15;
HANDLE hsafe_table[MAX_TABLE_SAFE];
SIZE_T hsafe_table_COUNTER = 0;
volatile size_t hfailed_safe_entrypoint = 0;
CRITICAL_SECTION csec_fail_safe;


constexpr auto STATUS_ERROR_PROCESS_NOT_IN_JOB = 0xC00001AE;

typedef struct _PROCESS_JOB_MEMORY_INFO
{
    ULONGLONG SharedCommitUsage;
    ULONGLONG PrivateCommitUsage;
    ULONGLONG PeakPrivateCommitUsage;
    ULONGLONG PrivateCommitLimit;
    ULONGLONG TotalCommitLimit;
} PROCESS_JOB_MEMORY_INFO, * PPROCESS_JOB_MEMORY_INFO;



typedef struct _VM_COUNTERS_EX
{
    SIZE_T PeakVirtualSize;
    SIZE_T VirtualSize;
    ULONG PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
    SIZE_T PrivateUsage;
} VM_COUNTERS_EX, * PVM_COUNTERS_EX;


typedef struct _VM_COUNTERS
{
    SIZE_T PeakVirtualSize;
    SIZE_T VirtualSize;
    ULONG PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
} VM_COUNTERS, * PVM_COUNTERS;

typedef struct _VM_COUNTERS_EX2
{
    VM_COUNTERS_EX CountersEx;
    SIZE_T PrivateWorkingSetSize;
    SIZE_T SharedCommitUsage;
    SIZE_T unknown1;
    SIZE_T unknown2;
} VM_COUNTERS_EX2, * PVM_COUNTERS_EX2;

// ----- ABSENT AP -----
HMODULE pKernel32;
HMODULE pNtdll;
HMODULE pMsvcrt;
HMODULE pWLDP_MSEDGE = NULL;

BOOL render_process = 0;

typedef DWORD(WINAPI api_DiscardVirtualMemory)(
    PVOID VirtualAddress,
    SIZE_T Size
    );

typedef BOOL(WINAPI api_PrefetchVirtualMemory)(
    HANDLE                    hProcess,
    ULONG_PTR                 NumberOfEntries,
    PMEMORY_RANGE_ENTRY       VirtualAddresses,
    ULONG                     Flags
);

typedef BOOL (WINAPI api_SetThreadInformation)(
    HANDLE hThread,
    THREAD_INFORMATION_CLASS ThreadInformationClass,
    LPVOID ThreadInformation,
    DWORD ThreadInformationSize
);

typedef bool(WINAPI chrome_IsSandboxedProcess)(void
    );

#define _FIRMWARE_TYPE is_already_defined
#ifndef _FIRMWARE_TYPE
typedef enum _FIRMWARE_TYPE {
    FirmwareTypeUnknown,
    FirmwareTypeBios,
    FirmwareTypeUefi,
    FirmwareTypeMax
} FIRMWARE_TYPE, * PFIRMWARE_TYPE;
#endif // !_FIRMWARE_TYPE


typedef BOOL(WINAPI api_GetFirmwareType)(PFIRMWARE_TYPE FirmwareType);


typedef BOOL (WINAPI api_GetProcessMitigationPolicy)(HANDLE  hProcess,
    PROCESS_MITIGATION_POLICY MitigationPolicy,
    PVOID                     lpBuffer,
    SIZE_T                    dwLength);

typedef BOOL(WINAPI api_SetProcessMitigationPolicy)(PROCESS_MITIGATION_POLICY MitigationPolicy,
    PVOID                     lpBuffer,
    SIZE_T                    dwLength);

typedef BOOL(WINAPI api_SetProcessInformation)(HANDLE hProcess,
    PROCESS_INFORMATION_CLASS ProcessInformationClass,
    LPVOID ProcessInformation,
    DWORD ProcessInformationSize);

typedef BOOL(WINAPI api_Wow64GetThreadContext)(HANDLE hThread, PWOW64_CONTEXT lpContext);

typedef BOOL(WINAPI api_IsEnclaveTypeSupported)(DWORD flEnclaveType);

typedef LONG(WINAPI api_GetPackageFamilyName)(HANDLE hProcess,
    UINT32* packageFamilyNameLength,
    PWSTR  packageFamilyName);

typedef LONG (WINAPI api_NtQueryInformationToken)(
    HANDLE                  TokenHandle,
    TOKEN_INFORMATION_CLASS TokenInformationClass,
    PVOID                   TokenInformation,
    ULONG                   TokenInformationLength,
    PULONG                  ReturnLength
);

typedef void (WINAPI api_GetSystemTimePreciseAsFileTime)(
   LPFILETIME lpSystemTimeAsFileTime
);

typedef LONG(WINAPI api_GetPackageApplicationIds)(PACKAGE_INFO_REFERENCE packageInfoReference,
    UINT32* bufferLength,
    BYTE* buffer,
    UINT32* count);

typedef LONG(WINAPI api_OpenPackageInfoByFullName)(PCWSTR                 packageFullName,
    const UINT32           reserved,
    PACKAGE_INFO_REFERENCE* packageInfoReference);

typedef LONG(WINAPI api_GetApplicationUserModelId)(HANDLE hProcess,
    UINT32* applicationUserModelIdLength,
    PWSTR  applicationUserModelId);

typedef LONG(WINAPI api_GetCurrentPackageFullName)(UINT32* packageFullNameLength, 
    PWSTR  packageFullName);

typedef BOOL(WINAPI api_GetProcessInformation)(HANDLE                    hProcess,
    PROCESS_INFORMATION_CLASS ProcessInformationClass,
    LPVOID                    ProcessInformation,
    DWORD                     ProcessInformationSize);

typedef BOOL(WINAPI api_GetSystemCpuSetInformation)(
    PSYSTEM_CPU_SET_INFORMATION  Information,
    ULONG                        BufferLength,
    PULONG                       ReturnedLength,
    HANDLE                       Process,
    ULONG                        Flags
);

typedef BOOL(WINAPI api_GetOverlappedResultEx)(HANDLE       hFile,
    LPOVERLAPPED lpOverlapped,
    LPDWORD      lpNumberOfBytesTransferred,
    DWORD        dwMilliseconds,
    BOOL         bAlertable);

typedef int(WINAPI api_swprintf_s)(
wchar_t* buffer, size_t sizeOfBuffer,
const wchar_t* format, 
LONG random1, LONG random2, LONG random3, LONG random4);

api_DiscardVirtualMemory* farproc_DiscardVirtualMemory = 0;
api_PrefetchVirtualMemory* farproc_PrefetchVirtualMemory = 0;
api_SetThreadInformation* farproc_SetThreadInformation = 0;
api_GetProcessMitigationPolicy* farproc_GetProcessMitigationPolicy = 0;
api_SetProcessMitigationPolicy* farproc_SetProcessMitigationPolicy = 0;
api_GetFirmwareType* farproc_GetFirmwareType = 0;
api_NtSetInformationThread* farproc_NtSetInformationThread = 0;
api_NtSetInformationVirtualMemory* farproc_NtSetInformationVirtualMemory = 0;
api_SetProcessInformation* farproc_SetProcessInformation = 0;
api_Wow64GetThreadContext* farproc_Wow64GetThreadContext = 0;
api_IsEnclaveTypeSupported* farproc_IsEnclaveTypeSupported = 0;
api_GetPackageFamilyName* farproc_GetPackageFamilyName = 0;
api_GetSystemTimePreciseAsFileTime* farproc_GetSystemTimePreciseAsFileTime = 0;
api_GetPackageApplicationIds* farproc_GetPackageApplicationIds = 0;
api_OpenPackageInfoByFullName* farproc_OpenPackageInfoByFullName = 0;
api_NtQueryInformationToken* farproc_NtQueryInformationToken = 0;
api_GetApplicationUserModelId* farproc_GetApplicationUserModelId = 0;
api_GetCurrentPackageFullName* farproc_GetCurrentPackageFullName = 0;
api_GetProcessInformation* farproc_GetProcessInformation = 0;
chrome_IsSandboxedProcess* farproc_IsSandboxedProcess = 0;
api_GetSystemCpuSetInformation* farproc_GetSystemCpuSetInformation = 0;
api_GetOverlappedResultEx* farproc_GetOverlappedResultEx = 0;

api_swprintf_s* farproc_wsprintf_s = 0;

BOOL DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{


    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        
        //    checkl_stop_option();
#ifdef DEBUG_OUT
        //for OUTPUT DEBUG STRINGS (if needed)
        isdp = ::IsDebuggerPresent();
         checkl_stop_option();
#endif // DEBUG_OUT

         render_process = checkl_RENDER_opt();
      
        
         if (!pKernel32)
         {
             pKernel32 = ::GetModuleHandle(WIDE_KERNEL32DLL);
             pNtdll = ::GetModuleHandle(WIDE_NTDLLDLL);
             if (pKernel32 && pNtdll)
             {
#ifndef COMPATIBLE10_7_MODE
                 farproc_DiscardVirtualMemory = (api_DiscardVirtualMemory*)::GetProcAddress(pKernel32, A_DVM);
                 farproc_PrefetchVirtualMemory = (api_PrefetchVirtualMemory*)::GetProcAddress(pKernel32, A_PVM);
                 farproc_SetThreadInformation = (api_SetThreadInformation*)::GetProcAddress(pKernel32, A_STI);
                 farproc_GetFirmwareType = (api_GetFirmwareType*)::GetProcAddress(pKernel32, A_GFT);
                 farproc_GetProcessMitigationPolicy = (api_GetProcessMitigationPolicy*)::GetProcAddress(pKernel32, A_GPMP);
                 farproc_SetProcessMitigationPolicy = (api_SetProcessMitigationPolicy*)::GetProcAddress(pKernel32, A_SPMP);
                 farproc_SetProcessInformation = (api_SetProcessInformation*)::GetProcAddress(pKernel32, A_SPI);
                 farproc_GetPackageFamilyName = (api_GetPackageFamilyName*)::GetProcAddress(pKernel32, A_GPFN);
                 farproc_Wow64GetThreadContext = (api_Wow64GetThreadContext*)::GetProcAddress(pKernel32, A_W64GTC);
                 farproc_GetSystemTimePreciseAsFileTime = (api_GetSystemTimePreciseAsFileTime*)::GetProcAddress(pKernel32, A_GSTPAFT);
                 farproc_GetPackageApplicationIds = (api_GetPackageApplicationIds*)::GetProcAddress(pKernel32, A_GPAI);
                 farproc_OpenPackageInfoByFullName = (api_OpenPackageInfoByFullName*)::GetProcAddress(pKernel32, A_OPIBFN);
                 farproc_GetCurrentPackageFullName = (api_GetCurrentPackageFullName*)::GetProcAddress(pKernel32, A_GCPFN);
                 farproc_GetProcessInformation = (api_GetProcessInformation*)::GetProcAddress(pKernel32, A_GPI);
                 farproc_GetSystemCpuSetInformation = (api_GetSystemCpuSetInformation*)::GetProcAddress(pKernel32, A_GSCSI);
                 farproc_GetOverlappedResultEx = (api_GetOverlappedResultEx*)::GetProcAddress(pKernel32, A_GORE);

                 farproc_NtSetInformationVirtualMemory = (api_NtSetInformationVirtualMemory*)::GetProcAddress(pNtdll, A_NTSIVM);
                 farproc_IsEnclaveTypeSupported = (api_IsEnclaveTypeSupported*)::GetProcAddress(pNtdll, A_IETS);
                 farproc_NtQueryInformationToken = (api_NtQueryInformationToken*)::GetProcAddress(pNtdll, A_NTQIT);
                 farproc_GetApplicationUserModelId = (api_GetApplicationUserModelId*)::GetProcAddress(pNtdll, A_GAUMI);
                 //farproc_NtQuerySystemInformationEx = (api_NtQuerySystemInformationEx*)::GetProcAddress(pNtdll, A_NTQSIEX);
#endif
                 farproc_NtSetInformationThread = (api_NtSetInformationThread*)::GetProcAddress(pNtdll, A_NTSIT);


                 //GPU SANDBOX preload (without \System32\ && \SysWOW64\)
                 MPFLAT_preloader();
                 //DirectX DRAW SANDBOX (Windows 7)
                 DDRAW_FontCase_Service_SANDBOX_hook();
                 //for PRINTER_PREVIEW HANDLE - SANDBOX
                 hsafe_table_COUNTER = Fill_fail_safe_CFMAPPING_Handle();
                 //#ifdef EDGE
                             //WLDP
                 WLDP_preloader_MSEDGE();
                 //#endif // EDGE
             }//end if (!pKernel32)
         }//end pKernel32 && pNtdll

#ifdef FIREFOX
        ::CoInitialize(NULL);
#endif //FIREFOX

        break; }
    case DLL_THREAD_ATTACH: {break;}
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH: {
        break;}
    }//end switch (ul_reason_for_call)
    return TRUE;
}
//NON-DEFAULT

//gpu || render
//#define GPU_STOP 1
BOOL checkl_RENDER_opt()
{
    //gpu process || renderer
    LPWSTR cmdline = ::GetCommandLine();
    size_t i = wcslen(cmdline);

    //type=renderer
    while (i--)
    {
   
        
#if GPU_STOP
        //gpu
        if (*cmdline++ != L'g')
            continue;

        if (cmdline[0] == L'p' && cmdline[1] == L'u')
#else
        if (*cmdline++ != L'r')
            continue;
        
        if (cmdline[0] == L'e' && cmdline[1] == L'n' && cmdline[2] == L'd' && cmdline[3] == L'e' && cmdline[4] == L'r')
#endif // GPU_STOP

   //     if (cmdline[0] == L't' && cmdline[1] == L'o' && cmdline[2] == L'r' && cmdline[3] == L'a' && cmdline[4] == L'g')
            {
          //  ::MessageBox(NULL, cmdline, NULL, MB_OK);
            return TRUE;
        }
    }//end while (i--)
    return FALSE;
}


BOOL checkl_stop_option()
{
    //gpu process || renderer
    LPWSTR cmdline = ::GetCommandLine();
    size_t i = wcslen(cmdline);

    //type=renderer
    while (i--)
    {
        //papi
        if (*cmdline++ != L'r')
            continue;

        if (cmdline[0] == L'e' && cmdline[1] == L'n' && cmdline[2] == L'd' && cmdline[3] == L'e')

        {
            /*
            while (1)
            {
                ::MessageBox(NULL, cmdline, NULL, MB_OK);
                ::SwitchToThread();   
            }
              */
            ::Sleep(10000);
            return TRUE;
        }
    }//end while (i--)
    return FALSE;
}

extern "C"
{


    /*
      std::u16string name;
  if (win::GetVersion() < win::Version::WIN8_1) {
    // Windows < 8.1 ignores DACLs on certain unnamed objects (like shared
    // sections). So, we generate a random name when we need to enforce
    // read-only.
	/*
	Windows < 8.1 игнорирует DACL для некоторых неименованных объектов (like shared sections). 
	Поэтому мы генерируем случайное имя, когда нам нужно обеспечить только для чтения.
	
    uint64_t rand_values[4];
    RandBytes(&rand_values, sizeof(rand_values));
    name = ASCIIToUTF16(StringPrintf("CrSharedMem_%016llx%016llx%016llx%016llx",
        rand_values[0], rand_values[1],
        rand_values[2], rand_values[3]));
    DCHECK(!name.empty());
}
    */
    EXPORT HANDLE WINAPI _CreateFileMappingW(HANDLE hFile,
        LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
        DWORD flProtect,
        DWORD dwMaximumSizeHigh,
        DWORD dwMaximumSizeLow,
        LPCWSTR lpName) {

        //DACL shared section fix
        WCHAR name_buffer[MAX_PATH];
        if ((!lpName) && (hFile == INVALID_HANDLE_VALUE) && (lpFileMappingAttributes) && (flProtect == PAGE_READWRITE))
        {
            if (!render_process)
            {
                // farproc_wsprintf_s(name_buffer, sizeof(name_buffer), WIDE_CH_SHARED_SECTION_NAME_TEMPLATE, randr(), randr(), randr(), randr());
                lpName = name_buffer;
                wsprintf(name_buffer, WIDE_CH_SHARED_SECTION_NAME_TEMPLATE, randr());
                HANDLE reta = ::CreateFileMappingW(hFile,
                    lpFileMappingAttributes,
                    flProtect,
                    dwMaximumSizeHigh,
                    dwMaximumSizeLow,
                    lpName);

                //need use FAIL SAFE table?
                if (!reta)
                {

                    //FAIL SAFE table is FILL?!
                    if (hsafe_table_COUNTER)
                    {
                        ::EnterCriticalSection(&csec_fail_safe);
                        if (hfailed_safe_entrypoint < MAX_TABLE_SAFE)
                        {
                            if (hsafe_table[hfailed_safe_entrypoint])
                            {
                                reta = hsafe_table[hfailed_safe_entrypoint];
                                hsafe_table[hfailed_safe_entrypoint] = 0;
                                hfailed_safe_entrypoint++;
                                return reta;
                            }//end if (hsafe_table[hfailed_safe_entrypoint])
                        }//end  if (hfailed_safe_entrypoint < MAX_TABLE_SAFE)
                        ::LeaveCriticalSection(&csec_fail_safe);
                    }//end if (hsafe_table_COUNTER)
                }//end if (FAILED(reta))

                lpName = NULL;
            }//end   if (!render_process)
        }//end if (!lpName)
        return ::CreateFileMappingW(hFile,
            lpFileMappingAttributes,
            flProtect,
            dwMaximumSizeHigh,
            dwMaximumSizeLow,
            lpName);
    }


    //DiscardVirtualMemory function (memoryapi.h)
    /*
    Requirements

    Minimum supported client 	Windows 8.1 Update [desktop apps | UWP apps]
    Minimum supported server 	Windows Server 2012 R2 Update [desktop apps | UWP apps]
    Target Platform 	Windows
    Header 	memoryapi.h (include Windows.h, Memoryapi.h)
    Library 	onecore.lib
    DLL 	Kernel32.dll
    */
    EXPORT DWORD WINAPI _DiscardVirtualMemory(PVOID VirtualAddress,
        SIZE_T Size)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - DiscardVirtualMemory(%p, %i)", ::GetCurrentThreadId(), VirtualAddress, Size);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_DiscardVirtualMemory)
        {
            //Windows 7

            ::VirtualAlloc(VirtualAddress, Size, MEM_RESET, PAGE_READWRITE);
            return ERROR_SUCCESS;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_DiscardVirtualMemory(VirtualAddress, Size);
    }

    /*
    Minimum supported client 	Windows 8 [desktop apps only]
    Minimum supported server 	Windows Server 2012 [desktop apps only]
    Target Platform 	Windows
    Header 	memoryapi.h (include Windows.h, Memoryapi.h)
    Library 	onecore.lib
    DLL 	Kernel32.dll
    */
    EXPORT BOOL WINAPI _PrefetchVirtualMemory(HANDLE  hProcess,
        ULONG_PTR                 NumberOfEntries,
        PMEMORY_RANGE_ENTRY       VirtualAddresses,
        ULONG                     Flags)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - PrefetchVirtualMemory(%x, %i)", ::GetCurrentThreadId(), hProcess, NumberOfEntries);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_PrefetchVirtualMemory)
        {
            //NATIVE PRIMARY IS AVIABLE?
            if (farproc_NtSetInformationVirtualMemory)
            {
                NTSTATUS rets = farproc_NtSetInformationVirtualMemory(hProcess, VmPrefetchInformation, NumberOfEntries, VirtualAddresses, &Flags, sizeof(DWORD));
                if (FAILED(rets))
                {
                    return FALSE;
                }//end if (FAILED(rets))
                return TRUE;
            }//end if (farproc_NtSetInformationVirtualMemory)

            //Windows 7
            while (!NumberOfEntries)
            {
                ::VirtualAllocEx(hProcess, VirtualAddresses->VirtualAddress, VirtualAddresses->NumberOfBytes, MEM_RESERVE | MEM_COMMIT | MEM_LARGE_PAGES, PAGE_READWRITE); //MEM_PHYSICAL
                VirtualAddresses++;
                NumberOfEntries--;
            }//end while (!NumberOfEntries)
            return TRUE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_PrefetchVirtualMemory(hProcess, NumberOfEntries, VirtualAddresses, Flags);
    }

    //SetThreadInformation function (processthreadsapi.h)
    /*
    Minimum supported client 	Windows 8 [desktop apps only]
    Minimum supported server 	Windows Server 2012 [desktop apps only]
    Target Platform 	Windows
    Header 	processthreadsapi.h (include Windows.h)
    Library 	Kernel32.lib
    DLL 	Kernel32.dll
    */
    EXPORT BOOL WINAPI _SetThreadInformation(HANDLE hThread,
        THREAD_INFORMATION_CLASS ThreadInformationClass,
        THREAD_POWER_THROTTLING_STATE* pThreadInformation,
        DWORD ThreadInformationSize)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - SetThreadInformation(%x, %i, %i)", ::GetCurrentThreadId(), hThread, ThreadInformationClass, ThreadInformationSize);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_SetThreadInformation)
        {
            //Windows 7

            switch (ThreadInformationClass)
            {
            case ThreadMemoryPriority:
            {
                return farproc_NtSetInformationThread(hThread, (THREADINFOCLASS)ProcessSessionInformation, pThreadInformation, ThreadInformationSize);
            }//end case ThreadMemoryPriority
            case ThreadAbsoluteCpuPriority:
            {
                return farproc_NtSetInformationThread(hThread, (THREADINFOCLASS)ProcessForegroundInformation, pThreadInformation, ThreadInformationSize);
            }//end  case ThreadAbsoluteCpuPriority:
            case ThreadDynamicCodePolicy:
            {
                return farproc_NtSetInformationThread(hThread, (THREADINFOCLASS)ProcessWorkingSetWatchEx, pThreadInformation, ThreadInformationSize);
            }//end  case ThreadDynamicCodePolicy:

            case ThreadInformationClassMax:
            {
                DWORD cmask = pThreadInformation->ControlMask & 0xFFFFFFFE;
                if ((ThreadInformationClass != ThreadPowerThrottling) ||
                    (ThreadInformationSize < (sizeof(THREADINFOCLASS) + 4)) ||
                    (cmask != 0) ||
                    ((~cmask & pThreadInformation->StateMask) != 0) ||
                    (pThreadInformation->Version > 1)
                    )
                {
                    ::SetLastError(STATUS_INVALID_PARAMETER);
                    return  STATUS_INVALID_PARAMETER;
                }//end  if (ThreadInformationClass != ThreadPowerThrottling)


                THREAD_POWER_THROTTLING_STATE thread_info = { 1, pThreadInformation->ControlMask, pThreadInformation->StateMask };

                return farproc_NtSetInformationThread(hThread, (THREADINFOCLASS)(0x31 | 0x20), &thread_info, ThreadInformationSize);

            }//end  case ThreadDynamicCodePolicy:

            default:
                break;
            }//end switch (ThreadInformationClass)
            return ERROR_SUCCESS;
        }//end if (!farproc_DiscardVirtualMemory)

        return farproc_SetThreadInformation(hThread,
            ThreadInformationClass,
            pThreadInformation,
            ThreadInformationSize);
    }


    //GetFirmwareType
    /*
    Minimum supported client 	Windows 8 [desktop apps only]
    Minimum supported server 	Windows Server 2012 [desktop apps only]
    Target Platform 	Windows
    Header 	winbase.h (include Windows.h)
    Library 	Kernel32.lib
    DLL 	Kernel32.dll
    */
    EXPORT UINT WINAPI _GetFirmwareType(PFIRMWARE_TYPE FirmwareType) {

#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - GetFirmwareType(%p)", ::GetCurrentThreadId(), FirmwareType);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_GetFirmwareType)
        {
            //Windows XP/2k3/7
            ::SetLastError(ERROR_SUCCESS);
            GetFirmwareEnvironmentVariableW(NULL, WIDE_NULL_GUID_PTR, NULL, NULL);
            if (::GetLastError() == ERROR_INVALID_FUNCTION)
                return FirmwareTypeBios;
            else
                return FirmwareTypeUefi;

            return FirmwareTypeUnknown;
        } //end if (!farproc_GetFirmwareType)

        return  farproc_GetFirmwareType(FirmwareType);
    }

    //mitiga stack roll
    volatile HANDLE remote_process = 0;
    
    BYTE r_mitiga[] = { 0x01, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x3D, 0x00, 0x00, 0x80 };
    const BYTE mitiga[] = { 0x03, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33 };
    /*
    BYTE r_mitiga[] = { 0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x00, 0x00, 0x00, 0x00, 0x0, 0x00, 0x00, 0x00 };
    const BYTE mitiga[] = { 0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
    */
    //GetProcessMitigationPolicy
    /*
    Minimum supported client 	Windows 8 [desktop apps | UWP apps]
    Minimum supported server 	Windows Server 2012 [desktop apps | UWP apps]
    Target Platform 	Windows
    Header 	processthreadsapi.h
    Library 	Kernel32.lib
    DLL 	Kernel32.dll
    */
    EXPORT BOOL WINAPI _GetProcessMitigationPolicy(HANDLE   hProcess,
        PROCESS_MITIGATION_POLICY MitigationPolicy,
        PVOID                     lpBuffer,
        SIZE_T                    dwLength) {

#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - GetProcessMitigationPolicy(%x, %i, %p, %i)", ::GetCurrentThreadId(), hProcess, MitigationPolicy, lpBuffer, dwLength);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_GetProcessMitigationPolicy)
        {
            //Windows XP/2k3/7
            //emulate :/
            if (!lpBuffer || !dwLength || dwLength > sizeof(mitiga))
            {
                ::SetLastError(STATUS_INVALID_PARAMETER);
                return FALSE;
            }//end if (!lpBuffer || !dwLength || dwLength > sizeof(mitiga))

            if (hProcess == (HANDLE)-1 || !remote_process)
                memcpy_s1(lpBuffer, dwLength, mitiga, sizeof(mitiga));
            else
                memcpy_s1(lpBuffer, dwLength, r_mitiga, sizeof(r_mitiga));

            return TRUE;
        } //end true branch  if (!farproc_GetProcessMitigationPolicy)
        else
            return farproc_GetProcessMitigationPolicy(hProcess, MitigationPolicy, lpBuffer, dwLength);
    }
    
    //SetProcessMitigationPolicy
    /*
    Minimum supported client 	Windows 8 [desktop apps only]
    Minimum supported server 	Windows Server 2012 [desktop apps only]
    Target Platform 	Windows
    Header 	processthreadsapi.h
    Library 	Kernel32.lib
    DLL 	Kernel32.dll
    */
    EXPORT BOOL WINAPI _SetProcessMitigationPolicy(PROCESS_MITIGATION_POLICY MitigationPolicy,
        PVOID                     lpBuffer,
        SIZE_T                    dwLength) {

#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - SetProcessMitigationPolicy(%i, %p, %i)", ::GetCurrentThreadId(), MitigationPolicy, lpBuffer, dwLength);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_SetProcessMitigationPolicy)
        {
            //Windows XP/2k3/7
            //emulate :/
            if (!lpBuffer || !dwLength || dwLength > sizeof(mitiga))
            {
                ::SetLastError(STATUS_INVALID_PARAMETER);
                return FALSE;
            }//end if (!lpBuffer || !dwLength || dwLength > sizeof(mitiga))

            memcpy_s1(r_mitiga, dwLength, lpBuffer, sizeof(r_mitiga));

            /*
          if (flags & MITIGATION_HEAP_TERMINATE) {
            if (!::HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption,
                nullptr, 0)) {
                return false;
            }
            */

#ifdef _WIN32
            /*
    Minimum supported client 	Windows Vista with SP1, Windows XP with SP3 [desktop apps only]
    Minimum supported server 	Windows Server 2008 [desktop apps only]
    Target Platform 	Windows
    Header 	winbase.h (include Windows.h)
    Library 	Kernel32.lib
    DLL 	Kernel32.dll
                */
#if (_WIN32_WINNT >= 0x0600)
            ::SetProcessDEPPolicy(PROCESS_DEP_ENABLE);
#endif
#endif // _WIN32

            return TRUE;
        } //end true branch  if (!farproc_GetProcessMitigationPolicy)
        else
            return farproc_SetProcessMitigationPolicy(MitigationPolicy, lpBuffer, dwLength);
    }

    //SetProcessInformation
    /*
    Минимальная версия клиента 	Windows 8 [классические приложения | Приложения UWP]
    Минимальная версия сервера 	Windows Server 2012 [классические приложения | Приложения UWP]
    Целевая платформа 	Windows
    Header 	processthreadsapi.h (включая Windows.h)
    Библиотека 	Kernel32.lib
    DLL 	Kernel32.dll
    */
    EXPORT BOOL WINAPI _SetProcessInformation(HANDLE hProcess,
        PROCESS_INFORMATION_CLASS ProcessInformationClass,
        LPVOID ProcessInformation,
        DWORD ProcessInformationSize) {

        if (!farproc_SetProcessInformation)
        {
            //Windows 7

        }
        else
            return farproc_SetProcessInformation(hProcess, ProcessInformationClass, ProcessInformation, ProcessInformationSize);

        return 0;
    }

    EXPORT BOOL WINAPI _Wow64GetThreadContext(HANDLE hThread, PWOW64_CONTEXT lpContext) {
        if (!farproc_Wow64GetThreadContext)
        {
            if (!lpContext)
                return FALSE;

            //Windows 7
            CONTEXT pctx;
            BOOL gth = ::GetThreadContext(hThread, &pctx);
            if (gth)
            {
                //ctx flag
                lpContext->ContextFlags = pctx.ContextFlags;

                //hw bp
                lpContext->Dr0 = static_cast<DWORD>(pctx.Dr0);
                lpContext->Dr1 = static_cast<DWORD>(pctx.Dr1);
                lpContext->Dr2 = static_cast<DWORD>(pctx.Dr2);
                lpContext->Dr3 = static_cast<DWORD>(pctx.Dr3);
                lpContext->Dr6 = static_cast<DWORD>(pctx.Dr6);
                lpContext->Dr7 = static_cast<DWORD>(pctx.Dr7);

                //commmon cpu
#ifdef _AMD64_

                lpContext->Eax = static_cast<DWORD>(pctx.Rax);
                lpContext->Ecx = static_cast<DWORD>(pctx.Rcx);
                lpContext->Edx = static_cast<DWORD>(pctx.Rdx);
                lpContext->Ebx = static_cast<DWORD>(pctx.Rbx);
                lpContext->Edi = static_cast<DWORD>(pctx.Rsi);
                lpContext->Esi = static_cast<DWORD>(pctx.Rdi);
                lpContext->Esp = static_cast<DWORD>(pctx.Rsp);
                lpContext->Ebp = static_cast<DWORD>(pctx.Rbp);
                lpContext->Eip = static_cast<DWORD>(pctx.Rip);
#else
                lpContext->Eax = pctx->Eax;
                lpContext->Ecx = pctx->Ecx;
                lpContext->Edx = pctx->Edx;
                lpContext->Ebx = pctx->Ebx;
                lpContext->Edi = pctx->Edi;
                lpContext->Esi = pctx->Esi;
                lpContext->Esp = pctx->Esp;
                lpContext->Ebp = pctx->Ebp;
                lpContext->Eip = pctx->Eip;
#endif // _AMD64_

                //EFL
                lpContext->EFlags = pctx.EFlags;

                //seg regs
                lpContext->SegCs = pctx.SegCs;
                lpContext->SegGs = pctx.SegGs;
                lpContext->SegFs = pctx.SegFs;
                lpContext->SegEs = pctx.SegEs;
                lpContext->SegDs = pctx.SegDs;
#ifdef _AMD64_
                //FPU 80387 /XMM )
                lpContext->FloatSave.ControlWord = pctx.FltSave.ControlWord;
                lpContext->FloatSave.DataOffset = pctx.FltSave.DataOffset;
                lpContext->FloatSave.DataSelector = pctx.FltSave.DataSelector;
                lpContext->FloatSave.ErrorOffset = pctx.FltSave.ErrorOffset;
                lpContext->FloatSave.ErrorSelector = pctx.FltSave.ErrorSelector;
                lpContext->FloatSave.StatusWord = pctx.FltSave.StatusWord;
                lpContext->FloatSave.TagWord = pctx.FltSave.TagWord;
                memcpy(lpContext->FloatSave.RegisterArea, pctx.FltSave.FloatRegisters, WOW64_SIZE_OF_80387_REGISTERS); //???
#else
                lpContext->FloatSave.ControlWord = pctx->FloatSave.ControlWord;
                lpContext->FloatSave.DataOffset = pctx->FloatSave.DataOffset;
                lpContext->FloatSave.DataSelector = pctx->FloatSave.DataSelector;
                lpContext->FloatSave.ErrorOffset = pctx->FloatSave.ErrorOffset;
                lpContext->FloatSave.ErrorSelector = pctx->FloatSave.ErrorSelector;
                lpContext->FloatSave.StatusWord = pctx->FloatSave.StatusWord;
                lpContext->FloatSave.TagWord = pctx->FloatSave.TagWord;
#endif // _AMD64_

                //null extended
                ::ZeroMemory(lpContext->ExtendedRegisters, sizeof(lpContext->ExtendedRegisters));
            }//end TRUE if(gth)
            else
            {

            }//end if(gth)
        }
        else
            return farproc_Wow64GetThreadContext(hThread, lpContext);
        return FALSE;
    }

    EXPORT BOOL WINAPI _IsEnclaveTypeSupported(DWORD flEnclaveType) {
        if (!farproc_IsEnclaveTypeSupported)
        {
            ::SetLastError(ERROR_NOT_SUPPORTED);
            return FALSE;
        }
        else
            return farproc_IsEnclaveTypeSupported(flEnclaveType);
    }


    //fix  cmp eax, 0x3FFFFBD8 //STATUS_INVALID_IMAGE_HASH
    /*
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF
    PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY

    //chromium/sandbox/win/src/process_mitigations.cc
void ConvertProcessMitigationsToPolicy(MitigationFlags flags,
                                       DWORD64* policy_flags,
                                       size_t* size) {
                                             // Mitigations >= Win10 TH2:
  //----------------------------------------------------------------------------
  if (version >= base::win::Version::WIN10_TH2) {
    if (flags & MITIGATION_FORCE_MS_SIGNED_BINS) {
      *policy_value_1 |=
          PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON;
    }

    */
    EXPORT BOOL WINAPI _UpdateProcThreadAttribute(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
        DWORD dwFlags,
        DWORD_PTR Attribute,
        PVOID lpValue,
        SIZE_T cbSize,
        PVOID lpPreviousValue,
        PSIZE_T lpReturnSize) {

#ifndef MY_KERNEL64DLL_WHQL_or_MICROSOFT_SIGNED

        if (Attribute == PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY)
        {
            if (lpValue)
            {
                //UNLOCK Win
              //  DWORD64* lpValue64 = reinterpret_cast<DWORD64*>(lpValue);
                //   *lpValue64 |= PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF;
            }//end if (lpValue)
        }//end   if (Attribute == PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY)
#endif // MY_DLL_WHQL_or_MICROSOFT_SIGNED

         ::UpdateProcThreadAttribute(lpAttributeList,
            dwFlags,
            Attribute,
            lpValue,
            cbSize,
            lpPreviousValue,
            lpReturnSize);
         return TRUE;
    }

constexpr auto STATUS_BUFFER_TOO_SMALL = 0xC0000023;
    EXPORT LONG WINAPI _GetPackageFamilyName(HANDLE hProcess,
        UINT32* packageFamilyNameLength,
        PWSTR  packageFamilyName) {
        if (!farproc_GetPackageFamilyName)
        {
            //Windows 7
            if (!hProcess || !packageFamilyNameLength || (*packageFamilyNameLength && !packageFamilyName))
                return ERROR_INVALID_PARAMETER;
            return APPMODEL_ERROR_NO_APPLICATION;
          
        }
        else
            return ::farproc_GetPackageFamilyName(hProcess, packageFamilyNameLength, packageFamilyName);

        return ERROR_SUCCESS;
    }


    /*
    DWORD ARI_ProcessToken_SysAppId_OpenProcess(HANDLE hProcess)
    {
        //  v4 = ARI::ProcessToken::AutoSysAppId::OpenProcessIfPackaged((PVOID *)&v10, hProcess);
        void* TokenHandle;
        if (hProcess == ::GetCurrentProcess())
        {
            TokenHandle = (void*)-4;
        }
        else if (::OpenProcessToken(hProcess, TOKEN_QUERY, &TokenHandle))
        {
            if (farproc_NtQueryInformationToken)
            {
                //LastError = ARI::ProcessToken::SysAppId::Open(a2, TokenHandle, this, a3);
                ULONG ReturnLength;
                LONG nt_ret = farproc_NtQueryInformationToken(hProcess, TokenSecurityAttributes, 0, 0, &ReturnLength);

                if (nt_ret != STATUS_BUFFER_TOO_SMALL)
                    return nt_ret;

                LPVOID Heap = ::HeapAlloc(::GetProcessHeap(), 0, ReturnLength);
                if (Heap)
                {
                    memset(Heap, 0, ReturnLength);

                    nt_ret = farproc_NtQueryInformationToken(hProcess, TokenSecurityAttributes, Heap, ReturnLength, &ReturnLength);

                    if (nt_ret)
                    {

                    }//end if (nt_ret) #2
                    ::HeapFree(::GetProcessHeap(), 0, Heap);
                }//end if (Heap)
            }//end if (!farproc_NtQueryInformationToken)
        }//end if (hProcess == ::GetCurrentProcess())
    }
    */

    //  e d g e //

    /*
Минимальная версия клиента 	Windows 8.1 [только классические приложения]
Минимальная версия сервера 	Windows Server 2012 R2 [только классические приложения]
Целевая платформа 	Windows
Header 	appmodel.h
Библиотека 	Kernel32.lib
DLL 	Kernel32.dll
    */
    EXPORT LONG WINAPI _FindPackagesByPackageFamily(
        PCWSTR packageFamilyName,
        UINT32 packageFilters,
        UINT32* count,
        PWSTR* packageFullNames,
        UINT32* bufferLength,
        WCHAR* buffer,
        UINT32* packageProperties
    ) {

        return APPMODEL_ERROR_NO_PACKAGE;
    }


   EXPORT LONG WINAPI _GetApplicationUserModelId(HANDLE hProcess,
        UINT32* applicationUserModelIdLength,
        PWSTR  applicationUserModelId
    ) {
        if (!farproc_GetApplicationUserModelId)
        {
            //Windows 7
            return APPMODEL_ERROR_NO_APPLICATION;
        }
        else
            return ::farproc_GetApplicationUserModelId(hProcess, applicationUserModelIdLength, applicationUserModelId);
    }

   EXPORT LONG WINAPI _GetCurrentApplicationUserModelId(UINT32* applicationUserModelIdLength,
       PWSTR  applicationUserModelId
   ) {
       LONG result = APPMODEL_ERROR_NO_APPLICATION;
       HANDLE process = ::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, GetCurrentProcessId());
       if (process)
       {
           result = _GetApplicationUserModelId(process, applicationUserModelIdLength, applicationUserModelId);
           CloseHandle(process);
       }//end if (process)
       return result;
   }
   

    //edge 122
    EXPORT LONG WINAPI _GetPackagesByPackageFamily(
        PCWSTR packageFamilyName,
        UINT32* count,
        PWSTR* packageFullNames,
        UINT32* bufferLength,
        WCHAR* buffer
    )
    {
        return APPMODEL_ERROR_NO_PACKAGE;
    }

    EXPORT LONG WINAPI _GetPackagePathByFullName(
        PCWSTR packageFullName,
        UINT32* pathLength,
        PWSTR  path
    )
    {
        return APPMODEL_ERROR_NO_PACKAGE;
    }


    EXPORT LONG WINAPI _GetCurrentPackageFullName(UINT32* packageFullNameLength,
        PWSTR  packageFullName
    )
    {
        if (!farproc_GetCurrentPackageFullName)
        {
            //Windows 7
            return APPMODEL_ERROR_NO_PACKAGE;
        }
        else
            return ::farproc_GetCurrentPackageFullName(packageFullNameLength, packageFullName);
    }

    EXPORT HRESULT WINAPI _SetThreadDescription(
        HANDLE hThread,
        PCWSTR lpThreadDescription
    ) {
        if (!hThread)
        {
            ::SetLastError(E_INVALIDARG);
            return E_INVALIDARG;
        }//end if (!hThread)

        if(!farproc_NtSetInformationThread)
            return  ERROR_SUCCESS;

        UNICODE_STRING WideThreadDescription = {0,0,0};
        ::RtlInitUnicodeString(&WideThreadDescription, lpThreadDescription);
        
        farproc_NtSetInformationThread(hThread, (THREADINFOCLASS)ThreadNameInformation, &WideThreadDescription, sizeof(UNICODE_STRING));

        return ERROR_SUCCESS;
    }

    EXPORT void WINAPI _GetSystemTimePreciseAsFileTime(LPFILETIME lpSystemTimeAsFileTime)
    {
        if (!farproc_GetSystemTimePreciseAsFileTime)
        {
            //Windows 7
            if (!lpSystemTimeAsFileTime)
            {
                ::SetLastError(E_INVALIDARG);
                return;
            }//end if if (!lpSystemTimeAsFileTime)
            return ::GetSystemTimeAsFileTime(lpSystemTimeAsFileTime);
        }
        else
            return ::farproc_GetSystemTimePreciseAsFileTime(lpSystemTimeAsFileTime);
    }

    EXPORT LONG WINAPI _GetPackageApplicationIds(PACKAGE_INFO_REFERENCE packageInfoReference,
        UINT32* bufferLength,
        BYTE* buffer,
        UINT32* count) {
        if (!farproc_GetPackageApplicationIds)
        {
            //Windows 7
            return ERROR_NOT_FOUND;
        }
        else
            return ::farproc_GetPackageApplicationIds(packageInfoReference, bufferLength, buffer, count);
    }

    EXPORT LONG WINAPI _OpenPackageInfoByFullName(
        PCWSTR                 packageFullName,
        const UINT32           reserved,
        PACKAGE_INFO_REFERENCE* packageInfoReference
    ) {
        if (!farproc_OpenPackageInfoByFullName)
        {
            //Windows 7
            return ERROR_NOT_FOUND;
        }
        else
            return ::farproc_OpenPackageInfoByFullName(packageFullName, reserved, packageInfoReference);
    }


    NTSTATUS QueryAppMemoryInformation(HANDLE ProcessHandle, APP_MEMORY_INFORMATION* pMemPI)
    {
        APP_MEMORY_INFORMATION local_pmi;
        VM_COUNTERS_EX2 mem_counters;
        PROCESS_JOB_MEMORY_INFO jmi;
        UINT64 ava_commits = 0;

        NTSTATUS retq = NtQueryInformationProcess(ProcessHandle, PROCESSINFOCLASS(ProcessJobMemoryInformation), &jmi, sizeof(_PROCESS_JOB_MEMORY_INFO), 0);
        if (FAILED(retq) && retq != STATUS_ERROR_PROCESS_NOT_IN_JOB)
            return retq;
        ::ZeroMemory(&local_pmi,sizeof(APP_MEMORY_INFORMATION));
        if (retq == STATUS_ERROR_PROCESS_NOT_IN_JOB)
        {
            retq = NtQueryInformationProcess(ProcessHandle, PROCESSINFOCLASS(ProcessVmCounters), &mem_counters, sizeof(VM_COUNTERS_EX2), 0);
            if (FAILED(retq))
                return retq;
            local_pmi.PrivateCommitUsage = mem_counters.CountersEx.PeakPagefileUsage;
            local_pmi.PeakPrivateCommitUsage = mem_counters.unknown1;
            local_pmi.TotalCommitUsage = mem_counters.unknown2 + mem_counters.CountersEx.PeakPagefileUsage;
        }
        size_t commit_usage = jmi.PrivateCommitUsage + jmi.SharedCommitUsage;
        local_pmi.PeakPrivateCommitUsage = jmi.PeakPrivateCommitUsage;
        local_pmi.PrivateCommitUsage = jmi.PrivateCommitUsage;
        local_pmi.TotalCommitUsage = commit_usage;
        if (jmi.TotalCommitLimit)
        {
            ava_commits = (jmi.TotalCommitLimit - commit_usage) >> 32;
            local_pmi.AvailableCommit = jmi.TotalCommitLimit - commit_usage;
        }
        if (jmi.PrivateCommitLimit)
        {
            ava_commits = (jmi.PrivateCommitLimit - jmi.PrivateCommitUsage) >> 32;
            local_pmi.AvailableCommit = jmi.PrivateCommitLimit - jmi.PrivateCommitUsage;
        }
        /*
        retq = NtQuerySystemInformation(
            0x7b,
            SystemInformation,
            0x10u,
            0);
        if (SUCCEEDED(retq))
        {
            v5 = (v18 - (unsigned _int64)v17) * Size;
            LODWORD(v9[0]) = (v18 - v17) * Size;
        LABEL_8:
            HIDWORD(v9[0]) = HIDWORD(v5);
            InformationProcess = 0;
            qmemcpy(v10, v9, 0x20u);
        }
        */
        memcpy(pMemPI, &local_pmi, sizeof(APP_MEMORY_INFORMATION));
        return retq;
    }

    EXPORT BOOL WINAPI _GetProcessInformation(
        HANDLE                    hProcess,
        PROCESS_INFORMATION_CLASS ProcessInformationClass,
        LPVOID                    ProcessInformation,
        DWORD                     ProcessInformationSize
    ) {
        if (!farproc_GetProcessInformation)
        {
            //Windows 7
            NTSTATUS ret = -1; // esi
            BYTE v8; // [esp+17h] [ebp-1h] BYREF

            switch (ProcessInformationClass)
            {
            case ProcessMemoryPriority:
                ret = NtQueryInformationProcess(
                    hProcess,
                    (PROCESSINFOCLASS)ProcessPagePriority,
                    ProcessInformation,
                    ProcessInformationSize,
                    0);
            case ProcessAppMemoryInfo:
                if (ProcessInformationSize != sizeof(APP_MEMORY_INFORMATION))
                {
                    ::SetLastError(ERROR_BAD_ARGUMENTS);
                    return FALSE;
                }
                ret = QueryAppMemoryInformation(hProcess, (APP_MEMORY_INFORMATION*)ProcessInformation);
            case ProcessInPrivateInfo:
                if (ProcessInformationSize != sizeof(BYTE))
                {
                    ::SetLastError(ERROR_BAD_ARGUMENTS);
                    return FALSE;
                }
                ret = NtQueryInformationProcess(hProcess, (PROCESSINFOCLASS)(ProcessRaisePriority | 0x40), ProcessInformation, sizeof(BYTE), 0);
            case ProcessProtectionLevelInfo:
                if (!ProcessInformation)
                {
                    ::SetLastError(ERROR_BAD_ARGUMENTS);
                    return FALSE;
                }
                if (ProcessInformationSize != sizeof(PROCESS_PROTECTION_LEVEL_INFORMATION))
                {
                    ::SetLastError(ERROR_BAD_ARGUMENTS);
                    return FALSE;
                }
                ret = NtQueryInformationProcess(hProcess, (PROCESSINFOCLASS)(ProcessAffinityUpdateMode | ProcessUserModeIOPL), &v8, sizeof(BYTE), 0);
                if (FAILED(ret))
                {
                    ::SetLastError(ERROR_NOT_SUPPORTED);
                    return FALSE;
                }
                if (v8 > 0x51u)
                {
                    switch (v8)
                    {
                    case 0x52u:
                        *(DWORD*)ProcessInformation = 1;
                    case 0x61u:
                        *(DWORD*)ProcessInformation = 0;
                    case 0x62u:
                    case 0x72u:
                        *(DWORD*)ProcessInformation = 5;
                    case 0x81u:
                        *(DWORD*)ProcessInformation = 8;
                    }
                }
                else
                {
                    switch (v8)
                    {
                    case 0x51u:
                        *(DWORD*)ProcessInformation = 2;
                    case 0u:
                        *(DWORD*)ProcessInformation = -2;
                    case 8u:
                    case 0x12u:
                        *(DWORD*)ProcessInformation = 7;
                    case 0x21u:
                        *(DWORD*)ProcessInformation = 6;
                    case 0x31u:
                        *(DWORD*)ProcessInformation = 3;
                    case 0x41u:
                        *(DWORD*)ProcessInformation = 4;
                       
                    }
                    ret = 0;
                    return ret >= 0;
                }
                
                    ::SetLastError(ERROR_NOT_SUPPORTED);
                    return FALSE;
                
            case ProcessLeapSecondInfo:
                if (!ProcessInformation)
                {
                   ::SetLastError(ERROR_NOT_SUPPORTED);
                   return FALSE;
                }
                if (ProcessInformationSize != sizeof(UINT64))
                {
                     ::SetLastError(ERROR_NOT_SUPPORTED);
                     return FALSE;
                }
                int SPI = 0;
                ret = NtQueryInformationProcess(hProcess, (PROCESSINFOCLASS)(ProcessIoPriority | 0x40), &SPI, sizeof(UINT64), 0);
                if (FAILED(ret))
                {
                    ::SetLastError(ERROR_NOT_SUPPORTED);
                    return FALSE;
                }
                PROCESS_LEAP_SECOND_INFO* pLeapSecInfo = reinterpret_cast<PROCESS_LEAP_SECOND_INFO*>(ProcessInformation);
                pLeapSecInfo->Flags = SPI;
                pLeapSecInfo->Reserved = 0;
       
                ret = 0;
                return ret >= 0;
            }

            if (FAILED(ret))
            {
                ::SetLastError(ERROR_NOT_SUPPORTED);
                return FALSE;
            }
            ::SetLastError(ERROR_SUCCESS);
            return TRUE;
            
        }
        else
            return ::farproc_GetProcessInformation(hProcess, ProcessInformationClass, ProcessInformation, ProcessInformationSize);
    }


   
#ifdef SPOOTIFY
    //fix spooty kernel32.dll > redirected to > user32.dll
    EXPORT int WINAPI _LoadStringW(HINSTANCE hInstance,
        UINT      uID,
        LPWSTR    lpBuffer,
        int       cchBufferMax) {
        return ::LoadStringW(hInstance, uID, lpBuffer, cchBufferMax);
    }
#endif

#ifdef SPOOTIFY
#include <shellapi.h>
    //fix LINK open miss - Windows 7 (Spotify LOGON ERROR!!!)
    EXPORT int WINAPI _ELFSL7(const char* AString) {

        ::ShellExecuteA(NULL, "open", AString, NULL, NULL, SW_SHOWNORMAL);
        /*
        LPBC pShellContext = 0;
        ::CreateBindCtx(NULL, &pShellContext);
        IShellItem* pIshell;
        HRESULT reta = ::SHCreateItemFromParsingName(WideString, pShellContext, IID_IShellItem, (void**)&pIshell);
        if (reta)
            return 1;
        
        pIshell->BindToHandler()
        */
       return 0;
    }
#endif

//void
EXPORT BOOL WINAPI _QueryUnbiasedInterruptTimePrecise(
        PULONGLONG lpUnbiasedInterruptTimePrecise
    ) {
    return ::QueryUnbiasedInterruptTime(lpUnbiasedInterruptTimePrecise);
}

EXPORT BOOL WINAPI _GetSystemCpuSetInformation(
    PSYSTEM_CPU_SET_INFORMATION  Information,
    ULONG                        BufferLength,
    PULONG                       ReturnedLength,
    HANDLE                       Process,
    ULONG                        Flags
) {

    if (!farproc_GetSystemCpuSetInformation)
    {
        //windows 7
    //  if (NtQuerySystemInformationEx)
        {
            if (Flags)
            {
                ::SetLastError(E_INVALIDARG);
                return FALSE;
            }//end if (Flags)
            HANDLE hProcess = Process;
            NTSTATUS rt = NtQuerySystemInformationEx((_SYSTEM_INFORMATION_CLASS)SystemCPUSetInformation, &hProcess, sizeof(ULONG64), Information, BufferLength, ReturnedLength);
            if(SUCCEEDED(rt))
                return TRUE;
            ::SetLastError(RtlNtStatusToDosError(rt));
            return FALSE;
        }
        return TRUE;
    }
    else
        return farproc_GetSystemCpuSetInformation(Information, BufferLength, ReturnedLength, Process, Flags);
}

/*
* 
* DISCROD PATCH 
$+2B629EC        | lea rcx,qword ptr ds:[14A08C866]                                               | 000000014A08C866:"ws2_32.dll" >> "kernel64.dll"
$+2B629F3        | call qword ptr ds:[<GetModuleHandleA>]                                         |
$+2B629F9        | test rax,rax                                                                   | 
$+2B629FC        | je discord.142263A15                                                           |
$+2B629FE        | lea rdx,qword ptr ds:[14A08C871]                                               | 000000014A08C871:"GetHostNameW"
$+2B62A05        | mov rcx,rax                                                                    | 
$+2B62A08        | call qword ptr ds:[<GetProcAddress>]                                           |
$+2B62A0E        | mov qword ptr ds:[14A9B6AC0],rax                                               | 

The GetHostNameW function retrieves the standard host name for the local computer as a Unicode string.
Requirement 	Value
Minimum supported client 	Windows 8.1, Windows 8 [desktop apps | UWP apps]
Minimum supported server 	Windows Server 2012 [desktop apps | UWP apps]
Target Platform 	Windows
Header 	winsock2.h
Library 	Ws2_32.lib
DLL 	Ws2_32.dll
*/
#ifdef DISCORD
//#include <winsock2.h>
//#include <Ws2tcpip.h>
//#pragma comment(lib, "Ws2_32.lib")
constexpr auto WIDE_LOCALHOST = L"locahost";
EXPORT int WINAPI _GetHostNameW(
    PWSTR name,
    int   namelen
)
{
    DWORD lpnamelen = namelen;
    if (!::GetComputerNameW(name, &lpnamelen))
    {
        if (namelen < wcslen(WIDE_LOCALHOST))
            return WSAEFAULT;
        wcscpy(name, WIDE_LOCALHOST);
    }//end if (!::GetComputerNameW(name, &lpnamelen))
    return ERROR_SUCCESS;
}


    
#endif // DISCROD


EXPORT BOOL WINAPI _GetOverlappedResultEx(HANDLE hFile,
    LPOVERLAPPED lpOverlapped,
    LPDWORD lpNumberOfBytesTransferred,
    DWORD dwMilliseconds,
    BOOL bAlertable)
{
    if (!farproc_GetOverlappedResultEx)
    {
        // Windows 7
        ::SleepEx(dwMilliseconds, bAlertable);
        return ::GetOverlappedResult(hFile, lpOverlapped, lpNumberOfBytesTransferred, FALSE);
    }
    else
        return ::farproc_GetOverlappedResultEx(hFile, lpOverlapped, lpNumberOfBytesTransferred, dwMilliseconds, bAlertable);
}

    
EXPORT BOOL WINAPI _IsGPU_Process(LPWSTR cmdline)
{
 
    size_t i = wcslen(cmdline);

    while (i--)
    {
        //gpu
        if (*cmdline++ != L'g')
            continue;

        if (cmdline[0] == L'p' && cmdline[1] == L'u')
        {

            return TRUE;
        }
    }//end while (i--)
    return FALSE;
}


EXPORT BOOL _CompareObjectHandles(
    HANDLE hFirstObjectHandle,
    HANDLE hSecondObjectHandle
)
{
    //TO DO: bad code cmp, need another
    DWORD handle_FIRST = 0;
    DWORD handle_NEXT = 0;
    
    BOOL faF = ::GetHandleInformation(hFirstObjectHandle, &handle_FIRST);
    BOOL faN = ::GetHandleInformation(hSecondObjectHandle, &handle_NEXT);

    if (faF && faN && (handle_FIRST == handle_NEXT))
    {
        BY_HANDLE_FILE_INFORMATION bhfi1 = { 0 };
        BY_HANDLE_FILE_INFORMATION bhfi2 = { 0 };
        if (::GetFileInformationByHandle(hFirstObjectHandle, &bhfi1) &&
            ::GetFileInformationByHandle(hSecondObjectHandle, &bhfi2)) {
            return ((bhfi1.nFileIndexHigh == bhfi2.nFileIndexHigh) &&
                (bhfi1.nFileIndexLow == bhfi2.nFileIndexLow) &&
                (bhfi1.dwVolumeSerialNumber == bhfi2.dwVolumeSerialNumber));
        }
        return FALSE;
    }
    return FALSE;
}



void MPFLAT_preloader()
{
    LPWSTR cmdline = ::GetCommandLine();
    if (_IsGPU_Process(cmdline))
    {
     //   ::MessageBox(NULL, L"AAAAAAAAAAAAA", L"GPU", MB_OK);
        size_t i = wcslen(cmdline);
#ifdef MAIL
        if (i > 16)
#else
        if(i > 5)
#endif
        {
            LPWSTR path_copy = (LPWSTR)::HeapAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY, (i * sizeof(WCHAR)) + 10);

            if(path_copy)
            {
                size_t ii = i;
                size_t last_div_i = 0;
                LPWSTR cmdline_local = cmdline;

                while (--ii)
                {
                    cmdline_local++;
                    if ((cmdline_local[0] == L'\\') || (cmdline_local[0] == L'/'))
                        last_div_i = (i - ii);

                    if (cmdline_local[0] == L'\"')
                        break;
                }//end while (i--)

                if (cmdline[0] == L'\"')
                {
                    cmdline++;
                }//end  if (cmdline_local[0] == L'\"')

                memcpy_s1(path_copy, (i * sizeof(WCHAR)), cmdline, last_div_i * sizeof(WCHAR));

               // ::MessageBoxW(NULL, path_copy, L"MPFLAT", MB_ICONERROR);
                cmdline = &cmdline[last_div_i];
                if (




#ifdef CHROME

                ((cmdline[0] == L'c') || (cmdline[0] == L'C')) &&
                    ((cmdline[1] == L'h') || (cmdline[1] == L'H')) &&
                    ((cmdline[2] == L'r') || (cmdline[2] == L'R')) &&
                    ((cmdline[3] == L'o') || (cmdline[3] == L'O')) &&
                    ((cmdline[4] == L'm') || (cmdline[4] == L'M')) &&
                    ((cmdline[5] == L'e') || (cmdline[5] == L'E')) &&
#endif
#ifdef EDGE
                    ((cmdline[0] == L'm') || (cmdline[0] == L'M')) &&
                    ((cmdline[1] == L's') || (cmdline[1] == L'S')) &&
                    ((cmdline[2] == L'e') || (cmdline[2] == L'E')) &&
                    ((cmdline[3] == L'd') || (cmdline[3] == L'D')) &&
                    ((cmdline[4] == L'g') || (cmdline[4] == L'G')) &&
                    ((cmdline[5] == L'e') || (cmdline[5] == L'E')) &&
#endif // EDGE

#if  defined(EDGE) || defined(CHROME)

                   ((cmdline[6] == L'.'))&&
                   ((cmdline[7] == L'e') || (cmdline[7] == L'E'))&&
                   ((cmdline[8] == L'x') || (cmdline[8] == L'X'))&&
                   ((cmdline[9] == L'e') || (cmdline[9] == L'E'))
#endif 

#ifdef BRAVE

                    ((cmdline[0] == L'b') || (cmdline[0] == L'B')) &&
                    ((cmdline[1] == L'r') || (cmdline[1] == L'R')) &&
                    ((cmdline[2] == L'a') || (cmdline[2] == L'A')) &&
                    ((cmdline[3] == L'v') || (cmdline[3] == L'V')) &&
                    ((cmdline[4] == L'e') || (cmdline[4] == L'E')) &&
#endif
#ifdef OPERA
                    ((cmdline[0] == L'o') || (cmdline[0] == L'O')) &&
                    ((cmdline[1] == L'p') || (cmdline[1] == L'P')) &&
                    ((cmdline[2] == L'e') || (cmdline[2] == L'E')) &&
                    ((cmdline[3] == L'r') || (cmdline[3] == L'R')) &&
                    ((cmdline[4] == L'a') || (cmdline[4] == L'A')) &&
#endif

#ifdef VIVALDI
                    ((cmdline[0] == L'v') || (cmdline[0] == L'V')) &&
                    ((cmdline[1] == L'i') || (cmdline[1] == L'I')) &&
                    ((cmdline[2] == L'v') || (cmdline[2] == L'V')) &&
                    ((cmdline[3] == L'a') || (cmdline[3] == L'A')) &&
                    ((cmdline[4] == L'l') || (cmdline[4] == L'L')) &&
                    ((cmdline[5] == L'd') || (cmdline[5] == L'D')) &&
                    ((cmdline[6] == L'i') || (cmdline[6] == L'I')) &&
#endif

#ifdef MAIL
                    ((cmdline[0] == L'e') || (cmdline[0] == L'E')) &&
                    ((cmdline[1] == L'l') || (cmdline[1] == L'L')) &&
                    ((cmdline[2] == L'e') || (cmdline[2] == L'E')) &&
                    ((cmdline[3] == L'c') || (cmdline[3] == L'C')) &&
                    ((cmdline[5] == L't') || (cmdline[5] == L'T')) &&
                    ((cmdline[6] == L'r') || (cmdline[6] == L'R')) &&
                    ((cmdline[7] == L'o') || (cmdline[7] == L'O')) &&
                    ((cmdline[8] == L'n') || (cmdline[8] == L'N')) &&
                    ((cmdline[9] == L'm') || (cmdline[9] == L'M')) &&
                    ((cmdline[10] == L'a') || (cmdline[10] == L'A')) &&
                    ((cmdline[11] == L'i') || (cmdline[11] == L'I')) &&
                    ((cmdline[12] == L'l') || (cmdline[12] == L'L')) &&
#endif

#ifdef FIREFOX
                    ((cmdline[0] == L'f') || (cmdline[0] == L'F')) &&
                    ((cmdline[1] == L'i') || (cmdline[1] == L'I')) &&
                    ((cmdline[2] == L'r') || (cmdline[2] == L'R')) &&
                    ((cmdline[3] == L'e') || (cmdline[3] == L'E')) &&
                    ((cmdline[5] == L'f') || (cmdline[5] == L'F')) &&
                    ((cmdline[6] == L'o') || (cmdline[6] == L'O')) &&
                    ((cmdline[7] == L'x') || (cmdline[7] == L'X')) &&
#endif

                    //Spotify.exe
#ifdef SPOOTIFY
                    ((cmdline[0] == L's') || (cmdline[0] == L'S')) &&
                    ((cmdline[1] == L'p') || (cmdline[1] == L'P')) &&
                    ((cmdline[2] == L'o') || (cmdline[2] == L'O')) &&
                    ((cmdline[3] == L't') || (cmdline[3] == L'T')) &&
                    ((cmdline[5] == L'i') || (cmdline[5] == L'I')) &&
                    ((cmdline[6] == L'f') || (cmdline[6] == L'F')) &&
                    ((cmdline[7] == L'y') || (cmdline[7] == L'Y')) &&
#endif

#ifdef TRVIEW
                    //TradingView.exe
                    ((cmdline[0] == L't') || (cmdline[0] == L'T')) &&
                    ((cmdline[1] == L'r') || (cmdline[1] == L'R')) &&
                    ((cmdline[2] == L'a') || (cmdline[2] == L'A')) &&
                    ((cmdline[3] == L'd') || (cmdline[3] == L'D')) &&
                    ((cmdline[4] == L'i') || (cmdline[4] == L'I')) &&
                    ((cmdline[5] == L'n') || (cmdline[5] == L'N')) &&
                    ((cmdline[6] == L'g') || (cmdline[6] == L'G')) &&
                    ((cmdline[7] == L'v') || (cmdline[7] == L'V')) &&
                    ((cmdline[8] == L'i') || (cmdline[8] == L'I')) &&
                    ((cmdline[9] == L'e') || (cmdline[9] == L'E')) &&
                    ((cmdline[10] == L'w') || (cmdline[10] == L'W')) &&
#endif

#if defined(MAILBIRD)
                        //CefSharp.BrowserSubprocess.exe
                        ((cmdline[0] == L'c') || (cmdline[0] == L'C')) &&
                        ((cmdline[1] == L'e') || (cmdline[1] == L'E')) &&
                        ((cmdline[2] == L'f') || (cmdline[2] == L'F')) &&
                        ((cmdline[3] == L's') || (cmdline[3] == L'S')) &&
                        ((cmdline[4] == L'h') || (cmdline[4] == L'H')) &&
                        ((cmdline[5] == L'a') || (cmdline[5] == L'A')) &&
                        ((cmdline[6] == L'r') || (cmdline[6] == L'R')) &&
                        ((cmdline[7] == L'p') || (cmdline[7] == L'P')) &&
                        ((cmdline[8] == L'.') || (cmdline[8] == L'.')) &&
                        ((cmdline[9] == L'b') || (cmdline[9] == L'B')) &&
                        ((cmdline[10] == L'r') || (cmdline[10] == L'R')) &&
                        ((cmdline[11] == L'o') || (cmdline[11] == L'O')) &&
                        ((cmdline[12] == L'w') || (cmdline[12] == L'W')) &&
                        ((cmdline[13] == L's') || (cmdline[13] == L'S')) &&
                        ((cmdline[14] == L'e') || (cmdline[14] == L'E')) &&
                        ((cmdline[15] == L'r') || (cmdline[15] == L'R')) &&
                        ((cmdline[16] == L's') || (cmdline[16] == L'S')) &&
                        ((cmdline[17] == L'u') || (cmdline[17] == L'U')) &&
                        ((cmdline[18] == L'b') || (cmdline[18] == L'B')) &&
                        ((cmdline[19] == L'p') || (cmdline[19] == L'P')) &&
                        ((cmdline[20] == L'r') || (cmdline[20] == L'R')) &&
                        ((cmdline[21] == L'o') || (cmdline[21] == L'O')) &&
                        ((cmdline[22] == L'c') || (cmdline[22] == L'C')) &&
                        ((cmdline[23] == L'e') || (cmdline[23] == L'E')) &&
                        ((cmdline[24] == L's') || (cmdline[24] == L'S')) &&
                        ((cmdline[25] == L's') || (cmdline[25] == L'S')) &&
#endif

#ifdef DISCORD
                        ((cmdline[0] == L'd') || (cmdline[0] == L'D')) &&
                        ((cmdline[1] == L'i') || (cmdline[1] == L'I')) &&
                        ((cmdline[2] == L's') || (cmdline[2] == L'S')) &&
                        ((cmdline[3] == L'c') || (cmdline[3] == L'C')) &&
                        ((cmdline[4] == L'o') || (cmdline[4] == L'O')) &&
                        ((cmdline[5] == L'r') || (cmdline[5] == L'R')) &&
                        ((cmdline[6] == L'd') || (cmdline[6] == L'D')) &&
#endif // DISCORD

#if  defined(BRAVE) || defined(OPERA)
                    ((cmdline[5] == L'.')) &&
                    ((cmdline[6] == L'e') || (cmdline[6] == L'E')) &&
                    ((cmdline[7] == L'x') || (cmdline[7] == L'X')) &&
                    ((cmdline[8] == L'e') || (cmdline[8] == L'E'))
#endif

#if  defined(VIVALDI)
                    ((cmdline[7] == L'.')) &&
                    ((cmdline[8] == L'e') || (cmdline[8] == L'E')) &&
                    ((cmdline[9] == L'x') || (cmdline[9] == L'X')) &&
                    ((cmdline[10] == L'e') || (cmdline[10] == L'E'))
#endif

#if  defined(MAIL)
                    ((cmdline[13] == L'.')) &&
                    ((cmdline[14] == L'e') || (cmdline[14] == L'E')) &&
                    ((cmdline[15] == L'x') || (cmdline[15] == L'X')) &&
                    ((cmdline[16] == L'e') || (cmdline[16] == L'E'))
#endif

#if defined(SPOOTIFY) || defined(FIREFOX)
                    ((cmdline[8] == L'.')) &&
                    ((cmdline[9] == L'e') || (cmdline[6] == L'E')) &&
                    ((cmdline[10] == L'x') || (cmdline[7] == L'X')) &&
                    ((cmdline[11] == L'e') || (cmdline[8] == L'E'))
#endif
#if defined(TRVIEW)
                            ((cmdline[11] == L'.')) &&
                            ((cmdline[12] == L'e') || (cmdline[12] == L'E')) &&
                            ((cmdline[13] == L'x') || (cmdline[13] == L'X')) &&
                            ((cmdline[13] == L'e') || (cmdline[13] == L'E'))
#endif
#if defined(MAILBIRD)
                        ((cmdline[26] == L'.')) &&
                        ((cmdline[27] == L'e') || (cmdline[27] == L'E')) &&
                        ((cmdline[28] == L'x') || (cmdline[28] == L'X')) &&
                        ((cmdline[29] == L'e') || (cmdline[29] == L'E'))
#endif

#ifdef DISCORD
                        ((cmdline[7] == L'.')) &&
                        ((cmdline[8] == L'e') || (cmdline[8] == L'E')) &&
                        ((cmdline[9] == L'x') || (cmdline[9] == L'X')) &&
                        ((cmdline[10] == L'e') || (cmdline[10] == L'E'))
#endif // DISCORD

                    )
                    {
                    memcpy_s1(&path_copy[last_div_i], i * sizeof(WCHAR), WIDE_MPFLAT_386, sizeof(WIDE_MPFLAT_386));
                       
#ifdef DEBUG_OUT
                    HMODULE ll = ::LoadLibrary(path_copy);
                        if (!ll)
                           ::MessageBoxA(NULL, "MPFLAT", "", MB_ICONERROR);
#else
                    ::LoadLibrary(path_copy);
#endif
                    }//end if(chrome...)
                ::HeapFree(::GetProcessHeap(), 0, path_copy);
            }//end  if(path_copy)
            
        }//end   if(i)
    }//gpu
}

}


void WLDP_preloader_MSEDGE()
{
    TCHAR path[MAX_PATH*2];

    pWLDP_MSEDGE = ::LoadLibraryExW(WIDE_WLDP, NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (pWLDP_MSEDGE)
        return;

    SIZE_T i = ::GetModuleFileName(::GetModuleHandle(NULL), path, MAX_PATH);
    if (i)
    {
        TCHAR* pCursor = &path[i];
        while (i--)
        {
            pCursor--;
            if ((*pCursor == '\\') || (*pCursor == '/'))
            {
                memcpy(&pCursor[1], WIDE_WLDP, sizeof(WIDE_WLDP));
                pWLDP_MSEDGE = ::LoadLibrary(path);
                return;
            }//end if ((*pCursor == '\\') || (*pCursor == '/'))
        }//end while (i--)
        pWLDP_MSEDGE = ::LoadLibrary(WIDE_WLDP);
    }//end if (::GetModuleFileName(::GetModuleHandle(NULL), path, sizeof(path)) == 0)
    
}


void DDRAW_FontCase_Service_SANDBOX_hook()
{
    HMODULE hPrimary = ::GetModuleHandleA(PRIMARY_EXE);

    if (!hPrimary)
    {
        //::MessageBox(NULL, L"Target Module (chrome..exe) Handle not found!", L"[BUG]", MB_OK | MB_ICONASTERISK);
        return;
    }//end if (!hPrimary)

    farproc_IsSandboxedProcess = (chrome_IsSandboxedProcess*)::GetProcAddress(hPrimary, PRIMARY_EXE_Is_SANDBOXED_SA);

    if (!farproc_IsSandboxedProcess)
    {
        ::MessageBox(NULL, L"Function \"IsSandboxedProcess()\" not found in EXPORT TABLE !", L"[BUG]", MB_OK | MB_ICONASTERISK);
        return;
    }//end if (!farproc_IsSandboxedProcess)

    //not in SANDBOX - hook not req
    if (!farproc_IsSandboxedProcess())
    {

        SC_HANDLE SCS = ::OpenSCManager(NULL, NULL, NULL);
        if (SCS)
        {
            SC_HANDLE SCS_FONTCACHE_SERVICE = ::OpenService(SCS, WIDE_SCS_FONTCACHE_SERVICENAME, SC_MANAGER_QUERY_LOCK_STATUS| SC_MANAGER_ENUMERATE_SERVICE);
            if (SCS_FONTCACHE_SERVICE)
            {
                ::StartService(SCS_FONTCACHE_SERVICE, NULL, NULL);

                ::CloseServiceHandle(SCS_FONTCACHE_SERVICE);
                ::CloseServiceHandle(SCS);
            }//end if (SCS_FONTCACHE_SERVICE)
        }//end if (SCS)
        return;
    }//end    if (!farproc_IsSandboxedProcess)

    //SANDBOX!
    //public: static bool _cdecl ClientSideConnection::StartFontCacheService(unsigned int)
    HMODULE dwrite_module = ::LoadLibrary(WIDE_DWRITE);
    if(dwrite_module)
    {
        DWORD st = 0;
        IMAGE_IMPORT_DESCRIPTOR* import_first_thunk = get_IMPORT_table_shift_prop_VA(dwrite_module, &st);
        get_IMPORT_table_DLLNAME_props(SERVICE_QUERY_ADVAPI32_DLL, advapi32_pp, dwrite_module, import_first_thunk, st);

    }//end if(dwrite_module)
}

UINT Fill_fail_safe_CFMAPPING_Handle()
{    
    size_t i = MAX_TABLE_SAFE;

    WCHAR name_buffer[MAX_PATH];      

    HANDLE* hsafe_table_cursor = hsafe_table;
    UINT SUCCESS_RET = 0;

    if(!farproc_IsSandboxedProcess)
        return 0;

    if (!farproc_IsSandboxedProcess())
        return 0;

    while (i--)
    {
        ACL acl_0;
        ::ZeroMemory(&acl_0, sizeof(acl_0));
        if (::InitializeAcl(&acl_0, sizeof(ACL), 2))
        {
            SECURITY_DESCRIPTOR sd;
            ::ZeroMemory(&sd, sizeof(sd));
            if (::InitializeSecurityDescriptor(&sd, 1))
            {
                if (::SetSecurityDescriptorDacl(&sd, TRUE, &acl_0, FALSE))
                {
                    SECURITY_ATTRIBUTES sa;
                    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
                    sa.lpSecurityDescriptor = &sd;
                    sa.bInheritHandle = FALSE;

                    DWORD masxsize_hight = 0;

                    wsprintf(name_buffer, WIDE_CH_SHARED_SECTION_NAME_TEMPLATE, randr());
                    HANDLE answer = ::CreateFileMappingW((HANDLE)-1, &sa, PAGE_READWRITE, masxsize_hight, 0L, name_buffer);
                    ::SwitchToThread();
                    if (answer)
                    {
                        *hsafe_table_cursor++ = answer;
                        SUCCESS_RET++;
                    }//end if (SUCCEEDED(answer))
                }//end if (::SetSecurityDescriptorDacl(&sd, TRUE, &acl_0, FALSE))
            }//end if (::InitializeSecurityDescriptor(&sd, 1))
        }//end if (::InitializeAcl(&acl_0, sizeof(ACL), 2))
    }//end while (i--)

    ::InitializeCriticalSection(&csec_fail_safe);
    return SUCCESS_RET;
}



#ifdef _WIN64

extern "C" EXPORT LPVOID WINAPI _VirtualAlloc(LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flAllocationType,
    DWORD flProtect) {
    //decrease size for WINDIWS 7 HUGE MEMORY BUG
   // if ((flAllocationType == MEM_RESERVE) && dwSize == 0x000000800000000)
     //   dwSize = 0x000000800000000;

    return ::VirtualAlloc(lpAddress,
        dwSize,
        flAllocationType,
        flProtect);
}

#else
extern "C" EXPORT LPVOID WINAPI _VirtualAlloc(LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flAllocationType,
    DWORD flProtect) {
    return ::VirtualAlloc(lpAddress,
        dwSize,
        flAllocationType,
        flProtect);
}

#endif // _WIN64


/*  
      std::u16string name;
if (win::GetVersion() < win::Version::WIN8_1) {
  // Windows < 8.1 ignores DACLs on certain unnamed objects (like shared
  // sections). So, we generate a random name when we need to enforce
  // read-only.
  /*
  Windows < 8.1 игнорирует DACL для некоторых неименованных объектов (like shared sections).
  Поэтому мы генерируем случайное имя, когда нам нужно обеспечить только для чтения.
  
    uint64_t rand_values[4];
    RandBytes(&rand_values, sizeof(rand_values));
    name = ASCIIToUTF16(StringPrintf("CrSharedMem_%016llx%016llx%016llx%016llx",
        rand_values[0], rand_values[1],
        rand_values[2], rand_values[3]));
    DCHECK(!name.empty());
}
*/


    /*
    EXPORT BOOL WINAPI _UpdateProcThreadAttribute(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
        DWORD dwFlags,
        DWORD_PTR Attribute,
        PVOID lpValue,
        SIZE_T cbSize,
        PVOID lpPreviousValue,
        PSIZE_T lpReturnSize) {
}


*/


