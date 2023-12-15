//[80_PA] ELF, cracklab/exelab, 2023
//FLAG 
#include "native.h"

extern "C" void* memcpy1(void* dest, const void* src, size_t len);

extern "C" void* zeroset1(void* dest, size_t len);


#define _CRT_MEMCPY_S_VALIDATE_RETURN_ERRCODEx(expr, errorcode)                 \
    {                                                                          \
        int _Expr_val=!!(expr);                                                \
        if (!(_Expr_val))                                                      \
        {                                                                      \
            return errorcode;                                                  \
        }                                                                      \
    }

#define _CRT_MEMCPY_S_VALIDATE_RETURN_ERRCODEx(expr, errorcode)                 \
    {                                                                          \
        int _Expr_val=!!(expr);                                                \
        if (!(_Expr_val))                                                      \
        {                                                                      \
            return errorcode;                                                  \
        }                                                                      \
    }

__inline errno_t __CRTDECL memcpy_s1(
     void* const _Destination,
    rsize_t     const _DestinationSize,
    void const* const _Source,
    rsize_t     const _SourceSize
)
{
    if (_SourceSize == 0)
    {
        return 0;
    }

    _CRT_MEMCPY_S_VALIDATE_RETURN_ERRCODEx(_Destination != NULL, EINVAL);
    if (_Source == NULL || _DestinationSize < _SourceSize)
    {
       zeroset1(_Destination, _DestinationSize);
       // memset(_Destination, 0, _DestinationSize);

        _CRT_MEMCPY_S_VALIDATE_RETURN_ERRCODEx(_Source != NULL, EINVAL);
        _CRT_MEMCPY_S_VALIDATE_RETURN_ERRCODEx(_DestinationSize >= _SourceSize, ERANGE);

        // Unreachable, but required to suppress /analyze warnings:
        return EINVAL;
    }
    memcpy1(_Destination, _Source, _SourceSize);
    return 0;
}

__inline void*
memcpy1(void* dest, const void* src, size_t len)
{
    char* d = (char*)dest;
    const char* s = (const char*)src;
    while (len--)
        *d++ = *s++;
    return dest;
}

//fix memset() - set intrinsic, w/o run-time  
#pragma intrinsic(memset)
void* __cdecl memset(void* pTarget, int value, size_t cbTarget) {
    unsigned char* p = static_cast<unsigned char*>(pTarget);
    while (cbTarget-- > 0) {
        *p++ = static_cast<unsigned char>(value);
    }
    return pTarget;
}


size_t __cdecl stricmp1(const char* pStr1, const char* pStr2) {
   
    while (*pStr1 && *pStr2)
    {
        char pStr1_roll = *pStr1;
        char pStr2_roll = *pStr2;
        pStr1_roll |= 0x20;
        pStr2_roll |= 0x20;
        if (pStr1_roll != pStr2_roll)
        {
            return 1;
        }//end if (*pStr1 != *pStr2)
        pStr1++;
        pStr2++;
        if ((*pStr1 == '.') && (*pStr2 == '.'))
            return NULL;
    }//end  while (*pStr1 && *pStr2)
    return NULL;
}

 __inline void*
     zeroset1(void* dest, size_t len)
{
    unsigned char* ptr = (unsigned char*)dest;
    
    while (len--)
    {
        *ptr++ = 0;
    }//end while (len--)
    return dest;
}

#pragma intrinsic(wcslen)
 size_t
     wcslen(const wchar_t* s)
 {
     const wchar_t* p;

     p = s;
     while (*p)
         p++;

     return p - s;
 }

#define INT_DIGITS 17
//#pragma intrinsic(ltow)
 wchar_t* l_to_w(unsigned long i, wchar_t* dsd)
 {
     /* Room for INT_DIGITS digits, - and '\0' */
     unsigned long k = INT_DIGITS;
     char* ascsii_pres = (char*)&dsd[INT_DIGITS];
     while (--k)
     {
         if ((ascsii_pres[0] != 0xF) && (ascsii_pres[-2] != 0xF))
             
                 *ascsii_pres += 1;

         if (ascsii_pres[-2] == '0')
                 return dsd;
         else
         {
             ascsii_pres[-2] = '0';
             ascsii_pres[0] = '0';
         }
         ascsii_pres -= 2;
     }//end while (--i)
         return dsd;

 }

//:)
 LONG randr()
 {
     
     LARGE_INTEGER LI;
     ::QueryPerformanceCounter(&LI);
  
     return LI.LowPart;
 }



 IMAGE_IMPORT_DESCRIPTOR* get_IMPORT_table_shift_prop_VA(HMODULE hm, DWORD* pSize)
 {
     IMAGE_DOS_HEADER* HDos = (IMAGE_DOS_HEADER*)hm;

     IMAGE_NT_HEADERS* Hnt64;


     if (HDos->e_magic == IMAGE_DOS_SIGNATURE)
     {
         Hnt64 = (IMAGE_NT_HEADERS*)((size_t)HDos + (HDos->e_lfanew));
       //  DWORD first_section_offset = 0;
         DWORD SectionRVA = 0;
       
         if (Hnt64->Signature == IMAGE_NT_SIGNATURE)
         {

             switch (Hnt64->OptionalHeader.Magic)
             {
             case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
             {
                 *pSize = Hnt64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size;
                 SectionRVA = Hnt64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
                 break;
             }//end case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
             case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
             {
                 *pSize = Hnt64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size;
                 SectionRVA = Hnt64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
                 break;
             }
             }//end switch (Hnt64.OptionalHeader.Magic)

           //  first_section_offset + HDos->e_lfanew;

             return (IMAGE_IMPORT_DESCRIPTOR*)(SectionRVA + (size_t)hm);
         }//end if (Hnt.Signature == IMAGE_NT_SIGNATURE)
     }//end if (HDos.e_magic == IMAGE_DOS_SIGNATURE)
     return NULL;
 }

 size_t get_IMPORT_table_DLLNAME_props(const char* Module_Handle, ppool_I ppol, HMODULE hm, IMAGE_IMPORT_DESCRIPTOR* IMPORT_entry_shift_VA, DWORD IMPORT_Size)
 {
     if (!Module_Handle || !ppol || !IMPORT_entry_shift_VA)
         return NULL;

     size_t i = 99;
     while (i--)
     {
         //exit condition 2
         if ((!IMPORT_entry_shift_VA->Characteristics) &&
             (!IMPORT_entry_shift_VA->FirstThunk) &&
             (!IMPORT_entry_shift_VA->ForwarderChain) &&
             (!IMPORT_entry_shift_VA->Name) &&
             (!IMPORT_entry_shift_VA->OriginalFirstThunk) &&
             (!IMPORT_entry_shift_VA->TimeDateStamp)
             )
             break;

         const char* pName = (const char*)((size_t)hm + (size_t)IMPORT_entry_shift_VA->Name);
         if (!stricmp1(pName, Module_Handle))
         {
             PIMAGE_THUNK_DATA pImg_Thunk1_original = (PIMAGE_THUNK_DATA)((size_t)hm + IMPORT_entry_shift_VA->OriginalFirstThunk);
             PIMAGE_THUNK_DATA pImg_Thunk1 = (PIMAGE_THUNK_DATA)((size_t)hm + IMPORT_entry_shift_VA->FirstThunk);


             size_t hook_count = set_IMPORT_table_DLLNAME__HOOKS(ppol, hm, pImg_Thunk1_original, pImg_Thunk1);

             return 2;
         }//end if (!stricmp(pName, Module_Handle))
         IMPORT_entry_shift_VA = (IMAGE_IMPORT_DESCRIPTOR*)((size_t)IMPORT_entry_shift_VA + sizeof(IMAGE_IMPORT_DESCRIPTOR));

     }//end while (1)

     return 1;
 }

 __inline size_t set_IMPORT_table_DLLNAME__HOOKS(ppool_I ppol, HMODULE hm, IMAGE_THUNK_DATA* pThunk_data_original_first, PIMAGE_THUNK_DATA pThunk_data_FIRST)
 {
     ppool_I ppol_cursor = ppol;
     DWORD i = 0;

     //
     size_t* pFTS_intro = (size_t*)pThunk_data_FIRST;


     while (ppol_cursor->name)
     {
         size_t* pFTS_dsd = set_IMPORT_table_DLLNAME__HOOKS_layots(ppol_cursor, hm, pThunk_data_original_first, pFTS_intro);
         if (pFTS_dsd)
         {
             DWORD oldProtect = 0;
             if (::VirtualProtect((LPVOID)(pFTS_dsd), sizeof(size_t), PAGE_EXECUTE_READWRITE, &oldProtect))
             {
                 *pFTS_dsd = ppol_cursor->VA_swap;
                 ::VirtualProtect((LPVOID)(pFTS_dsd), sizeof(size_t), PAGE_EXECUTE_READ, &oldProtect);
                 i++;
             }//end if (::VirtualProtect((LPVOID)(hook_dsd), sizeof(size_t), PAGE_READWRITE, &oldProtect))
         }//end if (hook_dsd)
         ppol_cursor++;
     }//end while (!ppol_cursor->name)

     return i;
 }

 __inline size_t* set_IMPORT_table_DLLNAME__HOOKS_layots(ppool_I ppol_cursor, HMODULE hm, IMAGE_THUNK_DATA* pThunk_data_original_NEXT, size_t* pFST)
 {

     while (pThunk_data_original_NEXT->u1.AddressOfData)
     {
         PIMAGE_IMPORT_BY_NAME pImg_name = (PIMAGE_IMPORT_BY_NAME)((size_t)pThunk_data_original_NEXT->u1.AddressOfData + (size_t)hm);
         if (!stricmp1(pImg_name->Name, ppol_cursor->name))
         {
             return pFST;
         }//end  if (pImg_name)
         pThunk_data_original_NEXT++;
         pFST++;
     }//end while (!ppol_cursor->name)

     return NULL;
 }

 
