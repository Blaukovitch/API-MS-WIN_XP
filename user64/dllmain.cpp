//[80_PA] ELF, cracklab/exelab, 2023
//FLAG
//#define DEBUG_OUT 1


// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_USER32DLL[] = L"user32.dll";
const TCHAR WIDE_PPROWDLL[] = L"powrprof.dll";
const char A_GPPI[] = "GetPointerPenInfo";
const char A_GPT[] = "GetPointerType";
const char A_RSRN[] = "RegisterSuspendResumeNotification";
const char A_USRN[] = "UnregisterSuspendResumeNotification";
const char A_POWRRSRN[] = "PowerRegisterSuspendResumeNotification";
const char A_POWRURSRN[] = "PowerUnregisterSuspendResumeNotification";
const char A_GDPIFW[] = "GetDpiForWindow";
const char A_PTLPPMDPI[] = "PhysicalToLogicalPointForPerMonitorDPI";
const char A_GPITR[] = "GetPointerInputTransform";


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

api_GetPointerPenInfo* farproc_GetPointerPenInfo = 0;
api_GetPointerType* farproc_GetPointerType = 0;
api_RegisterSuspendResumeNotification* farproc_RegisterSuspendResumeNotification = 0;
api_UnregisterSuspendResumeNotification* farproc_UnregisterSuspendResumeNotification = 0;
api_PowerRegisterSuspendResumeNotification* farproc_PowerRegisterSuspendResumeNotification = 0;
api_PowerUnregisterSuspendResumeNotification* farproc_PowerUnregisterSuspendResumeNotification = 0;
api_GetDpiForWindow* farproc_GetDpiForWindow = 0;
api_PhysicalToLogicalPointForPerMonitorDPI* farproc_PhysicalToLogicalPointForPerMonitorDPI = 0;
api_GetPointerInputTransform* farproc_GetPointerInputTransform = 0;

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

            pUser32 = ::GetModuleHandle(WIDE_USER32DLL);
            pPPow = ::GetModuleHandle(WIDE_PPROWDLL);
            if (pUser32 && pPPow)
            {
                farproc_GetPointerPenInfo = (api_GetPointerPenInfo*)::GetProcAddress(pUser32, A_GPPI);
                farproc_GetPointerType = (api_GetPointerType*)::GetProcAddress(pUser32, A_GPT);
                farproc_RegisterSuspendResumeNotification = (api_RegisterSuspendResumeNotification*)::GetProcAddress(pUser32, A_RSRN);
                farproc_UnregisterSuspendResumeNotification = (api_UnregisterSuspendResumeNotification*)::GetProcAddress(pUser32, A_USRN);
                farproc_GetDpiForWindow = (api_GetDpiForWindow*)::GetProcAddress(pUser32, A_GDPIFW);
                farproc_PhysicalToLogicalPointForPerMonitorDPI = (api_PhysicalToLogicalPointForPerMonitorDPI*)::GetProcAddress(pUser32, A_PTLPPMDPI);
                farproc_GetPointerInputTransform = (api_GetPointerInputTransform*)::GetProcAddress(pUser32, A_GPITR);

                farproc_PowerRegisterSuspendResumeNotification = (api_PowerRegisterSuspendResumeNotification*)::GetProcAddress(pPPow, A_POWRRSRN);
                farproc_PowerUnregisterSuspendResumeNotification = (api_PowerUnregisterSuspendResumeNotification*)::GetProcAddress(pPPow, A_POWRURSRN);
                
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

            HRESULT hr = ::GetMonitorInfo(hMon, &minfo);
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

            HRESULT hr = ::GetMonitorInfo(hMon, &minfo);
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

}
