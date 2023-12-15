//[80_PA] ELF, cracklab/exelab, 2023
//FLAG

extern "C"
{

	//DEFAULT 7
	EXPORT void WINAPI _DsRoleFreeMemory(PVOID    Buffer)
	{
		return ::DsRoleFreeMemory(Buffer);
	}

	EXPORT DWORD WINAPI _DsRoleGetPrimaryDomainInformation(LPCWSTR lpServer,
		DSROLE_PRIMARY_DOMAIN_INFO_LEVEL InfoLevel,
		PBYTE* Buffer)
	{
		return ::DsRoleGetPrimaryDomainInformation(lpServer, InfoLevel, Buffer);
	}

	EXPORT DWORD WINAPI _NetApiBufferFree(LPVOID Buffer)
	{
		return ::NetApiBufferFree(Buffer);
	}

	EXPORT int WINAPI _NetGetJoinInformation(LPCWSTR             lpServer,
		LPWSTR* lpNameBuffer,
		PNETSETUP_JOIN_STATUS  BufferType)
	{
		return ::NetGetJoinInformation(lpServer, lpNameBuffer, BufferType);
	}

	EXPORT DWORD WINAPI _NetUserGetInfo(LPCWSTR     servername ,
		LPCWSTR     username,
		DWORD      level,
		LPBYTE* bufptr)
	{
		return ::NetUserGetInfo(servername, username, level, bufptr);
	}
}
