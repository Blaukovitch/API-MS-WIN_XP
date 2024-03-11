////[80_PA] ELF, cracklab/exelab, 2023
#include "pch.h"
#include <Rpc.h>
#include <RpcNdr.h>

#pragma comment(lib, "Rpcrt4.lib")
//FLAG 
//#define DEBUG_OUT 1

#define E_STRING_NOT_NULL_TERMINATED     _HRESULT_TYPEDEF_(0x80000017L)
typedef struct HSTRING__ {
    int unused;
} HSTRING__;
typedef HSTRING__* HSTRING;

typedef struct HSTRING_HEADER {
    union {
        PVOID Reserved1;
#if _WIN64
        char  Reserved2[24];
#else
        char  Reserved2[20];
#endif
    } Reserved;
} HSTRING_HEADER;

// ------ globals ------ 
BOOL isdp = false;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    {
#ifdef DEBUG_OUT
        //for OUTPUT DEBUG STRINGS (if needed)
        isdp = ::IsDebuggerPresent();
#endif // DEBUG_OUT
        break; }
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;

    }
    return TRUE;
}

extern "C"
{
__declspec(dllexport) unsigned char* APIENTRY _HSTRING_UserMarshal(
    unsigned long* unnamedParam1,
    unsigned char* unnamedParam2,
    HSTRING* unnamedParam3
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY HSTRING_UserMarshal()");
#endif // DEBUG_OUT

    if (!unnamedParam3)
        return unnamedParam2;
    unsigned long* pFlags = unnamedParam1;

    _NDR_USER_MARSHAL_INFO marshalInfo;
    memset(&marshalInfo, 0, sizeof(marshalInfo));
   // ::NdrGetUserMarshalInfo(pFlags, 1u, &marshalInfo);

}

__declspec(dllexport) unsigned char* APIENTRY _HSTRING_UserMarshal64(
    unsigned long* unnamedParam1,
    unsigned char* unnamedParam2,
    HSTRING* unnamedParam3
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY HSTRING_UserMarshal64()");
#endif // DEBUG_OUT

    if (!unnamedParam3)
        return unnamedParam2;
    unsigned long* pFlags = unnamedParam1;


    _NDR_USER_MARSHAL_INFO marshalInfo;
    memset(&marshalInfo, 0, sizeof(marshalInfo));
   // ::NdrGetUserMarshalInfo(pFlags, 1u, &marshalInfo);

}

__declspec(dllexport) BOOL APIENTRY _RoOriginateErrorW(
    HRESULT error,
    UINT    cchMax,
    PCWSTR  message
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY RoOriginateErrorW()");
#endif // DEBUG_OUT

    return TRUE;
}

__declspec(dllexport) HRESULT APIENTRY _WindowsDeleteString(
    HSTRING string
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY WindowsDeleteString()");
#endif // DEBUG_OUT
    return S_OK;

    HANDLE ProcessHeap; // rax
    volatile unsigned int va_int = (volatile unsigned __int32)((BYTE*)(string) + 6);
    if (string
        && (*(BYTE*)string & 1) == 0
        && InterlockedExchangeAdd(&va_int, -1) == 1)
    {
        ProcessHeap = ::GetProcessHeap();
        ::HeapFree(ProcessHeap, 0, string);
    }
    return 0;
}

void __stdcall _HSTRING_UserFree64(unsigned int* a1, HSTRING* a2)
{

#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY HSTRING_UserFree64()");
#endif // DEBUG_OUT


    HSTRING v2; // rbx
    HANDLE ProcessHeap; // rax

    if (a2)
    {
        v2 = *a2;
        if (*a2)
        {
            if ((*(BYTE*)v2 & 1) == 0 && InterlockedExchangeAdd((volatile unsigned __int32*)v2 + 6, -1) == 1)
            {
                ProcessHeap = GetProcessHeap();
                HeapFree(ProcessHeap, 0, v2);
            }
        }
    }
}

__declspec(dllexport) void APIENTRY _HSTRING_UserFree(
    unsigned long* unnamedParam1,
    HSTRING* unnamedParam2
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY HSTRING_UserFree()");
#endif // DEBUG_OUT


    if (unnamedParam2)
        _WindowsDeleteString(*unnamedParam2);
}


__declspec(dllexport) unsigned int APIENTRY _HSTRING_UserSize(unsigned int* a1, unsigned int a2, HSTRING* a3)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY HSTRING_UserSize()");
#endif // DEBUG_OUT


    unsigned int v3; // r9d
    unsigned int v5; // ecx
    unsigned int v6; // eax
    unsigned __int64 v7; // rax
    unsigned int v10; // ecx
    /*
    v3 = 0;
    if (a3)
    {
        v5 = a2 + (a2 & 7);
        if (v5 >= a2)
        {
            v6 = v5 + 4;
            if (v5 + 4 >= v5)
            {
                if (*(BYTE*)a1 == 3)
                {
                    v10 = v6 + (v6 & 7);
                    if (v10 >= v6 && v10 + 8 >= v10)
                        return v10 + 8;
                }
                else
                {
                    if (*a3)
                        v3 = *((DWORD*)*a3 + 1);
                    v7 = 2i64 * v3;
                    if (v7 <= -1 && v5 + 8 >= v5 + 4 && (unsigned int)v7 + v5 + 8 >= v5 + 8)
                        return v7 + v5 + 8;
                }
            }
        }
        RpcRaiseException(0x8007000E);
        
    }
    return a2;
    */
    return S_OK;
}

__declspec(dllexport) unsigned int APIENTRY _HSTRING_UserSize64(unsigned int* a1, unsigned int a2, HSTRING* a3)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY HSTRING_UserSize64()");
#endif // DEBUG_OUT


    unsigned int v4; // ecx

    if (!a3)
        return a2;
    v4 = a2 + (a2 & 7);
   // if (v4 < a2)
     //   RpcRaiseException(0x8007000E);
    return _HSTRING_UserSize(a1, v4, a3);
}


__declspec(dllexport) unsigned char* APIENTRY _HSTRING_UserUnmarshal(
    unsigned long* unnamedParam1,
    unsigned char* unnamedParam2,
    HSTRING* unnamedParam3
)
{
#ifdef DEBUG_OUT
    //for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY HSTRING_UserUnmarshal()");
#endif // DEBUG_OUT


    if (!unnamedParam3)
        return unnamedParam2;
    unsigned long* pFlags = unnamedParam1;


    _NDR_USER_MARSHAL_INFO marshalInfo;
    memset(&marshalInfo, 0, sizeof(marshalInfo));
   // ::NdrGetUserMarshalInfo(pFlags, 1u, &marshalInfo);
}

__declspec(dllexport) HRESULT APIENTRY _WindowsCreateString(PCNZWCH sourceString, UINT32 length, HSTRING* string)
{
    unsigned __int16 v3; // r9
    __int64 v4; // r14
    HRESULT v7; // ebx
    UINT32 v8; // r12d
    int v9; // eax
    HRESULT v10; // ebp
    unsigned int v11; // edi
    HANDLE ProcessHeap; // rax
    HSTRING v13; // rax
    HSTRING v14; // rdi
    HSTRING v15; // r13
    const wchar_t* v17; // r8
    unsigned int v18; // edx

#ifdef DEBUG_OUT
//for OUTPUT DEBUG STRINGS (if needed)
    if (isdp)
        ::OutputDebugString(L"APIENTRY WindowsCreateString()");
#endif // DEBUG_OUT


    return S_OK;
    /*
    v4 = length;
    if (string)
    {
        v7 = 0;
        *string = 0i64;
        if (!sourceString && length)
        {
            RoOriginateErrorW(E_POINTER, 6u, L"length");
            return E_POINTER;
        }
        *string = 0i64;
        if (!length)
            return v7;
        v8 = 2 * length;
        if (2 * length > -1
            || ((v9 = v8 + 32, v8 >= 0xFFFFFFE0) ? (v9 = -1, v10 = 0x80070216) : (v10 = 0), v10 == 0x80070216))
        {
            v10 = MEM_E_INVALID_SIZE;
            v17 = L"length";
            v18 = 6;
        }
        else
        {
            v11 = v9;
            ProcessHeap = GetProcessHeap();
            v13 = (HSTRING)HeapAlloc(ProcessHeap, 0, v11);
            *string = v13;
            v14 = v13;
            if (v13)
            {
                v15 = v13 + 7;
                if (sourceString)
                    memcpy(v13 + 7, sourceString, 2 * v4);
                *((WORD*)v14 + v4 + 14) = 0;
                *((HSTRING*)v14 + 2) = v15;
                *(DWORD*)v14 = 0;
                *((DWORD*)v14 + 1) = v4;
                *((DWORD*)v14 + 6) = 1;
                *string = v14;
                if (v14)
                    return v10;
            }
            v17 = 0i64;
            v10 = E_OUTOFMEMORY;
            v18 = 0;
        }
        RoOriginateErrorW(v10, v18, v17);
        return v10;
    }
    RoOriginateErrorW(E_INVALIDARG, 6u, L"string");
    return E_INVALIDARG;
    */
}

__declspec(dllexport) HRESULT APIENTRY _WindowsCreateStringReference(
    PCWSTR sourceString,
    UINT32 length,
    HSTRING_HEADER* hstringHeader,
    HSTRING* string)
{
    return S_OK;
    HRESULT v4; // ebp
    __int64 v5; // rbx
    HRESULT result; // eax
    /*
    v4 = 0;
    v5 = length;
    if (!string)
    {
        v4 = E_INVALIDARG;
        RoOriginateErrorW(E_INVALIDARG, 6u, L"string");
    }
    if (hstringHeader)
    {
        if (v4 >= 0)
            *string = 0i64;
    }
    else
    {
        v4 = E_INVALIDARG;
        RoOriginateErrorW(E_INVALIDARG, 0xDu, L"hstringHeader");
    }
    if ((DWORD)v5 == -1)
    {
        RoOriginateErrorW(E_INVALIDARG, 6u, L"length");
        return E_INVALIDARG;
    }
    if (v4 < 0)
        return v4;
    if (!sourceString)
    {
        if ((DWORD)v5)
        {
            RoOriginateErrorW(E_POINTER, 6u, L"length");
            return E_POINTER;
        }
        return v4;
    }
    if (sourceString[v5])
    {
        RoOriginateErrorW(E_STRING_NOT_NULL_TERMINATED, 0xCu, L"sourceString");
        return E_STRING_NOT_NULL_TERMINATED;
    }
    else
    {
        result = v4;
        if ((DWORD)v5)
        {
            /*
            LODWORD(v10) = 1;
            DWORD1(v10) = v5;
            *(OWORD*)&hstringHeader->Reserved.Reserved1 = v10;
            *(QWORD*)&hstringHeader->Reserved.Reserved2[16] = sourceString;
            *string = (HSTRING)hstringHeader;
            
        }
    }
 
    return result;
     */
    return S_OK;
}

const WCHAR ret_string[] = L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

__declspec(dllexport) PCWSTR APIENTRY _WindowsGetStringRawBuffer(
    HSTRING string,
    UINT32* length
)
{
    *length = 1;
    return ret_string;
}

__declspec(dllexport) HRESULT APIENTRY _WindowsCompareStringOrdinal(
    HSTRING string1,
    HSTRING string2,
    INT32* result
)
{
    if (result)
    {
        *result = 0;
    }//end if (result)
    return ERROR_BAD_FORMAT;
}

__declspec(dllexport) BOOL APIENTRY _WindowsIsStringEmpty(
    HSTRING string
)
{
    return TRUE;
}

__declspec(dllexport) UINT32 APIENTRY _WindowsGetStringLen(
    HSTRING string
)
{
    return NULL;
}

__declspec(dllexport) UINT32 APIENTRY _WindowsDuplicateString(
    HSTRING string,
    HSTRING* newString
)
{

    return E_INVALIDARG;
}

__declspec(dllexport) HRESULT APIENTRY WindowsStringHasEmbeddedNull(
    HSTRING string,
    BOOL* hasEmbedNull
)
{
    return E_INVALIDARG;
}


}
