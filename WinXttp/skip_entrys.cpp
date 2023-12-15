//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 

extern "C"
{
    EXPORT BOOL WINAPI  _WinHttpCloseHandle(HINTERNET hInternet) {
        return ::WinHttpCloseHandle(hInternet);
    }

    EXPORT BOOL WINAPI  _WinHttpGetIEProxyConfigForCurrentUser(WINHTTP_CURRENT_USER_IE_PROXY_CONFIG* pProxyConfig) {
        return ::WinHttpGetIEProxyConfigForCurrentUser(pProxyConfig);
    }

    EXPORT BOOL WINAPI  _WinHttpGetProxyForUrl(HINTERNET                   hSession,
        LPCWSTR                     lpcwszUrl,
        WINHTTP_AUTOPROXY_OPTIONS* pAutoProxyOptions,
        WINHTTP_PROXY_INFO* pProxyInfo) {
        return ::WinHttpGetProxyForUrl(hSession, lpcwszUrl, pAutoProxyOptions, pProxyInfo);
    }

    EXPORT HINTERNET WINAPI  _WinHttpOpen(LPCWSTR pszAgentW,
        DWORD dwAccessType,
        LPCWSTR pszProxyW,
        LPCWSTR pszProxyBypassW,
        DWORD dwFlags) {
        return ::WinHttpOpen(pszAgentW,
            dwAccessType,
            pszProxyW,
            pszProxyBypassW,
            dwFlags);
    }

    EXPORT WINHTTP_STATUS_CALLBACK WINAPI  _WinHttpSetStatusCallback(HINTERNET hInternet,
        WINHTTP_STATUS_CALLBACK lpfnInternetCallback,
        DWORD dwNotificationFlags,
        DWORD_PTR dwReserved) {
        return ::WinHttpSetStatusCallback(hInternet,
            lpfnInternetCallback,
            dwNotificationFlags,
            dwReserved);
    }

    EXPORT BOOL WINAPI  _WinHttpSetTimeouts(HINTERNET    hInternet,           // Session/Request handle.
        int          nResolveTimeout,
        int          nConnectTimeout,
        int          nSendTimeout,
        int          nReceiveTimeout) {
        return ::WinHttpSetTimeouts(hInternet,           // Session/Request handle.
            nResolveTimeout,
            nConnectTimeout,
            nSendTimeout,
            nReceiveTimeout);
    }

    EXPORT BOOL WINAPI  _WinHttpAddRequestHeaders(HINTERNET hRequest,
        LPCWSTR lpszHeaders,
        DWORD dwHeadersLength,
        DWORD dwModifiers) {
        return ::WinHttpAddRequestHeaders(hRequest,
            lpszHeaders,
            dwHeadersLength,
            dwModifiers);
    }

    EXPORT HINTERNET WINAPI  _WinHttpConnect(HINTERNET hSession,
        LPCWSTR pswzServerName,
        INTERNET_PORT nServerPort,
        DWORD dwReserved) {
        return ::WinHttpConnect(hSession,
            pswzServerName,
            nServerPort,
            dwReserved);
    }

    EXPORT HINTERNET WINAPI  _WinHttpOpenRequest(HINTERNET hConnect,
        LPCWSTR pwszVerb,
        LPCWSTR pwszObjectName,
        LPCWSTR pwszVersion,
        LPCWSTR pwszReferrer,
        LPCWSTR FAR* ppwszAcceptTypes,
        DWORD dwFlags) {
        return ::WinHttpOpenRequest(hConnect,
            pwszVerb,
            pwszObjectName,
            pwszVersion,
            pwszReferrer,
            ppwszAcceptTypes,
            dwFlags);
    }
    
    EXPORT BOOL WINAPI  _WinHttpQueryHeaders(HINTERNET hRequest,
        DWORD     dwInfoLevel,
        LPCWSTR   pwszName,
        LPVOID lpBuffer,
        LPDWORD   lpdwBufferLength,
        LPDWORD   lpdwIndex) {
        return ::WinHttpQueryHeaders(hRequest,
            dwInfoLevel,
            pwszName,
            lpBuffer,
            lpdwBufferLength,
            lpdwIndex);
    }

    EXPORT BOOL WINAPI  _WinHttpReadData(HINTERNET hRequest,
        LPVOID lpBuffer,
        DWORD dwNumberOfBytesToRead,
        LPDWORD lpdwNumberOfBytesRead) {
        return ::WinHttpReadData(hRequest,
            lpBuffer,
            dwNumberOfBytesToRead,
            lpdwNumberOfBytesRead);
    }

    EXPORT BOOL WINAPI  _WinHttpReceiveResponse(HINTERNET hRequest,
        LPVOID lpReserved) {
        return ::WinHttpReceiveResponse(hRequest,
            lpReserved);
    }
    
    EXPORT BOOL WINAPI  _WinHttpSendRequest(HINTERNET hRequest,
        LPCWSTR lpszHeaders,
        DWORD dwHeadersLength,
        LPVOID lpOptional,
        DWORD dwOptionalLength,
        DWORD dwTotalLength,
        DWORD_PTR dwContext) {
        return ::WinHttpSendRequest(hRequest,
            lpszHeaders,
            dwHeadersLength,
            lpOptional,
            dwOptionalLength,
            dwTotalLength,
            dwContext);
    }

    EXPORT BOOL WINAPI  _WinHttpSetOption(HINTERNET hInternet,
        DWORD dwOption,
        LPVOID lpBuffer,
        DWORD dwBufferLength) {
        return ::WinHttpSetOption(hInternet,
            dwOption,
            lpBuffer,
            dwBufferLength);
    }

    EXPORT BOOL WINAPI  _WinHttpCrackUrl(LPCWSTR pwszUrl,
        DWORD dwUrlLength,
        DWORD dwFlags,
        LPURL_COMPONENTS lpUrlComponents) {
        return ::WinHttpCrackUrl(pwszUrl,
            dwUrlLength,
            dwFlags,
            lpUrlComponents);
    }

    EXPORT BOOL WINAPI  _WinHttpWriteData(HINTERNET hRequest,
        LPCVOID lpBuffer,
        DWORD dwNumberOfBytesToWrite,
        LPDWORD lpdwNumberOfBytesWritten) {
        return ::WinHttpWriteData(hRequest,
            lpBuffer,
            dwNumberOfBytesToWrite,
            lpdwNumberOfBytesWritten);
    }
    /*
    EXPORT BOOL WINAPI  _WinHttpCrackUrl(LPCWSTR pwszUrl,
        DWORD dwUrlLength,
        DWORD dwFlags,
        LPURL_COMPONENTS lpUrlComponents) {
        return ::WinHttpCrackUrl(pwszUrl,
            dwUrlLength,
            dwFlags,
            lpUrlComponents);
    }
    */
}
