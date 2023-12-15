//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 

// ----- ABSENT AP -----
HMODULE pWinhttp = 0;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_WINHTTP[] = L"WINHTTP.DLL";
const char A_WinHTTPCPR[] = "WinHttpCreateProxyResolver";
const char A_WinHTTPFPR[] = "WinHttpFreeProxyResult";
const char A_WinHTTPGPUEx[] = "WinHttpGetProxyForUrlEx";
const char A_WinHTTPGPR[] = "WinHttpGetProxyResult";
#pragma code_seg(pop)

typedef DWORD(WINAPI api_WinHttpCreateProxyResolver)(
        HINTERNET hSession,
        HINTERNET* phResolver
    );

typedef VOID(WINAPI api_WinHttpFreeProxyResult)(
    WINHTTP_PROXY_RESULT* pProxyResult
);

typedef DWORD(WINAPI api_WinHttpGetProxyForUrlEx)(
    HINTERNET hResolver,
    PCWSTR pcwszUrl,
    WINHTTP_AUTOPROXY_OPTIONS* pAutoProxyOptions,
    DWORD_PTR pContext
    );

typedef DWORD(WINAPI api_WinHttpGetProxyResult)(
    HINTERNET hResolver,
    WINHTTP_PROXY_RESULT* pProxyResult
);

api_WinHttpCreateProxyResolver* farproc_WinHttpCreateProxyResolver = 0;
api_WinHttpFreeProxyResult* farproc_WinHttpFreeProxyResult = 0;
api_WinHttpGetProxyForUrlEx* farproc_WinHttpGetProxyForUrlEx = 0;
api_WinHttpGetProxyResult* farproc_WinHttpGetProxyResult = 0;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {

        if(!pWinhttp)
        {
            pWinhttp = ::GetModuleHandle(WIDE_WINHTTP);

            if(pWinhttp)
            {
                farproc_WinHttpCreateProxyResolver = (api_WinHttpCreateProxyResolver*)::GetProcAddress(pWinhttp, A_WinHTTPCPR);
                farproc_WinHttpFreeProxyResult = (api_WinHttpFreeProxyResult*)::GetProcAddress(pWinhttp, A_WinHTTPFPR);
                farproc_WinHttpGetProxyForUrlEx = (api_WinHttpGetProxyForUrlEx*)::GetProcAddress(pWinhttp, A_WinHTTPGPUEx);
                farproc_WinHttpGetProxyResult = (api_WinHttpGetProxyResult*)::GetProcAddress(pWinhttp, A_WinHTTPGPR);
                
            }//end if(pWinhttp)
        }//end if(!pWinhttp)

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
Минимальная версия клиента 	Windows 8 [только классические приложения]
Минимальная версия сервера 	Windows Server 2012 [только классические приложения]
Целевая платформа 	Windows
Header 	winhttp.h
Библиотека 	Winhttp.lib
DLL 	Winhttp.dll
    */

    EXPORT DWORD WINAPI _WinHttpCreateProxyResolver(HINTERNET hSession,
        HINTERNET* phResolver)
    {
        if(!farproc_WinHttpCreateProxyResolver)
        {
            ::SetLastError(E_NOTIMPL);
            return E_NOTIMPL;
        }
        else
            return farproc_WinHttpCreateProxyResolver(hSession, phResolver);
    }

    EXPORT VOID WINAPI _WinHttpFreeProxyResult(WINHTTP_PROXY_RESULT* pProxyResult)
    {
        if (!farproc_WinHttpFreeProxyResult)
        {
            ::SetLastError(E_NOTIMPL);
            return;
        }
        else
            return farproc_WinHttpFreeProxyResult(pProxyResult);
    }

    EXPORT DWORD WINAPI _WinHttpGetProxyForUrlEx(HINTERNET hResolver,
        PCWSTR pcwszUrl,
        WINHTTP_AUTOPROXY_OPTIONS* pAutoProxyOptions,
        DWORD_PTR pContext)
    {
        if (!farproc_WinHttpGetProxyForUrlEx)
        {
            ::SetLastError(E_NOTIMPL);
            return E_NOTIMPL;
        }
        else
            return farproc_WinHttpGetProxyForUrlEx(hResolver, pcwszUrl, pAutoProxyOptions, pContext);
    }

    EXPORT DWORD WINAPI _WinHttpGetProxyResult(HINTERNET hResolver,
        WINHTTP_PROXY_RESULT* pProxyResult)
    {
        if (!farproc_WinHttpGetProxyForUrlEx)
        {
            ::SetLastError(E_NOTIMPL);
            return E_NOTIMPL;
        }
        else
            return farproc_WinHttpGetProxyResult(hResolver, pProxyResult);
    }


    
}
