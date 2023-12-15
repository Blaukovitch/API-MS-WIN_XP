#include "pch.h"


extern "C"
{
	EXPORT BOOL WINAPI _CreateEnvironmentBlock(LPVOID* lpEnvironment,
		HANDLE hToken,
		BOOL   bInherit)
	{
		return ::CreateEnvironmentBlock(lpEnvironment, hToken, bInherit);
	}

	EXPORT BOOL WINAPI _DestroyEnvironmentBlock(LPVOID lpEnvironment)
	{
		return ::DestroyEnvironmentBlock(lpEnvironment);
	}

	EXPORT HANDLE WINAPI _EnterCriticalPolicySection(BOOL bMachine)
	{
		return ::EnterCriticalPolicySection(bMachine);
	}

	EXPORT BOOL WINAPI _LeaveCriticalPolicySection(HANDLE hSection)
	{
		return ::LeaveCriticalPolicySection(hSection);
	}

	EXPORT BOOL WINAPI _RegisterGPNotification(HANDLE  hEvent,
		BOOL    bMachine)
	{
		return ::RegisterGPNotification(hEvent, bMachine);
	}

	EXPORT BOOL WINAPI _UnregisterGPNotification(HANDLE hEvent)
	{
		return ::UnregisterGPNotification(hEvent);
	}

	EXPORT BOOL WINAPI _GetUserProfileDirectoryW(HANDLE  hToken,
		LPWSTR lpProfileDir,
		LPDWORD lpcchSize)
	{
		return ::GetUserProfileDirectoryW(hToken, lpProfileDir, lpcchSize);
	}

	EXPORT BOOL WINAPI _GetProfileType(DWORD* dwFlags)
	{
		return ::GetProfileType(dwFlags);
	}


	EXPORT BOOL WINAPI _UnloadUserProfile(HANDLE  hToken,
		HANDLE  hProfile)
	{
		return ::UnloadUserProfile(hToken, hProfile);
	}
	
}