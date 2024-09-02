
extern "C"
{
  void* memcpy1(void* dest, const void* src, size_t len);

  void* zeroset1(void* dest, size_t len);
  HRESULT wcscpys(wchar_t* dest, rsize_t dmax, const wchar_t* src);
  wchar_t* wcschr1(const wchar_t* s, wchar_t c);

	/*
	Requirement 	Value
	Minimum supported client 	Windows Vista with SP1 [desktop apps only]
	Minimum supported server 	Windows Server 2008 [desktop apps only]
	Target Platform 	Windows
	Header 	sysinfoapi.h (include Windows.h)
	Library 	Kernel32.lib
	DLL 	Kernel32.dll
	*/
	EXPORT BOOL WINAPI _GetPhysicallyInstalledSystemMemory(PULONGLONG TotalMemoryInKilobytes)
	{
		return  ::GetPhysicallyInstalledSystemMemory(TotalMemoryInKilobytes);
	}

	/*
	Requirement	Value
	Minimum supported client 	Windows 2000 Professional [desktop apps only]
	Minimum supported server 	Windows 2000 Server [desktop apps only]
	Target Platform 	Windows
	Header 	sysinfoapi.h (include Windows.h)
	Library 	Kernel32.lib
	DLL 	Kernel32.dll
	*/
	EXPORT BOOL WINAPI _SetSystemTimeAdjustment(DWORD dwTimeAdjustment,
		BOOL  bTimeAdjustmentDisabled) {
		return  ::SetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled);
	}
	
}
