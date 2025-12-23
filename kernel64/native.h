//[80_PA] ELF, cracklab/exelab, 2023-2025
//FLAG 

#include <Windows.h>

extern "C"
{
    //CONST
    constexpr auto KUSER_SHARED_DATA_LP = 0x07FFE0000UL;

    constexpr auto PROCESSOR_FEATURE_MAX = 64;
    constexpr auto MAX_WOW64_SHARED_ENTRIES = 16;

    constexpr auto NX_SUPPORT_POLICY_ALWAYSOFF = 0;
    constexpr auto NX_SUPPORT_POLICY_ALWAYSON = 1;
    constexpr auto NX_SUPPORT_POLICY_OPTIN = 2;
    constexpr auto NX_SUPPORT_POLICY_OPTOUT = 3;

    typedef struct _KSYSTEM_TIME
    {
        ULONG LowPart;
        LONG High1Time;
        LONG High2Time;
    } KSYSTEM_TIME, * PKSYSTEM_TIME;

    typedef enum _NT_PRODUCT_TYPE
    {
        NtProductWinNt = 1,
        NtProductLanManNt = 2,
        NtProductServer = 3
    } NT_PRODUCT_TYPE;

    typedef enum _ALTERNATIVE_ARCHITECTURE_TYPE
    {
        StandardDesign = 0,
        NEC98x86 = 1,
        EndAlternatives = 2
    } ALTERNATIVE_ARCHITECTURE_TYPE;


    typedef struct _KUSER_SHARED_DATA {
        ULONG                         TickCountLowDeprecated;
        ULONG                         TickCountMultiplier;
        KSYSTEM_TIME                  InterruptTime;
        KSYSTEM_TIME                  SystemTime;
        KSYSTEM_TIME                  TimeZoneBias;
        USHORT                        ImageNumberLow;
        USHORT                        ImageNumberHigh;
        WCHAR                         NtSystemRoot[260];
        ULONG                         MaxStackTraceDepth;
        ULONG                         CryptoExponent;
        ULONG                         TimeZoneId;
        ULONG                         LargePageMinimum;
        ULONG                         AitSamplingValue;
        ULONG                         AppCompatFlag;
        ULONGLONG                     RNGSeedVersion;
        ULONG                         GlobalValidationRunlevel;
        LONG                          TimeZoneBiasStamp;
        ULONG                         NtBuildNumber;
        NT_PRODUCT_TYPE               NtProductType;
        BOOLEAN                       ProductTypeIsValid;
        BOOLEAN                       Reserved0[1];
        USHORT                        NativeProcessorArchitecture;
        ULONG                         NtMajorVersion;
        ULONG                         NtMinorVersion;
        BOOLEAN                       ProcessorFeatures[PROCESSOR_FEATURE_MAX];
        ULONG                         Reserved1;
        ULONG                         Reserved3;
        ULONG                         TimeSlip;
        ALTERNATIVE_ARCHITECTURE_TYPE AlternativeArchitecture;
        ULONG                         BootId;
        LARGE_INTEGER                 SystemExpirationDate;
        ULONG                         SuiteMask;
        BOOLEAN                       KdDebuggerEnabled;
        union {
            UCHAR MitigationPolicies;
            struct {
                UCHAR NXSupportPolicy : 2;
                UCHAR SEHValidationPolicy : 2;
                UCHAR CurDirDevicesSkippedForDlls : 2;
                UCHAR Reserved : 2;
            };
        };
        USHORT                        CyclesPerYield;
        ULONG                         ActiveConsoleId;
        ULONG                         DismountCount;
        ULONG                         ComPlusPackage;
        ULONG                         LastSystemRITEventTickCount;
        ULONG                         NumberOfPhysicalPages;
        BOOLEAN                       SafeBootMode;
        union {
            UCHAR VirtualizationFlags;
            struct {
                UCHAR ArchStartedInEl2 : 1;
                UCHAR QcSlIsSupported : 1;
            };
        };
        UCHAR                         Reserved12[2];
        union {
            ULONG SharedDataFlags;
            struct {
                ULONG DbgErrorPortPresent : 1;
                ULONG DbgElevationEnabled : 1;
                ULONG DbgVirtEnabled : 1;
                ULONG DbgInstallerDetectEnabled : 1;
                ULONG DbgLkgEnabled : 1;
                ULONG DbgDynProcessorEnabled : 1;
                ULONG DbgConsoleBrokerEnabled : 1;
                ULONG DbgSecureBootEnabled : 1;
                ULONG DbgMultiSessionSku : 1;
                ULONG DbgMultiUsersInSessionSku : 1;
                ULONG DbgStateSeparationEnabled : 1;
                ULONG SpareBits : 21;
            } DUMMYSTRUCTNAME2;
        } DUMMYUNIONNAME2;
        ULONG                         DataFlagsPad[1];
        ULONGLONG                     TestRetInstruction;
        LONGLONG                      QpcFrequency;
        ULONG                         SystemCall;
        ULONG                         Reserved2;
        ULONGLONG                     SystemCallPad[2];
        union {
            KSYSTEM_TIME TickCount;
            ULONG64      TickCountQuad;
            struct {
                ULONG ReservedTickCountOverlay[3];
                ULONG TickCountPad[1];
            } DUMMYSTRUCTNAME;
        } DUMMYUNIONNAME3;
        ULONG                         Cookie;
        ULONG                         CookiePad[1];
        LONGLONG                      ConsoleSessionForegroundProcessId;
        ULONGLONG                     TimeUpdateLock;
        ULONGLONG                     BaselineSystemTimeQpc;
        ULONGLONG                     BaselineInterruptTimeQpc;
        ULONGLONG                     QpcSystemTimeIncrement;
        ULONGLONG                     QpcInterruptTimeIncrement;
        UCHAR                         QpcSystemTimeIncrementShift;
        UCHAR                         QpcInterruptTimeIncrementShift;
        USHORT                        UnparkedProcessorCount;
        ULONG                         EnclaveFeatureMask[4];
        ULONG                         TelemetryCoverageRound;
        USHORT                        UserModeGlobalLogger[16];
        ULONG                         ImageFileExecutionOptions;
        ULONG                         LangGenerationCount;
        ULONGLONG                     Reserved4;
        ULONGLONG                     InterruptTimeBias;
        ULONGLONG                     QpcBias;
        ULONG                         ActiveProcessorCount;
        UCHAR                         ActiveGroupCount;
        UCHAR                         Reserved9;
        union {
            USHORT QpcData;
            struct {
                UCHAR QpcBypassEnabled;
                UCHAR QpcShift;
            };
        };
        LARGE_INTEGER                 TimeZoneBiasEffectiveStart;
        LARGE_INTEGER                 TimeZoneBiasEffectiveEnd;
        XSTATE_CONFIGURATION          XState;
        KSYSTEM_TIME                  FeatureConfigurationChangeStamp;
        ULONG                         Spare;
        ULONG64                       UserPointerAuthMask;
    } KUSER_SHARED_DATA, * PKUSER_SHARED_DATA;

    //const  static_cast<PKUSER_SHARED_DATA>(KUSER_SHARED_DATA_LP);
    constexpr auto pKUSERSHAREDDATA = KUSER_SHARED_DATA_LP;

    typedef enum _SYSTEM_INFORMATION_CLASS
    {
        SystemBasicInformation = 0,
        SystemProcessorInformation = 1,             // obsolete...delete
        SystemPerformanceInformation = 2,
        SystemTimeOfDayInformation = 3,
        SystemPathInformation = 4,
        SystemProcessInformation = 5,
        SystemCallCountInformation = 6,
        SystemDeviceInformation = 7,
        SystemProcessorPerformanceInformation = 8,
        SystemFlagsInformation = 9,
        SystemCallTimeInformation = 10,
        SystemModuleInformation = 11,
        SystemLocksInformation = 12,
        SystemStackTraceInformation = 13,
        SystemPagedPoolInformation = 14,
        SystemNonPagedPoolInformation = 15,
        SystemHandleInformation = 16,
        SystemObjectInformation = 17,
        SystemPageFileInformation = 18,
        SystemVdmInstemulInformation = 19,
        SystemVdmBopInformation = 20,
        SystemFileCacheInformation = 21,
        SystemPoolTagInformation = 22,
        SystemInterruptInformation = 23,
        SystemDpcBehaviorInformation = 24,
        SystemFullMemoryInformation = 25,
        SystemLoadGdiDriverInformation = 26,
        SystemUnloadGdiDriverInformation = 27,
        SystemTimeAdjustmentInformation = 28,
        SystemSummaryMemoryInformation = 29,
        SystemMirrorMemoryInformation = 30,
        SystemPerformanceTraceInformation = 31,
        SystemObsolete0 = 32,
        SystemExceptionInformation = 33,
        SystemCrashDumpStateInformation = 34,
        SystemKernelDebuggerInformation = 35,
        SystemContextSwitchInformation = 36,
        SystemRegistryQuotaInformation = 37,
        SystemExtendServiceTableInformation = 38,
        SystemPrioritySeperation = 39,
        SystemVerifierAddDriverInformation = 40,
        SystemVerifierRemoveDriverInformation = 41,
        SystemProcessorIdleInformation = 42,
        SystemLegacyDriverInformation = 43,
        SystemCurrentTimeZoneInformation = 44,
        SystemLookasideInformation = 45,
        SystemTimeSlipNotification = 46,
        SystemSessionCreate = 47,
        SystemSessionDetach = 48,
        SystemSessionInformation = 49,
        SystemRangeStartInformation = 50,
        SystemVerifierInformation = 51,
        SystemVerifierThunkExtend = 52,
        SystemSessionProcessInformation = 53,
        SystemLoadGdiDriverInSystemSpace = 54,
        SystemNumaProcessorMap = 55,
        SystemPrefetcherInformation = 56,
        SystemExtendedProcessInformation = 57,
        SystemRecommendedSharedDataAlignment = 58,
        SystemComPlusPackage = 59,
        SystemNumaAvailableMemory = 60,
        SystemProcessorPowerInformation = 61,
        SystemEmulationBasicInformation = 62,
        SystemEmulationProcessorInformation = 63,
        SystemExtendedHandleInformation = 64,
        SystemLostDelayedWriteInformation = 65,
        SystemBigPoolInformation = 66,
        SystemSessionPoolTagInformation = 67,
        SystemSessionMappedViewInformation = 68,
        SystemHotpatchInformation = 69,
        SystemObjectSecurityMode = 70,
        SystemWatchdogTimerHandler = 71,
        SystemWatchdogTimerInformation = 72,
        SystemLogicalProcessorInformation = 73,
        SystemWow64SharedInformation = 74,
        SystemRegisterFirmwareTableInformationHandler = 75,
        SystemFirmwareTableInformation = 76,
        SystemModuleInformationEx = 77,
        SystemVerifierTriageInformation = 78,
        SystemSuperfetchInformation = 79,
        SystemMemoryListInformation = 80,
        SystemFileCacheInformationEx = 81,
        SecSetEALMInfoHandle = 152,
        MaxSystemInfoClass = 153  // MaxSystemInfoClass should always be the last enum

    } SYSTEM_INFORMATION_CLASS;



    typedef enum _PROCESSINFOCLASS
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
    } PROCESSINFOCLASS;

    ///////////////
}
