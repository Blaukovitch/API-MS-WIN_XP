#pragma once

//[80_PA] ELF, cracklab/exelab, 2023-2025
//FLAG 

#include <Windows.h>
#include <TlHelp32.h>
#include <werapi.h>
#include <psapi.h>
#include <appmodel.h>
#define EXPORT __declspec(dllexport)

#include "native.h"
#include "ntheader.h"

typedef struct {
    const char* name;
    size_t VA_swap;
}pool_I, * ppool_I;


extern "C"
{
    LONG randr();
    errno_t __cdecl memcpy_s1(
        void* const _Destination,
        rsize_t     const _DestinationSize,
        void const* const _Source,
        rsize_t     const _SourceSize
    );
    IMAGE_IMPORT_DESCRIPTOR* get_IMPORT_table_shift_prop_VA(HMODULE hm, DWORD* pSize);
    size_t get_IMPORT_table_DLLNAME_props(const char* Module_Handle, ppool_I ppol, HMODULE hm, IMAGE_IMPORT_DESCRIPTOR* IMPORT_entry_shift_VA, DWORD IMPORT_Size);
    size_t set_IMPORT_table_DLLNAME__HOOKS(ppool_I ppol, HMODULE hm, IMAGE_THUNK_DATA* pThunk_data_original_first, PIMAGE_THUNK_DATA pThunk_data_FIRST);
    size_t* set_IMPORT_table_DLLNAME__HOOKS_layots(ppool_I ppol_cursor, HMODULE hm, IMAGE_THUNK_DATA* pThunk_data_original_NEXT, size_t* pFST);
    
}
