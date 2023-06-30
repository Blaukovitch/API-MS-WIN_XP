//[80_PA] ELF, cracklab/exelab, 2023
/*
#include "d2d1.h"

#pragma comment(lib, "D2d1.lib")
*/
//FLAG 
#define DEBUG_OUT 1

// ------ new ENUMS ------ 

//https://learn.microsoft.com/en-us/windows/win32/api/shellscalingapi/ne-shellscalingapi-monitor_dpi_type
typedef enum MONITOR_DPI_TYPE {
    MDT_EFFECTIVE_DPI = 0,
    MDT_ANGULAR_DPI = 1,
    MDT_RAW_DPI = 2,
    MDT_DEFAULT
};

//https://learn.microsoft.com/en-us/windows/win32/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness
typedef enum PROCESS_DPI_AWARENESS {
    PROCESS_DPI_UNAWARE = 0,
    PROCESS_SYSTEM_DPI_AWARE = 1,
    PROCESS_PER_MONITOR_DPI_AWARE = 2
};

// ------ subs ------ 
UINT FloatToUINT(FLOAT float_val);


// ------ globals ------ 
BOOL isdp = false;
WCHAR Buffer[1024];


// ------ DLLMAIN ------ 
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    {
#ifdef DEBUG_OUT
        //for OUTPUT DEBUG STRINGS (if needed)
        isdp = ::IsDebuggerPresent();
#endif // DEBUG_OUT
        break; }
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
        
    }
    return TRUE;
}

__declspec(dllexport) HRESULT WINAPI GetDpiForMonitor(
   HMONITOR         hmonitor,
   MONITOR_DPI_TYPE dpiType,
   UINT* dpiX,
   UINT* dpiY
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY GetDpiForMonitor()");
#endif // DEBUG_OUT

    //bad args
    if (!dpiX || !dpiY)
        return ERROR_BAD_ARGUMENTS;

    //get monitor info
    MONITORINFOEX minfo;
    memset(&minfo, 0, sizeof(MONITORINFOEX));
    minfo.cbSize = sizeof(MONITORINFOEX);

    HRESULT hr = ::GetMonitorInfo(hmonitor, &minfo);
    if (!hr)
        return hr;
    
    HDC screen = ::CreateDC(NULL, minfo.szDevice, NULL, NULL);
        if (!screen)
            return ERROR_NOT_SUPPORTED;

    *dpiX = ::GetDeviceCaps(screen, LOGPIXELSX);
    *dpiY = ::GetDeviceCaps(screen, LOGPIXELSY);
    ReleaseDC(0, screen);

    return ERROR_SUCCESS;
}


__declspec(dllexport) HRESULT WINAPI SetProcessDpiAwareness(
    PROCESS_DPI_AWARENESS value
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY SetProcessDpiAwareness()");
#endif // DEBUG_OUT
   return  SetProcessDPIAware();
}


//local
__inline UINT FloatToUINT(FLOAT float_val)
{
    UINT int_val = 0;
    if (float_val < -40.0f)
    {
        int_val = 0;
    }
    else if (float_val > 120.0f)
    {
        int_val = 0xFFFF;
    }
    else
    {
        int_val = (UINT16)((float_val + 40.0f) / 160.0f * (float)0xFFFF); //uint16_t
    }
    return int_val;
}

