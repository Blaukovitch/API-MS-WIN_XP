//[80_PA] ELF, cracklab/exelab, 2023
//FLAG


//FPLAT
extern "C"
{
	//DEFAULT 7
	EXPORT HRESULT WINAPI _MFCreateAlignedMemoryBuffer(DWORD  cbMaxLength,
		DWORD                      cbAligment,
		IMFMediaBuffer** ppBuffer)
	{
		return  ::MFCreateAlignedMemoryBuffer(cbMaxLength, cbAligment, ppBuffer);
	}

	EXPORT HRESULT WINAPI _MFCreateAsyncResult(IUnknown* punkObject,
		IMFAsyncCallback* pCallback,
		IUnknown* punkState,
		IMFAsyncResult** ppAsyncResult)
	{
		return  ::MFCreateAsyncResult(punkObject,
			pCallback,
			punkState,
			ppAsyncResult);
	}

	EXPORT HRESULT WINAPI _MFCreateAttributes(IMFAttributes** ppMFAttributes,
		UINT32          cInitialSize)
	{
		return  ::MFCreateAttributes(ppMFAttributes,
			cInitialSize);
	}

	EXPORT HRESULT WINAPI _MFCreateEventQueue(IMFMediaEventQueue** ppMediaEventQueue)
	{
		return  ::MFCreateEventQueue(ppMediaEventQueue);
	}

	EXPORT HRESULT WINAPI _MFCreateMediaBufferWrapper(IMFMediaBuffer* pBuffer,
		DWORD                      cbOffset,
		DWORD                      dwLength,
		IMFMediaBuffer** ppBuffer)
	{
		return  ::MFCreateMediaBufferWrapper(pBuffer,
			cbOffset,
			dwLength,
			ppBuffer);
	}

	EXPORT HRESULT WINAPI _MFCreateMediaEvent(MediaEventType met,
		REFGUID guidExtendedType,
		HRESULT hrStatus,
		const PROPVARIANT* pvValue,
		IMFMediaEvent** ppEvent)
	{
		return  ::MFCreateMediaEvent(met,
			guidExtendedType,
			hrStatus,
			pvValue,
			ppEvent);
	}

	EXPORT HRESULT WINAPI _MFCreateMediaType(IMFMediaType** ppMFType)
	{
		return  ::MFCreateMediaType(ppMFType);
	}

	EXPORT HRESULT WINAPI _MFCreateMemoryBuffer(DWORD                      cbMaxLength,
		IMFMediaBuffer** ppBuffer)
	{
		return  ::MFCreateMemoryBuffer(cbMaxLength, ppBuffer);
	}

	/*
	This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

    Windows XP with Service Pack 2 (SP2) and later.
    Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

Requirements
  	 
Minimum supported client 	Windows Vista [desktop apps | UWP apps]
Minimum supported server 	Windows Server 2008 [desktop apps | UWP apps]
Target Platform 	Windows
Header 	mfidl.h
Library 	Mfplat.lib
DLL 	Mfplat.dll
	*/
	EXPORT HRESULT WINAPI _MFCreatePresentationDescriptor(DWORD cStreamDescriptors,
		IMFStreamDescriptor** apStreamDescriptors,
		IMFPresentationDescriptor** ppPresentationDescriptor)
	{
		return  ::MFCreatePresentationDescriptor(cStreamDescriptors, apStreamDescriptors, ppPresentationDescriptor);
	}

	EXPORT HRESULT WINAPI _MFCreateSample(IMFSample** ppIMFSample)
	{
		return  ::MFCreateSample(ppIMFSample);
	}

	EXPORT HRESULT WINAPI _MFCreateStreamDescriptor(DWORD dwStreamIdentifier,
		DWORD cMediaTypes,
		IMFMediaType** apMediaTypes,
		IMFStreamDescriptor** ppDescriptor)
	{
		return  ::MFCreateStreamDescriptor(dwStreamIdentifier, cMediaTypes, apMediaTypes, ppDescriptor);
	}

	EXPORT HRESULT WINAPI _MFCreateWaveFormatExFromMFMediaType(IMFMediaType* pMFType,
		WAVEFORMATEX** ppWF,
		UINT32* pcbSize,
		UINT32  Flags)
	{
		return  ::MFCreateWaveFormatExFromMFMediaType(pMFType, ppWF, pcbSize, Flags);
	}

	EXPORT HRESULT WINAPI _MFFrameRateToAverageTimePerFrame(UINT32                  unNumerator,
		UINT32                  unDenominator,
		UINT64* punAverageTimePerFrame)
	{
		return  ::MFFrameRateToAverageTimePerFrame(unNumerator, unDenominator, punAverageTimePerFrame);
	}

	EXPORT HRESULT WINAPI _MFInitMediaTypeFromWaveFormatEx(IMFMediaType* pMFType,
		const WAVEFORMATEX* pWaveFormat,
		UINT32                  cbBufSize)
	{
		return  ::MFInitMediaTypeFromWaveFormatEx(pMFType, pWaveFormat, cbBufSize);
	}


	EXPORT HRESULT WINAPI _MFShutdown(VOID)
	{
		return  ::MFShutdown();
	}

	EXPORT HRESULT WINAPI _MFStartup(ULONG Version, DWORD dwFlags)
	{
		return  ::MFStartup(Version, dwFlags);
	}

	EXPORT HRESULT WINAPI _MFTEnumEx(GUID                            guidCategory,
		UINT32                          Flags,
		const MFT_REGISTER_TYPE_INFO* pInputType,
		const MFT_REGISTER_TYPE_INFO* pOutputType,
		IMFActivate*** pppMFTActivate,
		UINT32* pnumMFTActivate)
	{
		return  ::MFTEnumEx(guidCategory, Flags, pInputType, pOutputType, pppMFTActivate, pnumMFTActivate);
	}

	EXPORT HRESULT WINAPI _MFSerializeAttributesToStream(IMFAttributes* pAttr,
		DWORD dwOptions,
		IStream* pStm)
	{
		return  ::MFSerializeAttributesToStream(pAttr,
			dwOptions,
			 pStm);
		
	}
}
