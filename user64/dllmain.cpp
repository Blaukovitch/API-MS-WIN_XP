//[80_PA] ELF, cracklab/exelab, 2023-2025
//FLAG 
//#define DEBUG_OUT 1
#include <Windows.h>
#define WIN32_LEAN_AND_MEAN             
#define EXPORT __declspec( dllexport )

// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_USER32DLL[] = L"user32.dll";
const TCHAR WIDE_PPROWDLL[] = L"powrprof.dll";
const TCHAR WIDE_NTDLL[] = L"ntdll.dll";
const char A_GPPI[] = "GetPointerPenInfo";
const char A_GPT[] = "GetPointerType";
const char A_RSRN[] = "RegisterSuspendResumeNotification";
const char A_USRN[] = "UnregisterSuspendResumeNotification";
const char A_POWRRSRN[] = "PowerRegisterSuspendResumeNotification";
const char A_POWRURSRN[] = "PowerUnregisterSuspendResumeNotification";
const char A_GDPIFW[] = "GetDpiForWindow";
const char A_PTLPPMDPI[] = "PhysicalToLogicalPointForPerMonitorDPI";
const char A_GPITR[] = "GetPointerInputTransform";
const char A_GPD[] = "GetPointerDevice";
const char A_GPDS[] = "GetPointerDevices";
const char A_RPDN[] = "RegisterPointerDeviceNotifications";
const char A_STDC[] = "SetThreadDpiAwarenessContext";
const char A_CSPD[] = "CreateSyntheticPointerDevice";
const char A_ISPI[] = "InjectSyntheticPointerInput";
const char A_GARS[] = "GetAutoRotationState";
const char A_NUGARS[] = "NtUserGetAutoRotationState";
const char A_GPFTI[] = "GetPointerFrameTouchInfo";
const char A_SPDAC[] = "SetProcessDpiAwarenessContext";
const char A_SPIFD[] = "SystemParametersInfoForDpi";
#pragma code_seg(pop)

//https://stackoverflow.com/questions/66161063/c-windows-api-how-to-retrieve-font-scaling-percentage-on-windows-10
/*
Then, on Windows 7, you get the scaling factor using the GetDeviceCaps function with LOGPIXELSX and LOGPIXELSY,
and dividing the result by 96 (because 96 dpi is "100%").(1)
This will give you the DPI setting of the main monitor.
GetDeviceCaps has been the way to get this setting since Windows XP.
This will also do fine on Windows 10 if and only if you do not declare DPI awareness per monitor.
*/
const UINT standart_DPI_100_PERCENT = 96;

// ----- ABSENT AP -----
HMODULE pUser32;
HMODULE pPPow;
HMODULE pNtdll;

typedef BOOL(WINAPI api_GetPointerPenInfo)(UINT32 pointerId,
   POINTER_PEN_INFO* penInfo);
typedef BOOL(WINAPI api_GetPointerType)(UINT32 pointerId,
    POINTER_INPUT_TYPE* pointerType);
typedef HPOWERNOTIFY(WINAPI api_RegisterSuspendResumeNotification)(HANDLE hRecipient,
    DWORD Flags);
typedef BOOL(WINAPI api_UnregisterSuspendResumeNotification)(HPOWERNOTIFY Handle);

typedef DWORD(WINAPI api_PowerRegisterSuspendResumeNotification)(DWORD         Flags,
    HANDLE        Recipient,
    PHPOWERNOTIFY RegistrationHandle);

typedef DWORD(WINAPI api_PowerUnregisterSuspendResumeNotification)(HPOWERNOTIFY RegistrationHandle);

typedef UINT(WINAPI api_GetDpiForWindow)(HWND    hWnd);

typedef BOOL(WINAPI api_PhysicalToLogicalPointForPerMonitorDPI)(HWND    hWnd, LPPOINT lpPoint);

typedef BOOL(WINAPI api_GetPointerInputTransform)(UINT32          pointerId,
    UINT32          historyCount,
    INPUT_TRANSFORM* inputTransform);

typedef BOOL(WINAPI api_GetPointerDevice)(HANDLE device, POINTER_DEVICE_INFO* pointerDevice);
typedef BOOL(WINAPI api_GetPointerDevices)(UINT32* deviceCount, POINTER_DEVICE_INFO* pointerDevices);

typedef BOOL(WINAPI api_RegisterPointerDeviceNotifications)(HWND window, BOOL notifyRange);

typedef DPI_AWARENESS_CONTEXT(WINAPI api_SetThreadDpiAwarenessContext)(DPI_AWARENESS_CONTEXT dpiContext);

typedef HSYNTHETICPOINTERDEVICE(WINAPI api_CreateSyntheticPointerDevice)(POINTER_INPUT_TYPE    pointerType,
    ULONG                 maxCount,
    POINTER_FEEDBACK_MODE mode);

typedef BOOL(WINAPI api_InjectSyntheticPointerInput)(HSYNTHETICPOINTERDEVICE device,
    const POINTER_TYPE_INFO* pointerInfo,
    UINT32                  count);

typedef BOOL(WINAPI api_GetAutoRotationState)(PAR_STATE pState
    );

typedef BOOL(WINAPI api_NtUserGetAutoRotationState)(PAR_STATE pState
    );

typedef BOOL(WINAPI api_GetPointerFrameTouchInfo)(
    UINT32             pointerId,
    UINT32* pointerCount,
    POINTER_TOUCH_INFO* touchInfo
);

typedef BOOL(WINAPI api_SetProcessDpiAwarenessContext)(DPI_AWARENESS_CONTEXT value);

typedef BOOL(WINAPI api_SystemParametersInfoForDpi)(
    UINT  uiAction,
    UINT  uiParam,
    PVOID pvParam,
    UINT  fWinIni,
    UINT  dpi
    );

api_GetPointerPenInfo* farproc_GetPointerPenInfo = 0;
api_GetPointerType* farproc_GetPointerType = 0;
api_RegisterSuspendResumeNotification* farproc_RegisterSuspendResumeNotification = 0;
api_UnregisterSuspendResumeNotification* farproc_UnregisterSuspendResumeNotification = 0;
api_PowerRegisterSuspendResumeNotification* farproc_PowerRegisterSuspendResumeNotification = 0;
api_PowerUnregisterSuspendResumeNotification* farproc_PowerUnregisterSuspendResumeNotification = 0;
api_GetDpiForWindow* farproc_GetDpiForWindow = 0;
api_PhysicalToLogicalPointForPerMonitorDPI* farproc_PhysicalToLogicalPointForPerMonitorDPI = 0;
api_GetPointerInputTransform* farproc_GetPointerInputTransform = 0;
api_GetPointerDevice* farproc_GetPointerDevice = 0;
api_GetPointerDevices* farproc_GetPointerDevices = 0;
api_RegisterPointerDeviceNotifications* farproc_RegisterPointerDeviceNotifications = 0;
api_SetThreadDpiAwarenessContext* farproc_SetThreadDpiAwarenessContext = 0;
api_CreateSyntheticPointerDevice* farproc_CreateSyntheticPointerDevice = 0;
api_InjectSyntheticPointerInput* farproc_InjectSyntheticPointerInput = 0;
api_GetAutoRotationState* farproc_GetAutoRotationState = 0;
api_NtUserGetAutoRotationState* farproc_NtUserGetAutoRotationState = 0;
api_GetPointerFrameTouchInfo* farproc_GetPointerFrameTouchInfo = 0;
api_SetProcessDpiAwarenessContext* farproc_SetProcessDpiAwarenessContext = 0;
api_SystemParametersInfoForDpi* farproc_SystemParametersInfoForDpi = 0;

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

        if (!pUser32)
        {

            pUser32 = ::LoadLibrary(WIDE_USER32DLL);
            pPPow = ::LoadLibrary(WIDE_PPROWDLL);
            pNtdll = ::GetModuleHandle(WIDE_NTDLL);
            if (pUser32 && pPPow && pNtdll)
            {
                farproc_GetPointerPenInfo = (api_GetPointerPenInfo*)::GetProcAddress(pUser32, A_GPPI);
                farproc_GetPointerType = (api_GetPointerType*)::GetProcAddress(pUser32, A_GPT);
                farproc_RegisterSuspendResumeNotification = (api_RegisterSuspendResumeNotification*)::GetProcAddress(pUser32, A_RSRN);
                farproc_UnregisterSuspendResumeNotification = (api_UnregisterSuspendResumeNotification*)::GetProcAddress(pUser32, A_USRN);
                farproc_GetDpiForWindow = (api_GetDpiForWindow*)::GetProcAddress(pUser32, A_GDPIFW);
                farproc_PhysicalToLogicalPointForPerMonitorDPI = (api_PhysicalToLogicalPointForPerMonitorDPI*)::GetProcAddress(pUser32, A_PTLPPMDPI);
                farproc_GetPointerInputTransform = (api_GetPointerInputTransform*)::GetProcAddress(pUser32, A_GPITR);
                farproc_GetPointerDevice = (api_GetPointerDevice*)::GetProcAddress(pUser32, A_GPD);
                farproc_GetPointerDevices = (api_GetPointerDevices*)::GetProcAddress(pUser32, A_GPDS);
                farproc_RegisterPointerDeviceNotifications = (api_RegisterPointerDeviceNotifications*)::GetProcAddress(pUser32, A_RPDN);
                farproc_SetThreadDpiAwarenessContext = (api_SetThreadDpiAwarenessContext*)::GetProcAddress(pUser32, A_STDC);
                farproc_SystemParametersInfoForDpi = (api_SystemParametersInfoForDpi*)::GetProcAddress(pUser32, A_SPIFD);
               
                //FFOX 130.0.1
                farproc_CreateSyntheticPointerDevice = (api_CreateSyntheticPointerDevice*)::GetProcAddress(pPPow, A_CSPD);
                farproc_InjectSyntheticPointerInput = (api_InjectSyntheticPointerInput*)::GetProcAddress(pPPow, A_ISPI);
                //FFOX 135.0.0
                farproc_GetAutoRotationState = (api_GetAutoRotationState*)::GetProcAddress(pUser32, A_GARS);
                farproc_NtUserGetAutoRotationState = (api_NtUserGetAutoRotationState*)::GetProcAddress(pNtdll, A_GARS);
                //FFFOX 137.0.2
                farproc_GetPointerFrameTouchInfo = (api_GetPointerFrameTouchInfo*)::GetProcAddress(pUser32, A_GPFTI);

                //discord 0.1.9.7
                farproc_SetProcessDpiAwarenessContext = (api_SetProcessDpiAwarenessContext*)::GetProcAddress(pUser32, A_SPDAC);
                
            }//end if (pUser32 && pNtdll)
        }//end if (!pKernel32)

        break; };
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
    Минимальная версия клиента 	Windows 8 [только классические приложения]
    Минимальная версия сервера 	Windows Server 2012 [только классические приложения]
    Целевая платформа 	Windows
    Header 	winuser.h (включая Windows.h)
    Библиотека 	User32.lib
    DLL 	User32.dll
    Набор API 	ext-ms-win-rtcore-ntuser-wmpointer-l1-1-0 (представлено в Windows 10, версия 10.0.14393)
    */
    EXPORT BOOL WINAPI _GetPointerPenInfo(UINT32 pointerId,
        POINTER_PEN_INFO* penInfo)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - GetPointerPenInfo(%i, %p)", ::GetCurrentThreadId(), pointerId, penInfo);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_GetPointerPenInfo)
        {
            //Windows 7
            if (!penInfo)
            {
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return FALSE;
            }//end if (!penInfo)

            
            memset(penInfo, 0, sizeof(POINTER_PEN_INFO));
            penInfo->pointerInfo.ButtonChangeType = POINTER_CHANGE_NONE;
            penInfo->pointerInfo.pointerId = pointerId;
            penInfo->pointerInfo.pointerType = PT_POINTER;
            penInfo->penFlags = PEN_FLAG_NONE;
            penInfo->penMask = PEN_MASK_NONE;
            penInfo->pressure = 0;
            penInfo->rotation = 0;
            penInfo->tiltX = 0;
            penInfo->tiltY = 0;
            return TRUE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_GetPointerPenInfo(pointerId, penInfo);
    }

    EXPORT BOOL WINAPI _GetPointerType(UINT32 pointerId,
        POINTER_INPUT_TYPE* pointerType)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - GetPointerType(%i, %p)", ::GetCurrentThreadId(), pointerId, pointerType);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_GetPointerType)
        {
            //Windows 7
            if (!pointerType)
            {
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return FALSE;
            }//end if (!penInfo)

            //universal
            *pointerType = PT_POINTER;
            return TRUE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_GetPointerType(pointerId, pointerType);
    }

    EXPORT HPOWERNOTIFY WINAPI _RegisterSuspendResumeNotification(HANDLE hRecipient,
        DWORD Flags)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - RegisterSuspendResumeNotification(%i, %p)", ::GetCurrentThreadId(), hRecipient, Flags);
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_RegisterSuspendResumeNotification)
        {
            //Windows 7
            if (farproc_PowerRegisterSuspendResumeNotification)
            {
                HPOWERNOTIFY hpower = 0;
                if (farproc_PowerRegisterSuspendResumeNotification(Flags, hRecipient, &hpower) == ERROR_SUCCESS)
                    return hpower;
            }//end if (farproc_PowerRegisterSuspendResumeNotification)
        
            return NULL;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_RegisterSuspendResumeNotification(hRecipient, Flags);
    }

    EXPORT BOOL WINAPI _UnregisterSuspendResumeNotification(HPOWERNOTIFY Handle)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - farproc_UnregisterSuspendResumeNotification()", ::GetCurrentThreadId());
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_UnregisterSuspendResumeNotification)
        {
            //Windows 7

            if (farproc_PowerUnregisterSuspendResumeNotification)
                return farproc_PowerUnregisterSuspendResumeNotification(Handle);
            return TRUE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_UnregisterSuspendResumeNotification(Handle);
    }

EXPORT UINT WINAPI _GetDpiForWindow(HWND hwnd)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - GetDpiForWindow()", ::GetCurrentThreadId());
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_GetDpiForWindow)
        {
            //Windows 7
            if (!hwnd)
            {
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return NULL;
            }//end if (!hwnd)

            HMONITOR hMon = ::MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
             //get monitor info
            MONITORINFOEX minfo;
            memset(&minfo, 0, sizeof(MONITORINFOEX));
            minfo.cbSize = sizeof(MONITORINFOEX);

            BOOL hr = ::GetMonitorInfo(hMon, &minfo);
            if (!hr)
                return standart_DPI_100_PERCENT;

            HDC screen = ::CreateDC(NULL, minfo.szDevice, NULL, NULL);
            if (!screen)
                return standart_DPI_100_PERCENT;

            UINT dpiX = ::GetDeviceCaps(screen, LOGPIXELSX);
            ReleaseDC(0, screen);
   
            return dpiX;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_GetDpiForWindow(hwnd);
    }

//https://learn.microsoft.com/ru-ru/windows/win32/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness
    EXPORT BOOL WINAPI _PhysicalToLogicalPointForPerMonitorDPI(HWND hWnd,
        LPPOINT lpPoint)
    {
#ifdef DEBUG_OUT
            if (isdp)
            {
                WCHAR Buffer[1024];
                wsprintf(Buffer, L"[%i] - farproc_PhysicalToLogicalPointForPerMonitorDPI()", ::GetCurrentThreadId());
                ::OutputDebugString(Buffer);
            }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_PhysicalToLogicalPointForPerMonitorDPI)
        {
            //Windows 7
            if (!hWnd || !lpPoint)
            {
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return FALSE;
            }//end if (!hwnd)

            HMONITOR hMon = ::MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
            //get monitor info
            MONITORINFOEX minfo;
            memset(&minfo, 0, sizeof(MONITORINFOEX));
            minfo.cbSize = sizeof(MONITORINFOEX);

            BOOL hr = ::GetMonitorInfo(hMon, &minfo);
            if (!hr)
                return TRUE;

            HDC screen = ::CreateDC(NULL, minfo.szDevice, NULL, NULL);
            if (!screen)
                return TRUE;

            UINT dpiX = ::GetDeviceCaps(screen, LOGPIXELSX);
            UINT dpiY = ::GetDeviceCaps(screen, LOGPIXELSY);

            ReleaseDC(0, screen);
            lpPoint->x = (lpPoint->x) * (dpiX / standart_DPI_100_PERCENT);
            lpPoint->y = (lpPoint->y) * (dpiY / standart_DPI_100_PERCENT);

            return TRUE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_PhysicalToLogicalPointForPerMonitorDPI(hWnd, lpPoint);
    }
 
    EXPORT BOOL WINAPI _GetPointerInputTransform(UINT32          pointerId,
        UINT32          historyCount,
        INPUT_TRANSFORM* inputTransform)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - farproc_GetPointerInputTransform()", ::GetCurrentThreadId());
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_GetPointerInputTransform)
        {
            //Windows 7
            if (!inputTransform)
            {
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return FALSE;
            }//end if (!hwnd)

            //no transform
            //inputTransform->m;

            return TRUE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_GetPointerInputTransform(pointerId, historyCount, inputTransform);
    }


    EXPORT BOOL WINAPI _GetPointerDevice(HANDLE  device, POINTER_DEVICE_INFO* pointerDevice)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - farproc_GetPointerDevice()", ::GetCurrentThreadId());
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT
        
        if (!farproc_GetPointerDevice)
        {
            //Windows 7
            if (!device)
            {
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return FALSE;
            }//end if (!hwnd)

            //no transform
            //inputTransform->m;
            ::SetLastError(ERROR_SYSTEM_DEVICE_NOT_FOUND);
            return FALSE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_GetPointerDevice(device, pointerDevice);
    }

    EXPORT BOOL WINAPI _GetPointerDevices(UINT32* deviceCount, POINTER_DEVICE_INFO* pointerDevices)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - farproc_GetPointerDevices()", ::GetCurrentThreadId());
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_GetPointerDevices)
        {
            //Windows 7
            if (!deviceCount)
            {
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return FALSE;
            }//end if (!hwnd)

            //no transform
            //inputTransform->m;
            ::SetLastError(ERROR_SYSTEM_DEVICE_NOT_FOUND);
            return FALSE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_GetPointerDevices(deviceCount, pointerDevices);
    }

    EXPORT BOOL WINAPI _RegisterPointerDeviceNotifications(HWND window, BOOL notifyRange)
    {
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - farproc_RegisterPointerDeviceNotifications()", ::GetCurrentThreadId());
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_RegisterPointerDeviceNotifications)
        {
            //Windows 7
            if (!window)
            {
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return FALSE;
            }//end if (!hwnd)

            //no transform
            //inputTransform->m;
            ::SetLastError(ERROR_SUCCESS);
            return TRUE;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_RegisterPointerDeviceNotifications(window, notifyRange);
    }

     EXPORT DPI_AWARENESS_CONTEXT WINAPI  _SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT dpiContext){
#ifdef DEBUG_OUT
        if (isdp)
        {
            WCHAR Buffer[1024];
            wsprintf(Buffer, L"[%i] - farproc_SetThreadDpiAwarenessContext()", ::GetCurrentThreadId());
            ::OutputDebugString(Buffer);
        }//end if (isdp)
#endif // DEBUG_OUT

        if (!farproc_SetThreadDpiAwarenessContext)
        {
            //Windows 7
            if (!dpiContext)
            {             
                ::SetLastError(ERROR_INVALID_PARAMETER);
                return FALSE;
            }//end if (!hwnd)

            //no transform
            //inputTransform->m;
            ::SetLastError(ERROR_SUCCESS);
            return NULL;
        }//end if (!farproc_DiscardVirtualMemory)
        return farproc_SetThreadDpiAwarenessContext(dpiContext);
    }

     EXPORT HSYNTHETICPOINTERDEVICE WINAPI _CreateSyntheticPointerDevice(POINTER_INPUT_TYPE    pointerType,
         ULONG                 maxCount,
         POINTER_FEEDBACK_MODE mode) {
#ifdef DEBUG_OUT
         if (isdp)
         {
             WCHAR Buffer[1024];
             wsprintf(Buffer, L"[%i] - farproc_CreateSyntheticPointerDevice()", ::GetCurrentThreadId());
             ::OutputDebugString(Buffer);
         }//end if (isdp)
#endif // DEBUG_OUT

         if (!farproc_CreateSyntheticPointerDevice)
         {
             //Windows 7
        
             ::SetLastError(ERROR_NOT_SUPPORTED);
             return NULL;
         }//end if (!farproc_DiscardVirtualMemory)
         return farproc_CreateSyntheticPointerDevice(pointerType, maxCount, mode);
     }

     EXPORT  BOOL WINAPI _InjectSyntheticPointerInput(HSYNTHETICPOINTERDEVICE device,
         const POINTER_TYPE_INFO* pointerInfo,
         UINT32                  count) {
#ifdef DEBUG_OUT
         if (isdp)
         {
             WCHAR Buffer[1024];
             wsprintf(Buffer, L"[%i] - farproc_InjectSyntheticPointerInput()", ::GetCurrentThreadId());
             ::OutputDebugString(Buffer);
         }//end if (isdp)
#endif // DEBUG_OUT

         if (!farproc_InjectSyntheticPointerInput)
         {
             //Windows 7

             ::SetLastError(ERROR_NOT_SUPPORTED);
             return NULL;
         }//end if (!farproc_DiscardVirtualMemory)
         return farproc_InjectSyntheticPointerInput(device, pointerInfo, count);
     }

     EXPORT BOOL WINAPI _GetAutoRotationState(PAR_STATE pState)
     {
#ifdef DEBUG_OUT
         if (isdp)
         {
             WCHAR Buffer[1024];
             wsprintf(Buffer, L"[%i] - farproc_GetAutoRotationState()", ::GetCurrentThreadId());
             ::OutputDebugString(Buffer);
         }//end if (isdp)
#endif // DEBUG_OUT
         if (!farproc_GetAutoRotationState)
         {
             if (farproc_NtUserGetAutoRotationState)
                 return farproc_NtUserGetAutoRotationState(pState);

            //windows 7
             if (!pState)
             {
                 ::SetLastError(E_INVALIDARG);
                 return FALSE;
             }//end if (!pState)

             *pState = AR_NOT_SUPPORTED;
             return TRUE;
         }
         return farproc_GetAutoRotationState(pState);
     }

     EXPORT BOOL WINAPI _GetPointerFrameTouchInfo(
         UINT32  pointerId,
         UINT32* pointerCount,
         POINTER_TOUCH_INFO* touchInfo)
     {
#ifdef DEBUG_OUT
         if (isdp)
         {
             WCHAR Buffer[1024];
             wsprintf(Buffer, L"[%i] - farproc_GetPointerFrameTouchInfo()", ::GetCurrentThreadId());
             ::OutputDebugString(Buffer);
         }//end if (isdp)

#endif // DEBUG_OUT
         
             if (!farproc_GetPointerFrameTouchInfo)
             {
                 //Windows 7 
                 if (!touchInfo)
                 {
                     ::SetLastError(E_INVALIDARG);
                     return FALSE;
                 }
                 ::SetLastError(ERROR_NOT_SUPPORTED);
                 return FALSE;
             }
         return farproc_GetPointerFrameTouchInfo(pointerId, pointerCount, touchInfo);
     }

     //chrome 137
     EXPORT BOOL WINAPI _IsWindowArranged(HWND hwnd)
     {
         if (!IsWindow(hwnd))
             ::SetLastError(ERROR_INVALID_HANDLE);
         else
             ::SetLastError(ERROR_SUCCESS);
         return FALSE;
     }

     EXPORT BOOL WINAPI _SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT value)
     {
#ifdef DEBUG_OUT
         if (isdp)
         {
             WCHAR Buffer[1024];
             wsprintf(Buffer, L"[%i] - farproc_SetProcessDpiAwarenessContext(), %i", ::GetCurrentThreadId(), value);
             ::OutputDebugString(Buffer);
         }//end if (isdp)
#endif // DEBUG_OUT

         if (!farproc_SetProcessDpiAwarenessContext)
         {
             //Windows 7
             if (!value)
             {
                 ::SetLastError(ERROR_INVALID_PARAMETER);
                 return FALSE;
             }//end if (!hwnd)

             //no transform
             //inputTransform->m;
             ::SetLastError(ERROR_SUCCESS);
             return NULL;
         }
         else
             return farproc_SetProcessDpiAwarenessContext(value);
     }

     EXPORT BOOL WINAPI _SystemParametersInfoForDpi(UINT  uiAction,
         UINT  uiParam,
         PVOID pvParam,
         UINT  fWinIni,
         UINT  dpi)
     {
#ifdef DEBUG_OUT
         if (isdp)
         {
             WCHAR Buffer[1024];
             wsprintf(Buffer, L"[%i] - farproc_SystemParametersInfoForDpi(), %i %i %i", ::GetCurrentThreadId(), uiAction, uiParam, dpi);
             ::OutputDebugString(Buffer);
         }//end if (isdp)
#endif // DEBUG_OUT

         if (!farproc_SystemParametersInfoForDpi)
         {
             //Windows 7
             if (!pvParam)
             {
                 ::SetLastError(ERROR_INVALID_PARAMETER);
                 return FALSE;
             }//end if (!hwnd)

             ::SetLastError(ERROR_SUCCESS);
             return NULL;
         }
         else
             return farproc_SystemParametersInfoForDpi(uiAction, uiParam, pvParam, fWinIni, dpi);
     }

     EXPORT int WINAPI _GetSystemMetricsForDpi(int  nIndex, UINT dpi)
     {
         return ::GetSystemMetrics(nIndex);
     }

     EXPORT BOOL _AreDpiAwarenessContextsEqual(
         DPI_AWARENESS_CONTEXT dpiContextA,
         DPI_AWARENESS_CONTEXT dpiContextB
     )
     {
         if (!dpiContextA || !dpiContextB)
             return FALSE;
         return TRUE;
     }

     EXPORT DPI_AWARENESS_CONTEXT WINAPI _GetWindowDpiAwarenessContext(HWND hwnd)
     {
         if (!::IsWindow(hwnd))
             return NULL;
         return DPI_AWARENESS_CONTEXT_SYSTEM_AWARE;
     }

     EXPORT BOOL WINAPI _AdjustWindowRectExForDpi(
         LPRECT lpRect,
         DWORD  dwStyle,
         BOOL   bMenu,
         DWORD  dwExStyle,
         UINT   dpi
     ) {
         return AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);
    }
}


