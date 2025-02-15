//[80_PA] ELF, cracklab/exelab, 2025
//FLAG 

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#include "pch.h"
#include <ole2.h>
#include <inspectable.h>
#include <Activation.h>

EXTERN_C const CLSID CLSID_fakeShellBridge1;
EXTERN_C const IID IID_IfakeShellBridge1;

typedef HINSTANCE(WINAPI api_ShellExecute32W)(
    HWND    hwnd,
    LPCWSTR lpOperation,
    LPCWSTR lpFile,
    LPCWSTR lpParameters,
    LPCWSTR lpDirectory,
    INT     nShowCmd
    );

typedef HINSTANCE(WINAPI api_ShellExecute32A)(
    HWND    hwnd,
    LPCSTR lpOperation,
    LPCSTR lpFile,
    LPCSTR lpParameters,
    LPCSTR lpDirectory,
    INT     nShowCmd
    );

/*
   interface ILauncherOptions3 : IInspectable
        {
            [propget] HRESULT IgnoreAppUriHandlers([out] [retval] boolean* value);
            [propput] HRESULT IgnoreAppUriHandlers([in] boolean value);
        }
*/
#if defined(__cplusplus)
extern "C++"
{
    MIDL_INTERFACE("F0770655-4B63-4E3A-9107-4E687841923A")
        ILauncherOptions3 : public IInspectable
    {
    public:

      virtual HRESULT STDMETHODCALLTYPE  IgnoreAppUriHandlers(boolean * value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  IgnoreAppUriHandlers(boolean value) = 0;
    };
} // extern
#endif

class __declspec(uuid("{33111111-1111-1111-1111-111111111111}")) fakeLauncherOptions31 : public ILauncherOptions3
{
public:
    STDMETHODIMP QueryInterface(REFIID riid, void** ppv)
    {
        if (NULL == ppv)
            return E_POINTER;
        if ((IID_IUnknown == riid)
            || (__uuidof(IAgileObject) == riid))
        {
            AddRef();
            *ppv = reinterpret_cast<LPVOID>(this);
            //*ppv = (fakeLauncherOptions1*)(<this>);
            return NOERROR;
        }


        return ERROR_NO_INHERITANCE;
    };

    STDMETHODIMP_(ULONG) AddRef(void) { return 0; };
    STDMETHODIMP_(ULONG) Release(void) { return 0; };


    STDMETHODIMP_(HRESULT) GetIids(
        /* [out] */ __RPC__out ULONG* iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID** iids) {
        if (iidCount)
            *iidCount = 1;
        return 1;
    };

    STDMETHODIMP_(HRESULT)GetRuntimeClassName(
        /* [out] */ __RPC__deref_out_opt HSTRING* className)
    {
        return 0;
    };

    STDMETHODIMP_(HRESULT) GetTrustLevel(
        /* [out] */ __RPC__out TrustLevel* trustLevel) {
        if (trustLevel)
            *trustLevel = FullTrust;
        return 0;
    };


    STDMETHODIMP_(HRESULT)  IgnoreAppUriHandlers(boolean* value) { return 0; };
    STDMETHODIMP_(HRESULT)  IgnoreAppUriHandlers(boolean value) { return 0; };

};


fakeLauncherOptions31 fbridge31_launhcer_options;




/////////////////////////////

/*
ILauncherOptions: IInspectable
{
    [propget] HRESULT TreatAsUntrusted([out][retval] boolean * value);
    [propput] HRESULT TreatAsUntrusted([in] boolean value);
    [propget] HRESULT DisplayApplicationPicker([out][retval] boolean* value);
    [propput] HRESULT DisplayApplicationPicker([in] boolean value);
    [propget] HRESULT UI([out][retval] Windows.System.LauncherUIOptions** value);
    [propget] HRESULT PreferredApplicationPackageFamilyName([out][retval] HSTRING* value);
    [propput] HRESULT PreferredApplicationPackageFamilyName([in] HSTRING value);
    [propget] HRESULT PreferredApplicationDisplayName([out][retval] HSTRING* value);
    [propput] HRESULT PreferredApplicationDisplayName([in] HSTRING value);
    [propget] HRESULT FallbackUri([out][retval] Windows.Foundation.Uri** value);
    [propput] HRESULT FallbackUri([in] Windows.Foundation.Uri* value);
    [propget] HRESULT ContentType([out][retval] HSTRING* value);
    [propput] HRESULT ContentType([in] HSTRING value);
}
*/
#if defined(__cplusplus)
extern "C++"
{
    MIDL_INTERFACE("BAFA21D8-B071-4CD8-853E-341203E557D3")
        ILauncherOptions : public IInspectable
    {
    public:

      virtual HRESULT STDMETHODCALLTYPE  TreatAsUntrusted(boolean * value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  TreatAsUntrusted(boolean value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  DisplayApplicationPicker(boolean* value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  DisplayApplicationPicker(boolean value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  UI(void** value) = 0; //Windows.System.LauncherUIOptions**
      virtual HRESULT STDMETHODCALLTYPE  PreferredApplicationPackageFamilyName(HSTRING* value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  PreferredApplicationPackageFamilyName(HSTRING value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  PreferredApplicationDisplayName(HSTRING* value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  PreferredApplicationDisplayName(HSTRING value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  FallbackUri(void* value) = 0; // Windows.Foundation.Uri**
      virtual HRESULT STDMETHODCALLTYPE  FallbackUri(void** value) = 0; //Windows.Foundation.Uri*
      virtual HRESULT STDMETHODCALLTYPE  ContentType(HSTRING* value) = 0;
      virtual HRESULT STDMETHODCALLTYPE  ContentType(HSTRING value) = 0;
    };
} // extern
#endif



class __declspec(uuid("{33111111-1111-1111-1111-111111111111}")) fakeLauncherOptions1 : public ILauncherOptions
{
public:
    STDMETHODIMP QueryInterface(REFIID riid, void** ppv)
    {
        if (NULL == ppv)
            return E_POINTER;
        if ((IID_IUnknown == riid)
            || (__uuidof(IAgileObject) == riid))
        {
            AddRef();
             *ppv = reinterpret_cast<LPVOID>(this);
            //*ppv = (fakeLauncherOptions1*)(<this>);
            return NOERROR;
        }

        if (riid == __uuidof(ILauncherOptions3))
            *ppv = &fbridge31_launhcer_options;
        return ERROR_NO_INHERITANCE;
    };

    STDMETHODIMP_(ULONG) AddRef(void) { return 0; };
    STDMETHODIMP_(ULONG) Release(void) { return 0; };


    STDMETHODIMP_(HRESULT) GetIids(
        /* [out] */ __RPC__out ULONG* iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID** iids) {
        if (iidCount)
            *iidCount = 1;
        return 1;
    };

    STDMETHODIMP_(HRESULT)GetRuntimeClassName(
        /* [out] */ __RPC__deref_out_opt HSTRING* className)
    {
        return 0;
    };

    STDMETHODIMP_(HRESULT) GetTrustLevel(
        /* [out] */ __RPC__out TrustLevel* trustLevel) {
        if (trustLevel)
            *trustLevel = FullTrust;
        return 0;
    };



    STDMETHODIMP_(HRESULT)  TreatAsUntrusted(boolean* value) { *value = false; return 0; };
    STDMETHODIMP_(HRESULT)  TreatAsUntrusted(boolean value) { return 0; };
    STDMETHODIMP_(HRESULT)  DisplayApplicationPicker(boolean* value) { return 0; }
    STDMETHODIMP_(HRESULT)  DisplayApplicationPicker(boolean value) { return 0; }
    STDMETHODIMP_(HRESULT)  UI(void** value) { return RPC_S_NO_INTERFACES; } //Windows.System.LauncherUIOptions**
    STDMETHODIMP_(HRESULT)  PreferredApplicationPackageFamilyName(HSTRING* value) { return RPC_S_NO_INTERFACES; }
    STDMETHODIMP_(HRESULT)  PreferredApplicationPackageFamilyName(HSTRING value) { return RPC_S_NO_INTERFACES; }
    STDMETHODIMP_(HRESULT)  PreferredApplicationDisplayName(HSTRING* value) { return RPC_S_NO_INTERFACES; }
    STDMETHODIMP_(HRESULT)  PreferredApplicationDisplayName(HSTRING value) { return RPC_S_NO_INTERFACES; }
    STDMETHODIMP_(HRESULT)  FallbackUri(void* value) { return RPC_S_NO_INTERFACES; } // Windows.Foundation.Uri**
    STDMETHODIMP_(HRESULT)  FallbackUri(void** value) { return RPC_S_NO_INTERFACES; } //Windows.Foundation.Uri*
    STDMETHODIMP_(HRESULT)  ContentType(HSTRING* value) { return RPC_S_NO_INTERFACES; }
    STDMETHODIMP_(HRESULT)  ContentType(HSTRING value) { return RPC_S_NO_INTERFACES; }

};


fakeLauncherOptions1 fbridge1_launhcer_options;

#if defined(__cplusplus)
extern "C++"
{
    MIDL_INTERFACE("44A9796F-723E-4FDF-A218-033E75B0C084")
        IUriRuntimeClassFactory : public IInspectable
    {
    public:
        //Windows.Foundation.Uri
      virtual HRESULT STDMETHODCALLTYPE CreateUri(HSTRING uri, void** instance) = 0;
      virtual HRESULT STDMETHODCALLTYPE CreateWithRelativeUri(HSTRING baseUri, HSTRING relativeUri, void** instance) = 0;
    };
} // extern
#endif
class __declspec(uuid("{11111111-1111-1111-1111-111111111111}")) fakeShellBridge1 : public IUriRuntimeClassFactory
{
public:
    // fakeShellBridge1() {};
     //virtual ~fakeShellBridge1() {};

     // IUnknown methods
    STDMETHODIMP QueryInterface(REFIID riid, void** ppv)
    {
        if (NULL == ppv)
            return E_POINTER;
        if ((IID_IUnknown == riid)
            || (__uuidof(IUriRuntimeClassFactory) == riid)
            || (__uuidof(IInspectable) == riid))
        {
            AddRef();
            *ppv = reinterpret_cast<LPVOID>(this);
            return NOERROR;
        }


        if (riid == __uuidof(ILauncherOptions))
            *ppv = &fbridge1_launhcer_options;

        return ERROR_NO_INHERITANCE;
    };

    STDMETHODIMP_(ULONG) AddRef(void) { return 0; };
    STDMETHODIMP_(ULONG) Release(void) { return 0; };

    STDMETHODIMP_(HRESULT) GetIids(
        /* [out] */ __RPC__out ULONG* iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID** iids) {
        if (iidCount)
            *iidCount = 1;
        return 1;
    };

    STDMETHODIMP_(HRESULT)GetRuntimeClassName(
        /* [out] */ __RPC__deref_out_opt HSTRING* className)
    {
        return 0;
    };

    STDMETHODIMP_(HRESULT) GetTrustLevel(
        /* [out] */ __RPC__out TrustLevel* trustLevel) {
        if (trustLevel)
            *trustLevel = FullTrust;
        return 0;
    };

    STDMETHODIMP_(HRESULT) CreateUri(HSTRING uri, void** instance)
    {
        HMODULE shell32 = ::LoadLibrary(L"shell32.dll");

        if (shell32)
        {
            api_ShellExecute32A* SEW32 = (api_ShellExecute32A*)::GetProcAddress(shell32, "ShellExecuteA");

            if (SEW32)
            {
                SEW32(NULL, "open", (LPCSTR)uri, NULL, NULL, SW_SHOWNORMAL);
                ::FreeLibrary(shell32);
            }
        }//end if (shell32)

        return 0;
    }

    STDMETHODIMP_(HRESULT) CreateWithRelativeUri(HSTRING baseUri, HSTRING relativeUri, void** instance)
    {

        return 0;
    }

};

fakeShellBridge1 fbridge1;

#define   EXPORT __declspec(dllexport) 
#define EXPORT_END _exported

const CLSID CLSID_fakeShellBridge1 = __uuidof(fakeShellBridge1);


///////////////////////////////////////////////////
/*
        [exclusiveto(Windows.System.Launcher)]
        [uuid(277151C3-9E3E-42F6-91A4-5DFDEB232451)]
        [version(0x06020000)]
        interface ILauncherStatics : IInspectable
        {
            [overload("LaunchFileAsync")] HRESULT LaunchFileAsync([in] Windows.Storage.IStorageFile* file, [out] [retval] Windows.Foundation.IAsyncOperation<boolean>** operation);
            [overload("LaunchFileAsync")] HRESULT LaunchFileWithOptionsAsync([in] Windows.Storage.IStorageFile* file, [in] Windows.System.LauncherOptions* options, [out] [retval] Windows.Foundation.IAsyncOperation<boolean>** operation);
            [overload("LaunchUriAsync")] HRESULT LaunchUriAsync([in] Windows.Foundation.Uri* uri, [out] [retval] Windows.Foundation.IAsyncOperation<boolean>** operation);
            [overload("LaunchUriAsync")] HRESULT LaunchUriWithOptionsAsync([in] Windows.Foundation.Uri* uri, [in] Windows.System.LauncherOptions* options, [out] [retval] Windows.Foundation.IAsyncOperation<boolean>** operation);
        }
*/
#if defined(__cplusplus)
extern "C++"
{
    MIDL_INTERFACE("277151C3-9E3E-42F6-91A4-5DFDEB232451")
        ILauncherStatics : public IInspectable
    {
    public:

      virtual HRESULT STDMETHODCALLTYPE TreatAsUntrusted(boolean * value) = 0;
      virtual HRESULT STDMETHODCALLTYPE LaunchFileAsync(void* file,boolean** operation) = 0; //Windows.Storage.IStorageFile* // Windows.Foundation.IAsyncOperation<boolean>**
      virtual HRESULT STDMETHODCALLTYPE LaunchFileWithOptionsAsync(void* file, void* options, boolean** operation) = 0;
      virtual HRESULT STDMETHODCALLTYPE LaunchUriAsync(void* uri, boolean** operation) = 0;
      virtual HRESULT STDMETHODCALLTYPE LaunchUriWithOptionsAsync(void* uri, void* options, boolean** operation) = 0;

    };
} // extern
#endif


class __declspec(uuid("{44111111-1111-1111-1111-111111111111}")) fakeLauncherStatics1 : public ILauncherStatics
{
public:
    STDMETHODIMP QueryInterface(REFIID riid, void** ppv)
    {
        if (NULL == ppv)
            return E_POINTER;
        if ((IID_IUnknown == riid)
            || (__uuidof(IUriRuntimeClassFactory) == riid)
            || (__uuidof(IInspectable) == riid) || (__uuidof(IAgileObject) == riid))
        {
            AddRef();
            // *ppv = reinterpret_cast<LPVOID>(this);
            *ppv = (fakeShellBridge1*)(&fbridge1);
            return NOERROR;
        }

        if (riid == __uuidof(ILauncherOptions))
            *ppv = &fbridge1_launhcer_options;
        return ERROR_NO_INHERITANCE;
    };

    STDMETHODIMP_(ULONG) AddRef(void) { return 0; };
    STDMETHODIMP_(ULONG) Release(void) { return 0; };


    STDMETHODIMP_(HRESULT) GetIids(
        /* [out] */ __RPC__out ULONG* iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID** iids) {
        if (iidCount)
            *iidCount = 1;
        return 1;
    };

    STDMETHODIMP_(HRESULT)GetRuntimeClassName(
        /* [out] */ __RPC__deref_out_opt HSTRING* className)
    {
        return 5;
    };

    STDMETHODIMP_(HRESULT) GetTrustLevel(
        /* [out] */ __RPC__out TrustLevel* trustLevel) {
        if (trustLevel)
            *trustLevel = FullTrust;
        return 6;
    };


    STDMETHODIMP_(HRESULT) TreatAsUntrusted(
        boolean* value)
    {

        return 7;
    };

    STDMETHODIMP_(HRESULT) LaunchFileAsync(
        void* file, boolean** operation)
    {
        return 8;
    };

    STDMETHODIMP_(HRESULT) LaunchFileWithOptionsAsync(
        void* file, void* options, boolean** operation)
    {
        return 9;
    };

    STDMETHODIMP_(HRESULT) LaunchUriAsync(
        void* uri, boolean** operation)
    {
        fbridge1.CreateUri((HSTRING)uri, (void**)operation);
        return 10;
    };

    STDMETHODIMP_(HRESULT) LaunchUriWithOptionsAsync(
        void* uri, void* options, boolean** operation)
    {
        return 100;
    };
};

fakeLauncherStatics1 fbridge_launcherstatic;


class __declspec(uuid("{22111111-1111-1111-1111-111111111111}")) fakeActivateFactory1 : public IActivationFactory
{
public:
    STDMETHODIMP QueryInterface(REFIID riid, void** ppv)
    {
        if (NULL == ppv)
            return E_POINTER;
        if ((IID_IUnknown == riid)
            || (__uuidof(IUriRuntimeClassFactory) == riid)
            || (__uuidof(IInspectable) == riid) || (__uuidof(IAgileObject) == riid))
        {
            AddRef();
           // *ppv = reinterpret_cast<LPVOID>(this);
            *ppv = (fakeShellBridge1*)(&fbridge1);
            return NOERROR;
        }

        if (riid == __uuidof(ILauncherOptions))
            *ppv = &fbridge1_launhcer_options;
        return ERROR_NO_INHERITANCE;
    };

    STDMETHODIMP_(ULONG) AddRef(void) { return 0; };
    STDMETHODIMP_(ULONG) Release(void) { return 0; };

    STDMETHODIMP_(HRESULT) GetIids(
        /* [out] */ __RPC__out ULONG* iidCount,
        /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID** iids) {
        if (iidCount)
            *iidCount = 1;
        return 1;
    };

    STDMETHODIMP_(HRESULT)GetRuntimeClassName(
        /* [out] */ __RPC__deref_out_opt HSTRING* className)
    {
        return 0;
    };

    STDMETHODIMP_(HRESULT) GetTrustLevel(
        /* [out] */ __RPC__out TrustLevel* trustLevel) {
        if (trustLevel)
            *trustLevel = FullTrust;
        return 0;
    };

    STDMETHODIMP_(HRESULT) ActivateInstance(
        /* [out] */ __RPC__deref_out_opt IInspectable** instance)
    {
        *instance = (fakeShellBridge1*)&fbridge_launcherstatic;
        return 0;
    }
};

fakeActivateFactory1 fbridge1_factory;


///////////////////////////////////////////
//TV
//LAUNCHER RO ACTIVATOR WINDOWS10/11 
extern "C"
{

    //#if defined(TRVIEW)
    EXPORT HRESULT WINAPI RoGetActivationFactory(
        HSTRING* activatableClassId,
        REFIID  iid,
        void** factory
    )
    {
        //IActivationFactory
        if (IsEqualIID(__uuidof(IUriRuntimeClassFactory), iid))
        {
            *factory = (fakeShellBridge1*)&fbridge1;
        }

        if (IsEqualIID(__uuidof(IActivationFactory), iid))
        {
            *factory = (IActivationFactory*)&fbridge1_factory;
        }
        
        if (IsEqualIID(__uuidof(ILauncherStatics), iid))
        {
            *factory = (ILauncherStatics*)&fbridge_launcherstatic;
        }


        return ERROR_SUCCESS;
    }
    //#endif 
}


