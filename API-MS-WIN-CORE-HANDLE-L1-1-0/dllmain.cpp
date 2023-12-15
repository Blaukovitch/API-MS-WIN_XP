//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_KERNEL32DLL[] = L"kernel32.dll";
const TCHAR WIDE_NTDLLDLL[] = L"ntdll.dll";
const char A_COH[] = "CompareObjectHandles";
const char A_NtCO[] = "NtCompareObjects";
#pragma code_seg(pop)

typedef BOOL(WINAPI api_CompareObjectHandles)(HANDLE hFirstObjectHandle,
    HANDLE hSecondObjectHandle);
typedef LSTATUS(WINAPI api_NtCompareObjects)(HANDLE hFirstObjectHandle,
    HANDLE hSecondObjectHandle);

api_CompareObjectHandles* farproc_CompareObjectHandles = 0;
api_NtCompareObjects* farproc_NtCompareObjects = 0;

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

        if (!pKernel32)
        {

            pKernel32 = ::GetModuleHandle(WIDE_KERNEL32DLL);
            pNtdll = ::GetModuleHandle(WIDE_NTDLLDLL);

            if (pKernel32 && pNtdll)
            {
                farproc_CompareObjectHandles = (api_CompareObjectHandles*)::GetProcAddress(pKernel32, A_COH);
                farproc_NtCompareObjects = (api_NtCompareObjects*)::GetProcAddress(pNtdll, A_NtCO);
            }//end if (pKernel32 && pNtdll)
        }//ennd   if (!pKernel32)

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

    EXPORT BOOL WINAPI _CompareObjectHandles(HANDLE hFirstObjectHandle,
        HANDLE hSecondObjectHandle)
    {
        if (!farproc_CompareObjectHandles)
        {
            if (!farproc_NtCompareObjects)
            {
                //Windows 7 
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
            else
            {
                LSTATUS ntret = farproc_NtCompareObjects(hFirstObjectHandle, hSecondObjectHandle);
                if (!ntret)
                    return TRUE;
                return FALSE;
            }
        }
        else
            return farproc_CompareObjectHandles(hFirstObjectHandle, hSecondObjectHandle);
    }
}
