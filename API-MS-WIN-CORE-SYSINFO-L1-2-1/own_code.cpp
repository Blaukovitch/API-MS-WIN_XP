

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
       ::ZeroMemory(_Destination, _DestinationSize);
   
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

//#pragma optimize("", on)
//#pragma optimize("", on)

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

#define 	RSIZE_MAX_STR   (4UL << 10) /* 4KB */
 #pragma intrinsic(wcscpy_s)
 __inline HRESULT wcscpys(wchar_t* dest, rsize_t dmax, const wchar_t* src)
 {
     const wchar_t* overlap_bumper;

     if (dest == NULL) {
         return ERROR_BAD_ARGUMENTS;
     }

     if (dmax == 0) {
         return ERROR_EMPTY;
     }

     if (dmax * sizeof(wchar_t) > RSIZE_MAX_STR) {
         return ERROR_BUFFER_OVERFLOW;
     }

     if (src == NULL) {
         return ERROR_BAD_ARGUMENTS;
     }

     /* Verify proper length according to dmax if src = dest */
     if (dest == src) {
         /* Ensure that src is not longer than dmax */
         while (*src != L'\0' && (dmax != 0)) { src++; dmax--; }
         if (*src != L'\0') {
             return ERROR_BUFFER_OVERFLOW;
         }
         return ERROR_SUCCESS;
     }

     if (dest < src) {
         overlap_bumper = src;

         while (dmax > 0) {
             if (dest == overlap_bumper) {
                 return ERROR_STACK_OVERFLOW_READ;
             }

             *dest = *src;
             if (*dest == '\0') {
                 return ERROR_SUCCESS;
             }

             dmax--;
             dest++;
             src++;
         }

     }
     else {
         overlap_bumper = dest;

         while (dmax > 0) {
             if (src == overlap_bumper) {
                 return ERROR_STACK_OVERFLOW_READ;
             }

             *dest = *src;
             if (*dest == '\0') {
                 return ERROR_SUCCESS;
             }

             dmax--;
             dest++;
             src++;
         }
     }

     return ERROR_STACK_OVERFLOW_READ;
 }

#pragma intrinsic(wcschr)
 __inline wchar_t* wcschr1(const wchar_t* s, wchar_t c)
 {
     while (*s != c && *s != L'\0')
         s++;
     if (*s == c)
         return ((wchar_t*)s);
     return (NULL);
 }

 LONG randr()
 {
     
     LARGE_INTEGER LI;
     ::QueryPerformanceCounter(&LI);
  
     return LI.LowPart;
 }


  
