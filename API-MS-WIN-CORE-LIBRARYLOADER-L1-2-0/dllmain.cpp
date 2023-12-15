//[80_PA] ELF, cracklab/exelab, 2023
//include 'skip_entrys.cpp' ^)

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


/*
 NO SELF-EMULATE&SELF-EXECUTABLE FUNC
 NEED ONLY LIBRARY NAME FOR PE IMPORT TABLE(!)
 SEE 'skip_entrys.cpp' - simple bridged to actual Windows 7 WinAPI 
*/ 
