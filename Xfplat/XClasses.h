//[80_PA] ELF, cracklab/exelab, 2023
//FLAG
#pragma once

class XDVM : public IMFDXGIDeviceManager
{
	public:
        XDVM() { _i_ref = 1; };
        virtual ~XDVM() {};
        
        // IUnknown methods
        STDMETHODIMP QueryInterface(REFIID riid, void** ppv)
        {
            if (NULL == ppv)
                return E_POINTER;
            if ((IID_IUnknown == riid)
                || (IID_IMFDXGIDeviceManager == riid))
            {
                AddRef();
                *ppv = reinterpret_cast<LPVOID>(this);
                return ERROR_SUCCESS;
            }
         //   return _p_instance->QueryInterface(riid, ppv);
        };

        STDMETHODIMP_(ULONG) AddRef(void) { return ::InterlockedIncrement((LONG*)&_i_ref); };
        STDMETHODIMP_(ULONG) Release(void) {
            if (!::InterlockedDecrement((LONG*)&_i_ref))
            {
                delete this;
                return 0;
            }
            return _i_ref;
        };

        STDMETHODIMP CloseDeviceHandle(
            /* [annotation] */
            HANDLE hDevice) {
            return ERROR_SUCCESS;
        };

        STDMETHODIMP GetVideoService(
            /* [annotation] */
            HANDLE hDevice,
            /* [annotation] */
            REFIID riid,
            /* [annotation] */
            void** ppService) {
        //D3D11On12CreateDevice
            return ERROR_NOT_FOUND;
        };

        STDMETHODIMP LockDevice(
            /* [annotation] */
            HANDLE hDevice,
            /* [annotation] */
            REFIID riid,
            /* [annotation] */
            void** ppUnkDevice,
            /* [annotation] */
            BOOL fBlock) {
            return ERROR_SUCCESS;
        };

        STDMETHODIMP OpenDeviceHandle(
            /* [annotation] */
            HANDLE* phDevice) {
            return ERROR_NOT_FOUND;
        };

        STDMETHODIMP ResetDevice(
            /* [annotation] */
            IUnknown* pUnkDevice,
            /* [annotation] */
            UINT resetToken) {
            return ERROR_SUCCESS;
        };

        STDMETHODIMP TestDevice(
            /* [annotation] */
            HANDLE hDevice) {
            return ERROR_SUCCESS;};

        STDMETHODIMP UnlockDevice(
            /* [annotation] */
            HANDLE hDevice,
            /* [annotation] */
            BOOL fSaveState) {
            return ERROR_SUCCESS;};

private:
    ULONG _i_ref;
};
