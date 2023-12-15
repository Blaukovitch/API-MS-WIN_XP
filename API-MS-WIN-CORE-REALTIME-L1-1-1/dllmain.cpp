//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 
//#define DEBUG_OUT 1


// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_KERNEL32DLL[] = L"kernel32.dll";
const TCHAR WIDE_NTDLL32DLL[] = L"ntdll.dll";
const char A_QUITP[] = "QueryUnbiasedInterruptTimePrecise";
const char A_RTLGITP[] = "RtlGetInterruptTimePrecise";

volatile ULONGLONG unibias = 0x122L;

#pragma code_seg(pop)

// ----- ABSENT AP -----
HMODULE pKernel32;
HMODULE pNtdll;

typedef void(WINAPI api_QueryUnbiasedInterruptTimePrecise)(PULONGLONG lpUnbiasedInterruptTimePrecise);
typedef void(WINAPI api_RtlGetInterruptTimePrecise)(PULONGLONG lpUnbiasedInterruptTimePrecise);

api_QueryUnbiasedInterruptTimePrecise* farproc_lpUnbiasedInterruptTimePrecise = 0;
api_RtlGetInterruptTimePrecise* farproc_RtlGetInterruptTimePrecise = 0;

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
            pNtdll = ::GetModuleHandle(WIDE_NTDLL32DLL);
            if (pKernel32 && pNtdll)
            {
                farproc_lpUnbiasedInterruptTimePrecise = (api_QueryUnbiasedInterruptTimePrecise*)::GetProcAddress(pKernel32, A_QUITP);
                farproc_RtlGetInterruptTimePrecise = (api_RtlGetInterruptTimePrecise*)::GetProcAddress(pNtdll, A_RTLGITP);
            }//end  if (pKernel32)
        }//end    if (!pKernel32)
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
Minimum supported client 	Windows 10 [desktop apps | UWP apps]
Minimum supported server 	Windows Server 2016 [desktop apps | UWP apps]
Target Platform 	Windows
Header 	realtimeapiset.h
Library 	Kernel32.lib
DLL 	Kernel32.dll
*/
    EXPORT void WINAPI QueryUnbiasedInterruptTimePrecise(PULONGLONG lpUnbiasedInterruptTimePrecise)
    {
        if (!farproc_lpUnbiasedInterruptTimePrecise)
        {
            if (farproc_RtlGetInterruptTimePrecise)
            {
              //  ULONGLONG bias_time = 0;
                //ULONGLONG interrupt_kuser_shared_data = 
             //   do{

               //     farproc_RtlGetInterruptTimePrecise(&bias_time);
             //   }while()
            }//end  if (farproc_RtlGetInterruptTimePrecise)
            ::InterlockedIncrement(&unibias);
            *lpUnbiasedInterruptTimePrecise = unibias;
        }
        else
            return farproc_lpUnbiasedInterruptTimePrecise(lpUnbiasedInterruptTimePrecise);
    }
}
