//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 
//#define DEBUG_OUT 1
#include "native.h"

// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_BCRYPTPRIMITIVES[] = L"bcryptprimitives.dll";
const char A_PROCPRNG[] = "ProcessPrng";
#pragma code_seg(pop)

typedef BOOL(WINAPI api_ProcessPrng)(
    PBYTE  pbData,
    SIZE_T cbData);

api_ProcessPrng* farproc_ProcessPrng = 0;

// ----- ABSENT AP -----
HMODULE pBcryptprimitives;


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
        pBcryptprimitives = ::GetModuleHandle(WIDE_BCRYPTPRIMITIVES);

        if (pBcryptprimitives)
        {
            farproc_ProcessPrng = (api_ProcessPrng*)::GetProcAddress(pBcryptprimitives, A_PROCPRNG);
        }//end if (pBcryptprimitives)

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
    EXPORT BOOL WINAPI ProcessPrng(PBYTE  pbData,
        SIZE_T cbData)
    {
        if (!farproc_ProcessPrng)
        {
            SIZE_T div4 = cbData / 4;
            SIZE_T resid = cbData % 4;
            PDWORD pbDat4 = reinterpret_cast<PDWORD>(pbData);
            ULONG prnd = pKUSERSHAREDDATA->InterruptTime.LowPart;
            LARGE_INTEGER li;
            li.HighPart = 0;
            li.LowPart = 0;
            li.QuadPart = 0;
            while (div4--)
            {
                *pbDat4++ = prnd;
                ::QueryPerformanceCounter(&li);
                prnd = pKUSERSHAREDDATA->InterruptTime.LowPart + li.LowPart;
            }//end  while(cbData)

            pbData = reinterpret_cast<PBYTE>(pbDat4);
            switch (resid)
            {
            case 1: {
                *pbData = (BYTE)pKUSERSHAREDDATA->InterruptTime.LowPart;
                break; }
            case 2: {
                PSHORT pbDat2 = reinterpret_cast<PSHORT>(pbData);
                *pbDat2 = (SHORT)pKUSERSHAREDDATA->InterruptTime.LowPart;
                break; }
            case 3: {
                ULONG rnd_value = pKUSERSHAREDDATA->InterruptTime.LowPart;
                pbData[0] = (BYTE)(rnd_value);
                pbData[1] = (BYTE)(rnd_value >> 8);
                pbData[3] = (BYTE)(rnd_value >> 16);
                break; }

            case 4: {
                PDWORD pbDat4 = reinterpret_cast<PDWORD>(pbData);
                *pbDat4 = pKUSERSHAREDDATA->InterruptTime.LowPart;
                break; }
            }//end switch (cbData)
        }
        else 
            return farproc_ProcessPrng(pbData, cbData);

        return TRUE;
    }
}
