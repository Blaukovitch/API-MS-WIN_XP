//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 

#define NTSTATUS signed long


#define STATUS_SUCCESS   ((NTSTATUS)0x00000000L) // ntsubauth
#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0

typedef enum _THREADINFOCLASS {
    ThreadBasicInformation = 0,
    ThreadTimes = 1,
    ThreadPriority = 2,
    ThreadBasePriority = 3,
    ThreadAffinityMask = 4,
    ThreadImpersonationToken = 5,
    ThreadDescriptorTableEntry = 6,
    ThreadEnableAlignmentFaultFixup = 7,
    ThreadEventPair_Reusable = 8,
    ThreadQuerySetWin32StartAddress = 9,
    ThreadZeroTlsCell = 10,
    ThreadPerformanceCount = 11,
    ThreadAmILastThread = 12,
    ThreadIdealProcessor = 13,
    ThreadPriorityBoost = 14,
    ThreadSetTlsArrayAddress = 15,   // Obsolete
    ThreadIsIoPending = 16,
    ThreadHideFromDebugger = 17,
    ThreadBreakOnTermination = 18,
    ThreadSwitchLegacyState = 19,
    ThreadIsTerminated = 20,
    ThreadLastSystemCall = 21,
    ThreadIoPriority = 22,
    ThreadCycleTime = 23,
    ThreadPagePriority = 24,
    ThreadActualBasePriority = 25,
    ThreadTebInformation = 26,
    ThreadCSwitchMon = 27,   // Obsolete
    ThreadCSwitchPmu = 28,
    ThreadWow64Context = 29,
    ThreadGroupInformation = 30,
    ThreadUmsInformation = 31,   // UMS
    ThreadCounterProfiling = 32,
    ThreadIdealProcessorEx = 33,
    ThreadCpuAccountingInformation = 34,
    ThreadSuspendCount = 35,
    ThreadActualGroupAffinity = 41,
    ThreadDynamicCodePolicyInfo = 42,
    MaxThreadInfoClass = 45,
} THREADINFOCLASS;



#if (NTDDI_VERSION >= NTDDI_WINXP)
typedef NTSTATUS (WINAPI
api_NtSetInformationThread)(
    HANDLE ThreadHandle,
    THREADINFOCLASS ThreadInformationClass,
    PVOID ThreadInformation,
    ULONG ThreadInformationLength
);
#endif // NTDDI_VERSION >= NTDDI_WINXP


typedef enum _VIRTUAL_MEMORY_INFORMATION_CLASS
{
    VmPrefetchInformation,
    VmPagePriorityInformation,
    VmCfgCallTargetInformation
} VIRTUAL_MEMORY_INFORMATION_CLASS;

typedef struct _MEMORY_RANGE_ENTRY
{
    PVOID	VirtualAddress;
    SIZE_T	NumberOfBytes;
} MEMORY_RANGE_ENTRY, * PMEMORY_RANGE_ENTRY;

typedef NTSTATUS(WINAPI api_NtSetInformationVirtualMemory)(
    HANDLE								hProcess,
    VIRTUAL_MEMORY_INFORMATION_CLASS	VmInformationClass,
    ULONG_PTR							NumberOfEntries,
    PMEMORY_RANGE_ENTRY					VirtualAddresses,
    PVOID								VmInformation,
    ULONG								VmInformationLength
    );

typedef enum PROCESSINFOCLASS
{
    ProcessBasicInformation = 0x00,
    ProcessQuotaLimits = 0x01,
    ProcessIoCounters = 0x02,
    ProcessVmCounters = 0x03,
    ProcessTimes = 0x04,
    ProcessBasePriority = 0x05,
    ProcessRaisePriority = 0x06,
    ProcessDebugPort = 0x07,
    ProcessExceptionPort = 0x08,
    ProcessAccessToken = 0x09,
    ProcessLdtInformation = 0x0A,
    ProcessLdtSize = 0x0B,
    ProcessDefaultHardErrorMode = 0x0C,
    ProcessIoPortHandlers = 0x0D,
    ProcessPooledUsageAndLimits = 0x0E,
    ProcessWorkingSetWatch = 0x0F,
    ProcessUserModeIOPL = 0x10,
    ProcessEnableAlignmentFaultFixup = 0x11,
    ProcessPriorityClass = 0x12,
    ProcessWx86Information = 0x13,
    ProcessHandleCount = 0x14,
    ProcessAffinityMask = 0x15,
    ProcessPriorityBoost = 0x16,
    ProcessDeviceMap = 0x17,
    ProcessSessionInformation = 0x18,
    ProcessForegroundInformation = 0x19,
    ProcessWow64Information = 0x1A,
    ProcessImageFileName = 0x1B,
    ProcessLUIDDeviceMapsEnabled = 0x1C,
    ProcessBreakOnTermination = 0x1D,
    ProcessDebugObjectHandle = 0x1E,
    ProcessDebugFlags = 0x1F,
    ProcessHandleTracing = 0x20,
    ProcessIoPriority = 0x21,
    ProcessExecuteFlags = 0x22,
    ProcessResourceManagement = 0x23,
    ProcessCookie = 0x24,
    ProcessImageInformation = 0x25,
    ProcessCycleTime = 0x26,
    ProcessPagePriority = 0x27,
    ProcessInstrumentationCallback = 0x28,
    ProcessThreadStackAllocation = 0x29,
    ProcessWorkingSetWatchEx = 0x2A,
    ProcessImageFileNameWin32 = 0x2B,
    ProcessImageFileMapping = 0x2C,
    ProcessAffinityUpdateMode = 0x2D,
    ProcessMemoryAllocationMode = 0x2E,
    ProcessGroupInformation = 0x2F,
    ProcessTokenVirtualizationEnabled = 0x30,
    ProcessConsoleHostProcess = 0x31,
    ProcessWindowInformation = 0x32,
    ProcessHandleInformation = 0x33,
    ProcessMitigationPolicy = 0x34,
    ProcessDynamicFunctionTableInformation = 0x35,
    ProcessHandleCheckingMode = 0x36,
    ProcessKeepAliveCount = 0x37,
    ProcessRevokeFileHandles = 0x38,
    ProcessWorkingSetControl = 0x39,
    ProcessHandleTable = 0x3A,
    ProcessCheckStackExtentsMode = 0x3B,
    ProcessCommandLineInformation = 0x3C,
    ProcessProtectionInformation = 0x3D,
    ProcessMemoryExhaustion = 0x3E,
    ProcessFaultInformation = 0x3F,
    ProcessTelemetryIdInformation = 0x40,
    ProcessCommitReleaseInformation = 0x41,
    ProcessDefaultCpuSetsInformation = 0x42,
    ProcessAllowedCpuSetsInformation = 0x43,
    ProcessSubsystemProcess = 0x44,
    ProcessJobMemoryInformation = 0x45,
    ProcessInPrivate = 0x46,
    ProcessRaiseUMExceptionOnInvalidHandleClose = 0x47,
    ProcessIumChallengeResponse = 0x48,
    ProcessChildProcessInformation = 0x49,
    ProcessHighGraphicsPriorityInformation = 0x4A,
    ProcessSubsystemInformation = 0x4B,
    ProcessEnergyValues = 0x4C,
    ProcessActivityThrottleState = 0x4D,
    ProcessActivityThrottlePolicy = 0x4E,
    ProcessWin32kSyscallFilterInformation = 0x4F,
    ProcessDisableSystemAllowedCpuSets = 0x50,
    ProcessWakeInformation = 0x51,
    ProcessEnergyTrackingState = 0x52,
    ProcessManageWritesToExecutableMemory = 0x53,
    ProcessCaptureTrustletLiveDump = 0x54,
    ProcessTelemetryCoverage = 0x55,
    ProcessEnclaveInformation = 0x56,
    ProcessEnableReadWriteVmLogging = 0x57,
    ProcessUptimeInformation = 0x58,
    ProcessImageSection = 0x59,
    ProcessDebugAuthInformation = 0x5A,
    ProcessSystemResourceManagement = 0x5B,
    ProcessSequenceNumber = 0x5C,
    ProcessLoaderDetour = 0x5D,
    ProcessSecurityDomainInformation = 0x5E,
    ProcessCombineSecurityDomainsInformation = 0x5F,
    ProcessEnableLogging = 0x60,
    ProcessLeapSecondInformation = 0x61,
    ProcessFiberShadowStackAllocation = 0x62,
    ProcessFreeFiberShadowStackAllocation = 0x63,
    MaxProcessInfoClass = 0x64
}PRTS;
