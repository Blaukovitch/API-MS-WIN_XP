//[80_PA] ELF, cracklab/exelab, 2023-2025
//FLAG 

#include <Windows.h>
#define NTSTATUS signed long



#define STATUS_SUCCESS   ((NTSTATUS)0x00000000L) // ntsubauth
#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0

constexpr auto SystemCPUSetInformation = 0xAFL;

extern "C"
{

    typedef enum _THREADINFOCLASS
    {
        ThreadBasicInformation,                         // q: THREAD_BASIC_INFORMATION
        ThreadTimes,                                    // q: KERNEL_USER_TIMES
        ThreadPriority,                                 // s: KPRIORITY (requires SeIncreaseBasePriorityPrivilege)
        ThreadBasePriority,                             // s: KPRIORITY
        ThreadAffinityMask,                             // s: KAFFINITY
        ThreadImpersonationToken,                       // s: HANDLE
        ThreadDescriptorTableEntry,                     // q: DESCRIPTOR_TABLE_ENTRY (or WOW64_DESCRIPTOR_TABLE_ENTRY)
        ThreadEnableAlignmentFaultFixup,                // s: BOOLEAN
        ThreadEventPair,                                // q: Obsolete
        ThreadQuerySetWin32StartAddress,                // qs: PVOID (requires THREAD_SET_LIMITED_INFORMATION)
        ThreadZeroTlsCell,                              // s: ULONG // TlsIndex // 10
        ThreadPerformanceCount,                         // q: LARGE_INTEGER
        ThreadAmILastThread,                            // q: ULONG
        ThreadIdealProcessor,                           // s: ULONG
        ThreadPriorityBoost,                            // qs: ULONG
        ThreadSetTlsArrayAddress,                       // s: ULONG_PTR
        ThreadIsIoPending,                              // q: ULONG
        ThreadHideFromDebugger,                         // q: BOOLEAN; s: void
        ThreadBreakOnTermination,                       // qs: ULONG
        ThreadSwitchLegacyState,                        // s: void // NtCurrentThread // NPX/FPU
        ThreadIsTerminated,                             // q: ULONG // 20
        ThreadLastSystemCall,                           // q: THREAD_LAST_SYSCALL_INFORMATION
        ThreadIoPriority,                               // qs: IO_PRIORITY_HINT (requires SeIncreaseBasePriorityPrivilege)
        ThreadCycleTime,                                // q: THREAD_CYCLE_TIME_INFORMATION (requires THREAD_QUERY_LIMITED_INFORMATION)
        ThreadPagePriority,                             // qs: PAGE_PRIORITY_INFORMATION
        ThreadActualBasePriority,                       // s: LONG (requires SeIncreaseBasePriorityPrivilege)
        ThreadTebInformation,                           // q: THREAD_TEB_INFORMATION (requires THREAD_GET_CONTEXT + THREAD_SET_CONTEXT)
        ThreadCSwitchMon,                               // q: Obsolete
        ThreadCSwitchPmu,                               // q: Obsolete
        ThreadWow64Context,                             // qs: WOW64_CONTEXT, ARM_NT_CONTEXT since 20H1
        ThreadGroupInformation,                         // qs: GROUP_AFFINITY // 30
        ThreadUmsInformation,                           // q: THREAD_UMS_INFORMATION // Obsolete
        ThreadCounterProfiling,                         // q: BOOLEAN; s: THREAD_PROFILING_INFORMATION?
        ThreadIdealProcessorEx,                         // qs: PROCESSOR_NUMBER; s: previous PROCESSOR_NUMBER on return
        ThreadCpuAccountingInformation,                 // q: BOOLEAN; s: HANDLE (NtOpenSession) // NtCurrentThread // since WIN8
        ThreadSuspendCount,                             // q: ULONG // since WINBLUE
        ThreadHeterogeneousCpuPolicy,                   // q: KHETERO_CPU_POLICY // since THRESHOLD
        ThreadContainerId,                              // q: GUID
        ThreadNameInformation,                          // qs: THREAD_NAME_INFORMATION (requires THREAD_SET_LIMITED_INFORMATION)
        ThreadSelectedCpuSets,                          // q: ULONG[]
        ThreadSystemThreadInformation,                  // q: SYSTEM_THREAD_INFORMATION // 40
        ThreadActualGroupAffinity,                      // q: GROUP_AFFINITY // since THRESHOLD2
        ThreadDynamicCodePolicyInfo,                    // q: ULONG; s: ULONG (NtCurrentThread)
        ThreadExplicitCaseSensitivity,                  // qs: ULONG; s: 0 disables, otherwise enables // (requires SeDebugPrivilege and PsProtectedSignerAntimalware)
        ThreadWorkOnBehalfTicket,                       // q: ALPC_WORK_ON_BEHALF_TICKET // RTL_WORK_ON_BEHALF_TICKET_EX // NtCurrentThread
        ThreadSubsystemInformation,                     // q: SUBSYSTEM_INFORMATION_TYPE // since REDSTONE2
        ThreadDbgkWerReportActive,                      // s: ULONG; s: 0 disables, otherwise enables
        ThreadAttachContainer,                          // s: HANDLE (job object) // NtCurrentThread
        ThreadManageWritesToExecutableMemory,           // s: MANAGE_WRITES_TO_EXECUTABLE_MEMORY // since REDSTONE3
        ThreadPowerThrottlingState,                     // qs: POWER_THROTTLING_THREAD_STATE // since REDSTONE3 (set), WIN11 22H2 (query)
        ThreadWorkloadClass,                            // q: THREAD_WORKLOAD_CLASS // since REDSTONE5 // 50
        ThreadCreateStateChange,                        // s: Obsolete // since WIN11
        ThreadApplyStateChange,                         // s: Obsolete
        ThreadStrongerBadHandleChecks,                  // s: ULONG // NtCurrentThread // since 22H1
        ThreadEffectiveIoPriority,                      // q: IO_PRIORITY_HINT
        ThreadEffectivePagePriority,                    // q: ULONG
        ThreadUpdateLockOwnership,                      // s: THREAD_LOCK_OWNERSHIP // since 24H2
        ThreadSchedulerSharedDataSlot,                  // q: SCHEDULER_SHARED_DATA_SLOT_INFORMATION
        ThreadTebInformationAtomic,                     // q: THREAD_TEB_INFORMATION (requires THREAD_GET_CONTEXT + THREAD_QUERY_INFORMATION)
        ThreadIndexInformation,                         // q: THREAD_INDEX_INFORMATION
        MaxThreadInfoClass
    } THREADINFOCLASS;



#if (NTDDI_VERSION >= NTDDI_WINXP)
    typedef NTSTATUS(WINAPI
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



    typedef BOOL(WINAPI api_GetOverlappedResultEx)(HANDLE       hFile,
        LPOVERLAPPED lpOverlapped,
        LPDWORD      lpNumberOfBytesTransferred,
        DWORD        dwMilliseconds,
        BOOL         bAlertable);


    typedef struct _UNICODE_STRING {
        USHORT Length;
        USHORT MaximumLength;
        PWSTR  Buffer;
    } UNICODE_STRING, * PUNICODE_STRING;



    /**
     * The NtQuerySystemInformationEx routine queries information about the system.
     *
     * \param SystemInformationClass The type of information to be retrieved.
     * \param InputBuffer Pointer to a caller-allocated input buffer that contains class-specific information.
     * \param InputBufferLength The size of the buffer pointed to by InputBuffer.
     * \param SystemInformation A pointer to a buffer that receives the requested information.
     * \param SystemInformationLength The size of the buffer pointed to by SystemInformation.
     * \param ReturnLength A pointer to a variable that receives the size of the data returned in the buffer.
     * \return NTSTATUS Successful or errant status.
     * \see https://learn.microsoft.com/en-us/windows/win32/sysinfo/zwquerysysteminformation
     */
    NTSTATUS
        NTAPI
        NtQuerySystemInformationEx(
            _In_ SYSTEM_INFORMATION_CLASS SystemInformationClass,
            _In_reads_bytes_(InputBufferLength) PVOID InputBuffer,
            _In_ ULONG InputBufferLength,
            _Out_writes_bytes_opt_(SystemInformationLength) PVOID SystemInformation,
            _In_ ULONG SystemInformationLength,
            _Out_opt_ PULONG ReturnLength
        );



    typedef NTSTATUS(NTAPI api_NtQueryInformationProcess)(
        HANDLE ProcessHandle,
        PROCESSINFOCLASS ProcessInformationClass,
        PVOID ProcessInformation,
        ULONG ProcessInformationLength,
        PULONG ReturnLength);


    VOID
        NTAPI
        RtlInitUnicodeString(
            PUNICODE_STRING DestinationString,
            PCWSTR SourceString
        );

    NTSTATUS NTAPI NtQueryInformationProcess(
        HANDLE           ProcessHandle,
        PROCESSINFOCLASS ProcessInformationClass,
        PVOID            ProcessInformation,
        ULONG            ProcessInformationLength,
        PULONG           ReturnLength
    );


    ULONG
        NTAPI
        RtlNtStatusToDosError(
            NTSTATUS Status
        );

   
}
