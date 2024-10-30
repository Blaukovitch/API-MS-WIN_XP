//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 



//379
extern "C"
{

//DEFAULT 7
EXPORT void WINAPI _AcquireSRWLockExclusive(PSRWLOCK SRWLock)
{
    return  ::AcquireSRWLockExclusive(SRWLock);
}

EXPORT void WINAPI _AcquireSRWLockShared(PSRWLOCK SRWLock)
{
    return  ::AcquireSRWLockShared(SRWLock);
}

EXPORT PVOID WINAPI _AddVectoredExceptionHandler(
    ULONG                       First,
    PVECTORED_EXCEPTION_HANDLER Handler
)
{
    return ::AddVectoredExceptionHandler(First, Handler);
}

EXPORT BOOL WINAPI _AllocConsole(void) {
    return ::AllocConsole();
}

EXPORT BOOL WINAPI _AreFileApisANSI(void) {
    return ::AreFileApisANSI();
}

EXPORT BOOL WINAPI _AssignProcessToJobObject(HANDLE hJob, HANDLE hProcess) {
    return ::AssignProcessToJobObject(hJob, hProcess);
}

EXPORT BOOL WINAPI _AttachConsole(DWORD dwProcessId) {
    return ::AttachConsole(dwProcessId);
}

EXPORT BOOL WINAPI _CancelIo(HANDLE hFile) {
    return ::CancelIo(hFile);
}

EXPORT BOOL WINAPI _CancelIoEx(HANDLE hFile, LPOVERLAPPED lpOverlapped) {
    return ::CancelIoEx(hFile, lpOverlapped);
}

EXPORT BOOL WINAPI _CheckRemoteDebuggerPresent(HANDLE hProcess, PBOOL  pbDebuggerPresent) {
    return ::CheckRemoteDebuggerPresent(hProcess, pbDebuggerPresent);
}

EXPORT BOOL WINAPI _ClearCommError(HANDLE hFile,
    LPDWORD lpErrors,
    LPCOMSTAT lpStat) {
    return ::ClearCommError(hFile, lpErrors, lpStat);
}

EXPORT BOOL WINAPI _CloseHandle(HANDLE hObject) {
    return ::CloseHandle(hObject);
}


EXPORT BOOL WINAPI _CompareStringW(LCID Locale,
    DWORD dwCmpFlags,
    PCNZWCH lpString1,
    int cchCount1,
    PCNZWCH lpString2,
    int cchCount2) {
    return ::CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2);
}

EXPORT BOOL WINAPI _ConnectNamedPipe(HANDLE hNamedPipe,
    LPOVERLAPPED lpOverlapped) {
    return ::ConnectNamedPipe(hNamedPipe, lpOverlapped);
}

EXPORT BOOL WINAPI _ContinueDebugEvent(DWORD dwProcessId,
    DWORD dwThreadId,
    DWORD dwContinueStatus) {
    return ::ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus);
}

EXPORT BOOL WINAPI _CopyFileW(LPCWSTR lpExistingFileName,
    LPCWSTR lpNewFileName,
    BOOL bFailIfExists) {
    return ::CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists);
}

EXPORT BOOL WINAPI _CreateDirectoryW(LPCWSTR lpPathName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes) {
    return ::CreateDirectoryW(lpPathName, lpSecurityAttributes);
}

EXPORT HANDLE WINAPI _CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,
    BOOL bManualReset,
    BOOL bInitialState,
    LPCSTR lpName) {
    return ::CreateEventA(lpEventAttributes,
        bManualReset,
        bInitialState,
        lpName);
}

EXPORT HANDLE WINAPI _CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes,
    BOOL bManualReset,
    BOOL bInitialState,
    LPCWSTR lpName) {
    return ::CreateEventW(lpEventAttributes,
        bManualReset,
        bInitialState,
        lpName);
}

EXPORT HANDLE WINAPI _CreateFileA(LPCSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile) {
    return ::CreateFileA(lpFileName,
        dwDesiredAccess,
        dwShareMode,
        lpSecurityAttributes,
        dwCreationDisposition,
        dwFlagsAndAttributes,
        hTemplateFile);
}


EXPORT HANDLE WINAPI _CreateFileW(LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile) {
    return ::CreateFileW(lpFileName,
        dwDesiredAccess,
        dwShareMode,
        lpSecurityAttributes,
        dwCreationDisposition,
        dwFlagsAndAttributes,
        hTemplateFile);
}

EXPORT BOOL WINAPI _CreateHardLinkW(LPCWSTR lpFileName,
    LPCWSTR lpExistingFileName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes) {
    return ::CreateHardLinkW(lpFileName,
        lpExistingFileName,
        lpSecurityAttributes);
}

EXPORT HANDLE WINAPI _CreateIoCompletionPort(HANDLE FileHandle,
    HANDLE ExistingCompletionPort,
    ULONG_PTR CompletionKey,
    DWORD NumberOfConcurrentThreads) {
    return ::CreateIoCompletionPort(FileHandle,
        ExistingCompletionPort,
        CompletionKey,
        NumberOfConcurrentThreads);
}

EXPORT HANDLE WINAPI _CreateJobObjectW(LPSECURITY_ATTRIBUTES lpJobAttributes,
    LPCWSTR lpName) {
    return ::CreateJobObjectW(lpJobAttributes,
        lpName);
}

EXPORT HANDLE WINAPI _CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType) {
    return ::CreateMemoryResourceNotification(NotificationType);
}

EXPORT HANDLE WINAPI _CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL bInitialOwner,
    LPCWSTR lpName) {
    return ::CreateMutexW(lpMutexAttributes,
        bInitialOwner,
        lpName);
}

EXPORT HANDLE WINAPI _CreateNamedPipeW(LPCWSTR lpName,
    DWORD dwOpenMode,
    DWORD dwPipeMode,
    DWORD nMaxInstances,
    DWORD nOutBufferSize,
    DWORD nInBufferSize,
    DWORD nDefaultTimeOut,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes) {
    return ::CreateNamedPipeW(lpName,
        dwOpenMode,
        dwPipeMode,
        nMaxInstances,
        nOutBufferSize,
        nInBufferSize,
        nDefaultTimeOut,
        lpSecurityAttributes);
}

EXPORT BOOL WINAPI _CreateProcessW(LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation) {
    return ::CreateProcessW(lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation);
}

EXPORT HANDLE WINAPI _CreateRemoteThread(HANDLE hProcess,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId) {
    return ::CreateRemoteThread(hProcess,
        lpThreadAttributes,
        dwStackSize,
        lpStartAddress,
        lpParameter,
        dwCreationFlags,
        lpThreadId);
}

EXPORT HANDLE WINAPI _CreateRemoteThreadEx(HANDLE hProcess,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
    LPDWORD lpThreadId)
{
    return ::CreateRemoteThreadEx(hProcess,
        lpThreadAttributes,
        dwStackSize,
        lpStartAddress,
        lpParameter,
        dwCreationFlags,
        lpAttributeList,
        lpThreadId);
}

EXPORT HANDLE WINAPI _CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    LONG lInitialCount,
    LONG lMaximumCount,
    LPCSTR lpName) {
    return ::CreateSemaphoreA(lpSemaphoreAttributes,
        lInitialCount,
        lMaximumCount,
        lpName);
}

EXPORT HANDLE WINAPI _CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    LONG lInitialCount,
    LONG lMaximumCount,
    LPCWSTR lpName) {
    return ::CreateSemaphoreW(lpSemaphoreAttributes,
        lInitialCount,
        lMaximumCount,
        lpName);
}

EXPORT HANDLE WINAPI _CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId) {
    return ::CreateThread(lpThreadAttributes,
        dwStackSize,
        lpStartAddress,
        lpParameter,
        dwCreationFlags,
        lpThreadId);
}

EXPORT HANDLE WINAPI _CreateToolhelp32Snapshot(DWORD dwFlags,
    DWORD th32ProcessID) {
    return ::CreateToolhelp32Snapshot(dwFlags,
        th32ProcessID);
}

EXPORT BOOL WINAPI _DebugActiveProcess(DWORD dwProcessId) {
    return ::DebugActiveProcess(dwProcessId);
}

EXPORT void WINAPI _DebugBreak(void) {
    return ::DebugBreak();
}

EXPORT PVOID WINAPI _DecodePointer(PVOID Ptr) {
    return ::DecodePointer(Ptr);
}

EXPORT void WINAPI _DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
    return ::DeleteCriticalSection(lpCriticalSection);
}

EXPORT BOOL WINAPI _DeleteFileA(LPCSTR lpFileName) {
    return ::DeleteFileA(lpFileName);
}

EXPORT BOOL WINAPI _DeleteFileW(LPCWSTR lpFileName) {
    return ::DeleteFileW(lpFileName);
}

EXPORT void WINAPI _DeleteProcThreadAttributeList(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList) {
    return ::DeleteProcThreadAttributeList(lpAttributeList);
}

EXPORT BOOL WINAPI _DeviceIoControl(HANDLE hDevice,
    DWORD dwIoControlCode,
    LPVOID lpInBuffer,
    DWORD nInBufferSize,
    LPVOID lpOutBuffer,
    DWORD nOutBufferSize,
    LPDWORD lpBytesReturned,
    LPOVERLAPPED lpOverlapped) {
    return ::DeviceIoControl(hDevice,
        dwIoControlCode,
        lpInBuffer,
        nInBufferSize,
        lpOutBuffer,
        nOutBufferSize,
        lpBytesReturned,
        lpOverlapped);
}

EXPORT BOOL WINAPI _DisconnectNamedPipe(HANDLE hNamedPipe) {
    return ::DisconnectNamedPipe(hNamedPipe);
}

EXPORT BOOL WINAPI _DuplicateHandle(HANDLE hSourceProcessHandle,
    HANDLE hSourceHandle,
    HANDLE hTargetProcessHandle,
    LPHANDLE lpTargetHandle,
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    DWORD dwOptions) {
    return ::DuplicateHandle(hSourceProcessHandle,
        hSourceHandle,
        hTargetProcessHandle,
        lpTargetHandle,
        dwDesiredAccess,
        bInheritHandle,
        dwOptions);
}

EXPORT PVOID WINAPI _EncodePointer(PVOID Ptr) {

    return ::EncodePointer(Ptr);
}

EXPORT void WINAPI _EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
    return ::EnterCriticalSection(lpCriticalSection);
}

EXPORT BOOL WINAPI _EnumResourceNamesW(HMODULE hModule,
    LPCWSTR lpType,
    ENUMRESNAMEPROCW lpEnumFunc,
    LONG_PTR lParam) {
    return ::EnumResourceNamesW(hModule,
        lpType,
        lpEnumFunc,
        lParam);
}

EXPORT BOOL WINAPI _EnumSystemLocalesEx(LOCALE_ENUMPROCEX lpLocaleEnumProcEx,
    DWORD dwFlags,
    LPARAM lParam,
    LPVOID lpReserved) {
    return ::EnumSystemLocalesEx(lpLocaleEnumProcEx,
        dwFlags,
        lParam,
        lpReserved);
}

EXPORT BOOL WINAPI _EnumSystemLocalesW(LOCALE_ENUMPROCW lpLocaleEnumProc,
    DWORD            dwFlags) {
    return ::EnumSystemLocalesW(lpLocaleEnumProc,
        dwFlags);
}

EXPORT BOOL WINAPI _EscapeCommFunction(HANDLE hFile,
    DWORD dwFunc) {
    return ::EscapeCommFunction(hFile,
        dwFunc);
}

EXPORT void WINAPI _ExitProcess(UINT uExitCode) {
    return ::ExitProcess(uExitCode);
}

EXPORT void WINAPI _ExitThread(DWORD dwExitCode) {
    return ::ExitThread(dwExitCode);
}

EXPORT DWORD WINAPI _ExpandEnvironmentStringsW(LPCWSTR lpSrc,
    LPWSTR lpDst,
    DWORD nSize) {
    return ::ExpandEnvironmentStringsW(lpSrc,
        lpDst,
        nSize);
}

EXPORT BOOL WINAPI _FileTimeToLocalFileTime(CONST FILETIME* lpFileTime,
    LPFILETIME lpLocalFileTime) {
    return ::FileTimeToLocalFileTime(lpFileTime,
        lpLocalFileTime);
}

EXPORT BOOL WINAPI _FileTimeToSystemTime(FILETIME* lpFileTime,
    LPSYSTEMTIME lpSystemTime) {
    return ::FileTimeToSystemTime(lpFileTime,
        lpSystemTime);
}

EXPORT BOOL WINAPI _FindClose(HANDLE hFindFile) {
    return ::FindClose(hFindFile);
}

EXPORT BOOL WINAPI _FindCloseChangeNotification(HANDLE hChangeHandle) {
    return ::FindCloseChangeNotification(hChangeHandle);
}

EXPORT HANDLE WINAPI _FindFirstChangeNotificationW(LPCWSTR lpPathName,
    BOOL bWatchSubtree,
    DWORD dwNotifyFilter) {
    return ::FindFirstChangeNotificationW(lpPathName,
        bWatchSubtree,
        dwNotifyFilter);
}

EXPORT HANDLE WINAPI _FindFirstFileA(LPCSTR lpFileName,
    LPWIN32_FIND_DATAA lpFindFileData) {
    return ::FindFirstFileA(lpFileName, lpFindFileData);
}

EXPORT HANDLE WINAPI _FindFirstFileExA(LPCSTR lpFileName,
    FINDEX_INFO_LEVELS fInfoLevelId,
    LPVOID lpFindFileData,
    FINDEX_SEARCH_OPS fSearchOp,
    LPVOID lpSearchFilter,
    DWORD dwAdditionalFlags) {
    return ::FindFirstFileExA(lpFileName,
        fInfoLevelId,
        lpFindFileData,
        fSearchOp,
        lpSearchFilter,
        dwAdditionalFlags);
}

EXPORT HANDLE WINAPI _FindFirstFileExW(LPCWSTR lpFileName,
    FINDEX_INFO_LEVELS fInfoLevelId,
    LPVOID lpFindFileData,
    FINDEX_SEARCH_OPS fSearchOp,
    LPVOID lpSearchFilter,
    DWORD dwAdditionalFlags) {
    return ::FindFirstFileExW(lpFileName,
        fInfoLevelId,
        lpFindFileData,
        fSearchOp,
        lpSearchFilter,
        dwAdditionalFlags);
}

EXPORT HANDLE WINAPI _FindFirstFileW(LPCWSTR lpFileName,
    LPWIN32_FIND_DATAW lpFindFileData) {
    return ::FindFirstFileW(lpFileName,
        lpFindFileData);
}

EXPORT HANDLE WINAPI _FindFirstVolumeW(LPWSTR lpszVolumeName,
    DWORD cchBufferLength) {
    return ::FindFirstVolumeW(lpszVolumeName,
        cchBufferLength);
}

EXPORT BOOL WINAPI _FindVolumeClose(HANDLE hFindVolume) {
    return ::FindVolumeClose(hFindVolume);
}

EXPORT BOOL WINAPI _FindNextFileA(HANDLE hFindFile,
    LPWIN32_FIND_DATAA lpFindFileData) {
    return ::FindNextFileA(hFindFile,
        lpFindFileData);
}

EXPORT BOOL WINAPI _FindNextFileW(HANDLE hFindFile,
    LPWIN32_FIND_DATAW lpFindFileData) {
    return ::FindNextFileW(hFindFile,
        lpFindFileData);
}

EXPORT BOOL WINAPI _FindNextVolumeW(HANDLE hFindVolume,
    LPWSTR lpszVolumeName,
    DWORD cchBufferLength) {
    return ::FindNextVolumeW(hFindVolume,
        lpszVolumeName,
        cchBufferLength);
}

EXPORT HRSRC WINAPI _FindResourceW(HMODULE hModule,
    LPCWSTR lpName,
    LPCWSTR lpType) {
    return ::FindResourceW(hModule,
        lpName,
        lpType);
}

EXPORT DWORD WINAPI _FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback) {
    return ::FlsAlloc(lpCallback);
}

EXPORT BOOL WINAPI _FlsFree(DWORD dwFlsIndex) {
    return ::FlsFree(dwFlsIndex);
}


EXPORT PVOID WINAPI _FlsGetValue(DWORD dwFlsIndex) {
    return ::FlsGetValue(dwFlsIndex);
}

EXPORT BOOL WINAPI _FlsSetValue(DWORD dwFlsIndex,
    PVOID lpFlsData) {
    return ::FlsSetValue(dwFlsIndex,
        lpFlsData);
}

EXPORT BOOL WINAPI _FlushFileBuffers(HANDLE hFile) {
    return ::FlushFileBuffers(hFile);
}

EXPORT BOOL WINAPI _FlushInstructionCache(HANDLE hProcess,
    LPCVOID lpBaseAddress,
    SIZE_T dwSize) {
    return ::FlushInstructionCache(hProcess,
        lpBaseAddress,
        dwSize);
}

EXPORT BOOL WINAPI _FlushViewOfFile(LPCVOID lpBaseAddress,
    SIZE_T dwNumberOfBytesToFlush) {
    return ::FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush);
}

EXPORT BOOL WINAPI _FoldStringW(DWORD dwMapFlags,
    LPCWCH lpSrcStr,
    int cchSrc,
    LPWSTR lpDestStr,
    int cchDest) {
    return ::FoldStringW(dwMapFlags,
        lpSrcStr,
        cchSrc,
        lpDestStr,
        cchDest);
}

EXPORT DWORD WINAPI _FormatMessageA(DWORD dwFlags,
    LPCVOID lpSource,
    DWORD dwMessageId,
    DWORD dwLanguageId,
    LPSTR lpBuffer,
    DWORD nSize,
    va_list* Arguments) {
    return ::FormatMessageA(dwFlags,
        lpSource,
        dwMessageId,
        dwLanguageId,
        lpBuffer,
        nSize,
        Arguments);
}

EXPORT DWORD WINAPI _FormatMessageW(DWORD dwFlags,
    LPCVOID lpSource,
    DWORD dwMessageId,
    DWORD dwLanguageId,
    LPWSTR lpBuffer,
    DWORD nSize,
    va_list* Arguments) {
    return ::FormatMessageW(dwFlags,
        lpSource,
        dwMessageId,
        dwLanguageId,
        lpBuffer,
        nSize,
        Arguments);
}

EXPORT BOOL WINAPI _FreeConsole(VOID) {
    return ::FreeConsole();
}

EXPORT BOOL WINAPI _FreeEnvironmentStringsW(LPWCH penv) {
    return ::FreeEnvironmentStringsW(penv);
}

EXPORT void WINAPI _FreeLibraryAndExitThread(HMODULE hLibModule,
    DWORD dwExitCode) {
    return ::FreeLibraryAndExitThread(hLibModule,
        dwExitCode);
}

EXPORT UINT WINAPI _GetACP(void) {
    return ::GetACP();
}

EXPORT UINT WINAPI _GetCPInfo(UINT       CodePage,
    LPCPINFO  lpCPInfo) {
    return ::GetCPInfo(CodePage, lpCPInfo);
}

EXPORT BOOL WINAPI _GetCommModemStatus(HANDLE hFile,
    LPDWORD lpModemStat) {
    return ::GetCommModemStatus(hFile, lpModemStat);
}

EXPORT BOOL WINAPI _GetCommState(HANDLE hFile,
    LPDCB lpDCB) {
    return ::GetCommState(hFile, lpDCB);
}

EXPORT LPSTR WINAPI _GetCommandLineA(VOID) {
    return ::GetCommandLineA();
}

EXPORT LPWSTR WINAPI _GetCommandLineW(VOID) {
    return ::GetCommandLineW();
}

EXPORT BOOL WINAPI _GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,
    LPSTR lpBuffer,
    LPDWORD nSize) {
    return ::GetComputerNameExA(NameType,
        lpBuffer,
        nSize);
}

EXPORT BOOL WINAPI _GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,
    LPWSTR lpBuffer,
    LPDWORD nSize) {
    return ::GetComputerNameExW(NameType,
        lpBuffer,
        nSize);
}

EXPORT BOOL WINAPI _GetComputerNameW(LPWSTR lpBuffer,
    LPDWORD nSize) {
    return ::GetComputerNameW(lpBuffer,
        nSize);
}

EXPORT BOOL WINAPI _GetConsoleDisplayMode(LPDWORD lpModeFlags) {
    return ::GetConsoleDisplayMode(lpModeFlags);
}

EXPORT BOOL WINAPI _GetConsoleMode(HANDLE hConsoleHandle,
    LPDWORD lpMode) {
    return ::GetConsoleMode(hConsoleHandle,
        lpMode);
}

EXPORT UINT WINAPI _GetConsoleOutputCP(VOID) {
    return ::GetConsoleOutputCP();
}

EXPORT int WINAPI _GetCurrencyFormatEx(LPCWSTR lpLocaleName,
    DWORD dwFlags,
    LPCWSTR lpValue,
    CONST CURRENCYFMTW* lpFormat,
    LPWSTR lpCurrencyStr,
    int cchCurrency) {
    return ::GetCurrencyFormatEx(lpLocaleName,
        dwFlags,
        lpValue,
        lpFormat,
        lpCurrencyStr,
        cchCurrency);
}

EXPORT DWORD WINAPI _GetCurrentDirectoryW(DWORD nBufferLength,
    LPWSTR lpBuffer) {
    return ::GetCurrentDirectoryW(nBufferLength,
        lpBuffer);
}

EXPORT HANDLE WINAPI _GetCurrentProcess(VOID) {
    return ::GetCurrentProcess();
}

EXPORT DWORD WINAPI _GetCurrentProcessId(VOID) {
    return ::GetCurrentProcessId();
}

EXPORT DWORD WINAPI _GetCurrentProcessorNumber(VOID) {
    return ::GetCurrentProcessorNumber();
}

EXPORT HANDLE WINAPI _GetCurrentThread(VOID) {
    return ::GetCurrentThread();
}

EXPORT DWORD WINAPI _GetCurrentThreadId(VOID) {
    return ::GetCurrentThreadId();
}

EXPORT int WINAPI _GetDateFormatEx(LPCWSTR lpLocaleName,
    DWORD dwFlags,
    CONST SYSTEMTIME* lpDate,
    LPCWSTR lpFormat,
    LPWSTR lpDateStr,
    int cchDate,
    LPCWSTR lpCalendar) {
    return ::GetDateFormatEx(lpLocaleName,
        dwFlags,
        lpDate,
        lpFormat,
        lpDateStr,
        cchDate,
        lpCalendar);
}

EXPORT BOOL WINAPI _GetDateFormatW(LCID Locale,
    DWORD dwFlags,
    CONST SYSTEMTIME* lpDate,
    LPCWSTR lpFormat,
    LPWSTR lpDateStr,
    int cchDate) {
    return ::GetDateFormatW(Locale,
        dwFlags,
        lpDate,
        lpFormat,
        lpDateStr,
        cchDate);
}

EXPORT BOOL WINAPI _GetDiskFreeSpaceA(LPCSTR lpRootPathName,
    LPDWORD lpSectorsPerCluster,
    LPDWORD lpBytesPerSector,
    LPDWORD lpNumberOfFreeClusters,
    LPDWORD lpTotalNumberOfClusters) {
    return ::GetDiskFreeSpaceA(lpRootPathName,
        lpSectorsPerCluster,
        lpBytesPerSector,
        lpNumberOfFreeClusters,
        lpTotalNumberOfClusters);
}

EXPORT BOOL WINAPI _GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,
    PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    PULARGE_INTEGER lpTotalNumberOfBytes,
    PULARGE_INTEGER lpTotalNumberOfFreeBytes) {
    return ::GetDiskFreeSpaceExW(lpDirectoryName,
        lpFreeBytesAvailableToCaller,
        lpTotalNumberOfBytes,
        lpTotalNumberOfFreeBytes);
}

EXPORT BOOL WINAPI _GetDiskFreeSpaceW(LPCWSTR lpRootPathName,
    LPDWORD lpSectorsPerCluster,
    LPDWORD lpBytesPerSector,
    LPDWORD lpNumberOfFreeClusters,
    LPDWORD lpTotalNumberOfClusters) {
    return ::GetDiskFreeSpaceW(lpRootPathName,
        lpSectorsPerCluster,
        lpBytesPerSector,
        lpNumberOfFreeClusters,
        lpTotalNumberOfClusters);
}

EXPORT UINT WINAPI _GetDriveTypeW(LPCWSTR lpRootPathName) {
    return ::GetDriveTypeW(lpRootPathName);
}

EXPORT DWORD WINAPI _GetDynamicTimeZoneInformation(PDYNAMIC_TIME_ZONE_INFORMATION pTimeZoneInformation) {
    return ::GetDynamicTimeZoneInformation(pTimeZoneInformation);
}

EXPORT LPWCH WINAPI _GetEnvironmentStringsW(VOID) {
    return ::GetEnvironmentStringsW();
}

EXPORT DWORD WINAPI _GetEnvironmentVariableA(LPCSTR lpName,
    LPSTR lpBuffer,
    DWORD nSize) {
    return ::GetEnvironmentVariableA(lpName,
        lpBuffer,
        nSize);
}

EXPORT DWORD WINAPI _GetEnvironmentVariableW(LPCWSTR lpName,
    LPWSTR lpBuffer,
    DWORD nSize) {
    return ::GetEnvironmentVariableW(lpName,
        lpBuffer,
        nSize);
}

EXPORT BOOL WINAPI _GetExitCodeProcess(HANDLE hProcess,
    LPDWORD lpExitCode) {
    return ::GetExitCodeProcess(hProcess,
        lpExitCode);
}

EXPORT DWORD WINAPI _GetFileAttributesA(LPCSTR lpFileName) {
    return ::GetFileAttributesA(lpFileName);
}

EXPORT BOOL WINAPI _GetFileAttributesExW(LPCWSTR lpFileName,
    GET_FILEEX_INFO_LEVELS fInfoLevelId,
    LPVOID lpFileInformation) {
    return ::GetFileAttributesExW(lpFileName,
        fInfoLevelId,
        lpFileInformation);
}

EXPORT DWORD WINAPI _GetFileAttributesW(LPCWSTR lpFileName) {
    return ::GetFileAttributesW(lpFileName);
}

EXPORT BOOL WINAPI _GetFileInformationByHandle(HANDLE hFile,
    LPBY_HANDLE_FILE_INFORMATION lpFileInformation) {
    return ::GetFileInformationByHandle(hFile,
        lpFileInformation);
}

EXPORT DWORD WINAPI _GetFileSize(HANDLE hFile,
    LPDWORD lpFileSizeHigh) {
    return ::GetFileSize(hFile,
        lpFileSizeHigh);
}

EXPORT BOOL WINAPI _GetFileSizeEx(HANDLE hFile,
    PLARGE_INTEGER lpFileSize) {
    return ::GetFileSizeEx(hFile,
        lpFileSize);
}

EXPORT BOOL WINAPI _GetFileTime(HANDLE hFile,
    LPFILETIME lpCreationTime,
    LPFILETIME lpLastAccessTime,
    LPFILETIME lpLastWriteTime) {
    return ::GetFileTime(hFile,
        lpCreationTime,
        lpLastAccessTime,
        lpLastWriteTime);
}

EXPORT DWORD WINAPI _GetFileType(HANDLE hFile) {
    return ::GetFileType(hFile);
}

EXPORT DWORD WINAPI _GetFinalPathNameByHandleW(HANDLE hFile,
    LPWSTR lpszFilePath,
    DWORD cchFilePath,
    DWORD dwFlags) {
    return ::GetFinalPathNameByHandleW(hFile,
        lpszFilePath,
        cchFilePath,
        dwFlags);
}


EXPORT DWORD WINAPI _GetFullPathNameA(LPCSTR lpFileName,
    DWORD nBufferLength,
    LPSTR lpBuffer,
    LPSTR* lpFilePart) {
    return ::GetFullPathNameA(lpFileName,
        nBufferLength,
        lpBuffer,
        lpFilePart);
}

EXPORT DWORD WINAPI _GetFullPathNameW(LPCWSTR lpFileName,
    DWORD nBufferLength,
    LPWSTR lpBuffer,
    LPWSTR* lpFilePart) {
    return ::GetFullPathNameW(lpFileName,
        nBufferLength,
        lpBuffer,
        lpFilePart);
}

EXPORT int WINAPI _GetGeoInfoW(GEOID       Location,
    GEOTYPE     GeoType,
    LPWSTR     lpGeoData,
    int         cchData,
    LANGID      LangId) {
    return ::GetGeoInfoW(Location,
        GeoType,
        lpGeoData,
        cchData,
        LangId);
}

EXPORT DWORD WINAPI _GetLastError(VOID) {
    return ::GetLastError();
}

EXPORT VOID WINAPI _GetLocalTime(LPSYSTEMTIME lpSystemTime) {
    return ::GetLocalTime(lpSystemTime);
}

EXPORT int WINAPI _GetLocaleInfoEx(LPCWSTR lpLocaleName,
    LCTYPE LCType,
    LPWSTR lpLCData,
    int cchData) {
    return ::GetLocaleInfoEx(lpLocaleName,
        LCType,
        lpLCData,
        cchData);
}

EXPORT int WINAPI _GetLocaleInfoW(LCID     Locale,
    LCTYPE   LCType,
    LPWSTR lpLCData,
    int      cchData) {
    return ::GetLocaleInfoW(Locale,
        LCType,
        lpLCData,
        cchData);
}

EXPORT DWORD WINAPI _GetLogicalDriveStringsW(DWORD nBufferLength,
    LPWSTR lpBuffer) {
    return ::GetLogicalDriveStringsW(nBufferLength,
        lpBuffer);
}

EXPORT BOOL WINAPI _GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,
    PDWORD ReturnedLength) {
    return ::GetLogicalProcessorInformation(Buffer,
        ReturnedLength);
}

EXPORT BOOL WINAPI _GetLogicalProcessorInformationEx(LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType,
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Buffer,
    PDWORD ReturnedLength) {
    return ::GetLogicalProcessorInformationEx(RelationshipType,
        Buffer,
        ReturnedLength);
}

EXPORT DWORD WINAPI _GetLongPathNameW(LPCWSTR lpszShortPath,
    LPWSTR lpszLongPath,
    DWORD cchBuffer) {
    return ::GetLongPathNameW(lpszShortPath,
        lpszLongPath,
        cchBuffer);
}

EXPORT DWORD WINAPI _GetMaximumProcessorCount(WORD GroupNumber) {
    return ::GetMaximumProcessorCount(GroupNumber);
}

EXPORT WORD WINAPI _GetMaximumProcessorGroupCount(VOID) {
    return ::GetMaximumProcessorGroupCount();
}
EXPORT DWORD WINAPI _GetModuleFileNameA(HMODULE hModule,
    LPSTR lpFilename,
    DWORD nSize) {
    return ::GetModuleFileNameA(hModule,
        lpFilename,
        nSize);
}

EXPORT DWORD WINAPI _GetModuleFileNameW(HMODULE hModule,
    LPWSTR lpFilename,
    DWORD nSize) {
    return ::GetModuleFileNameW(hModule,
        lpFilename,
        nSize);
}

EXPORT HMODULE WINAPI _GetModuleHandleA(LPCSTR lpModuleName) {
    return ::GetModuleHandleA(lpModuleName);
}

EXPORT BOOL WINAPI _GetModuleHandleExA(DWORD dwFlags,
    LPCSTR lpModuleName,
    HMODULE* phModule) {
    return ::GetModuleHandleExA(dwFlags,
        lpModuleName,
        phModule);
}

EXPORT BOOL WINAPI _GetModuleHandleExW(DWORD dwFlags,
    LPCWSTR lpModuleName,
    HMODULE* phModule) {
    return ::GetModuleHandleExW(dwFlags,
        lpModuleName,
        phModule);
}

EXPORT HMODULE WINAPI _GetModuleHandleW(LPCWSTR lpModuleName) {
    return ::GetModuleHandleW(lpModuleName);
}

EXPORT BOOL WINAPI _GetNamedPipeClientProcessId(HANDLE Pipe,
    PULONG ClientProcessId) {
    return ::GetNamedPipeClientProcessId(Pipe,
        ClientProcessId);
}

EXPORT BOOL WINAPI _GetNamedPipeHandleStateW(HANDLE hNamedPipe,
    LPDWORD lpState,
    LPDWORD lpCurInstances,
    LPDWORD lpMaxCollectionCount,
    LPDWORD lpCollectDataTimeout,
    LPWSTR lpUserName,
    DWORD nMaxUserNameSize) {
    return ::GetNamedPipeHandleStateW(hNamedPipe,
        lpState,
        lpCurInstances,
        lpMaxCollectionCount,
        lpCollectDataTimeout,
        lpUserName,
        nMaxUserNameSize);
}

EXPORT BOOL WINAPI _GetNamedPipeServerProcessId(HANDLE Pipe,
    PULONG ServerProcessId) {
    return ::GetNamedPipeServerProcessId(Pipe,
        ServerProcessId);
}

EXPORT VOID WINAPI _GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo) {
    return ::GetNativeSystemInfo(lpSystemInfo);
}

EXPORT int WINAPI _GetNumberFormatEx(LPCWSTR lpLocaleName,
    DWORD dwFlags,
    LPCWSTR lpValue,
    CONST NUMBERFMTW* lpFormat,
    LPWSTR lpNumberStr,
    int cchNumber) {
    return ::GetNumberFormatEx(lpLocaleName,
        dwFlags,
        lpValue,
        lpFormat,
        lpNumberStr,
        cchNumber);
}

EXPORT UINT WINAPI _GetOEMCP(VOID) {
    return ::GetOEMCP();
}

EXPORT BOOL WINAPI _GetOverlappedResult(HANDLE hFile,
    LPOVERLAPPED lpOverlapped,
    LPDWORD lpNumberOfBytesTransferred,
    BOOL bWait) {
    return ::GetOverlappedResult(hFile,
        lpOverlapped,
        lpNumberOfBytesTransferred,
        bWait);
}

EXPORT DWORD WINAPI _GetPriorityClass(HANDLE hProcess) {
    return ::GetPriorityClass(hProcess);
}

EXPORT DWORD WINAPI _GetPrivateProfileStringW(LPCWSTR lpAppName,
    LPCWSTR lpKeyName,
    LPCWSTR lpDefault,
    LPWSTR lpReturnedString,
    DWORD nSize,
    LPCWSTR lpFileName) {
    return ::GetPrivateProfileStringW(lpAppName,
        lpKeyName,
        lpDefault,
        lpReturnedString,
        nSize,
        lpFileName);
}

EXPORT FARPROC WINAPI _GetProcAddress(HMODULE hModule,
    LPCSTR lpProcName) {
    return ::GetProcAddress(hModule,
        lpProcName);
}

EXPORT BOOL WINAPI _GetProcessAffinityMask(HANDLE hProcess,
    PDWORD_PTR lpProcessAffinityMask,
    PDWORD_PTR lpSystemAffinityMask) {
    return ::GetProcessAffinityMask(hProcess,
        lpProcessAffinityMask,
        lpSystemAffinityMask);
}

EXPORT BOOL WINAPI _GetProcessHandleCount(HANDLE hProcess,
    PDWORD pdwHandleCount) {
    return ::GetProcessHandleCount(hProcess,
        pdwHandleCount);
}

EXPORT HANDLE WINAPI _GetProcessHeap(VOID) {
    return ::GetProcessHeap();
}

EXPORT DWORD WINAPI _GetProcessHeaps(DWORD NumberOfHeaps,
    PHANDLE ProcessHeaps) {
    return ::GetProcessHeaps(NumberOfHeaps, ProcessHeaps);
}

EXPORT DWORD WINAPI _GetProcessId(HANDLE Process) {
    return ::GetProcessId(Process);
}

EXPORT BOOL WINAPI _GetProcessTimes(HANDLE hProcess,
    LPFILETIME lpCreationTime,
    LPFILETIME lpExitTime,
    LPFILETIME lpKernelTime,
    LPFILETIME lpUserTime) {
    return ::GetProcessTimes(hProcess,
        lpCreationTime,
        lpExitTime,
        lpKernelTime,
        lpUserTime);
}

EXPORT BOOL WINAPI _GetProductInfo(DWORD dwOSMajorVersion,
    DWORD dwOSMinorVersion,
    DWORD dwSpMajorVersion,
    DWORD dwSpMinorVersion,
    PDWORD pdwReturnedProductType) {
    return ::GetProductInfo(dwOSMajorVersion,
        dwOSMinorVersion,
        dwSpMajorVersion,
        dwSpMinorVersion,
        pdwReturnedProductType);
}

EXPORT BOOL WINAPI _GetQueuedCompletionStatus(HANDLE CompletionPort,
    LPDWORD lpNumberOfBytesTransferred,
    PULONG_PTR lpCompletionKey,
    LPOVERLAPPED* lpOverlapped,
    DWORD dwMilliseconds) {
    return ::GetQueuedCompletionStatus(CompletionPort,
        lpNumberOfBytesTransferred,
        lpCompletionKey,
        lpOverlapped,
        dwMilliseconds);
}

EXPORT DWORD WINAPI _GetShortPathNameW(LPCWSTR lpszLongPath,
    LPWSTR lpszShortPath,
    DWORD cchBuffer) {
    return ::GetShortPathNameW(lpszLongPath,
        lpszShortPath,
        cchBuffer);
}

EXPORT VOID WINAPI _GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo) {
    return ::GetStartupInfoW(lpStartupInfo);
}

EXPORT HANDLE WINAPI _GetStdHandle(DWORD nStdHandle) {
    return ::GetStdHandle(nStdHandle);
}

EXPORT BOOL WINAPI _GetStringTypeW(DWORD dwInfoType,
    LPCWCH lpSrcStr,
    int cchSrc,
    LPWORD lpCharType) {
    return ::GetStringTypeW(dwInfoType,
        lpSrcStr,
        cchSrc,
        lpCharType);
}

EXPORT UINT WINAPI _GetSystemDirectoryA(LPSTR lpBuffer,
    UINT uSize) {
    return ::GetSystemDirectoryA(lpBuffer, uSize);
}

EXPORT UINT WINAPI _GetSystemDirectoryW(LPWSTR lpBuffer,
    UINT uSize) {
    return ::GetSystemDirectoryW(lpBuffer,
        uSize);
}

EXPORT VOID WINAPI _GetSystemInfo(LPSYSTEM_INFO lpSystemInfo) {
    return ::GetSystemInfo(lpSystemInfo);
}

EXPORT BOOL WINAPI _GetSystemPowerStatus(LPSYSTEM_POWER_STATUS lpSystemPowerStatus) {
    return ::GetSystemPowerStatus(lpSystemPowerStatus);
}

EXPORT VOID WINAPI _GetSystemTime(LPSYSTEMTIME lpSystemTime) {
    return ::GetSystemTime(lpSystemTime);
}

EXPORT VOID WINAPI _GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime) {
    return ::GetSystemTimeAsFileTime(lpSystemTimeAsFileTime);
}

EXPORT UINT WINAPI _GetTempFileNameA(LPCSTR lpPathName,
    LPCSTR lpPrefixString,
    UINT uUnique,
    LPSTR lpTempFileName) {
    return ::GetTempFileNameA(lpPathName,
        lpPrefixString,
        uUnique,
        lpTempFileName);
}

EXPORT DWORD WINAPI _GetTempPathA(DWORD nBufferLength,
    LPSTR lpBuffer) {
    return ::GetTempPathA(nBufferLength, lpBuffer);
}

EXPORT DWORD WINAPI _GetTempPathW(DWORD nBufferLength,
    LPWSTR lpBuffer) {
    return ::GetTempPathW(nBufferLength, lpBuffer);
}

EXPORT BOOL WINAPI _GetThreadContext(HANDLE hThread,
    LPCONTEXT lpContext) {
    return ::GetThreadContext(hThread,
        lpContext);
}

EXPORT BOOL WINAPI _GetThreadGroupAffinity(HANDLE hThread,
    PGROUP_AFFINITY GroupAffinity) {
    return ::GetThreadGroupAffinity(hThread,
        GroupAffinity);
}

EXPORT DWORD WINAPI _GetThreadId(HANDLE Thread) {
    return ::GetThreadId(Thread);
}

EXPORT BOOL WINAPI _GetThreadPreferredUILanguages(DWORD dwFlags,
    PULONG pulNumLanguages,
    PZZWSTR pwszLanguagesBuffer,
    PULONG pcchLanguagesBuffer) {
    return ::GetThreadPreferredUILanguages(dwFlags,
        pulNumLanguages,
        pwszLanguagesBuffer,
        pcchLanguagesBuffer);
}

EXPORT int WINAPI _GetThreadPriority(HANDLE hThread) {
    return ::GetThreadPriority(hThread);
}

EXPORT BOOL WINAPI _GetThreadPriorityBoost(HANDLE hThread,
    PBOOL pDisablePriorityBoost) {
    return ::GetThreadPriorityBoost(hThread,
        pDisablePriorityBoost);
}

EXPORT BOOL WINAPI _GetThreadTimes(HANDLE hThread,
    LPFILETIME lpCreationTime,
    LPFILETIME lpExitTime,
    LPFILETIME lpKernelTime,
    LPFILETIME lpUserTime) {
    return ::GetThreadTimes(hThread,
        lpCreationTime,
        lpExitTime,
        lpKernelTime,
        lpUserTime);
}

#ifdef _AMD64_
EXPORT DWORD WINAPI _GetTickCount(VOID) {
    return ::GetTickCount();
}

EXPORT ULONGLONG _GetTickCount64(VOID) {
    return ::GetTickCount64();
}
#else
EXPORT ULONGLONG  __GetTickCount64(VOID) {
    return ::GetTickCount64();
}

EXPORT DWORD  __GetTickCount(VOID) {
    return ::GetTickCount();
}
#endif // _AMD64_


EXPORT int WINAPI _GetTimeFormatEx(LPCWSTR lpLocaleName,
    DWORD dwFlags,
    CONST SYSTEMTIME* lpTime,
    LPCWSTR lpFormat,
    LPWSTR lpTimeStr,
    int cchTime) {
    return ::GetTimeFormatEx(lpLocaleName,
        dwFlags,
        lpTime,
        lpFormat,
        lpTimeStr,
        cchTime);
}

EXPORT BOOL WINAPI _GetTimeFormatW(LCID Locale,
    DWORD dwFlags,
    CONST SYSTEMTIME* lpTime,
    LPCWSTR lpFormat,
    LPWSTR lpTimeStr,
    int cchTime) {
    return ::GetTimeFormatW(Locale,
        dwFlags,
        lpTime,
        lpFormat,
        lpTimeStr,
        cchTime);
}

EXPORT DWORD WINAPI _GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation) {
    return ::GetTimeZoneInformation(lpTimeZoneInformation);
}

EXPORT BOOL WINAPI _GetUserDefaultLCID() {
    return ::GetUserDefaultLCID();
}

EXPORT LANGID WINAPI _GetUserDefaultLangID(VOID) {
    return ::GetUserDefaultLangID();
}

EXPORT int WINAPI _GetUserDefaultLocaleName(LPWSTR lpLocaleName,
    int cchLocaleName) {
    return ::GetUserDefaultLocaleName(lpLocaleName,
        cchLocaleName);
}

EXPORT LANGID WINAPI _GetUserDefaultUILanguage(VOID) {
    return ::GetUserDefaultUILanguage();
}

EXPORT GEOID WINAPI _GetUserGeoID(GEOCLASS    GeoClass) {
    return ::GetUserGeoID(GeoClass);
}

EXPORT BOOL WINAPI _GetVersionExW(LPOSVERSIONINFOW lpVersionInformation) {
    return ::GetVersionExW(lpVersionInformation);
}

EXPORT BOOL WINAPI _GetVolumeInformationW(LPCWSTR lpRootPathName,
    LPWSTR lpVolumeNameBuffer,
    DWORD nVolumeNameSize,
    LPDWORD lpVolumeSerialNumber,
    LPDWORD lpMaximumComponentLength,
    LPDWORD lpFileSystemFlags,
    LPWSTR lpFileSystemNameBuffer,
    DWORD nFileSystemNameSize) {
    return ::GetVolumeInformationW(lpRootPathName,
        lpVolumeNameBuffer,
        nVolumeNameSize,
        lpVolumeSerialNumber,
        lpMaximumComponentLength,
        lpFileSystemFlags,
        lpFileSystemNameBuffer,
        nFileSystemNameSize);
}

EXPORT BOOL WINAPI _GetVolumeNameForVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,
    LPWSTR lpszVolumeName,
    DWORD cchBufferLength) {
    return ::GetVolumeNameForVolumeMountPointW(lpszVolumeMountPoint,
        lpszVolumeName,
        cchBufferLength);
}

EXPORT BOOL WINAPI _GetVolumePathNameW(LPCWSTR lpszFileName,
    LPWSTR lpszVolumePathName,
    DWORD cchBufferLength) {
    return ::GetVolumePathNameW(lpszFileName,
        lpszVolumePathName,
        cchBufferLength);
}

EXPORT BOOL WINAPI _GetVolumePathNamesForVolumeNameW(LPCWSTR lpszVolumeName,
    LPWCH lpszVolumePathNames,
    DWORD cchBufferLength,
    PDWORD lpcchReturnLength) {
    return ::GetVolumePathNamesForVolumeNameW(lpszVolumeName,
        lpszVolumePathNames,
        cchBufferLength,
        lpcchReturnLength);
}

EXPORT UINT WINAPI _GetWindowsDirectoryA(LPSTR lpBuffer,
    UINT uSize) {
    return ::GetWindowsDirectoryA(lpBuffer, uSize);
}

EXPORT UINT WINAPI _GetWindowsDirectoryW(LPWSTR lpBuffer,
    UINT uSize) {
    return ::GetWindowsDirectoryW(lpBuffer, uSize);
}

EXPORT HGLOBAL WINAPI _GlobalAlloc(UINT uFlags,
    SIZE_T dwBytes) {
    return ::GlobalAlloc(uFlags, dwBytes);
}

EXPORT HGLOBAL WINAPI _GlobalFree(HGLOBAL hMem) {
    return ::GlobalFree(hMem);
}

EXPORT LPVOID WINAPI _GlobalLock(HGLOBAL hMem) {
    return ::GlobalLock(hMem);
}

EXPORT BOOL WINAPI _GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer) {
    return ::GlobalMemoryStatusEx(lpBuffer);
}

EXPORT SIZE_T WINAPI _GlobalSize(HGLOBAL hMem) {
    return ::GlobalSize(hMem);
}

EXPORT BOOL WINAPI _GlobalUnlock(HGLOBAL hMem) {
    return ::GlobalUnlock(hMem);
}

EXPORT LPVOID WINAPI _HeapAlloc(HANDLE hHeap,
    DWORD dwFlags,
    SIZE_T dwBytes) {
    return ::HeapAlloc(hHeap,
        dwFlags,
        dwBytes);
}

EXPORT SIZE_T WINAPI _HeapCompact(HANDLE hHeap,
    DWORD dwFlags) {
    return ::HeapCompact(hHeap, dwFlags);
}

EXPORT HANDLE WINAPI _HeapCreate(DWORD flOptions,
    SIZE_T dwInitialSize,
    SIZE_T dwMaximumSize) {
    return ::HeapCreate(flOptions,
        dwInitialSize,
        dwMaximumSize);
}

EXPORT BOOL WINAPI _HeapDestroy(HANDLE hHeap) {
    return ::HeapDestroy(hHeap);
}

EXPORT BOOL WINAPI _HeapFree(HANDLE hHeap,
    DWORD dwFlags,
    LPVOID lpMem) {
    return ::HeapFree(hHeap,
        dwFlags,
        lpMem);
}

EXPORT BOOL WINAPI _HeapLock(HANDLE hHeap) {
    return ::HeapLock(hHeap);
}

EXPORT LPVOID WINAPI _HeapReAlloc(HANDLE hHeap,
    DWORD dwFlags,
    LPVOID lpMem,
    SIZE_T dwBytes) {
    return ::HeapReAlloc(hHeap,
        dwFlags,
        lpMem,
        dwBytes);
}

EXPORT BOOL WINAPI _HeapSetInformation(HANDLE HeapHandle,
    HEAP_INFORMATION_CLASS HeapInformationClass,
    PVOID HeapInformation,
    SIZE_T HeapInformationLength) {
    return ::HeapSetInformation(HeapHandle,
        HeapInformationClass,
        HeapInformation,
        HeapInformationLength);
}

EXPORT SIZE_T WINAPI _HeapSize(HANDLE hHeap,
    DWORD dwFlags,
    LPCVOID lpMem) {
    return ::HeapSize(hHeap,
        dwFlags,
        lpMem);
}

EXPORT BOOL WINAPI _HeapUnlock(HANDLE hHeap) {
    return ::HeapUnlock(hHeap);
}

EXPORT BOOL WINAPI _HeapValidate(HANDLE hHeap,
    DWORD dwFlags,
    LPCVOID lpMem) {
    return ::HeapValidate(hHeap, dwFlags, lpMem);
}

EXPORT BOOL WINAPI _HeapWalk(HANDLE hHeap,
    LPPROCESS_HEAP_ENTRY lpEntry) {
    return ::HeapWalk(hHeap, lpEntry);
}

EXPORT BOOL WINAPI _InitOnceBeginInitialize(LPINIT_ONCE lpInitOnce,
    DWORD dwFlags,
    PBOOL fPending,
    LPVOID* lpContext) {
    return ::InitOnceBeginInitialize(lpInitOnce,
        dwFlags,
        fPending,
        lpContext);
}

EXPORT BOOL WINAPI _InitOnceComplete(LPINIT_ONCE lpInitOnce,
    DWORD dwFlags,
    LPVOID lpContext) {
    return ::InitOnceComplete(lpInitOnce,
        dwFlags,
        lpContext);
}

EXPORT BOOL WINAPI _InitOnceExecuteOnce(PINIT_ONCE InitOnce,
    PINIT_ONCE_FN InitFn,
    PVOID Parameter,
    LPVOID* Context) {
    return ::InitOnceExecuteOnce(InitOnce,
        InitFn,
        Parameter,
        Context);
}

EXPORT VOID WINAPI _InitializeConditionVariable(PCONDITION_VARIABLE ConditionVariable) {
    return ::InitializeConditionVariable(ConditionVariable);
}

EXPORT VOID WINAPI _InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
    return ::InitializeCriticalSection(lpCriticalSection);
}

EXPORT BOOL WINAPI _InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection,
    DWORD dwSpinCount) {
    return ::InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}

EXPORT BOOL WINAPI _InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection,
    DWORD dwSpinCount,
    DWORD Flags) {
    return ::InitializeCriticalSectionEx(lpCriticalSection,
        dwSpinCount,
        Flags);
}

EXPORT BOOL WINAPI _InitializeProcThreadAttributeList(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
    DWORD dwAttributeCount,
    DWORD dwFlags,
    PSIZE_T lpSize) {
    return ::InitializeProcThreadAttributeList(lpAttributeList,
        dwAttributeCount,
        dwFlags,
        lpSize);
}

EXPORT VOID WINAPI _InitializeSListHead(PSLIST_HEADER ListHead) {
    return ::InitializeSListHead(ListHead);
}

EXPORT VOID WINAPI _InitializeSRWLock(PSRWLOCK SRWLock) {
    return ::InitializeSRWLock(SRWLock);
}

EXPORT PSLIST_ENTRY WINAPI _InterlockedFlushSList(PSLIST_HEADER ListHead) {
    return ::InterlockedFlushSList(ListHead);
}

EXPORT PSLIST_ENTRY WINAPI _InterlockedPopEntrySList(PSLIST_HEADER ListHead) {
    return ::InterlockedPopEntrySList(ListHead);
}

EXPORT PSLIST_ENTRY WINAPI _InterlockedPushEntrySList(PSLIST_HEADER ListHead,
    PSLIST_ENTRY ListEntry) {
    return ::InterlockedPushEntrySList(ListHead, ListEntry);
}

EXPORT BOOL WINAPI _IsDebuggerPresent() {
    return ::IsDebuggerPresent();
}

EXPORT BOOL WINAPI _IsProcessorFeaturePresent(DWORD ProcessorFeature) {
    return ::IsProcessorFeaturePresent(ProcessorFeature);
}

EXPORT BOOL WINAPI _IsValidCodePage(UINT  CodePage) {
    return ::IsValidCodePage(CodePage);
}

EXPORT BOOL WINAPI _IsValidLocale(LCID   Locale,
    DWORD  dwFlags) {
    return ::IsValidLocale(Locale,
        dwFlags);
}

EXPORT BOOL WINAPI _IsWow64Process(HANDLE hProcess,
    PBOOL Wow64Process) {
    return ::IsWow64Process(hProcess, Wow64Process);
}

EXPORT BOOL WINAPI _K32EnumProcessModules(HANDLE hProcess,
    HMODULE* lphModule,
    DWORD cb,
    LPDWORD lpcbNeeded) {
    return ::K32EnumProcessModules(hProcess,
        lphModule,
        cb,
        lpcbNeeded);
}

EXPORT DWORD WINAPI _K32GetMappedFileNameW(HANDLE hProcess,
    LPVOID lpv,
    LPWSTR lpFilename,
    DWORD nSize) {
    return ::K32GetMappedFileNameW(hProcess,
        lpv,
        lpFilename,
        nSize);
}

EXPORT DWORD WINAPI _K32GetModuleFileNameExW(HANDLE hProcess,
    HMODULE hModule,
    LPWSTR lpFilename,
    DWORD nSize) {
    return ::K32GetModuleFileNameExW(hProcess,
        hModule,
        lpFilename,
        nSize);
}

EXPORT BOOL WINAPI _K32GetModuleInformation(HANDLE hProcess,
    HMODULE hModule,
    LPMODULEINFO lpmodinfo,
    DWORD cb) {
    return ::K32GetModuleInformation(hProcess,
        hModule,
        lpmodinfo,
        cb);
}

EXPORT BOOL WINAPI _K32GetPerformanceInfo(PPERFORMANCE_INFORMATION pPerformanceInformation,
    DWORD cb) {
    return ::K32GetPerformanceInfo(pPerformanceInformation, cb);
}

EXPORT BOOL WINAPI _K32GetProcessMemoryInfo(HANDLE Process,
    PPROCESS_MEMORY_COUNTERS ppsmemCounters,
    DWORD cb) {
    return ::K32GetProcessMemoryInfo(Process,
        ppsmemCounters,
        cb);
}

EXPORT BOOL WINAPI _K32QueryWorkingSetEx(HANDLE hProcess,
    PVOID pv,
    DWORD cb) {
    return ::K32QueryWorkingSetEx(hProcess, pv, cb);
}

EXPORT BOOL WINAPI _K32QueryWorkingSet(HANDLE hProcess,
    PVOID pv,
    DWORD cb) {
    return ::K32QueryWorkingSet(hProcess, pv, cb);
}

EXPORT int WINAPI _LCIDToLocaleName(LCID     Locale,
    LPWSTR  lpName,
    int      cchName,
    DWORD    dwFlags) {
    return ::LCIDToLocaleName(Locale,
        lpName,
        cchName,
        dwFlags);
}

EXPORT int WINAPI _LCMapStringW(LCID     Locale,
    DWORD    dwMapFlags,
    LPCWSTR  lpSrcStr,
    int      cchSrc,
    LPWSTR  lpDestStr,
    int      cchDest) {
    return ::LCMapStringW(Locale,
        dwMapFlags,
        lpSrcStr,
        cchSrc,
        lpDestStr,
        cchDest);
}

EXPORT VOID WINAPI _LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
    return ::LeaveCriticalSection(lpCriticalSection);
}

EXPORT HMODULE WINAPI _LoadLibraryA(LPCSTR lpLibFileName) {
    return ::LoadLibraryA(lpLibFileName);
}

EXPORT HMODULE WINAPI _LoadLibraryExA(LPCSTR lpLibFileName,
    HANDLE hFile,
    DWORD dwFlags) {
    return ::LoadLibraryExA(lpLibFileName,
        hFile,
        dwFlags);
}

EXPORT HMODULE WINAPI _LoadLibraryExW(LPCWSTR lpLibFileName,
    HANDLE hFile,
    DWORD dwFlags) {
    return ::LoadLibraryExW(lpLibFileName, hFile, dwFlags);
}

EXPORT HMODULE WINAPI _LoadLibraryW(LPCWSTR lpLibFileName) {
    return ::LoadLibraryW(lpLibFileName);
}

EXPORT HGLOBAL WINAPI _LoadResource(HMODULE hModule,
    HRSRC hResInfo) {
    return ::LoadResource(hModule, hResInfo);
}

EXPORT HLOCAL WINAPI _LocalAlloc(UINT uFlags,
    SIZE_T uBytes) {
    return ::LocalAlloc(uFlags, uBytes);
}

EXPORT BOOL WINAPI _LocalFileTimeToFileTime(CONST FILETIME* lpLocalFileTime,
    LPFILETIME lpFileTime) {
    return ::LocalFileTimeToFileTime(lpLocalFileTime, lpFileTime);
}

EXPORT HLOCAL WINAPI _LocalFree(HLOCAL hMem) {
    return ::LocalFree(hMem);
}

EXPORT LCID WINAPI _LocaleNameToLCID(LPCWSTR lpName,
    DWORD dwFlags) {
    return ::LocaleNameToLCID(lpName, dwFlags);
}

EXPORT BOOL WINAPI _LockFile(HANDLE hFile,
    DWORD dwFileOffsetLow,
    DWORD dwFileOffsetHigh,
    DWORD nNumberOfBytesToLockLow,
    DWORD nNumberOfBytesToLockHigh) {
    return ::LockFile(hFile,
        dwFileOffsetLow,
        dwFileOffsetHigh,
        nNumberOfBytesToLockLow,
        nNumberOfBytesToLockHigh);
}

EXPORT BOOL WINAPI _LockFileEx(HANDLE hFile,
    DWORD dwFlags,
    DWORD dwReserved,
    DWORD nNumberOfBytesToLockLow,
    DWORD nNumberOfBytesToLockHigh,
    LPOVERLAPPED lpOverlapped) {
    return ::LockFileEx(hFile,
        dwFlags,
        dwReserved,
        nNumberOfBytesToLockLow,
        nNumberOfBytesToLockHigh,
        lpOverlapped);
}

EXPORT LPVOID WINAPI _LockResource(HGLOBAL hResData) {
    return ::LockResource(hResData);
}

EXPORT LPVOID WINAPI _MapViewOfFile(HANDLE hFileMappingObject,
    DWORD dwDesiredAccess,
    DWORD dwFileOffsetHigh,
    DWORD dwFileOffsetLow,
    SIZE_T dwNumberOfBytesToMap) {
    return ::MapViewOfFile(hFileMappingObject,
        dwDesiredAccess,
        dwFileOffsetHigh,
        dwFileOffsetLow,
        dwNumberOfBytesToMap);
}

EXPORT LPVOID WINAPI _MapViewOfFileEx(HANDLE hFileMappingObject,
    DWORD dwDesiredAccess,
    DWORD dwFileOffsetHigh,
    DWORD dwFileOffsetLow,
    SIZE_T dwNumberOfBytesToMap,
    LPVOID lpBaseAddress) {
    return ::MapViewOfFileEx(hFileMappingObject,
        dwDesiredAccess,
        dwFileOffsetHigh,
        dwFileOffsetLow,
        dwNumberOfBytesToMap,
        lpBaseAddress);
}

EXPORT BOOL WINAPI _Module32FirstW(HANDLE hSnapshot,
    LPMODULEENTRY32W lpme) {
    return ::Module32FirstW(hSnapshot,
        lpme);
}

EXPORT BOOL WINAPI _Module32NextW(HANDLE hSnapshot,
    LPMODULEENTRY32W lpme) {
    return ::Module32NextW(hSnapshot,
        lpme);
}

EXPORT BOOL WINAPI _MoveFileExW(LPCWSTR lpExistingFileName,
    LPCWSTR lpNewFileName,
    DWORD    dwFlags) {
    return ::MoveFileExW(lpExistingFileName,
        lpNewFileName,
        dwFlags);
}

EXPORT BOOL WINAPI _MoveFileW(LPCWSTR lpExistingFileName,
    LPCWSTR lpNewFileName) {
    return ::MoveFileW(lpExistingFileName,
        lpNewFileName);
}

EXPORT BOOL WINAPI _MultiByteToWideChar(UINT CodePage,
    DWORD dwFlags,
    LPCCH lpMultiByteStr,
    int cbMultiByte,
    LPWSTR lpWideCharStr,
    int cchWideChar) {
    return ::MultiByteToWideChar(CodePage,
        dwFlags,
        lpMultiByteStr,
        cbMultiByte,
        lpWideCharStr,
        cchWideChar);
}

EXPORT HANDLE WINAPI _OpenProcess(DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    DWORD dwProcessId) {
    return ::OpenProcess(dwDesiredAccess,
        bInheritHandle,
        dwProcessId);
}

EXPORT HANDLE WINAPI _OpenThread(DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    DWORD dwThreadId) {
    return ::OpenThread(dwDesiredAccess,
        bInheritHandle,
        dwThreadId);
}

EXPORT void WINAPI _OutputDebugStringA(LPCSTR lpOutputString) {
    return ::OutputDebugStringA(lpOutputString);
}

EXPORT void WINAPI _OutputDebugStringW(LPCWSTR lpOutputString) {
    return ::OutputDebugStringW(lpOutputString);
}

EXPORT BOOL WINAPI _PeekNamedPipe(HANDLE hNamedPipe,
    LPVOID lpBuffer,
    DWORD nBufferSize,
    LPDWORD lpBytesRead,
    LPDWORD lpTotalBytesAvail,
    LPDWORD lpBytesLeftThisMessage) {
    return ::PeekNamedPipe(hNamedPipe,
        lpBuffer,
        nBufferSize,
        lpBytesRead,
        lpTotalBytesAvail,
        lpBytesLeftThisMessage);
}

EXPORT BOOL WINAPI _PostQueuedCompletionStatus(HANDLE CompletionPort,
    DWORD dwNumberOfBytesTransferred,
    ULONG_PTR dwCompletionKey,
    LPOVERLAPPED lpOverlapped) {
    return ::PostQueuedCompletionStatus(CompletionPort,
        dwNumberOfBytesTransferred,
        dwCompletionKey,
        lpOverlapped);
}

EXPORT BOOL WINAPI _PowerClearRequest(HANDLE PowerRequest,
    POWER_REQUEST_TYPE RequestType) {
    return ::PowerClearRequest(PowerRequest,
        RequestType);
}

EXPORT HANDLE WINAPI _PowerCreateRequest(PREASON_CONTEXT Context) {
    return ::PowerCreateRequest(Context);
}

EXPORT BOOL WINAPI _PowerSetRequest(HANDLE PowerRequest,
    POWER_REQUEST_TYPE RequestType) {
    return ::PowerSetRequest(PowerRequest, RequestType);
}

EXPORT BOOL WINAPI _Process32FirstW(HANDLE hSnapshot,
    LPPROCESSENTRY32W lppe) {
    return ::Process32FirstW(hSnapshot,
        lppe);
}

EXPORT BOOL WINAPI _Process32NextW(HANDLE hSnapshot,
    LPPROCESSENTRY32W lppe) {
    return ::Process32NextW(hSnapshot,
        lppe);
}

EXPORT BOOL WINAPI _ProcessIdToSessionId(DWORD dwProcessId,
    DWORD* pSessionId) {
    return ::ProcessIdToSessionId(dwProcessId,
        pSessionId);
}

EXPORT BOOL WINAPI _PurgeComm(HANDLE hFile,
    DWORD dwFlags) {
    return ::PurgeComm(hFile,
        dwFlags);
}

EXPORT DWORD WINAPI _QueryDosDeviceW(LPCWSTR lpDeviceName,
    LPWSTR lpTargetPath,
    DWORD ucchMax) {
    return ::QueryDosDeviceW(lpDeviceName,
        lpTargetPath,
        ucchMax);
}

EXPORT BOOL WINAPI _QueryFullProcessImageNameA(HANDLE hProcess,
    DWORD dwFlags,
    LPSTR lpExeName,
    PDWORD lpdwSize) {
    return ::QueryFullProcessImageNameA(hProcess,
        dwFlags,
        lpExeName,
        lpdwSize);
}

EXPORT BOOL WINAPI _QueryFullProcessImageNameW(HANDLE hProcess,
    DWORD dwFlags,
    LPWSTR lpExeName,
    PDWORD lpdwSize) {
    return ::QueryFullProcessImageNameW(hProcess,
        dwFlags,
        lpExeName,
        lpdwSize);
}

EXPORT BOOL WINAPI _QueryInformationJobObject(HANDLE hJob,
    JOBOBJECTINFOCLASS JobObjectInformationClass,
    LPVOID lpJobObjectInformation,
    DWORD cbJobObjectInformationLength,
    LPDWORD lpReturnLength) {
    return ::QueryInformationJobObject(hJob,
        JobObjectInformationClass,
        lpJobObjectInformation,
        cbJobObjectInformationLength,
        lpReturnLength);
}

EXPORT BOOL WINAPI _QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount) {
    return ::QueryPerformanceCounter(lpPerformanceCount);
}

EXPORT BOOL WINAPI _QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency) {
    return ::QueryPerformanceFrequency(lpFrequency);
}

EXPORT BOOL WINAPI _QueryProcessCycleTime(HANDLE ProcessHandle,
    PULONG64 CycleTime) {
    return ::QueryProcessCycleTime(ProcessHandle,
        CycleTime);
}

EXPORT BOOL WINAPI _QueryThreadCycleTime(HANDLE ThreadHandle,
    PULONG64 CycleTime) {
    return ::QueryThreadCycleTime(ThreadHandle,
        CycleTime);
}

EXPORT BOOL WINAPI _QueryUnbiasedInterruptTime(PULONGLONG UnbiasedTime) {
    return ::QueryUnbiasedInterruptTime(UnbiasedTime);
}

EXPORT void WINAPI _RaiseException(DWORD dwExceptionCode,
    DWORD dwExceptionFlags,
    DWORD nNumberOfArguments,
    CONST ULONG_PTR* lpArguments) {
    return ::RaiseException(dwExceptionCode,
        dwExceptionFlags,
        nNumberOfArguments,
        lpArguments);
}

EXPORT BOOL WINAPI _ReadConsoleW(HANDLE hConsoleInput,
    LPVOID lpBuffer,
    DWORD nNumberOfCharsToRead,
    LPDWORD lpNumberOfCharsRead,
    PCONSOLE_READCONSOLE_CONTROL pInputControl) {
    return ::ReadConsoleW(hConsoleInput,
        lpBuffer,
        nNumberOfCharsToRead,
        lpNumberOfCharsRead,
        pInputControl);
}

EXPORT BOOL WINAPI _ReadFile(HANDLE hFile,
    LPVOID lpBuffer,
    DWORD nNumberOfBytesToRead,
    LPDWORD lpNumberOfBytesRead,
    LPOVERLAPPED lpOverlapped) {
    return ::ReadFile(hFile,
        lpBuffer,
        nNumberOfBytesToRead,
        lpNumberOfBytesRead,
        lpOverlapped);
}

EXPORT BOOL WINAPI _ReadProcessMemory(HANDLE hProcess,
    LPCVOID lpBaseAddress,
    LPVOID lpBuffer,
    SIZE_T nSize,
    SIZE_T* lpNumberOfBytesRead) {
    return ::ReadProcessMemory(hProcess,
        lpBaseAddress,
        lpBuffer,
        nSize,
        lpNumberOfBytesRead);
}

EXPORT BOOL WINAPI _RegisterWaitForSingleObject(PHANDLE phNewWaitObject,
    HANDLE hObject,
    WAITORTIMERCALLBACK Callback,
    PVOID Context,
    ULONG dwMilliseconds,
    ULONG dwFlags) {
    return ::RegisterWaitForSingleObject(phNewWaitObject,
        hObject,
        Callback,
        Context,
        dwMilliseconds,
        dwFlags);
}

EXPORT BOOL WINAPI _ReleaseMutex(HANDLE hMutex) {
    return ::ReleaseMutex(hMutex);
}

EXPORT void WINAPI _ReleaseSRWLockExclusive(PSRWLOCK SRWLock) {
    return ::ReleaseSRWLockExclusive(SRWLock);
}

EXPORT void WINAPI _ReleaseSRWLockShared(PSRWLOCK SRWLock) {
    return ::ReleaseSRWLockShared(SRWLock);
}

EXPORT BOOL WINAPI _ReleaseSemaphore(HANDLE hSemaphore,
    LONG lReleaseCount,
    LPLONG lpPreviousCount) {
    return ::ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount);
}

EXPORT BOOL WINAPI _RemoveDirectoryW(LPCWSTR lpPathName) {
    return ::RemoveDirectoryW(lpPathName);
}

EXPORT BOOL WINAPI _ReplaceFileW(LPCWSTR lpReplacedFileName,
    LPCWSTR lpReplacementFileName,
    LPCWSTR lpBackupFileName,
    DWORD    dwReplaceFlags,
    LPVOID   lpExclude,
    LPVOID  lpReserved) {
    return ::ReplaceFileW(lpReplacedFileName,
        lpReplacementFileName,
        lpBackupFileName,
        dwReplaceFlags,
        lpExclude,
        lpReserved);
}

EXPORT BOOL WINAPI _ResetEvent(HANDLE hEvent) {
    return ::ResetEvent(hEvent);
}

EXPORT int WINAPI _ResolveLocaleName(LPCWSTR lpNameToResolve,
    LPWSTR  lpLocaleName,
    int     cchLocaleName) {
    return ::ResolveLocaleName(lpNameToResolve, lpLocaleName, cchLocaleName);
}

EXPORT DWORD WINAPI _ResumeThread(HANDLE hThread) {
    return ::ResumeThread(hThread);
}

#if defined(_AMD64_)
EXPORT BOOLEAN WINAPI _RtlAddFunctionTable(PRUNTIME_FUNCTION FunctionTable,
    DWORD EntryCount,
    DWORD BaseAddress) {
    return ::RtlAddFunctionTable(FunctionTable, EntryCount, BaseAddress);
}
#endif

EXPORT VOID WINAPI _RtlCaptureContext(PCONTEXT ContextRecord) {
    return ::RtlCaptureContext(ContextRecord);
}

EXPORT WORD WINAPI _RtlCaptureStackBackTrace(DWORD FramesToSkip,
    DWORD FramesToCapture,
    PVOID* BackTrace,
    PDWORD BackTraceHash) {
    return ::RtlCaptureStackBackTrace(FramesToSkip,
        FramesToCapture,
        BackTrace,
        BackTraceHash);
}

#if defined(_AMD64_)
EXPORT BOOLEAN WINAPI _RtlDeleteFunctionTable(PRUNTIME_FUNCTION FunctionTable) {
    return ::RtlDeleteFunctionTable(FunctionTable);
}

EXPORT PRUNTIME_FUNCTION WINAPI _RtlLookupFunctionEntry(ULONG_PTR ControlPc,
    PDWORD64 ImageBase,
    PUNWIND_HISTORY_TABLE HistoryTable) {
    return ::RtlLookupFunctionEntry(ControlPc, ImageBase, HistoryTable);
}
#endif

#if defined(_AMD64_)
EXPORT PVOID WINAPI _RtlPcToFileHeader(PVOID PcValue,
    PVOID* BaseOfImage) {
    return ::RtlPcToFileHeader(PcValue, BaseOfImage);
}
#else
EXPORT PVOID WINAPI _RtlPcToFileHeader(PVOID PcValue,
    PVOID* BaseOfImage) {
    return 0;
}
#endif

EXPORT VOID WINAPI _RtlUnwind(PVOID TargetFrame,
    PVOID TargetIp,
    PEXCEPTION_RECORD ExceptionRecord,
    PVOID ReturnValue) {
    return ::RtlUnwind(TargetFrame,
        TargetIp,
        ExceptionRecord,
        ReturnValue);
}

#if defined(_AMD64_)
EXPORT VOID WINAPI _RtlUnwindEx(PVOID TargetFrame,
    PVOID TargetIp,
    PEXCEPTION_RECORD ExceptionRecord,
    PVOID ReturnValue,
    PCONTEXT ContextRecord,
    PUNWIND_HISTORY_TABLE HistoryTable) {
    return ::RtlUnwindEx(TargetFrame,
        TargetIp,
        ExceptionRecord,
        ReturnValue,
        ContextRecord,
        HistoryTable);
}

EXPORT PEXCEPTION_ROUTINE WINAPI _RtlVirtualUnwind(DWORD HandlerType,
    DWORD64 ImageBase,
    DWORD64 ControlPc,
    PRUNTIME_FUNCTION FunctionEntry,
    PCONTEXT ContextRecord,
    PVOID* HandlerData,
    PDWORD64 EstablisherFrame,
    PKNONVOLATILE_CONTEXT_POINTERS ContextPointers) {
    return ::RtlVirtualUnwind(HandlerType,
        ImageBase,
        ControlPc,
        FunctionEntry,
        ContextRecord,
        HandlerData,
        EstablisherFrame,
        ContextPointers);
}
#endif

EXPORT BOOL WINAPI _SetCommState(HANDLE hFile,
    LPDCB lpDCB) {
    return ::SetCommState(hFile, lpDCB);
}

EXPORT BOOL WINAPI _SetCommTimeouts(HANDLE hFile,
    LPCOMMTIMEOUTS lpCommTimeouts) {
    return ::SetCommTimeouts(hFile, lpCommTimeouts);
}

EXPORT BOOL WINAPI _SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,
    BOOL Add) {
    return ::SetConsoleCtrlHandler(HandlerRoutine, Add);
}

EXPORT BOOL WINAPI _SetConsoleTextAttribute(HANDLE hConsoleOutput,
    WORD wAttributes) {
    return ::SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

EXPORT BOOL WINAPI _SetCurrentDirectoryW(LPCWSTR lpPathName) {
    return ::SetCurrentDirectoryW(lpPathName);
}

EXPORT BOOL WINAPI _SetDefaultDllDirectories(DWORD DirectoryFlags) {
    return ::SetDefaultDllDirectories(DirectoryFlags);
}

EXPORT BOOL WINAPI _SetDllDirectoryW(LPCWSTR lpPathName) {
    return ::SetDllDirectoryW(lpPathName);
}

EXPORT BOOL WINAPI _SetEndOfFile(HANDLE hFile) {
    return ::SetEndOfFile(hFile);
}

EXPORT BOOL WINAPI _SetEnvironmentVariableA(LPCSTR lpName,
    LPCSTR lpValue) {
    return ::SetEnvironmentVariableA(lpName, lpValue);
}

EXPORT BOOL WINAPI _SetEnvironmentVariableW(LPCWSTR lpName,
    LPCWSTR lpValue) {
    return ::SetEnvironmentVariableW(lpName, lpValue);
}

EXPORT UINT WINAPI _SetErrorMode(UINT uMode) {
    return ::SetErrorMode(uMode);
}

EXPORT BOOL WINAPI _SetEvent(HANDLE hEvent) {
    return ::SetEvent(hEvent);
}

EXPORT BOOL WINAPI _SetFileAttributesW(LPCWSTR lpFileName,
    DWORD dwFileAttributes) {
    return ::SetFileAttributesW(lpFileName, dwFileAttributes);
}

EXPORT BOOL WINAPI _SetFileInformationByHandle(HANDLE hFile,
    FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
    LPVOID lpFileInformation,
    DWORD dwBufferSize) {
    return ::SetFileInformationByHandle(hFile, FileInformationClass, lpFileInformation, dwBufferSize);
}

EXPORT DWORD WINAPI _SetFilePointer(HANDLE hFile,
    LONG lDistanceToMove,
    PLONG lpDistanceToMoveHigh,
    DWORD dwMoveMethod) {
    return ::SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod);
}

EXPORT BOOL WINAPI _SetFilePointerEx(HANDLE hFile,
    LARGE_INTEGER liDistanceToMove,
    PLARGE_INTEGER lpNewFilePointer,
    DWORD dwMoveMethod) {
    return ::SetFilePointerEx(hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod);
}

EXPORT BOOL WINAPI _SetFileTime(HANDLE hFile,
    CONST FILETIME* lpCreationTime,
    CONST FILETIME* lpLastAccessTime,
    CONST FILETIME* lpLastWriteTime) {
    return ::SetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime);
}

EXPORT BOOL WINAPI _SetHandleInformation(HANDLE hObject,
    DWORD dwMask,
    DWORD dwFlags) {
    return ::SetHandleInformation(hObject, dwMask, dwFlags);
}

EXPORT BOOL WINAPI _SetInformationJobObject(HANDLE hJob,
    JOBOBJECTINFOCLASS JobObjectInformationClass,
    LPVOID lpJobObjectInformation,
    DWORD cbJobObjectInformationLength) {
    return ::SetInformationJobObject(hJob, JobObjectInformationClass, lpJobObjectInformation, cbJobObjectInformationLength);
}

EXPORT VOID WINAPI _SetLastError(DWORD dwErrCode) {
    return ::SetLastError(dwErrCode);
}

EXPORT BOOL WINAPI _SetNamedPipeHandleState(HANDLE hNamedPipe,
    LPDWORD lpMode,
    LPDWORD lpMaxCollectionCount,
    LPDWORD lpCollectDataTimeout) {
    return ::SetNamedPipeHandleState(hNamedPipe, lpMode, lpMaxCollectionCount, lpCollectDataTimeout);
}

EXPORT BOOL WINAPI _SetPriorityClass(HANDLE hProcess,
    DWORD dwPriorityClass) {
    return ::SetPriorityClass(hProcess, dwPriorityClass);
}

EXPORT BOOL WINAPI _SetStdHandle(DWORD nStdHandle,
    HANDLE hHandle) {
    return ::SetStdHandle(nStdHandle, hHandle);
}

EXPORT DWORD_PTR WINAPI _SetThreadAffinityMask(HANDLE hThread,
    DWORD_PTR dwThreadAffinityMask) {
    return ::SetThreadAffinityMask(hThread, dwThreadAffinityMask);
}

EXPORT BOOL WINAPI _SetThreadContext(HANDLE hThread,
    CONST CONTEXT* lpContext) {
    return ::SetThreadContext(hThread, lpContext);
}

EXPORT EXECUTION_STATE WINAPI _SetThreadExecutionState(EXECUTION_STATE esFlags) {
    return ::SetThreadExecutionState(esFlags);
}

EXPORT BOOL WINAPI _SetThreadPriority(HANDLE hThread,
    int nPriority) {
    return ::SetThreadPriority(hThread, nPriority);
}

EXPORT BOOL WINAPI _SetThreadPriorityBoost(HANDLE hThread,
    BOOL bDisablePriorityBoost) {
    return ::SetThreadPriorityBoost(hThread, bDisablePriorityBoost);
}

EXPORT LPTOP_LEVEL_EXCEPTION_FILTER WINAPI _SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter) {
    return ::SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}

EXPORT DWORD WINAPI _SizeofResource(HMODULE hModule,
    HRSRC hResInfo) {
    return ::SizeofResource(hModule,
        hResInfo);
}

EXPORT void WINAPI _Sleep(DWORD dwMilliseconds) {
    return ::Sleep(dwMilliseconds);
}

EXPORT BOOL WINAPI _SleepConditionVariableCS(PCONDITION_VARIABLE ConditionVariable,
    PCRITICAL_SECTION CriticalSection,
    DWORD dwMilliseconds) {
    return ::SleepConditionVariableCS(ConditionVariable,
        CriticalSection,
        dwMilliseconds);
}


EXPORT BOOL WINAPI _SleepConditionVariableSRW(PCONDITION_VARIABLE ConditionVariable,
    PSRWLOCK SRWLock,
    DWORD dwMilliseconds,
    ULONG Flags) {
    return ::SleepConditionVariableSRW(ConditionVariable,
        SRWLock,
        dwMilliseconds,
        Flags);
}

EXPORT DWORD WINAPI _SuspendThread(HANDLE hThread) {
    return ::SuspendThread(hThread);
}

EXPORT BOOL WINAPI _SwitchToThread() {
    return ::SwitchToThread();
}

EXPORT BOOL WINAPI _SystemTimeToFileTime(CONST SYSTEMTIME* lpSystemTime,
    LPFILETIME lpFileTime) {
    return ::SystemTimeToFileTime(lpSystemTime,
        lpFileTime);
}

EXPORT BOOL WINAPI _SystemTimeToTzSpecificLocalTime(CONST TIME_ZONE_INFORMATION* lpTimeZoneInformation,
    CONST SYSTEMTIME* lpUniversalTime,
    LPSYSTEMTIME lpLocalTime) {
    return ::SystemTimeToTzSpecificLocalTime(lpTimeZoneInformation,
        lpUniversalTime,
        lpLocalTime);
}

EXPORT BOOL WINAPI _TerminateJobObject(HANDLE hJob,
    UINT uExitCode) {
    return ::TerminateJobObject(hJob, uExitCode);
}

EXPORT BOOL WINAPI _TerminateProcess(HANDLE hProcess,
    UINT uExitCode) {
    return ::TerminateProcess(hProcess, uExitCode);
}

EXPORT DWORD WINAPI _TlsAlloc(VOID) {
    return ::TlsAlloc();
}

EXPORT BOOL WINAPI _TlsFree(DWORD dwTlsIndex) {
    return ::TlsFree(dwTlsIndex);
}

EXPORT LPVOID WINAPI _TlsGetValue(DWORD dwTlsIndex) {
    return ::TlsGetValue(dwTlsIndex);
}

EXPORT BOOL WINAPI _TlsSetValue(DWORD dwTlsIndex,
    LPVOID lpTlsValue) {
    return ::TlsSetValue(dwTlsIndex, lpTlsValue);
}

EXPORT BOOLEAN WINAPI _TryAcquireSRWLockExclusive(PSRWLOCK SRWLock) {
    return ::TryAcquireSRWLockExclusive(SRWLock);
}

EXPORT BOOLEAN WINAPI _TryAcquireSRWLockShared(PSRWLOCK SRWLock) {
    return ::TryAcquireSRWLockShared(SRWLock);
}

EXPORT BOOL WINAPI _TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
    return ::TryEnterCriticalSection(lpCriticalSection);
}

EXPORT BOOL WINAPI _TzSpecificLocalTimeToSystemTime(CONST TIME_ZONE_INFORMATION* lpTimeZoneInformation,
    CONST SYSTEMTIME* lpLocalTime,
    LPSYSTEMTIME lpUniversalTime) {
    return ::TzSpecificLocalTimeToSystemTime(lpTimeZoneInformation, lpLocalTime, lpUniversalTime);
}

EXPORT LONG WINAPI _UnhandledExceptionFilter(_EXCEPTION_POINTERS* ExceptionInfo) {
    return ::UnhandledExceptionFilter(ExceptionInfo);
}

EXPORT BOOL WINAPI _UnlockFile(HANDLE hFile,
    DWORD dwFileOffsetLow,
    DWORD dwFileOffsetHigh,
    DWORD nNumberOfBytesToUnlockLow,
    DWORD nNumberOfBytesToUnlockHigh) {
    return ::UnlockFile(hFile,
        dwFileOffsetLow,
        dwFileOffsetHigh,
        nNumberOfBytesToUnlockLow,
        nNumberOfBytesToUnlockHigh);
}

EXPORT BOOL WINAPI _UnlockFileEx(HANDLE hFile,
    DWORD dwReserved,
    DWORD nNumberOfBytesToUnlockLow,
    DWORD nNumberOfBytesToUnlockHigh,
    LPOVERLAPPED lpOverlapped) {
    return ::UnlockFileEx(hFile,
        dwReserved,
        nNumberOfBytesToUnlockLow,
        nNumberOfBytesToUnlockHigh,
        lpOverlapped);
}

EXPORT BOOL WINAPI _UnmapViewOfFile(LPCVOID lpBaseAddress) {
    return ::UnmapViewOfFile(lpBaseAddress);
}

EXPORT BOOL WINAPI _UnregisterWaitEx(HANDLE WaitHandle,
    HANDLE CompletionEvent) {
    return ::UnregisterWaitEx(WaitHandle, CompletionEvent);
}


EXPORT ULONGLONG WINAPI _VerSetConditionMask(ULONGLONG ConditionMask,
    DWORD TypeMask,
    BYTE  Condition) {
    return ::VerSetConditionMask(ConditionMask,
        TypeMask,
        Condition);
}

EXPORT BOOL WINAPI _VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInformation,
    DWORD dwTypeMask,
    DWORDLONG dwlConditionMask) {
    return ::VerifyVersionInfoW(lpVersionInformation, dwTypeMask, dwlConditionMask);
}

EXPORT LPVOID WINAPI _VirtualAlloc(LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flAllocationType,
    DWORD flProtect) {
    return ::VirtualAlloc(lpAddress,
        dwSize,
        flAllocationType,
        flProtect);
}

EXPORT LPVOID WINAPI _VirtualAllocEx(HANDLE hProcess,
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flAllocationType,
    DWORD flProtect) {
    return ::VirtualAllocEx(hProcess,
        lpAddress,
        dwSize,
        flAllocationType,
        flProtect);
}

EXPORT BOOL WINAPI _VirtualFree(LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD dwFreeType) {
    return ::VirtualFree(lpAddress, dwSize, dwFreeType);
}

EXPORT BOOL WINAPI _VirtualFreeEx(HANDLE hProcess,
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD dwFreeType) {
    return ::VirtualFreeEx(hProcess,
        lpAddress,
        dwSize,
        dwFreeType);
}

EXPORT BOOL WINAPI _VirtualProtect(LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flNewProtect,
    PDWORD lpflOldProtect) {
    return ::VirtualProtect(lpAddress,
        dwSize,
        flNewProtect,
        lpflOldProtect);
}

EXPORT BOOL WINAPI _VirtualProtectEx(HANDLE hProcess,
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flNewProtect,
    PDWORD lpflOldProtect) {
    return ::VirtualProtectEx(hProcess,
        lpAddress,
        dwSize,
        flNewProtect,
        lpflOldProtect);
}

EXPORT SIZE_T WINAPI _VirtualQuery(LPCVOID lpAddress,
    PMEMORY_BASIC_INFORMATION lpBuffer,
    SIZE_T dwLength) {
    return ::VirtualQuery(lpAddress,
        lpBuffer,
        dwLength);
}

EXPORT SIZE_T WINAPI _VirtualQueryEx(HANDLE hProcess,
    LPCVOID lpAddress,
    PMEMORY_BASIC_INFORMATION lpBuffer,
    SIZE_T dwLength) {
    return ::VirtualQueryEx(hProcess,
        lpAddress,
        lpBuffer,
        dwLength);
}


EXPORT BOOL WINAPI _WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,
    DWORD dwMilliseconds) {
    return ::WaitForDebugEvent(lpDebugEvent, dwMilliseconds);
}

EXPORT DWORD WINAPI _WaitForMultipleObjects(DWORD nCount,
    CONST HANDLE* lpHandles,
    BOOL bWaitAll,
    DWORD dwMilliseconds) {
    return ::WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds);
}

EXPORT DWORD WINAPI _WaitForSingleObject(HANDLE hHandle,
    DWORD dwMilliseconds) {
    return ::WaitForSingleObject(hHandle, dwMilliseconds);
}

EXPORT DWORD WINAPI _WaitForSingleObjectEx(HANDLE hHandle,
    DWORD dwMilliseconds,
    BOOL bAlertable) {
    return ::WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable);
}

EXPORT BOOL WINAPI _WaitNamedPipeW(LPCWSTR lpNamedPipeName,
    DWORD nTimeOut) {
    return ::WaitNamedPipeW(lpNamedPipeName, nTimeOut);
}

EXPORT void WINAPI _WakeAllConditionVariable(PCONDITION_VARIABLE ConditionVariable) {
    return ::WakeAllConditionVariable(ConditionVariable);
}

EXPORT void WINAPI _WakeConditionVariable(PCONDITION_VARIABLE ConditionVariable) {
    return ::WakeConditionVariable(ConditionVariable);
}

EXPORT int WINAPI _WideCharToMultiByte(UINT CodePage,
    DWORD dwFlags,
    LPCWCH lpWideCharStr,
    int cchWideChar,
    LPSTR lpMultiByteStr,
    int cbMultiByte,
    LPCCH lpDefaultChar,
    LPBOOL lpUsedDefaultChar) {
    return ::WideCharToMultiByte(CodePage,
        dwFlags,
        lpWideCharStr,
        cchWideChar,
        lpMultiByteStr,
        cbMultiByte,
        lpDefaultChar,
        lpUsedDefaultChar);
}

EXPORT BOOL WINAPI _WriteConsoleW(HANDLE hConsoleOutput,
    CONST VOID* lpBuffer,
    DWORD nNumberOfCharsToWrite,
    LPDWORD lpNumberOfCharsWritten,
    LPVOID lpReserved) {
    return ::WriteConsoleW(hConsoleOutput,
        lpBuffer,
        nNumberOfCharsToWrite,
        lpNumberOfCharsWritten,
        lpReserved);
}

EXPORT BOOL WINAPI _WriteFile(HANDLE hFile,
    LPCVOID lpBuffer,
    DWORD nNumberOfBytesToWrite,
    LPDWORD lpNumberOfBytesWritten,
    LPOVERLAPPED lpOverlapped) {
    return ::WriteFile(hFile,
        lpBuffer,
        nNumberOfBytesToWrite,
        lpNumberOfBytesWritten,
        lpOverlapped);
}

EXPORT BOOL WINAPI _WriteProcessMemory(HANDLE hProcess,
    LPVOID lpBaseAddress,
    LPCVOID lpBuffer,
    SIZE_T nSize,
    SIZE_T* lpNumberOfBytesWritten) {
    return ::WriteProcessMemory(hProcess,
        lpBaseAddress,
        lpBuffer,
        nSize,
        lpNumberOfBytesWritten);
}

EXPORT DWORD WINAPI _WTSGetActiveConsoleSessionId(VOID) {
    return ::WTSGetActiveConsoleSessionId();
}

typedef enum _PROCESSINFOCLASS_NATIVE
{
 //       ProcessBasicInformation, // 0, q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
             ProcessQuotaLimits, // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
             ProcessIoCounters, // q: IO_COUNTERS
             ProcessVmCounters, // q: VM_COUNTERS, VM_COUNTERS_EX, VM_COUNTERS_EX2
             ProcessTimes, // q: KERNEL_USER_TIMES
             ProcessBasePriority, // s: KPRIORITY
             ProcessRaisePriority, // s: ULONG
 //            ProcessDebugPort, // q: HANDLE
             ProcessExceptionPort, // s: HANDLE
             ProcessAccessToken, // s: PROCESS_ACCESS_TOKEN
             ProcessLdtInformation, // 10, qs: PROCESS_LDT_INFORMATION
             ProcessLdtSize, // s: PROCESS_LDT_SIZE
             ProcessDefaultHardErrorMode, // qs: ULONG
             ProcessIoPortHandlers, // (kernel-mode only)
             ProcessPooledUsageAndLimits, // q: POOLED_USAGE_AND_LIMITS
             ProcessWorkingSetWatch, // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
             ProcessUserModeIOPL,
             ProcessEnableAlignmentFaultFixup, // s: BOOLEAN
             ProcessPriorityClass, // qs: PROCESS_PRIORITY_CLASS
             ProcessWx86Information,
             ProcessHandleCount, // 20, q: ULONG, PROCESS_HANDLE_INFORMATION
             ProcessAffinityMask, // s: KAFFINITY
             ProcessPriorityBoost, // qs: ULONG
             ProcessDeviceMap, // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
             ProcessSessionInformation, // q: PROCESS_SESSION_INFORMATION
             ProcessForegroundInformation, // s: PROCESS_FOREGROUND_BACKGROUND
 //            ProcessWow64Information, // q: ULONG_PTR
 //            ProcessImageFileName, // q: UNICODE_STRING
             ProcessLUIDDeviceMapsEnabled, // q: ULONG
//             ProcessBreakOnTermination, // qs: ULONG
             ProcessDebugObjectHandle, // 30, q: HANDLE
             ProcessDebugFlags, // qs: ULONG
             ProcessHandleTracing, // q: PROCESS_HANDLE_TRACING_QUERY; s: size 0 disables, otherwise enables
             ProcessIoPriority, // qs: ULONG
             ProcessExecuteFlags, // qs: ULONG
             ProcessResourceManagement,
             ProcessCookie, // q: ULONG
             ProcessImageInformation, // q: SECTION_IMAGE_INFORMATION
             ProcessCycleTime, // q: PROCESS_CYCLE_TIME_INFORMATION // since VISTA
             ProcessPagePriority, // q: ULONG
             ProcessInstrumentationCallback, // 40
             ProcessThreadStackAllocation, // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
             ProcessWorkingSetWatchEx, // q: PROCESS_WS_WATCH_INFORMATION_EX[]
             ProcessImageFileNameWin32, // q: UNICODE_STRING
             ProcessImageFileMapping, // q: HANDLE (input)
             ProcessAffinityUpdateMode, // qs: PROCESS_AFFINITY_UPDATE_MODE
             ProcessMemoryAllocationMode, // qs: PROCESS_MEMORY_ALLOCATION_MODE
             ProcessGroupInformation, // q: USHORT[]
             ProcessTokenVirtualizationEnabled, // s: ULONG
             ProcessConsoleHostProcess, // q: ULONG_PTR
             ProcessWindowInformation, // 50, q: PROCESS_WINDOW_INFORMATION
             ProcessHandleInformation, // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
             ProcessMitigationPolicy, // s: PROCESS_MITIGATION_POLICY_INFORMATION
             ProcessDynamicFunctionTableInformation,
             ProcessHandleCheckingMode,
             ProcessKeepAliveCount, // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
             ProcessRevokeFileHandles, // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
             ProcessWorkingSetControl, // s: PROCESS_WORKING_SET_CONTROL
             ProcessHandleTable, // since WINBLUE
             ProcessCheckStackExtentsMode,
             ProcessCommandLineInformation, // 60, q: UNICODE_STRING
             ProcessProtectionInformation, // q: PS_PROTECTION
             ProcessMemoryExhaustion, // PROCESS_MEMORY_EXHAUSTION_INFO // since THRESHOLD
             ProcessFaultInformation, // PROCESS_FAULT_INFORMATION
             ProcessTelemetryIdInformation, // PROCESS_TELEMETRY_ID_INFORMATION
             ProcessCommitReleaseInformation, // PROCESS_COMMIT_RELEASE_INFORMATION
             ProcessDefaultCpuSetsInformation,
             ProcessAllowedCpuSetsInformation,
             ProcessReserved1Information,
             ProcessReserved2Information,
            ProcessSubsystemProcess, // 70
        ProcessJobMemoryInformation, // PROCESS_JOB_MEMORY_INFO
        MaxProcessInfoClass
        } PROCESSINFOCLASS_NATIVE;

///////////////

/*
Минимальная версия клиента 	Windows Vista [классические приложения | Приложения UWP]
Минимальная версия сервера 	Windows Server 2003 [классические приложения | Приложения UWP]
Целевая платформа 	Windows
Header 	winbase.h (включая Windows.h)
Библиотека 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT BOOL WINAPI _ConvertFiberToThread()
{
    return ::ConvertFiberToThread();
}


/*
Минимальная версия клиента 	Windows Vista [классические приложения | Приложения UWP]
Минимальная версия сервера 	Windows Server 2003 [классические приложения | Приложения UWP]
Целевая платформа 	Windows
Header 	winbase.h (включая Windows.h)
Библиотека 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT LPVOID WINAPI _ConvertThreadToFiberEx(
    LPVOID lpParameter,
    DWORD  dwFlags
)
{
    return ::ConvertThreadToFiberEx(lpParameter, dwFlags);
}

/*
Минимальная версия клиента 	Windows Vista [классические приложения | Приложения UWP]
Минимальная версия сервера 	Windows Server 2003 [классические приложения | Приложения UWP]
Целевая платформа 	Windows
Header 	winbase.h (включая Windows.h)
Библиотека 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT LPVOID WINAPI _CreateFiber(SIZE_T dwStackSize,
   LPFIBER_START_ROUTINE lpStartAddress,
   LPVOID lpParameter
)
{
    return ::CreateFiber(dwStackSize, lpStartAddress, lpParameter);
}

/*
Минимальная версия клиента 	Windows Vista [классические приложения | Приложения UWP]
Минимальная версия сервера 	Windows Server 2003 [классические приложения | Приложения UWP]
Целевая платформа 	Windows
Header 	winbase.h (включая Windows.h)
Библиотека 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT LPVOID WINAPI _CreateFiberEx(SIZE_T dwStackCommitSize,
    SIZE_T dwStackReserveSize,
    DWORD dwFlags,
    LPFIBER_START_ROUTINE lpStartAddress,
    LPVOID lpParameter
)
{
    return ::CreateFiberEx(dwStackCommitSize, dwStackReserveSize, dwFlags, lpStartAddress, lpParameter);
}

/*
Минимальная версия клиента 	Windows Vista [классические приложения | Приложения UWP]
Минимальная версия сервера 	Windows Server 2003 [классические приложения | Приложения UWP]
Целевая платформа 	Windows
Header 	winbase.h (включая Windows.h)
Библиотека 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT VOID WINAPI _DeleteFiber(LPVOID lpFiber)
{
    return ::DeleteFiber(lpFiber);
}


/*
Минимальная версия клиента 	Windows Vista [классические приложения | Приложения UWP]
Минимальная версия сервера 	Windows Server 2003 [классические приложения | Приложения UWP]
Целевая платформа 	Windows
Header 	winbase.h (включая Windows.h)
Библиотека 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT VOID WINAPI _SwitchToFiber(LPVOID lpFiber)
{
    return ::SwitchToFiber(lpFiber);
}


EXPORT BOOL WINAPI _FreeLibrary(HMODULE hLibModule)
{
    return ::FreeLibrary(hLibModule);
}

//////////////////  + CHROME.exe (116) ////////////////////////

/*
Minimum supported client 	Windows Vista [desktop apps | UWP apps]
Minimum supported server 	Windows Server 2008 [desktop apps | UWP apps]
Target Platform 	Windows
Header 	winbase.h (include Windows.h)
Library 	Kernel32.lib; FileExtd.lib on Windows Server 2003 and Windows XP
DLL 	Kernel32.dll
Redistributable 	Windows SDK on Windows Server 2003 and Windows XP.
*/
EXPORT BOOL WINAPI _GetFileInformationByHandleEx(HANDLE hFile,
    FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
    LPVOID lpFileInformation,
    DWORD dwBufferSize)
{
    return ::GetFileInformationByHandleEx(hFile,
        FileInformationClass,
        lpFileInformation,
        dwBufferSize);
}

EXPORT LCID WINAPI _GetSystemDefaultLCID(VOID)
{
    return ::GetSystemDefaultLCID();
}

EXPORT LCID WINAPI _GetThreadLocale(VOID)
{
    return ::GetThreadLocale();
}

EXPORT BOOL WINAPI _SetProcessShutdownParameters(DWORD dwLevel,
    DWORD dwFlags)
{
    return ::SetProcessShutdownParameters(dwLevel, dwFlags);
}

EXPORT DWORD WINAPI _SleepEx(DWORD dwMilliseconds,
    BOOL bAlertable)
{
    return ::SleepEx(dwMilliseconds, bAlertable);
}

EXPORT BOOL WINAPI _TransactNamedPipe(HANDLE hNamedPipe,
    LPVOID lpInBuffer,
    DWORD nInBufferSize,
    LPVOID lpOutBuffer,
    DWORD nOutBufferSize,
    LPDWORD lpBytesRead,
    LPOVERLAPPED lpOverlapped)
{
    return ::TransactNamedPipe(hNamedPipe,
        lpInBuffer,
        nInBufferSize,
        lpOutBuffer,
        nOutBufferSize,
        lpBytesRead,
        lpOverlapped);
}


//WerRegisterRuntimeExceptionModule
/*
Minimum supported client 	Windows 7 [desktop apps only]
Minimum supported server 	Windows Server 2008 R2 [desktop apps only]
Target Platform 	Windows
Header 	werapi.h
Library 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT HRESULT WINAPI _WerRegisterRuntimeExceptionModule(PCWSTR pwszOutOfProcessCallbackDll,
    PVOID pContext) {
    return ::WerRegisterRuntimeExceptionModule(pwszOutOfProcessCallbackDll,
        pContext);
}

/*/chrome.dll ++*/
//CreateWaitableTimerW
/*
Минимальная версия клиента 	Windows XP [классические приложения | Приложения UWP]
Минимальная версия сервера 	Windows Server 2003 [классические приложения | Приложения UWP]
Целевая платформа 	Windows
Header 	synchapi.h (включая Windows.h)
Библиотека 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT HANDLE WINAPI _CreateWaitableTimerW(
    LPSECURITY_ATTRIBUTES lpTimerAttributes,
    BOOL                  bManualReset,
    LPCWSTR               lpTimerName
){
    return ::CreateWaitableTimerW(lpTimerAttributes, bManualReset, lpTimerName);
}

/*
Minimum supported client 	Windows Vista [desktop apps | UWP apps]
Minimum supported server 	Windows Server 2008 [desktop apps | UWP apps]
Target Platform 	Windows
Header 	synchapi.h (include Windows.h)
Library 	Kernel32.lib
DLL 	Kernel32.dll
*/
EXPORT HANDLE WINAPI _CreateWaitableTimerExW(LPSECURITY_ATTRIBUTES lpTimerAttributes,
    LPCWSTR lpTimerName,
    DWORD dwFlags,
    DWORD dwDesiredAccess
) {
    return ::CreateWaitableTimerExW(lpTimerAttributes, lpTimerName, dwFlags, dwDesiredAccess);
}

EXPORT BOOL WINAPI _SetWaitableTimer(HANDLE hTimer,
    const LARGE_INTEGER* lpDueTime,
    LONG lPeriod,
    PTIMERAPCROUTINE pfnCompletionRoutine,
    LPVOID lpArgToCompletionRoutine,
    BOOL fResume
) {
    return ::SetWaitableTimer(hTimer,
        lpDueTime,
        lPeriod,
        pfnCompletionRoutine,
        lpArgToCompletionRoutine,
        fResume);
    
}

EXPORT BOOL WINAPI _GetThreadSelectorEntry(
     HANDLE hThread,
     DWORD dwSelector,
    LPLDT_ENTRY lpSelectorEntry
) {

    return ::GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry);
}

EXPORT BOOL WINAPI _SetProcessDEPPolicy(DWORD dwFlags
) {
    

    return ::SetProcessDEPPolicy(dwFlags);
}

EXPORT BOOL WINAPI _IsThreadAFiber(VOID) {

    return ::IsThreadAFiber();
}

//electron mail
EXPORT BOOL WINAPI _CancelSynchronousIo(HANDLE hThread) {

    return ::CancelSynchronousIo(hThread);
}

EXPORT HANDLE WINAPI _CreateNamedPipeA(LPCSTR lpName,
    DWORD dwOpenMode,
    DWORD dwPipeMode,
    DWORD nMaxInstances,
    DWORD nOutBufferSize,
    DWORD nInBufferSize,
    DWORD nDefaultTimeOut,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

    return ::CreateNamedPipeA(lpName,
        dwOpenMode,
        dwPipeMode,
        nMaxInstances,
        nOutBufferSize,
        nInBufferSize,
        nDefaultTimeOut,
        lpSecurityAttributes);
}

EXPORT BOOL WINAPI _CreatePipe(PHANDLE hReadPipe,
    PHANDLE hWritePipe,
    LPSECURITY_ATTRIBUTES lpPipeAttributes,
    DWORD nSize) {

    return ::CreatePipe(hReadPipe,
        hWritePipe,
        lpPipeAttributes,
        nSize);
}


EXPORT BOOL WINAPI _CreateSymbolicLinkW(LPCWSTR lpSymlinkFileName,
    LPCWSTR lpTargetFileName,
    DWORD dwFlags) {

    return ::CreateSymbolicLinkW(lpSymlinkFileName,
        lpTargetFileName,
        dwFlags);
}

EXPORT DWORD WINAPI _ExpandEnvironmentStringsA(LPCSTR lpSrc,
    LPSTR lpDst,
    DWORD nSize) {

    return ::ExpandEnvironmentStringsA( lpSrc,
        lpDst,
        nSize);
}

EXPORT BOOL WINAPI _FillConsoleOutputAttribute(HANDLE hConsoleOutput,
    WORD wAttribute,
    DWORD nLength,
    COORD dwWriteCoord,
    LPDWORD lpNumberOfAttrsWritten) {

    return ::FillConsoleOutputAttribute(hConsoleOutput,
        wAttribute,
        nLength,
        dwWriteCoord,
        lpNumberOfAttrsWritten);
}

EXPORT BOOL WINAPI _FillConsoleOutputCharacterW(HANDLE hConsoleOutput,
    WCHAR cCharacter,
    DWORD nLength,
    COORD dwWriteCoord,
    LPDWORD lpNumberOfCharsWritten) {

    return ::FillConsoleOutputCharacterW(hConsoleOutput,
        cCharacter,
        nLength,
        dwWriteCoord,
        lpNumberOfCharsWritten);
}

EXPORT HRSRC WINAPI _FindResourceA(HMODULE hModule,
    LPCSTR lpName,
    LPCSTR lpType) {

    return ::FindResourceA(hModule,
        lpName,
        lpType);
}

EXPORT BOOL WINAPI _GetConsoleCursorInfo(HANDLE hConsoleOutput,
    PCONSOLE_CURSOR_INFO lpConsoleCursorInfo) {

    return ::GetConsoleCursorInfo(hConsoleOutput, lpConsoleCursorInfo);
}

EXPORT BOOL WINAPI _GetConsoleScreenBufferInfo(HANDLE hConsoleOutput,
    PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo) {

    return ::GetConsoleScreenBufferInfo(hConsoleOutput, lpConsoleScreenBufferInfo);
}


EXPORT BOOL WINAPI _GetConsoleTitleW(LPWSTR lpConsoleTitle,
    DWORD nSize) {

    return ::GetConsoleTitleW(lpConsoleTitle, nSize);
}

EXPORT UINT WINAPI _GetErrorMode(VOID) {

    return ::GetErrorMode();
}

EXPORT BOOL WINAPI _GetNumberOfConsoleInputEvents(HANDLE hConsoleInput,
    LPDWORD lpNumberOfEvents) {

    return ::GetNumberOfConsoleInputEvents(hConsoleInput, lpNumberOfEvents);
}


//FIX EXPORT TABLE
#ifdef _AMD64_
EXPORT BOOL _GetProcessIoCounters(
    HANDLE       hProcess,
    PIO_COUNTERS lpIoCounters
) {
    return ::GetProcessIoCounters(hProcess, lpIoCounters);
 }


    EXPORT HANDLE _OpenFileMappingW(DWORD dwDesiredAccess,
        BOOL bInheritHandle,
        LPCWSTR lpName) {
        return ::OpenFileMappingW(dwDesiredAccess,
            bInheritHandle,
            lpName);
    }


    EXPORT BOOL _QueueUserWorkItem(LPTHREAD_START_ROUTINE Function,
        PVOID Context,
        ULONG Flags) {
        return ::QueueUserWorkItem(Function,
            Context,
            Flags);
    }

   EXPORT HANDLE _ReOpenFile(HANDLE  hOriginalFile,
        DWORD   dwDesiredAccess,
        DWORD   dwShareMode,
        DWORD   dwFlagsAndAttributes) {
        return ::ReOpenFile(hOriginalFile,
            dwDesiredAccess,
            dwShareMode,
            dwFlagsAndAttributes);
    }

    EXPORT BOOL _ReadConsoleInputW(HANDLE hConsoleInput,
        PINPUT_RECORD lpBuffer,
        DWORD nLength,
        LPDWORD lpNumberOfEventsRead) {
        return ::ReadConsoleInputW(hConsoleInput,
            lpBuffer,
            nLength,
            lpNumberOfEventsRead);
    }

    EXPORT BOOL _ReadDirectoryChangesW(HANDLE hDirectory,
        LPVOID lpBuffer,
        DWORD nBufferLength,
        BOOL bWatchSubtree,
        DWORD dwNotifyFilter,
        LPDWORD lpBytesReturned,
        LPOVERLAPPED lpOverlapped,
        LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
        return ::ReadDirectoryChangesW(hDirectory,
            lpBuffer,
            nBufferLength,
            bWatchSubtree,
            dwNotifyFilter,
            lpBytesReturned,
            lpOverlapped,
            lpCompletionRoutine);
    }

    EXPORT ULONG _RemoveVectoredExceptionHandler(PVOID Handle) {
        return ::RemoveVectoredExceptionHandler(Handle);
    }

    EXPORT BOOL _SetConsoleCursorInfo(HANDLE hConsoleOutput,
        CONST CONSOLE_CURSOR_INFO* lpConsoleCursorInfo) {
        return ::SetConsoleCursorInfo(hConsoleOutput,
            lpConsoleCursorInfo);
    }

    EXPORT BOOL _SetConsoleCursorPosition(HANDLE hConsoleOutput,
        COORD dwCursorPosition) {
        return ::SetConsoleCursorPosition(hConsoleOutput,
            dwCursorPosition);
    }


    EXPORT BOOL _SetConsoleMode(HANDLE hConsoleHandle,
        DWORD dwMode) {
        return ::SetConsoleMode(hConsoleHandle,
            dwMode);
    }

    EXPORT BOOL _SetConsoleTitleW(LPCWSTR lpConsoleTitle) {
        return ::SetConsoleTitleW(lpConsoleTitle);
    }

    EXPORT BOOL _SetFileCompletionNotificationModes(HANDLE FileHandle,
        UCHAR Flags) {
        return ::SetFileCompletionNotificationModes(FileHandle,
            Flags);
    }

    EXPORT BOOL _UnregisterWait(HANDLE WaitHandle) {
        return ::UnregisterWait(WaitHandle);
    }

    EXPORT BOOL _WriteConsoleInputW(HANDLE hConsoleInput,
        CONST INPUT_RECORD* lpBuffer,
        DWORD nLength,
        LPDWORD lpNumberOfEventsWritten) {
        return ::WriteConsoleInputW(hConsoleInput,
            lpBuffer,
            nLength,
            lpNumberOfEventsWritten);
    }

#else
EXPORT BOOL __GetProcessIoCounters(
    HANDLE       hProcess,
    PIO_COUNTERS lpIoCounters
) {
    return ::GetProcessIoCounters(hProcess, lpIoCounters);
}



EXPORT HANDLE __OpenFileMappingW(DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPCWSTR lpName) {
    return ::OpenFileMappingW(dwDesiredAccess,
        bInheritHandle,
        lpName);
    }


    EXPORT BOOL __QueueUserWorkItem(LPTHREAD_START_ROUTINE Function,
        PVOID Context,
        ULONG Flags) {
        return ::QueueUserWorkItem(Function,
            Context,
            Flags);
    }


    EXPORT HANDLE __ReOpenFile(HANDLE  hOriginalFile,
        DWORD   dwDesiredAccess,
        DWORD   dwShareMode,
        DWORD   dwFlagsAndAttributes) {
        return ::ReOpenFile(hOriginalFile,
            dwDesiredAccess,
            dwShareMode,
            dwFlagsAndAttributes);
    }

    EXPORT BOOL __ReadConsoleInputW(HANDLE hConsoleInput,
        PINPUT_RECORD lpBuffer,
        DWORD nLength,
        LPDWORD lpNumberOfEventsRead) {
        return ::ReadConsoleInputW(hConsoleInput,
            lpBuffer,
            nLength,
            lpNumberOfEventsRead);
    }

    EXPORT BOOL __ReadDirectoryChangesW(HANDLE hDirectory,
        LPVOID lpBuffer,
        DWORD nBufferLength,
        BOOL bWatchSubtree,
        DWORD dwNotifyFilter,
        LPDWORD lpBytesReturned,
        LPOVERLAPPED lpOverlapped,
        LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
        return ::ReadDirectoryChangesW(hDirectory,
            lpBuffer,
            nBufferLength,
            bWatchSubtree,
            dwNotifyFilter,
            lpBytesReturned,
            lpOverlapped,
            lpCompletionRoutine);
    }

    EXPORT ULONG __RemoveVectoredExceptionHandler(PVOID Handle) {
        return ::RemoveVectoredExceptionHandler(Handle);
    }

    EXPORT BOOL __SetConsoleCursorInfo(HANDLE hConsoleOutput,
        CONST CONSOLE_CURSOR_INFO* lpConsoleCursorInfo) {
        return ::SetConsoleCursorInfo(hConsoleOutput,
            lpConsoleCursorInfo);
    }

    EXPORT BOOL __SetConsoleCursorPosition(HANDLE hConsoleOutput,
        COORD dwCursorPosition) {
        return ::SetConsoleCursorPosition(hConsoleOutput,
            dwCursorPosition);
    }


    EXPORT BOOL __SetConsoleMode(HANDLE hConsoleHandle,
        DWORD dwMode) {
        return ::SetConsoleMode(hConsoleHandle,
            dwMode);
    }

    EXPORT BOOL __SetConsoleTitleW(LPCWSTR lpConsoleTitle) {
        return ::SetConsoleTitleW(lpConsoleTitle);
    }

    EXPORT BOOL __SetFileCompletionNotificationModes(HANDLE FileHandle,
        UCHAR Flags) {
        return ::SetFileCompletionNotificationModes(FileHandle,
            Flags);
    }

    EXPORT BOOL __UnregisterWait(HANDLE WaitHandle) {
        return ::UnregisterWait(WaitHandle);
    }

    EXPORT BOOL __WriteConsoleInputW(HANDLE hConsoleInput,
        CONST INPUT_RECORD* lpBuffer,
        DWORD nLength,
        LPDWORD lpNumberOfEventsWritten) {
        return ::WriteConsoleInputW(hConsoleInput,
            lpBuffer,
            nLength,
            lpNumberOfEventsWritten);
    }
#endif // _AMD64_


//OPERA BROWSER
EXPORT int WINAPI _CompareStringOrdinal(LPCWCH lpString1,
    int cchCount1,
    LPCWCH lpString2,
    int cchCount2,
    BOOL bIgnoreCase)
{
    return  ::CompareStringOrdinal(lpString1,
        cchCount1,
        lpString2,
        cchCount2,
        bIgnoreCase);
}


EXPORT HRSRC WINAPI _FindResourceExW(HMODULE hModule,
    LPCWSTR lpType,
    LPCWSTR lpName,
    WORD wLanguage)
{
    return  ::FindResourceExW(hModule,
        lpType,
        lpName,
        wLanguage);
}

EXPORT BOOL WINAPI _GetHandleInformation(HANDLE hObject,
    LPDWORD lpdwFlags)
{
    return  ::GetHandleInformation(hObject,
        lpdwFlags);
}

EXPORT DWORD WINAPI _GetLogicalDrives(VOID)
{
    return  ::GetLogicalDrives();
}

EXPORT HANDLE WINAPI _OpenEventW(DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPCWSTR lpName)
{
    return  ::OpenEventW(dwDesiredAccess,
        bInheritHandle,
        lpName);
}

EXPORT HANDLE WINAPI _OpenMutexW(DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPCWSTR lpName)
{
    return  ::OpenMutexW(dwDesiredAccess,
        bInheritHandle,
        lpName);
}

EXPORT DWORD WINAPI _QueueUserAPC(PAPCFUNC pfnAPC,
    HANDLE hThread,
    ULONG_PTR dwData)
{
    return  ::QueueUserAPC(pfnAPC,
        hThread,
        dwData);
}

EXPORT BOOL WINAPI _TerminateThread(HANDLE hThread,
    DWORD dwExitCode)
{
    return  ::TerminateThread(hThread,
        dwExitCode);
}

//spotify 
EXPORT BOOL WINAPI _CreateProcessA(LPCSTR lpApplicationName,
    LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation)
{
    return  ::CreateProcessA(lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation);
}

//CHROME 109
EXPORT BOOL WINAPI _CallbackMayRunLong(PTP_CALLBACK_INSTANCE pcin)
{
    return  ::CallbackMayRunLong(pcin);
}

EXPORT void WINAPI _CloseThreadpool(PTP_POOL ptpp)
{
    return  ::CloseThreadpool(ptpp);
}

EXPORT void WINAPI _CloseThreadpoolWork(PTP_WORK pwk)
{
    return  ::CloseThreadpoolWork(pwk);
}

EXPORT PTP_POOL WINAPI _CreateThreadpool(PVOID reserved)
{
    return  ::CreateThreadpool(reserved);
}

EXPORT PTP_WORK WINAPI _CreateThreadpoolWork(PTP_WORK_CALLBACK pfnwk,
    PVOID pv,
    PTP_CALLBACK_ENVIRON pcbe)
{
    return  ::CreateThreadpoolWork(pfnwk, pv, pcbe);
}

EXPORT BOOL WINAPI _IsProcessInJob(HANDLE ProcessHandle,
    HANDLE JobHandle,
    PBOOL Result)
{
    return  ::IsProcessInJob(ProcessHandle, JobHandle, Result);
}

EXPORT BOOL WINAPI _K32EmptyWorkingSet(HANDLE hProcess)
{
    return  ::K32EmptyWorkingSet(hProcess);
}

EXPORT void WINAPI _RaiseFailFastException(PEXCEPTION_RECORD pExceptionRecord,
    PCONTEXT pContextRecord,
    DWORD dwFlags)
{
    return  ::RaiseFailFastException(pExceptionRecord, pContextRecord, dwFlags);
}

EXPORT void WINAPI _SetThreadpoolThreadMaximum(PTP_POOL ptpp,
    DWORD cthrdMost)
{
    return  ::SetThreadpoolThreadMaximum(ptpp, cthrdMost);
}

EXPORT BOOL WINAPI _SetThreadpoolThreadMinimum(PTP_POOL ptpp,
    DWORD cthrdMost)
{
    return  ::SetThreadpoolThreadMinimum(ptpp, cthrdMost);
}

EXPORT void WINAPI _SubmitThreadpoolWork(PTP_WORK pwk)
{
    return  ::SubmitThreadpoolWork(pwk);
}

EXPORT void WINAPI _WaitForThreadpoolWorkCallbacks(PTP_WORK pwk,
    BOOL fCancelPendingCallbacks)
{
    return  ::WaitForThreadpoolWorkCallbacks(pwk, fCancelPendingCallbacks);
}

EXPORT BOOL WINAPI _WaitNamedPipeA(LPCSTR lpNamedPipeName,
    DWORD nTimeOut)
{
    return  ::WaitNamedPipeA(lpNamedPipeName, nTimeOut);
}

//EDGE 120

EXPORT UINT WINAPI _GetSystemWow64DirectoryW(LPWSTR lpBuffer,
    UINT uSize)
{
    return  ::GetSystemWow64DirectoryW(lpBuffer, uSize);
}


EXPORT VOID WINAPI _CloseThreadpoolWait(PTP_WAIT pwa)
{
    return  ::CloseThreadpoolWait(pwa);
}

EXPORT LONG WINAPI _CompareFileTime(CONST FILETIME* lpFileTime1,
    CONST FILETIME* lpFileTime2)
{
    return  ::CompareFileTime(lpFileTime1, lpFileTime2);
}

EXPORT int WINAPI _CompareStringEx(LPCWSTR lpLocaleName,
    DWORD dwCmpFlags,
    LPCWCH lpString1,
    int cchCount1,
    LPCWCH lpString2,
    int cchCount2,
    LPNLSVERSIONINFO lpVersionInformation,
    LPVOID lpReserved,
    LPARAM lParam)
{
    return  ::CompareStringEx(lpLocaleName,
        dwCmpFlags,
        lpString1,
        cchCount1,
        lpString2,
        cchCount2,
        lpVersionInformation,
        lpReserved,
        lParam);
}

EXPORT HANDLE WINAPI _CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL bInitialOwner,
    LPCSTR lpName)
{
    return  ::CreateMutexA(lpMutexAttributes,
        bInitialOwner,
        lpName);
}

EXPORT PTP_WAIT WINAPI _CreateThreadpoolWait(PTP_WAIT_CALLBACK pfnwa,
    PVOID pv,
    PTP_CALLBACK_ENVIRON pcbe)
{
    return  ::CreateThreadpoolWait(pfnwa,
        pv,
        pcbe);
}

EXPORT DWORD WINAPI _GetDllDirectoryW(DWORD nBufferLength,
    LPWSTR lpBuffer)
{
    return  ::GetDllDirectoryW(nBufferLength,
        lpBuffer);
}

EXPORT BOOL WINAPI _GetPhysicallyInstalledSystemMemory(PULONGLONG TotalMemoryInKilobytes)
{
    return  ::GetPhysicallyInstalledSystemMemory(TotalMemoryInKilobytes);
}

EXPORT BOOL WINAPI _GetSystemPreferredUILanguages(DWORD dwFlags,
    PULONG pulNumLanguages,
    PZZWSTR pwszLanguagesBuffer,
    PULONG pcchLanguagesBuffer)
{
    return  ::GetSystemPreferredUILanguages(dwFlags,
        pulNumLanguages,
        pwszLanguagesBuffer,
        pcchLanguagesBuffer);
}

EXPORT BOOL WINAPI _GetUserPreferredUILanguages(DWORD dwFlags,
    PULONG pulNumLanguages,
    PZZWSTR pwszLanguagesBuffer,
    PULONG pcchLanguagesBuffer)
{
    return  ::GetUserPreferredUILanguages(dwFlags,
        pulNumLanguages,
        pwszLanguagesBuffer,
        pcchLanguagesBuffer);
}

EXPORT BOOL WINAPI _GetVersionExA(LPOSVERSIONINFOA lpVersionInformation)
{
    return  ::GetVersionExA(lpVersionInformation);
}

EXPORT ATOM WINAPI _GlobalAddAtomA(LPCSTR lpString)
{
    return  ::GlobalAddAtomA(lpString);
}

EXPORT ATOM WINAPI _GlobalDeleteAtom(ATOM nAtom)
{
    return  ::GlobalDeleteAtom(nAtom);
}

EXPORT ATOM WINAPI _GlobalFindAtomA(LPCSTR lpString)
{
    return  ::GlobalFindAtomA(lpString);
}

EXPORT BOOL WINAPI _K32EnumProcesses(DWORD* lpidProcess,
    DWORD cb,
    LPDWORD lpcbNeeded)
{
    return  ::K32EnumProcesses(lpidProcess, cb, lpcbNeeded);
}

EXPORT DWORD WINAPI _K32GetProcessImageFileNameA(HANDLE hProcess,
    LPSTR lpImageFileName,
    DWORD nSize)
{
    return  ::K32GetProcessImageFileNameA(hProcess, lpImageFileName, nSize);
}

EXPORT DWORD WINAPI _K32GetProcessImageFileNameW(HANDLE hProcess,
    LPWSTR lpImageFileName,
    DWORD nSize)
{
    return  ::K32GetProcessImageFileNameW(hProcess, lpImageFileName, nSize);
}

EXPORT int WINAPI _LCMapStringEx(LPCWSTR lpLocaleName,
    DWORD dwMapFlags,
    LPCWSTR lpSrcStr,
    int cchSrc,
    LPWSTR lpDestStr,
    int cchDest,
    LPNLSVERSIONINFO lpVersionInformation,
    LPVOID lpReserved,
    LPARAM sortHandle)
{
    return  ::LCMapStringEx(lpLocaleName,
        dwMapFlags,
        lpSrcStr,
        cchSrc,
        lpDestStr,
        cchDest,
        lpVersionInformation,
        lpReserved,
        sortHandle);
}

EXPORT DWORD WINAPI _NormalizeString(NORM_FORM NormForm,
    LPCWSTR   lpSrcString,
    int       cwSrcLength,
    LPWSTR    lpDstString,
    int       cwDstLength)
{
    return  ::NormalizeString(NormForm,
        lpSrcString,
        cwSrcLength,
        lpDstString,
        cwDstLength);
}


EXPORT USHORT WINAPI _QueryDepthSList(PSLIST_HEADER ListHead)
{
    return  ::QueryDepthSList(ListHead);
}

EXPORT USHORT WINAPI _QueryDosDeviceA(LPCSTR lpDeviceName,
    LPSTR lpTargetPath,
    DWORD ucchMax) {
    return ::QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax);
}

EXPORT HRESULT WINAPI _RegisterApplicationRestart(PCWSTR pwzCommandline,
    DWORD dwFlags)
{
    return  ::RegisterApplicationRestart(pwzCommandline, dwFlags);
}

EXPORT void WINAPI _SetThreadpoolWait(PTP_WAIT pwa,
    HANDLE h,
    PFILETIME pftTimeout)
{
    return  ::SetThreadpoolWait(pwa, h, pftTimeout);
}

EXPORT HRESULT WINAPI _UnregisterApplicationRestart(void)
{
    return  ::UnregisterApplicationRestart();
}

EXPORT void WINAPI _WaitForThreadpoolWaitCallbacks(PTP_WAIT pwa,
    BOOL fCancelPendingCallbacks)
{
    return  ::WaitForThreadpoolWaitCallbacks(pwa, fCancelPendingCallbacks);
}

//EDGE 120...77
EXPORT DWORD WINAPI _WaitForMultipleObjectsEx(DWORD nCount,
    CONST HANDLE* lpHandles,
    BOOL bWaitAll,
    DWORD dwMilliseconds,
    BOOL bAlertable)
{
    return  ::WaitForMultipleObjectsEx(nCount,
        lpHandles,
        bWaitAll,
        dwMilliseconds,
        bAlertable);
}

EXPORT HANDLE WINAPI _OpenEventA(DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPCSTR lpName)
{
    return  ::OpenEventA(dwDesiredAccess,
        bInheritHandle,
        lpName);
}

//brave 

//IMPORT TABLE BUG??????????????
#ifndef _AMD64_
EXPORT BOOL WINAPI _SetThreadStackGuarantee(PULONG StackSizeInBytes)
{
    return ::SetThreadStackGuarantee(StackSizeInBytes);
}

EXPORT BOOL __WritePrivateProfileStringW(LPCWSTR lpAppName,
    LPCWSTR lpKeyName,
    LPCWSTR lpString,
    LPCWSTR lpFileName)
{
    return ::WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName);
}

EXPORT BOOL WINAPI _K32GetModuleFileNameExA(HANDLE hProcess,
    HMODULE hModule,
    LPSTR lpFilename,
    DWORD nSize)
{
    return ::K32GetModuleFileNameExA(hProcess, hModule, lpFilename, nSize);
}

EXPORT BOOL WINAPI _K32GetModuleBaseNameW(HANDLE hProcess,
    HMODULE hModule,
    LPWSTR lpBaseName,
    DWORD nSize)
{
    return ::K32GetModuleBaseNameW(hProcess, hModule, lpBaseName, nSize);
}

EXPORT BOOL WINAPI _DisableThreadLibraryCalls(HMODULE hLibModule)
{
    return  ::DisableThreadLibraryCalls(hLibModule);
}

#else
EXPORT BOOL WINAPI _SetThreadStackGuarantee(PULONG StackSizeInBytes)
{
    return ::SetThreadStackGuarantee(StackSizeInBytes);
}

EXPORT BOOL WINAPI _WritePrivateProfileStringW(LPCWSTR lpAppName,
    LPCWSTR lpKeyName,
    LPCWSTR lpString,
    LPCWSTR lpFileName)
{
    return ::WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName);
}

EXPORT BOOL WINAPI _K32GetModuleFileNameExA(HANDLE hProcess,
    HMODULE hModule,
    LPSTR lpFilename,
    DWORD nSize)
{
    return ::K32GetModuleFileNameExA(hProcess, hModule, lpFilename, nSize);
}

EXPORT BOOL WINAPI _K32GetModuleBaseNameW(HANDLE hProcess,
    HMODULE hModule,
    LPWSTR lpBaseName,
    DWORD nSize)
{
    return ::K32GetModuleBaseNameW(hProcess, hModule, lpBaseName, nSize);
}

EXPORT BOOL WINAPI _DisableThreadLibraryCalls(HMODULE hLibModule)
{
    return  ::DisableThreadLibraryCalls(hLibModule);
}
#endif // __AMD64
//opera_GX

EXPORT BOOL WINAPI _SetProcessAffinityMask(HANDLE hProcess,
    DWORD_PTR dwProcessAffinityMask) {
    return ::SetProcessAffinityMask(hProcess, dwProcessAffinityMask);
}

EXPORT BOOL WINAPI _GetExitCodeThread(HANDLE hThread, LPDWORD lpExitCode) {
    return ::GetExitCodeThread(hThread, lpExitCode);
}

EXPORT BOOL WINAPI _QueryMemoryResourceNotification(HANDLE ResourceNotificationHandle, PBOOL  ResourceState) {
    return ::QueryMemoryResourceNotification(ResourceNotificationHandle, ResourceState);
}

EXPORT  BOOL WINAPI _GetStringTypeExW(
    LCID                          Locale,
    DWORD                         dwInfoType,
    LPCWCH                        lpSrcStr,
    int                           cchSrc,
    LPWORD                        lpCharType
){
    return ::GetStringTypeExW(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType);
}

EXPORT HANDLE WINAPI _CreateFileMappingA(HANDLE hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD flProtect,
    DWORD dwMaximumSizeHigh,
    DWORD dwMaximumSizeLow,
    LPCSTR lpName)
{
    return ::CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
}

EXPORT HANDLE WINAPI _CreateEventExW(LPSECURITY_ATTRIBUTES lpEventAttributes,
    LPCWSTR lpName,
    DWORD dwFlags,
    DWORD dwDesiredAccess) {
    return ::CreateEventExW(lpEventAttributes, lpName, dwFlags, dwDesiredAccess);
}

EXPORT HANDLE WINAPI _OpenFileMappingA(DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPCSTR lpName)
{
    return ::OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName);
}

EXPORT BOOL _GetQueuedCompletionStatusEx(HANDLE CompletionPort,
    LPOVERLAPPED_ENTRY lpCompletionPortEntries,
    ULONG ulCount,
    PULONG ulNumEntriesRemoved,
    DWORD dwMilliseconds,
    BOOL fAlertable) {
    return ::GetQueuedCompletionStatusEx(CompletionPort, lpCompletionPortEntries, ulCount, ulNumEntriesRemoved, dwMilliseconds, fAlertable);
}

//** FIREFOX (130.0.1) ** //
EXPORT BOOL _CopyFileExW(LPCWSTR lpExistingFileName,
    LPCWSTR lpNewFileName,
    LPPROGRESS_ROUTINE lpProgressRoutine,
    LPVOID lpData,
    LPBOOL pbCancel,
    DWORD dwCopyFlags){

    return ::CopyFileExW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags);
}

EXPORT BOOL _GetApplicationRestartSettings(HANDLE hProcess,
    PWSTR pwzCommandline,
    PDWORD pcchSize,
    PDWORD pdwFlags) {

    return ::GetApplicationRestartSettings(hProcess, pwzCommandline, pcchSize, pdwFlags);
}


EXPORT int _GetDateFormatA(LCID             Locale,
    DWORD            dwFlags,
    const SYSTEMTIME* lpDate,
    LPCSTR           lpFormat,
    LPSTR            lpDateStr,
    int              cchDate) {
    return ::GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate);
}

EXPORT int _GetProcessIdOfThread(HANDLE Thread) {
    return ::GetProcessIdOfThread(Thread);
}

EXPORT LANGID _GetSystemDefaultLangID(void) {
    return ::GetSystemDefaultLangID();
}

EXPORT LANGID _GetTempFileNameW(LPCWSTR lpPathName,
    LPCWSTR lpPrefixString,
    UINT uUnique,
    LPWSTR lpTempFileName) {
    return ::GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName);
}

EXPORT int _GetTimeFormatA(LCID Locale,
    DWORD dwFlags,
    CONST SYSTEMTIME* lpTime,
    LPCSTR lpFormat,
    LPSTR lpTimeStr,
    int cchTime) {
    return ::GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
}

EXPORT DWORD _GetVersion(VOID) {
    return ::GetVersion();
}

EXPORT HGLOBAL _GlobalReAlloc(HGLOBAL hMem,
    SIZE_T dwBytes,
    UINT uFlags) {
    return ::GlobalReAlloc(hMem, dwBytes, uFlags);
}

EXPORT HANDLE _OpenMutexA(DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPCSTR lpName) {
    return ::OpenMutexA(dwDesiredAccess, bInheritHandle, lpName);
}

EXPORT BOOL _ReplaceFileA(LPCSTR lpReplacedFileName,
    LPCSTR lpReplacementFileName,
    LPCSTR lpBackupFileName,
    DWORD    dwReplaceFlags,
    LPVOID   lpExclude,
    LPVOID  lpReserved) {
    return ::ReplaceFileA(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved);
}

EXPORT BOOL _SetThreadErrorMode(DWORD dwNewMode,
    LPDWORD lpOldMode) {
    return ::SetThreadErrorMode(dwNewMode, lpOldMode);
}

EXPORT DWORD _SetThreadIdealProcessor(HANDLE hThread,
    DWORD dwIdealProcessor) {
    return ::SetThreadIdealProcessor(hThread, dwIdealProcessor);
}

EXPORT BOOL _VirtualUnlock(LPVOID lpAddress,
    SIZE_T dwSize) {
    return ::VirtualUnlock(lpAddress, dwSize);
}

EXPORT BOOL _ReadFileEx(HANDLE hFile,
    LPVOID lpBuffer,
    DWORD nNumberOfBytesToRead,
    LPOVERLAPPED lpOverlapped,
    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
    return ::ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
}

EXPORT BOOL _WriteFileEx(HANDLE hFile,
    LPVOID lpBuffer,
    DWORD nNumberOfBytesToRead,
    LPOVERLAPPED lpOverlapped,
    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
    return ::WriteFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
}

EXPORT LPSTR  _lstrcatA(LPSTR lpString1, // deprecated: annotation is as good as it gets
    LPCSTR lpString2) {
    return ::lstrcatA(lpString1, lpString2);
}

EXPORT LPWSTR  _lstrcatW(LPWSTR lpString1, // deprecated: annotation is as good as it gets
    LPWSTR lpString2) {
    return ::lstrcatW(lpString1, lpString2);
}

EXPORT int WINAPI _lstrcmpA(LPCSTR lpString1,
    LPCSTR lpString2)
{
    return  ::lstrcmpA(lpString1,
        lpString2);
}

EXPORT int WINAPI _lstrcmpW(LPCWSTR lpString1,
    LPCWSTR lpString2) {
    return ::lstrcmpW(lpString1, lpString2);
}


EXPORT int WINAPI _lstrcmpiA(LPCSTR lpString1,
    LPCSTR lpString2) {
    return ::lstrcmpiA(lpString1, lpString2);
}


EXPORT int WINAPI _lstrcmpiW(LPCWSTR lpString1,
    LPCWSTR lpString2) {
    return ::lstrcmpiW(lpString1, lpString2);
}


EXPORT int WINAPI _lstrlenA(LPCSTR lpString) {
    return ::lstrlenA(lpString);
}


EXPORT int WINAPI _lstrlenW(LPCWSTR lpString)
{
    return  ::lstrlenW(lpString);
}

EXPORT LPWSTR WINAPI _lstrcpyW(LPWSTR lpString1, // deprecated: annotation is as good as it gets
    LPCWSTR lpString2)
{
    return  ::lstrcpyW(lpString1, lpString2);
}

EXPORT LPWSTR WINAPI _lstrcpynW(LPWSTR lpString1,
    LPCWSTR lpString2,
    int iMaxLength)
{
    return  ::lstrcpynW(lpString1, lpString2, iMaxLength);
}

///////

EXPORT int WINAPI _zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz_LAST(LPCSTR lpString) {
    return 0x386;
}
EXPORT int WINAPI _zz_LAST(LPCSTR lpString) {
    return 0x386;
}


}
