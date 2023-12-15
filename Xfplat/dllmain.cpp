//[80_PA] ELF, cracklab/exelab, 2023
//FLAG
//#define DEBUG_OUT 1
#include "XClasses.h"


// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_MFPLAT[] = L"MFPLAT.DLL";
const char A_MFCDDVM[] = "MFCreateDXGIDeviceManager";
const char A_MFCDSB[] = "MFCreateDXGISurfaceBuffer";
const char A_MFLOCK[] = "MFLockDXGIDeviceManager";
const char A_MFUNLOCK[] = "MFUnlockDXGIDeviceManager";
#pragma code_seg(pop)

// ----- ABSENT AP -----
HMODULE pMFPLAT;

typedef HRESULT(WINAPI api_MFCreateDXGIDeviceManager)(
  UINT* resetToken,
  IMFDXGIDeviceManager** ppDeviceManager
    );

typedef HRESULT(WINAPI api_MFCreateDXGISurfaceBuffer)(
    REFIID         riid,
    IUnknown* punkSurface,
    UINT           uSubresourceIndex,
    BOOL           fBottomUpWhenLinear,
    IMFMediaBuffer** ppBuffer
    );

typedef HRESULT(WINAPI api_MFLockDXGIDeviceManager)(
    UINT* pResetToken,
    IMFDXGIDeviceManager** ppManager
    );

typedef HRESULT(WINAPI api_MFUnlockDXGIDeviceManager)(VOID
    );

api_MFCreateDXGIDeviceManager* farproc_MFCreateDXGIDeviceManager = 0;
api_MFCreateDXGISurfaceBuffer* farproc_MFCreateDXGISurfaceBuffer = 0;
api_MFLockDXGIDeviceManager* farproc_MFLockDXGIDeviceManager = 0;
api_MFUnlockDXGIDeviceManager* farproc_MFUnlockDXGIDeviceManager = 0;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        if (!pMFPLAT)
        {

            pMFPLAT = ::GetModuleHandle(WIDE_MFPLAT);
        
            if(!pMFPLAT)
            {
                farproc_MFCreateDXGIDeviceManager = (api_MFCreateDXGIDeviceManager*)::GetProcAddress(pMFPLAT, A_MFCDDVM);
                farproc_MFCreateDXGISurfaceBuffer = (api_MFCreateDXGISurfaceBuffer*)::GetProcAddress(pMFPLAT, A_MFCDSB);
                farproc_MFLockDXGIDeviceManager = (api_MFLockDXGIDeviceManager*)::GetProcAddress(pMFPLAT, A_MFLOCK);
                farproc_MFUnlockDXGIDeviceManager = (api_MFUnlockDXGIDeviceManager*)::GetProcAddress(pMFPLAT, A_MFUNLOCK);                  
            }//end if(!pMFPLAT)
        }//end if (!pKernel32)
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
Minimum supported client 	Windows 8 [desktop apps | UWP apps]
Minimum supported server 	Windows Server 2012 [desktop apps | UWP apps]
Target Platform 	Windows
Header 	mfapi.h
Library 	Mfplat.lib
DLL 	Mfplat.dll
    */

    EXPORT HRESULT WINAPI _MFCreateDXGIDeviceManager(UINT* resetToken,
        IMFDXGIDeviceManager** ppDeviceManager)
    {
        if (!farproc_MFCreateDXGIDeviceManager)
        {
            if (!resetToken || !ppDeviceManager)
                return E_INVALIDARG;

           // *ppDeviceManager = new (XDVM);
            return E_NOTIMPL;
        }
        else
            return farproc_MFCreateDXGIDeviceManager(resetToken, ppDeviceManager);

        return E_NOTIMPL;
    }

    EXPORT HRESULT WINAPI _MFCreateDXGISurfaceBuffer(REFIID         riid,
        IUnknown* punkSurface,
        UINT           uSubresourceIndex,
        BOOL           fBottomUpWhenLinear,
        IMFMediaBuffer** ppBuffer)
    {
        if (!farproc_MFCreateDXGISurfaceBuffer)
        {
            if (!ppBuffer || !punkSurface)
                return E_INVALIDARG;

            return E_NOTIMPL;
        }
        else
            return farproc_MFCreateDXGISurfaceBuffer(riid,
                punkSurface,
                uSubresourceIndex,
                fBottomUpWhenLinear,
                ppBuffer);

        return E_NOTIMPL;
    }

    EXPORT HRESULT WINAPI _MFLockDXGIDeviceManager(UINT* pResetToken,
        IMFDXGIDeviceManager** ppManager)
    {
        if (!farproc_MFLockDXGIDeviceManager)
        {
            if (!pResetToken || !ppManager)
                return E_INVALIDARG;

            return ERROR_SUCCESS;
        }
        else
            return farproc_MFLockDXGIDeviceManager(pResetToken,
               ppManager);

        return ERROR_SUCCESS;
    }

    EXPORT HRESULT WINAPI _MFUnlockDXGIDeviceManager(VOID)
    {
        if (!farproc_MFUnlockDXGIDeviceManager)
        {

            return ERROR_SUCCESS;
        }
        else
            return farproc_MFUnlockDXGIDeviceManager();

        return ERROR_SUCCESS;
    }
}
