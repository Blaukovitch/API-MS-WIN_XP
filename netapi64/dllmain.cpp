//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 
//#define DEBUG_OUT 1


// ------ globals ------ 
BOOL isdp = false;

#pragma code_seg(push, ".text$000004")
const TCHAR WIDE_NETAPI32DLL[] = L"netapi32.dll";
const char A_NFAJI[] = "NetFreeAadJoinInformation";
const char A_NGAJI[] = "NetGetAadJoinInformation";
const char A_FREE[] = "free";
const TCHAR WIDE_RUNTIMEVCDLL[] = L"msvcrt.dll";
#pragma code_seg(pop)
// ----- ABSENT AP -----
HMODULE pNetapi32;
HMODULE pRuntime;

typedef VOID(WINAPI api_NetFreeAadJoinInformation)(
    PDSREG_JOIN_INFO pJoinInfo
    );

typedef HRESULT(WINAPI api_NetGetAadJoinInformation)(
    LPCWSTR          pcszTenantId,
    PDSREG_JOIN_INFO* ppJoinInfo
    );

typedef void(WINAPI api_free)(
    void* Block
    );

api_NetFreeAadJoinInformation* farproc_NetFreeAadJoinInformation = 0;
api_NetGetAadJoinInformation* farproc_api_NetGetAadJoinInformation = 0;
api_free* farproc_free = 0;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {

        if (!pNetapi32)
        {
            pNetapi32 = ::GetModuleHandle(WIDE_NETAPI32DLL);
            pRuntime = ::GetModuleHandle(WIDE_RUNTIMEVCDLL);
            if (pNetapi32 && pRuntime)
            {
                farproc_NetFreeAadJoinInformation = (api_NetFreeAadJoinInformation*)::GetProcAddress(pNetapi32, A_NFAJI);
                farproc_api_NetGetAadJoinInformation = (api_NetGetAadJoinInformation*)::GetProcAddress(pNetapi32, A_NGAJI);
            }//end  if (!pNetapi32)
        }//end pNetapi32
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

    void free_userinfo(DSREG_USER_INFO* pUserInfo);
    /*
Минимальная версия клиента 	Windows 10 [только классические приложения]
Минимальная версия сервера 	Windows Server 2016 [только классические приложения]
Целевая платформа 	Windows
Header 	lmjoin.h
Библиотека 	Netapi32.lib
DLL 	Netapi32.dll
    */
    EXPORT VOID WINAPI _NetFreeAadJoinInformation(PDSREG_JOIN_INFO pJoinInfo)
    {
        if (!farproc_NetFreeAadJoinInformation)
        {
            //Windows 7

            /*
Минимальная версия клиента 	Windows XP [классические приложения | Приложения UWP]
Минимальная версия сервера 	Windows Server 2003 [классические приложения | Приложения UWP]
Целевая платформа 	Windows
Header 	wincrypt.h
Библиотека 	Crypt32.lib
DLL 	Crypt32.dll
            */
            if(pJoinInfo)
            {
                ::CertFreeCertificateContext(pJoinInfo->pJoinCertificate);
                pJoinInfo->pJoinCertificate = 0;

                if (farproc_free)
                {
                    farproc_free(pJoinInfo->pszDeviceId);
                    pJoinInfo->pszDeviceId = 0;
                    farproc_free(pJoinInfo->pszIdpDomain);
                    pJoinInfo->pszIdpDomain = 0;
                    farproc_free(pJoinInfo->pszTenantId);
                    pJoinInfo->pszTenantId = 0;
                    farproc_free(pJoinInfo->pszJoinUserEmail);
                    pJoinInfo->pszJoinUserEmail = 0;
                    farproc_free(pJoinInfo->pszTenantDisplayName);
                    pJoinInfo->pszTenantDisplayName = 0;
                    farproc_free(pJoinInfo->pszMdmEnrollmentUrl);
                    pJoinInfo->pszMdmEnrollmentUrl = 0;
                    farproc_free(pJoinInfo->pszMdmTermsOfUseUrl);
                    pJoinInfo->pszMdmTermsOfUseUrl = 0;
                    farproc_free(pJoinInfo->pszMdmComplianceUrl);
                    pJoinInfo->pszMdmComplianceUrl = 0;
                    farproc_free(pJoinInfo->pszUserSettingSyncUrl);
                    pJoinInfo->pszUserSettingSyncUrl = 0;

                    free_userinfo(pJoinInfo->pUserInfo);

                    farproc_free(pJoinInfo->pUserInfo);
                    pJoinInfo->pUserInfo = 0;
                    farproc_free(pJoinInfo);
                }//end if (farproc_free)
                
            }//end if(pJoinInfo)
        }
        else
            return farproc_NetFreeAadJoinInformation(pJoinInfo);
    }

void free_userinfo(DSREG_USER_INFO* pUserInfo)
{
    if (pUserInfo && farproc_free)
    {
        farproc_free(pUserInfo->pszUserEmail);
        farproc_free(pUserInfo->pszUserKeyId);
        farproc_free(pUserInfo->pszUserKeyName);
        pUserInfo->pszUserEmail = 0;
        pUserInfo->pszUserKeyId = 0;
        pUserInfo->pszUserKeyName = 0;
    }//end if (pUserInfo / farproc_free)
}
    /*
    
 .text:4CA0C18A ; Exported entry 130. NetFreeAadJoinInformation
.text:4CA0C18A                 public NetFreeAadJoinInformation
.text:4CA0C18A NetFreeAadJoinInformation db 'DSREG.DsrFreeJoinInfo',0
.text:4CA0C18A                                         ; DATA XREF: .text:off_4CA09DF8↑o
.text:4CA0C1A0 aNetgetaadjoini db 'NetGetAadJoinInformation',0
.text:4CA0C1A0                                         ; DATA XREF: .text:off_4CA0A298↑o
.text:4CA0C1B9 ; Exported entry 131. NetGetAadJoinInformation
.text:4CA0C1B9                 public NetGetAadJoinInformation
.text:4CA0C1B9 NetGetAadJoinInformation db 'DSREG.DsrGetJoinInfo',0
    */

    EXPORT HRESULT WINAPI _NetGetAadJoinInformation(LPCWSTR          pcszTenantId,
        PDSREG_JOIN_INFO* ppJoinInfo)
    {
        if (!farproc_api_NetGetAadJoinInformation)
        {
            //Windows 7

            return ERROR_NOT_CONNECTED;
        }
        else
            return farproc_api_NetGetAadJoinInformation(pcszTenantId, ppJoinInfo);
    }
}
