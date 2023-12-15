//[80_PA] ELF, cracklab/exelab, 2023
//FLAG

/*
WHAT IS FUC...G DOING THIS SIMPLE PROGRAM>?
Simple: after link you DLL (kernel64, API-MS-WIN-CORE-HANDLE-L1-1-0, user64, WinXttp ...) in MSVC (or you choose) set the latest command -
linker_export.exe "kernel64.dll"

More technical info:
1) We cannot directly compile DLLs with exported functions whose names are already written in the original Microsoft system dll-libraries. 
For example, WinAPI "GetProcessMitigationPolicy", "CreateFileA" from %SYSTEMROOT%\System32\kernel32.dll and so on.
2) Also, we cannot take the same system library name (e.g. kernel32) for our library to use without editing the PE COFF export table.

To solve the first problem (1), we mark the exported functions in our library with a special marker (lower dash).
"_GetProcessMitigationPolicy".
is a sign for linker_export that the name of the specified function should be renamed (remove the marker) to get the original name "GetProcessMitigationPolicy".
At the same time linker_export removes unnecessary characters such as @ that are left after x86 (32-bit compiler). On the output we get a correct name of the exported function, which is correctly recognized during initial library loading and after GetProcAddress() call.
To solve the second problem, we need to assign a name different from the name of the source system library: "kernel64.dll" instead of "kernel32.dll". In this case, our library "kernel64.dll" performs the following functions
a) proxy/bridged functions into the original system library "%SYSTEMROOT%\System32\kernel32.dll". This requires editing of the Chrome/EDGE/Opera/Spotify import table, etc.
b) substitutes or emulates WinAPI exported functions missing in Windows 7 such as "GetProcessMitigationPolicy", "SetThreadInformation", "GetFirmwareType" and so on.
Nice hunt!
*/

/*
Для чего это нужно?
Кратко: после линковки нужно поправить таблицу экспорта для kernel64 и некоторых остальных из-за известных особенностей компиляции dll'ок с одинаковыми именами WinAPI функций системных либ.
В MSVC (настройки проекта > события сборки > события после сборки > командная строка) вбить:
linker_export.exe  $(TargetName)$(TargetExt)

Для тех, кто в Т-80У:
1) Мы не можем напрямую компилировать DLL библиотеки с экспортируемыми функциями, имена которых уже прописаны в оригинальных системных библиотеках Microsoft (ну во всяком случае не слышал про то, как можно элегантно за раз так сделать сразу - малоизвестные флаги, что в компилях делают не то что нужно). 
Например, WinAPI "GetProcessMitigationPolicy", "CreateFileA" из kernel32.dll и так далее
2) Так-же мы не можем взять одно и то же имя системной библиотеки (например, kernel32) для нашей библиотеки, чтобы использовать её без правки таблицы импорта/экспорта PE COFF файла.

Для решения первой проблемы (1) в нашей библиотеке мы помечаем наши экспортируемые фукнции специальным маркером (нижнне тире).
"_GetProcessMitigationPolicy"
это знак для linker_export, что имя указанной фукнции необходимо переименовать (убрать маркер), чтобы получить оригинальное имя "GetProcessMitigationPolicy".
Заодно linker_export убирает лишние символы такие как @%ANY_TRASH%, которые остаются после работы x86 (32 битного компилятора). На выходе получается валидное имя экспортируемой фукнции, которое корректно распознаётся на начальном этапе загрузки образа библиотеки, а так-же после вызова GetProcAddress();
Для решения второго ньюанса (2) требуется присвоить имя отличное от оригинальной системной библиотки: "kernel64.dll" вместо "kernel32.dll". При этом наша библиотека "kernel64.dll" выполняет
а) проксирующее (proxy/bridged) фукнции в оригинальную системную библиотеку "%SYSTEMROOT%\System32\kernel32.dll". При этом требуется правка таблицы импорта Chrome/EDGE/Opera/Spotify и тп
б) подменяет или эмулирует отсутствующие в Windows 7 экспортируемые WinAPI фукнции как "GetProcessMitigationPolicy", "SetThreadInformation", "GetFirmwareType" и так далее
В остальном логика bridged (проксирования) должна быть понятна.
Удачной охоты!
*/

#include <iostream>
#include <Windows.h>

typedef struct RECALC
{
    DWORD Start_names_va_table;
    DWORD End_names_va_table;
    DWORD names_va_long;

    DWORD Start_names_string_area;
    DWORD End_names_string_area;
    DWORD names_string_long;

    DWORD Api_long;
}Recalc_resurected_req, *pRecalc_resurected_req;

IMAGE_DOS_HEADER HDos;
IMAGE_NT_HEADERS64 Hnt64;

IMAGE_EXPORT_DIRECTORY PE_Export_DIR;

#define MAX_SECTIONS 32
IMAGE_SECTION_HEADER pSections[MAX_SECTIONS];

DWORD NumOfSec;

DWORD get_Export_table_shift_prop(HANDLE f, DWORD* pSize);
DWORD get_Export_table_TEXT_props(HANDLE f, DWORD export_entry_shift, DWORD export_Size);
DWORD Rva2Offset(DWORD rva);
DWORD Resurect_original_API_names(HANDLE f, DWORD API_long, DWORD shift_va, pRecalc_resurected_req pRecalc_req);
BOOL NormalizeAPI(char* pApi, DWORD api_str_len);
DWORD Rebase_resurected_area(HANDLE f, pRecalc_resurected_req pRecalc_req);
LPVOID New_operation_region(HANDLE f, DWORD fp, DWORD size);
BOOL WRITE_operation_region(HANDLE f, DWORD raw, LPVOID buff, DWORD size);

int main(int argc, char* argv[])
{

    printf("%s\r\n", argv[1]);
    if (::GetFileAttributesA(argv[1]) == -1)
        return 5;

    HANDLE f = ::CreateFileA(argv[1], GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (f == INVALID_HANDLE_VALUE)
        return 5;

    printf("file open %s\r\n", argv[1]);

    DWORD size = 0;
    DWORD shift = get_Export_table_shift_prop(f, &size);

    printf("export_table va %x\r\n", shift);

    if (shift)
        get_Export_table_TEXT_props(f, shift, size);

    ::CloseHandle(f);
    
    HMODULE test_l = ::LoadLibraryA(argv[1]);
    if(test_l)
    {
        FARPROC TEST1 = ::GetProcAddress(test_l, "lstrcmpA"); //kernel64/32
      //FARPROC TEST1 = ::GetProcAddress(test_l, "WinHttpSetTimeouts"); //winxttp/winhttp
        if(!TEST1)
                 ::Sleep(1);
        
    }//end if(test_l)
}


DWORD get_Export_table_shift_prop(HANDLE f, DWORD* pSize)
{
    DWORD br = 0;
    BOOL bret = ::ReadFile(f, (LPVOID)&HDos, sizeof(IMAGE_DOS_HEADER), &br, NULL);

    if (bret && HDos.e_magic == IMAGE_DOS_SIGNATURE)
    {
        ::SetFilePointer(f, HDos.e_lfanew, NULL, FILE_BEGIN);
        br = 0;
        bret = ::ReadFile(f, &Hnt64, sizeof(IMAGE_NT_HEADERS64), &br, NULL);
        DWORD first_section_offset = 0;
        DWORD SectionRVA = 0;
        if (bret && Hnt64.Signature == IMAGE_NT_SIGNATURE)
        {

                switch (Hnt64.OptionalHeader.Magic)
                {
                    case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
                    {
                        PIMAGE_NT_HEADERS32 Hnt32 = (PIMAGE_NT_HEADERS32)&Hnt64;
                        *pSize = Hnt32->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;
                        SectionRVA = Hnt32->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
                        first_section_offset = FIELD_OFFSET(IMAGE_NT_HEADERS32, OptionalHeader) + Hnt32->FileHeader.SizeOfOptionalHeader;
                        NumOfSec = Hnt32->FileHeader.NumberOfSections;
                        break;
                    }//end case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
                    case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
                    {
                        *pSize = Hnt64.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;
                        SectionRVA = Hnt64.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
                        first_section_offset = FIELD_OFFSET(IMAGE_NT_HEADERS64, OptionalHeader) + Hnt64.FileHeader.SizeOfOptionalHeader;
                        NumOfSec = Hnt64.FileHeader.NumberOfSections;
                    }
                }//end switch (Hnt64.OptionalHeader.Magic)

                ::SetFilePointer(f, first_section_offset + HDos.e_lfanew, NULL, FILE_BEGIN);

                bret = ::ReadFile(f, &pSections, sizeof(pSections), &br, NULL);

                if (bret)
                {
                   return Rva2Offset(SectionRVA);          
                }//end if (bret)
              
        }//end if (Hnt.Signature == IMAGE_NT_SIGNATURE)
    }//end if (HDos.e_magic == IMAGE_DOS_SIGNATURE)
    return 0;
}

DWORD get_Export_table_TEXT_props(HANDLE f, DWORD export_entry_shift, DWORD export_Size)
{
    if (!export_Size || !export_entry_shift)
        return 0;
    
    DWORD br = 0;
    ::SetFilePointer(f, export_entry_shift, NULL, FILE_BEGIN);
    BOOL bret1 = ::ReadFile(f, (LPVOID)&PE_Export_DIR, sizeof(IMAGE_EXPORT_DIRECTORY), &br, NULL);

    if (bret1)
    {
        Recalc_resurected_req recal_resu_req = { 0,0,0,0,0,0, PE_Export_DIR.NumberOfNames};

        if (Resurect_original_API_names(f, PE_Export_DIR.NumberOfNames, Rva2Offset(PE_Export_DIR.AddressOfNames), &recal_resu_req))
            //  Rebase_resurected_area(f, &recal_resu_req);
            Beep(0, 0);

    }//end if (bret1)
}

DWORD Rva2Offset(DWORD rva) {
    DWORD noOfSection = NumOfSec;
    PIMAGE_SECTION_HEADER pFirstSec_save_prev;
    PIMAGE_SECTION_HEADER pFirstSec = pSections;
    pFirstSec--;
    DWORD RawAddress = 0;
    while (noOfSection--)
    {
        pFirstSec++;
        if ((pFirstSec->VirtualAddress + pFirstSec->SizeOfRawData) < rva)
            continue;

        pFirstSec_save_prev = pFirstSec - 1;
        return (rva - pFirstSec->VirtualAddress) + (pFirstSec_save_prev->SizeOfRawData + pFirstSec_save_prev->PointerToRawData);
    }//end while (i--)

    return 0;
}

#define MAX_API_LONG 1024
DWORD Resurect_original_API_names(HANDLE f, DWORD API_long, DWORD shift_va, pRecalc_resurected_req pRecalc_req)
{
    DWORD next_api_shift[2] = { 0, 0 };
    char API_buff[MAX_API_LONG];
    DWORD i = 0;

    if (pRecalc_req)
    {
        pRecalc_req->Start_names_va_table = shift_va;

        ::SetFilePointer(f, shift_va, NULL, FILE_BEGIN);
        DWORD br = 0;
        BOOL bret1 = ::ReadFile(f, &next_api_shift, sizeof(next_api_shift), &br, NULL);
        if(bret1)
            pRecalc_req->Start_names_string_area = Rva2Offset(next_api_shift[0]);
    }//end if (pRecalc_req)

    while (API_long--)
    {
        ::SetFilePointer(f, shift_va, NULL, FILE_BEGIN);
        shift_va += sizeof(DWORD);
        DWORD br = 0;
        BOOL bret1 = ::ReadFile(f, &next_api_shift, sizeof(next_api_shift), &br, NULL);
        DWORD api_str_len = next_api_shift[1] - next_api_shift[0];
        if (bret1 && api_str_len < MAX_API_LONG)
        {
#ifndef  _COPY
            ::SetFilePointer(f, Rva2Offset(next_api_shift[0]), NULL, FILE_BEGIN);
            br = 0;
            BOOL bret1 = ::ReadFile(f, API_buff, api_str_len, &br, NULL);
            if (bret1)
            {
                if (NormalizeAPI(API_buff, api_str_len))
                {
                    if (api_str_len > 1)
                        api_str_len--;
                    ::SetFilePointer(f, Rva2Offset(next_api_shift[0]), NULL, FILE_BEGIN);
                    br = 0;
                    if (::WriteFile(f, API_buff, api_str_len, &br, NULL))
                        i++;
                    printf("- %s_export @%i\r\n", API_buff, i-1);
                }//end if (NormalizeAPI(API_buff, api_str_len))
            }//end if (bret1) #2
#endif //  _COPY
        }//end if (bret1) #1
        else
        {
            //last
            if (API_long)
                continue;
#ifndef  _COPY
            ::SetFilePointer(f, Rva2Offset(next_api_shift[0]), NULL, FILE_BEGIN);
            br = 0;
            api_str_len = MAX_PATH;
            *API_buff = 0;
            BOOL bret1 = ::ReadFile(f, API_buff, api_str_len, &br, NULL);
            if (bret1)
            {
                //correct string long
                api_str_len = (DWORD)strlen(API_buff);

                 if (NormalizeAPI(API_buff, api_str_len))
                {
                  //  if (api_str_len > 1)
                    //    api_str_len--;
                    ::SetFilePointer(f, Rva2Offset(next_api_shift[0]), NULL, FILE_BEGIN);
                    br = 0;
                    if (::WriteFile(f, API_buff, api_str_len, &br, NULL))
                        i++;
                    printf("- %s_export @%i\r\n", API_buff, i-1);
                }//end if (NormalizeAPI(API_buff, api_str_len))
            }//end if (bret1) #2
#endif //  _COPY
        }
    }//end while (API_long--)
    if (pRecalc_req)
    {
        pRecalc_req->End_names_va_table = shift_va;
        pRecalc_req->End_names_string_area = Rva2Offset(next_api_shift[0]);

        pRecalc_req->names_va_long = pRecalc_req->End_names_va_table - pRecalc_req->Start_names_va_table;
        pRecalc_req->names_string_long = pRecalc_req->End_names_string_area - pRecalc_req->Start_names_string_area;
    }//end if (pRecalc_req)
    return i;
}

__inline BOOL NormalizeAPI(char* pApi, DWORD api_str_len)
{
    char* pApi_PREDICT = pApi;
    //is my
    if (*pApi == '_')
    {
        pApi_PREDICT++;
        //x86 style
        if (pApi[1] == '_')
            pApi_PREDICT++;;

        //shift to one symbol left
        while (api_str_len--)
        {
            *pApi++ = *pApi_PREDICT++;
            
            //_export
            if (pApi[-1] == '@')
            {
                memset(&pApi[-1], 0, api_str_len);
                return TRUE;
            }//END  if (pApi[-1] == '@')
        }//end  while (api_str_len--)
        pApi_PREDICT[-1] = '\0';
        pApi[-1] = '\0';
    }//end if (*pApi == '_') #1

    return TRUE;
}


#define SAFE_END 100
#define ZERO_END_BYTE 1
DWORD Rebase_resurected_area(HANDLE f, pRecalc_resurected_req pRecalc_req)
{
    DWORD i = pRecalc_req->names_string_long;

    DWORD* pRVA_recalc = (DWORD*)New_operation_region(f, pRecalc_req->Start_names_va_table, pRecalc_req->names_va_long);

    if (!pRVA_recalc)
        return 0;

    char* pString_area_recalc = (char*)New_operation_region(f, pRecalc_req->Start_names_string_area, pRecalc_req->names_string_long + SAFE_END);

    if (!pString_area_recalc)
    {
        free(pRVA_recalc);
        return 0;
    }//end     if (!pString_area_recalc)

    char* pString_area_recalc_cursor = pString_area_recalc;
    DWORD* pRVA_recalc_cursor = pRVA_recalc;

    pRVA_recalc_cursor[1] = pRVA_recalc_cursor[0];
    char* pString_area_recalc_NEW_NEXT = pString_area_recalc_cursor + strlen(pString_area_recalc_cursor);
    pRVA_recalc_cursor[1] += strlen(pString_area_recalc_cursor) + ZERO_END_BYTE;
    pRVA_recalc_cursor++;
    pRVA_recalc_cursor[1] = pRVA_recalc_cursor[0];
    pString_area_recalc_NEW_NEXT++;

    DWORD api_i = pRecalc_req->Api_long;
    while (i--)
    {
        if (*pString_area_recalc_cursor++ != '\0')
        {
            //increase long RVA
            /*
            if (api_i > 1)
             pRVA_recalc_cursor[1] += 1;
             */
        }//end increase
        else
        {
            //inc with ZERO str end
            if (api_i > 1)
                pRVA_recalc_cursor[1] += 1;
            
            BOOL NEW_NEXT_IS_READY = FALSE;
            while (--i)
            {
                pString_area_recalc_cursor++;

                //skip ZEROS
                if (*pString_area_recalc_cursor == '\0')
                {
                    if (!NEW_NEXT_IS_READY)
                        continue;
                    else
                    {
                        *pString_area_recalc_NEW_NEXT++ = '\0';
                        pString_area_recalc_cursor++;
                        if (i == 1 || !i)
                            break;

                        if (--api_i)
                        {
                            pRVA_recalc_cursor++;
                            pRVA_recalc_cursor[1] = pRVA_recalc_cursor[0];
                        }
                        else
                        {
                            //************* MUST APIs is NULL - SUCCESS END ******************** //
                            if (i > SAFE_END)
                            {
                               memset(pString_area_recalc_NEW_NEXT, 0, i - SAFE_END);
                            }//end if (i > SAFE_END)

                            BOOL retw = FALSE;
                            retw = WRITE_operation_region(f, pRecalc_req->Start_names_va_table, pRVA_recalc, pRecalc_req->names_va_long);
                            retw = WRITE_operation_region(f, pRecalc_req->Start_names_string_area, pString_area_recalc, pRecalc_req->names_string_long);

                            free(pString_area_recalc);
                            free(pRVA_recalc);
                            return 1;
                        }
                  
                        break;
                    }//end if (!NEW_NEXT_IS_READY)
                }
                else
                {
                    *pString_area_recalc_NEW_NEXT++ = *pString_area_recalc_cursor;
                    NEW_NEXT_IS_READY = TRUE;

                    if (api_i > 1)
                        pRVA_recalc_cursor[1] += 1;
                }   
            }//end while (i--) #2


        }// if (*pString_area_recalc_cursor++ != '\0')
    }//end while (i--) #1

    free(pString_area_recalc);
    free(pRVA_recalc_cursor);
    return 0;
}

LPVOID New_operation_region(HANDLE f, DWORD fp, DWORD size)
{
    LPVOID x_Calloc = (DWORD*)calloc(1, size + SAFE_END);

    if (!x_Calloc)
        return 0;

    DWORD br = 0;
    ::SetFilePointer(f, fp, NULL, FILE_BEGIN);
    BOOL bret1 = ::ReadFile(f, x_Calloc, size, &br, NULL);
    //SUCCESS
    if (bret1)
        return x_Calloc;

    free(x_Calloc);
    return 0;
}

BOOL WRITE_operation_region(HANDLE f, DWORD raw, LPVOID buff, DWORD size)
{
    DWORD WrtBytes = 0;
    ::SetFilePointer(f, raw, NULL, FILE_BEGIN);
    return ::WriteFile(f, buff, size, &WrtBytes, NULL);
}
