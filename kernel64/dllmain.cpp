//[80_PA] ELF, cracklab/exelab, 2023
//FLAG  
//#define DEBUG_OUT 1
//#define COMPATIBLE10_7_MODE 1
//#define EDGE 1

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
const char A_NTSIT[] = "NtSetInformationThread";
const char A_NTSIVM[] = "NtSetInformationVirtualMemory";
const char A_GFT[] = "GetFirmwareType";
const char A_W64GTC[] = "Wow64GetThreadContext";
const char A_SPI[] = "SetProcessInformation";
const char A_GPMP[] = "GetProcessMitigationPolicy";
const char A_SPMP[] = "SetProcessMitigationPolicy";
const char A_GPFN[] = "GetPackageFamilyName";
const char A_NTQIT[] = "NtQueryInformationToken";

#ifndef EDGE
const char PRIMARY_EXE[] = "chrome.exe";
#else
const char PRIMARY_EXE[] = "msedge.exe";
#endif // EDGE
const char PRIMARY_EXE_Is_SANDBOXED_SA[] = "IsSandboxedProcess";
const char SERVICE_QUERY_ADVAPI32_DLL[] = "ADVAPI32.DLL";



const WCHAR WIDE_NULL_GUID_PTR[] = L"{00000000-0000-0000-0000-000000000000}";
const WCHAR WIDE_CH_SHARED_SECTION_NAME_TEMPLATE[] = L"CrSharedMem_%lx";


#pragma code_seg(pop)


extern "C" BOOL checkl_stop_option();
extern "C" void MPFLAT_preloader();
extern "C" void DDRAW_FontCase_Service_SANDBOX_hook();
extern "C" void WLDP_preloader_MSEDGE();

pool_I advapi32_pp[] = {
    {"OpenServiceW", (size_t)hook_OpenServiceW},
    {"CloseServiceHandle",(size_t)hook_CloseServiceHandle },
    {"OpenSCManagerW",(size_t)hook_OpenSCManagerW  },
    {"StartServiceW", (size_t)hook_StartServiceW},
    {"NotifyServiceStatusChangeW", (size_t)hook_NotifyServiceStatusChangeW},
    {0, 0}
};

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
api_NtQueryInformationToken* farproc_NtQueryInformationToken = 0;
chrome_IsSandboxedProcess* farproc_IsSandboxedProcess = 0;

api_swprintf_s* farproc_wsprintf_s = 0;

BOOL DllMain( HMODULE hModule,
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
         checkl_stop_option();
#endif // DEBUG_OUT
         render_process = checkl_stop_option();
      
        
        if (!pKernel32)
        {
     
        pKernel32 = ::GetModuleHandle(WIDE_KERNEL32DLL);
        pNtdll = ::GetModuleHandle(WIDE_NTDLLDLL);
        
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
            farproc_NtSetInformationVirtualMemory = (api_NtSetInformationVirtualMemory*)::GetProcAddress(pNtdll, A_NTSIVM);
            farproc_IsEnclaveTypeSupported = (api_IsEnclaveTypeSupported*)::GetProcAddress(pNtdll, A_IETS);
            farproc_NtQueryInformationToken = (api_NtQueryInformationToken*)::GetProcAddress(pNtdll, A_NTQIT);
#endif
            farproc_NtSetInformationThread = (api_NtSetInformationThread*)::GetProcAddress(pNtdll, A_NTSIT);


            //GPU SANDBOX preload (without \System32\ && \SysWOW64\)
            MPFLAT_preloader();
            //DirectX DRAW SANDBOX (Windows 7)
            DDRAW_FontCase_Service_SANDBOX_hook();
#ifdef EDGE
            //WLDP
            WLDP_preloader_MSEDGE();
#endif // EDGE
        }//end if (!pKernel32)
        break; }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH: {
        break;}
    }//end switch (ul_reason_for_call)
    return TRUE;
}
//NON-DEFAULT

//gpu || render
//#define GPU_STOP 1
BOOL checkl_stop_option()
{
    //gpu process || renderer
    LPWSTR cmdline = ::GetCommandLine();
    UINT i = wcslen(cmdline);

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
            }
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
                return E_INVALIDARG;

            //Windows 7
            LPCONTEXT pctx = 0;
            BOOL gth = ::GetThreadContext(hThread, pctx);
            if (gth)
            {
                //ctx flag
                lpContext->ContextFlags = pctx->ContextFlags;

                //hw bp
                lpContext->Dr0 = pctx->Dr0;
                lpContext->Dr1 = pctx->Dr1;
                lpContext->Dr2 = pctx->Dr2;
                lpContext->Dr3 = pctx->Dr3;
                lpContext->Dr6 = pctx->Dr6;
                lpContext->Dr7 = pctx->Dr7;

                //commmon cpu
#ifdef _AMD64_

                lpContext->Eax = pctx->Rax;
                lpContext->Ecx = pctx->Rcx;
                lpContext->Edx = pctx->Rdx;
                lpContext->Ebx = pctx->Rbx;
                lpContext->Edi = pctx->Rsi;
                lpContext->Esi = pctx->Rdi;
                lpContext->Esp = pctx->Rsp;
                lpContext->Ebp = pctx->Rbp;
                lpContext->Eip = pctx->Rip;
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
                lpContext->EFlags = pctx->EFlags;

                //seg regs
                lpContext->SegCs = pctx->SegCs;
                lpContext->SegGs = pctx->SegGs;
                lpContext->SegFs = pctx->SegFs;
                lpContext->SegEs = pctx->SegEs;
                lpContext->SegDs = pctx->SegDs;
#ifdef _AMD64_
                //FPU 80387 /XMM )
                lpContext->FloatSave.ControlWord = pctx->FltSave.ControlWord;
                lpContext->FloatSave.DataOffset = pctx->FltSave.DataOffset;
                lpContext->FloatSave.DataSelector = pctx->FltSave.DataSelector;
                lpContext->FloatSave.ErrorOffset = pctx->FltSave.ErrorOffset;
                lpContext->FloatSave.ErrorSelector = pctx->FltSave.ErrorSelector;
                lpContext->FloatSave.StatusWord = pctx->FltSave.StatusWord;
                lpContext->FloatSave.TagWord = pctx->FltSave.TagWord;
                memcpy(lpContext->FloatSave.RegisterArea, pctx->FltSave.FloatRegisters, WOW64_SIZE_OF_80387_REGISTERS); //???
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
                memset(lpContext->ExtendedRegisters, 0, sizeof(lpContext->ExtendedRegisters));

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

        return ::UpdateProcThreadAttribute(lpAttributeList,
            dwFlags,
            Attribute,
            lpValue,
            cbSize,
            lpPreviousValue,
            lpReturnSize);
    }

#define STATUS_BUFFER_TOO_SMALL 0xC0000023
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
    EXPORT LONG _FindPackagesByPackageFamily(
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


    EXPORT LONG _GetApplicationUserModelId(
        HANDLE hProcess,
        UINT32* applicationUserModelIdLength,
        PWSTR  applicationUserModelId
    ) {
        return APPMODEL_ERROR_NO_APPLICATION;
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

void MPFLAT_preloader()
{
    LPWSTR cmdline = ::GetCommandLine();
    if (_IsGPU_Process(cmdline))
    {
        
        UINT i = wcslen(cmdline);
        if(i > 5)
        {
            LPWSTR path_copy = (LPWSTR)::HeapAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY, (i * sizeof(WCHAR)) + 10);

            if(path_copy)
            {
                UINT ii = i;
                UINT last_div_i = 0;
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
                if(
#ifndef EDGE

                   ((cmdline[0] == L'c') || (cmdline[0] == L'C'))&&
                   ((cmdline[1] == L'h') || (cmdline[1] == L'H')) &&
                   ((cmdline[2] == L'r') || (cmdline[2] == L'R'))&&
                   ((cmdline[3] == L'o') || (cmdline[3] == L'O'))&&
                   ((cmdline[4] == L'm') || (cmdline[4] == L'M'))&&
                   ((cmdline[5] == L'e') || (cmdline[5] == L'E'))&&
#else
                    ((cmdline[0] == L'm') || (cmdline[0] == L'M')) &&
                    ((cmdline[1] == L's') || (cmdline[1] == L'S')) &&
                    ((cmdline[2] == L'e') || (cmdline[2] == L'E')) &&
                    ((cmdline[3] == L'd') || (cmdline[3] == L'D')) &&
                    ((cmdline[4] == L'g') || (cmdline[4] == L'G')) &&
                    ((cmdline[5] == L'e') || (cmdline[5] == L'E')) &&
#endif // EDGE
                   ((cmdline[6] == L'.'))&&
                   ((cmdline[7] == L'e') || (cmdline[7] == L'E'))&&
                   ((cmdline[8] == L'x') || (cmdline[8] == L'X'))&&
                   ((cmdline[9] == L'e') || (cmdline[9] == L'E'))
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

    SIZE_T i = ::GetModuleFileName(::GetModuleHandle(NULL), path, sizeof(path));
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
    //public: static bool __cdecl ClientSideConnection::StartFontCacheService(unsigned int)
    HMODULE dwrite_module = ::LoadLibrary(WIDE_DWRITE);
    if(dwrite_module)
    {
        DWORD st = 0;
        IMAGE_IMPORT_DESCRIPTOR* import_first_thunk = get_IMPORT_table_shift_prop_VA(dwrite_module, &st);
        get_IMPORT_table_DLLNAME_props(SERVICE_QUERY_ADVAPI32_DLL, advapi32_pp, dwrite_module, import_first_thunk, st);

    }//end if(dwrite_module)
}

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
