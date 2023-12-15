//[80_PA] ELF, cracklab/exelab, 2023
#include "pch.h"
#include "d2d1.h"

#pragma comment(lib, "D2d1.lib")

//FLAG 
//#define DEBUG_OUT 1

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

//https://learn.microsoft.com/ru-ru/windows/win32/api/shtypes/ne-shtypes-device_scale_factor
typedef enum DEVICE_SCALE_FACTOR {
    DEVICE_SCALE_FACTOR_INVALID = 0,
    SCALE_100_PERCENT = 100,
    SCALE_120_PERCENT = 120,
    SCALE_125_PERCENT = 125,
    SCALE_140_PERCENT = 140,
    SCALE_150_PERCENT = 150,
    SCALE_160_PERCENT = 160,
    SCALE_175_PERCENT = 175,
    SCALE_180_PERCENT = 180,
    SCALE_200_PERCENT = 200,
    SCALE_225_PERCENT = 225,
    SCALE_250_PERCENT = 250,
    SCALE_300_PERCENT = 300,
    SCALE_350_PERCENT = 350,
    SCALE_400_PERCENT = 400,
    SCALE_450_PERCENT = 450,
    SCALE_500_PERCENT = 500
};

//https://stackoverflow.com/questions/66161063/c-windows-api-how-to-retrieve-font-scaling-percentage-on-windows-10
/*
Then, on Windows 7, you get the scaling factor using the GetDeviceCaps function with LOGPIXELSX and LOGPIXELSY, 
and dividing the result by 96 (because 96 dpi is "100%").(1) 
This will give you the DPI setting of the main monitor. 
GetDeviceCaps has been the way to get this setting since Windows XP. 
This will also do fine on Windows 10 if and only if you do not declare DPI awareness per monitor.
*/
const UINT DPI_100_PERCENT = 96;

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

__declspec(dllexport) HRESULT WINAPI GetScaleFactorForMonitor(
    HMONITOR            hMon,
    DEVICE_SCALE_FACTOR* pScale
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY GetDpiForMonitor()");
#endif // DEBUG_OUT

    //bad args
    if (!pScale)
        return ERROR_BAD_ARGUMENTS;

    //get monitor info
    MONITORINFOEX minfo;
    memset(&minfo, 0, sizeof(MONITORINFOEX));
    minfo.cbSize = sizeof(MONITORINFOEX);

    HRESULT hr = ::GetMonitorInfo(hMon, &minfo);
    if (!hr)
        return hr;
    
    HDC screen = ::CreateDC(NULL, minfo.szDevice, NULL, NULL);
        if (!screen)
            return ERROR_NOT_SUPPORTED;

    UINT dpiX = ::GetDeviceCaps(screen, LOGPIXELSX);
    UINT dpiY = ::GetDeviceCaps(screen, LOGPIXELSY);
    ReleaseDC(0, screen);

    UINT scale_factor1 = dpiX / DPI_100_PERCENT;
    UINT scale_factor2 = dpiY % DPI_100_PERCENT;

    switch (scale_factor1)
    {
    case 1:
    {
        if (!scale_factor2)
            return SCALE_100_PERCENT;

        if (scale_factor2 <= 20)
            return SCALE_120_PERCENT;

        if (scale_factor2 <= 24)
            return SCALE_125_PERCENT;

        if (scale_factor2 <= 30)
            return SCALE_140_PERCENT;

        if (scale_factor2 <= 40)
            return SCALE_150_PERCENT;

        if (scale_factor2 <= 50)
            return SCALE_160_PERCENT;

        if (scale_factor2 <= 65)
            return SCALE_175_PERCENT;

        if (scale_factor2 > 65)
            return SCALE_180_PERCENT;
    }//end case 1:

    case 2: {

        if (!scale_factor2)
            return SCALE_200_PERCENT; 

          if (scale_factor2 <= 24)
              return SCALE_225_PERCENT;

          if (scale_factor2 > 24)
              return SCALE_250_PERCENT;
        }//end case 2:
    

        case 3:
        {
            if (!scale_factor2)
                return SCALE_300_PERCENT; 
        
            return SCALE_350_PERCENT;
        }//end case 3:

        case 4: {

            if (!scale_factor2)
                return SCALE_400_PERCENT;

            return SCALE_450_PERCENT;
        }//end case 4:

        case 5: {

            if (!scale_factor2)
                return SCALE_500_PERCENT;
        }//end case 4:

    }//end switch (scale_factor1)
     
    return SCALE_100_PERCENT;
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


