// //[80_PA] ELF, cracklab/exelab, 2023-2024
#include "native.h"

// >>>>>>>>>> FLAG (debug options) <<<<<<<<<<<
#include <list>
#include <string>
#include <ntstatus.h>

#ifdef __cplusplus
template <size_t N> struct ArraySizeHelper { char _[N]; };

template <typename T, size_t N>
ArraySizeHelper<N> makeArraySizeHelper(T(&)[N]);

#  define ARRAY_SIZE(a)  sizeof(makeArraySizeHelper(a))
#else
#  // C definition as shown in Google's code
#endif


const TCHAR WIDE_KERNEL32DLL[] = L"kernel32.dll";
const TCHAR WIDE_NTDLLDLL[] = L"ntdll.dll";

const char A_BFTO[] = "BaseFormatTimeOut";
const char A_RtlWOA[] = "RtlWaitOnAddress";

typedef BOOL(WINAPI api_WaitOnAddress)(
    volatile VOID* Address,
    PVOID         CompareAddress,
    SIZE_T        AddressSize,
    DWORD         dwMilliseconds
);

typedef void(WINAPI api_WakeByAddressAll)(
    PVOID Address
    );


typedef void(WINAPI api_WakeByAddressSingle)(
    PVOID Address
    );

typedef LARGE_INTEGER* (WINAPI api_BaseFormatTimeOut)(
    LARGE_INTEGER* pLITimeout,
    DWORD dwMillis
    );

typedef NTSTATUS(WINAPI api_RtlWaitOnAddress)(const void* addr, const void* cmp, SIZE_T size,
    const LARGE_INTEGER* timeout);

api_WaitOnAddress* farproc_WaitOnAddress = 0;
api_WakeByAddressAll* farproc_WakeByAddressAll = 0;
api_WakeByAddressSingle* farproc_WakeByAddressSingle = 0;

api_BaseFormatTimeOut* farproc_BaseFormatTimeOut = 0;
api_RtlWaitOnAddress* farproc_RtlWaitOnAddress = 0;

// ----- ABSENT AP -----
HMODULE pKernel32;
HMODULE pNtdll;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {

    case DLL_PROCESS_ATTACH: {
        if (!pKernel32)
        {

            pKernel32 = ::GetModuleHandle(WIDE_KERNEL32DLL);
            pNtdll = ::GetModuleHandle(WIDE_NTDLLDLL);

            farproc_BaseFormatTimeOut = (api_BaseFormatTimeOut*)::GetProcAddress(pKernel32, A_BFTO);
            farproc_RtlWaitOnAddress = (api_RtlWaitOnAddress*)::GetProcAddress(pKernel32, A_RtlWOA);
        }
        break;}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
extern "C"
{
    struct list
    {
        struct list* next;
        struct list* prev;
    };

    struct futex_queue
    {
        list queue;
        LONG lock;
    };

    struct futex_entry
    {
        list entry;
        const void* addr;
        DWORD tid;
    };


    /* Define a list like so:
     *
     *   struct gadget
     *   {
     *       struct list  entry;   <-- doesn't have to be the first item in the struct
     *       int          a, b;
     *   };
     *
     *   static struct list global_gadgets = LIST_INIT( global_gadgets );
     *
     * or
     *
     *   struct some_global_thing
     *   {
     *       struct list gadgets;
     *   };
     *
     *   list_init( &some_global_thing->gadgets );
     *
     * Manipulate it like this:
     *
     *   list_add_head( &global_gadgets, &new_gadget->entry );
     *   list_remove( &new_gadget->entry );
     *   list_add_after( &some_random_gadget->entry, &new_gadget->entry );
     *
     * And to iterate over it:
     *
     *   struct gadget *gadget;
     *   LIST_FOR_EACH_ENTRY( gadget, &global_gadgets, struct gadget, entry )
     *   {
     *       ...
     *   }
     *
     */

     /* add an element after the specified one */
    static inline void list_add_after(struct list* elem, struct list* to_add)
    {
        to_add->next = elem->next;
        to_add->prev = elem;
        elem->next->prev = to_add;
        elem->next = to_add;
    }

    /* add an element before the specified one */
    static inline void list_add_before(struct list* elem, struct list* to_add)
    {
        to_add->next = elem;
        to_add->prev = elem->prev;
        elem->prev->next = to_add;
        elem->prev = to_add;
    }

    /* add element at the head of the list */
    static inline void list_add_head(struct list* list, struct list* elem)
    {
        list_add_after(list, elem);
    }

    /* add element at the tail of the list */
    static inline void list_add_tail(struct list* list, struct list* elem)
    {
        list_add_before(list, elem);
    }

    /* remove an element from its list */
    static inline void list_remove(struct list* elem)
    {
        elem->next->prev = elem->prev;
        elem->prev->next = elem->next;
    }

    /* get the next element */
    static inline struct list* list_next(const struct list* list, const struct list* elem)
    {
        struct list* ret = elem->next;
        if (elem->next == list) ret = NULL;
        return ret;
    }

    /* get the previous element */
    static inline struct list* list_prev(const struct list* list, const struct list* elem)
    {
        struct list* ret = elem->prev;
        if (elem->prev == list) ret = NULL;
        return ret;
    }

    /* get the first element */
    static inline struct list* list_head(const struct list* list)
    {
        return list_next(list, list);
    }

    /* get the last element */
    static inline struct list* list_tail(const struct list* list)
    {
        return list_prev(list, list);
    }

    /* check if a list is empty */
    static inline int list_empty(const struct list* list)
    {
        return list->next == list;
    }

    /* initialize a list */
    static inline void list_init(struct list* list)
    {
        list->next = list->prev = list;
    }

    /* count the elements of a list */
    static inline unsigned int list_count(const struct list* list)
    {
        unsigned count = 0;
        const struct list* ptr;
        for (ptr = list->next; ptr != list; ptr = ptr->next) count++;
        return count;
    }

    /* move all elements from src to before the specified element */
    static inline void list_move_before(struct list* dst, struct list* src)
    {
        if (list_empty(src)) return;

        dst->prev->next = src->next;
        src->next->prev = dst->prev;
        dst->prev = src->prev;
        src->prev->next = dst;
        list_init(src);
    }

    /* move all elements from src to after the specified element */
    static inline void list_move_after(struct list* dst, struct list* src)
    {
        if (list_empty(src)) return;

        dst->next->prev = src->prev;
        src->prev->next = dst->next;
        dst->next = src->next;
        src->next->prev = dst;
        list_init(src);
    }

    /* move all elements from src to the head of dst */
    static inline void list_move_head(struct list* dst, struct list* src)
    {
        list_move_after(dst, src);
    }

    /* move all elements from src to the tail of dst */
    static inline void list_move_tail(struct list* dst, struct list* src)
    {
        list_move_before(dst, src);
    }

    /* move the slice of elements from begin to end inclusive to the head of dst */
    static inline void list_move_slice_head(struct list* dst, struct list* begin, struct list* end)
    {
        struct list* dst_next = dst->next;
        begin->prev->next = end->next;
        end->next->prev = begin->prev;
        dst->next = begin;
        dst_next->prev = end;
        begin->prev = dst;
        end->next = dst_next;
    }

    /* move the slice of elements from begin to end inclusive to the tail of dst */
    static inline void list_move_slice_tail(struct list* dst, struct list* begin, struct list* end)
    {
        struct list* dst_prev = dst->prev;
        begin->prev->next = end->next;
        end->next->prev = begin->prev;
        dst_prev->next = begin;
        dst->prev = end;
        begin->prev = dst_prev;
        end->next = dst;
    }

    /* iterate through the list */
#define LIST_FOR_EACH(cursor,list) \
    for ((cursor) = (list)->next; (cursor) != (list); (cursor) = (cursor)->next)

/* iterate through the list, with safety against removal */
#define LIST_FOR_EACH_SAFE(cursor, cursor2, list) \
    for ((cursor) = (list)->next, (cursor2) = (cursor)->next; \
         (cursor) != (list); \
         (cursor) = (cursor2), (cursor2) = (cursor)->next)

/* iterate through the list using a list entry */
#define LIST_FOR_EACH_ENTRY(elem, list, type, field) \
    for ((elem) = LIST_ENTRY((list)->next, type, field); \
         &(elem)->field != (list); \
         (elem) = LIST_ENTRY((elem)->field.next, type, field))

/* iterate through the list using a list entry, with safety against removal */
#define LIST_FOR_EACH_ENTRY_SAFE(cursor, cursor2, list, type, field) \
    for ((cursor) = LIST_ENTRY((list)->next, type, field), \
         (cursor2) = LIST_ENTRY((cursor)->field.next, type, field); \
         &(cursor)->field != (list); \
         (cursor) = (cursor2), \
         (cursor2) = LIST_ENTRY((cursor)->field.next, type, field))

/* iterate through the list in reverse order */
#define LIST_FOR_EACH_REV(cursor,list) \
    for ((cursor) = (list)->prev; (cursor) != (list); (cursor) = (cursor)->prev)

/* iterate through the list in reverse order, with safety against removal */
#define LIST_FOR_EACH_SAFE_REV(cursor, cursor2, list) \
    for ((cursor) = (list)->prev, (cursor2) = (cursor)->prev; \
         (cursor) != (list); \
         (cursor) = (cursor2), (cursor2) = (cursor)->prev)

/* iterate through the list in reverse order using a list entry */
#define LIST_FOR_EACH_ENTRY_REV(elem, list, type, field) \
    for ((elem) = LIST_ENTRY((list)->prev, type, field); \
         &(elem)->field != (list); \
         (elem) = LIST_ENTRY((elem)->field.prev, type, field))

/* iterate through the list in reverse order using a list entry, with safety against removal */
#define LIST_FOR_EACH_ENTRY_SAFE_REV(cursor, cursor2, list, type, field) \
    for ((cursor) = LIST_ENTRY((list)->prev, type, field), \
         (cursor2) = LIST_ENTRY((cursor)->field.prev, type, field); \
         &(cursor)->field != (list); \
         (cursor) = (cursor2), \
         (cursor2) = LIST_ENTRY((cursor)->field.prev, type, field))

/* macros for statically initialized lists */
#undef LIST_INIT
#define LIST_INIT(list)  { &(list), &(list) }

/* get pointer to object containing list element */
#undef LIST_ENTRY
#define LIST_ENTRY(elem, type, field) \
    ((type *)((char *)(elem) - offsetof(type, field)))

static struct futex_queue futex_queues[256];


static struct futex_queue* get_futex_queue(const void* addr)
{
        ULONG_PTR val = (ULONG_PTR)addr;

        return &futex_queues[(val >> 4) % ARRAY_SIZE(futex_queues)];
}

static void spin_lock(LONG* lock)
{
    while (InterlockedCompareExchange(lock, -1, 0))
        YieldProcessor();
}

static void spin_unlock(LONG* lock)
{
    InterlockedExchange(lock, 0);
}

static BOOL compare_addr(const void* addr, const void* cmp, SIZE_T size)
{
    switch (size)
    {
    case 1:
        return (*(const UCHAR*)addr == *(const UCHAR*)cmp);
    case 2:
        return (*(const USHORT*)addr == *(const USHORT*)cmp);
    case 4:
        return (*(const ULONG*)addr == *(const ULONG*)cmp);
    case 8:
        return (*(const ULONG64*)addr == *(const ULONG64*)cmp);
    }

    return FALSE;
}


EXPORT BOOL WINAPI _WaitOnAddress(
    volatile VOID* Address,
    PVOID         CompareAddress,
    SIZE_T        AddressSize,
    DWORD         dwMilliseconds
) 
{
    Sleep(0);
    SwitchToThread();
    //Windows 7
    if ((farproc_BaseFormatTimeOut) && (farproc_RtlWaitOnAddress))
    {
        LARGE_INTEGER li;
        li.u.HighPart = 0;
        li.u.LowPart = 0;
        farproc_BaseFormatTimeOut(&li, dwMilliseconds);
        if (farproc_RtlWaitOnAddress((const void*)(Address), CompareAddress, AddressSize, &li) == ERROR_SUCCESS)
            return TRUE;
    }
    return FALSE;;
    //***** WINE HQ *****//
    struct futex_queue* queue = get_futex_queue((const VOID*)Address);
    struct futex_entry entry;
    NTSTATUS ret;


    if (AddressSize != sizeof(BYTE) && AddressSize != sizeof(WORD) && AddressSize != sizeof(DWORD) && AddressSize != sizeof(__int64))
        return STATUS_INVALID_PARAMETER;

    entry.addr = (const VOID*)Address;
    entry.tid = GetCurrentThreadId();

    spin_lock(&queue->lock);

    /* Do the comparison inside of the spinlock, to reduce spurious wakeups. */

    if (!compare_addr((const VOID*)Address, CompareAddress, AddressSize))
    {
        spin_unlock(&queue->lock);
        return ERROR_SUCCESS;
    }

    if (!queue->queue.next)
        list_init(&queue->queue);
    list_add_tail(&queue->queue, &entry.entry);

    spin_unlock(&queue->lock);

   // ret = NtWaitForAlertByThreadId(NULL, dwMilliseconds);
    

    /* We may have already been removed by a call to RtlWakeAddressSingle() or RtlWakeAddressAll(). */
    if (entry.addr)
    {
        spin_lock(&queue->lock);
        if (entry.addr)
            list_remove(&entry.entry);
        spin_unlock(&queue->lock);
    }


   // if (ret == STATUS_ALERTED) ret = STATUS_SUCCESS;
   // return ret;
    return TRUE;
}

EXPORT void WINAPI _WakeByAddressAll(
    PVOID Address
)
{
    Sleep(0);
    SwitchToThread();
    return;
    struct futex_queue* queue = get_futex_queue(Address);
    struct futex_entry* entry, * next;
    unsigned int count = 0, i;
    DWORD tids[256];

    if (!Address) return;

    spin_lock(&queue->lock);

    if (!queue->queue.next)
        list_init(&queue->queue);

    LIST_FOR_EACH_ENTRY_SAFE(entry, next, &queue->queue, struct futex_entry, entry)
    {
        if (entry->addr == Address)
        {
            entry->addr = NULL;
            list_remove(&entry->entry);
            /* Try to buffer wakes, so that we don't make a system call while
             * holding a spinlock. */
            if (count < ARRAY_SIZE(tids))
                tids[count++] = entry->tid;
          //  else
          //      NtAlertThreadByThreadId((HANDLE)(DWORD_PTR)entry->tid);
        }
    }

    spin_unlock(&queue->lock);

  //  for (i = 0; i < count; ++i)
    //    NtAlertThreadByThreadId((HANDLE)(DWORD_PTR)tids[i]);
}

EXPORT void WINAPI _WakeByAddressSingle(
    PVOID Address
)
{
    Sleep(1);
    SwitchToThread();
    return;
    struct futex_queue* queue = get_futex_queue(Address);
    struct futex_entry* entry;
    DWORD tid = 0;


    if (!Address) return;

    spin_lock(&queue->lock);

    if (!queue->queue.next)
        list_init(&queue->queue);

    LIST_FOR_EACH_ENTRY(entry, &queue->queue, struct futex_entry, entry)
    {
        if (entry->addr == Address)
        {
            /* Try to buffer wakes, so that we don't make a system call while
             * holding a spinlock. */
            tid = entry->tid;

            /* Remove this entry from the queue, so that a simultaneous call to
             * RtlWakeAddressSingle() will not also wake it—two simultaneous
             * calls must wake at least two waiters if they exist. */
            entry->addr = NULL;
            list_remove(&entry->entry);
            break;
        }
    }

    spin_unlock(&queue->lock);

   // if (tid) NtAlertThreadByThreadId((HANDLE)(DWORD_PTR)tid);
}

EXPORT void _Sleep(DWORD dwMilliseconds)
{
    return ::Sleep(dwMilliseconds);
}

}
