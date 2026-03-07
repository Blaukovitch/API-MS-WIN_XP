//[80_PA] ELF, cracklab/exelab, 2023-2026
//FLAG 
#include <Windows.h>  
#include <usp10.h>
#define EXPORT __declspec( dllexport )

//379
extern "C"
{

//DEFAULT 7


EXPORT int WINAPI _AbortDoc(HDC hdc) {
    return ::AbortDoc(hdc);
}

EXPORT HANDLE WINAPI _AddFontMemResourceEx(PVOID pFileView,
    DWORD cjSize,
    PVOID pvResrved,
    DWORD* pNumFonts) {
    return ::AddFontMemResourceEx(pFileView, cjSize, pvResrved, pNumFonts);
}

EXPORT int WINAPI _AddFontResourceExW(LPCWSTR name, DWORD fl, PVOID res) {
    return ::AddFontResourceExW(name, fl, res);
}

EXPORT BOOL WINAPI _BeginPath(HDC hdc) {
    return ::BeginPath(hdc);
}

EXPORT BOOL WINAPI _BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop) {
    return ::BitBlt(hdc, x, y, cx, cy, hdcSrc, x1, y1, rop);
}

EXPORT int WINAPI _ChoosePixelFormat(HDC hdc, PIXELFORMATDESCRIPTOR* ppfd) {
    return ::ChoosePixelFormat(hdc, ppfd);
}

EXPORT int WINAPI _CloseFigure(HDC hdc) {
    return ::CloseFigure(hdc);
}

EXPORT HBITMAP WINAPI _CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitCount, VOID* lpBits) {
    return ::CreateBitmap(nWidth, nHeight, nPlanes, nBitCount, lpBits);
}

EXPORT HBITMAP WINAPI _CreateCompatibleBitmap(HDC hdc, int cx, int cy) {
    return ::CreateCompatibleBitmap(hdc, cx, cy);
}

EXPORT HDC WINAPI _CreateCompatibleDC(HDC hdc) {
    return ::CreateCompatibleDC(hdc);
}

EXPORT HDC WINAPI _CreateDCW(LPCWSTR pwszDriver, LPCWSTR pwszDevice, LPCWSTR pszPort, DEVMODEW* pdm) {
    return ::CreateDCW(pwszDriver, pwszDevice, pszPort, pdm);
}

EXPORT HBITMAP WINAPI _CreateDIBSection(
    HDC         hdc,
    BITMAPINFO* pbmi,
    UINT        usage,
    VOID**      ppvBits,
    HANDLE      hSection,
    DWORD       offset) {
    return ::CreateDIBSection(hdc, pbmi, usage, ppvBits, hSection, offset);
}

EXPORT HBITMAP WINAPI _CreateDIBitmap(
    HDC hdc, 
    BITMAPINFOHEADER* pbmih, 
    DWORD flInit, 
    VOID* pjBits, 
    BITMAPINFO* pbmi, 
    UINT iUsage) {
    return ::CreateDIBitmap(hdc, pbmih, flInit, pjBits, pbmi, iUsage);
}

EXPORT HFONT WINAPI _CreateFontIndirectW(LOGFONTW* lplf) {
    return ::CreateFontIndirectW(lplf);
}

EXPORT HDC WINAPI _CreateICW(LPCWSTR pszDriver, LPCWSTR pszDevice, LPCWSTR pszPort, DEVMODEW* pdm) {
    return ::CreateICW(pszDriver, pszDevice, pszPort, pdm);
}

EXPORT HBRUSH WINAPI _CreatePatternBrush(HBITMAP hbm) {
    return ::CreatePatternBrush(hbm);
}

EXPORT HRGN WINAPI _CreateRectRgn(int x1, int y1, int x2, int y2) {
    return ::CreateRectRgn(x1, y1, x2, y2);
}

EXPORT HBRUSH WINAPI _CreateSolidBrush(COLORREF color) {
    return ::CreateSolidBrush(color);
}

EXPORT BOOL WINAPI _DeleteDC(HDC hdc) {
    return ::DeleteDC(hdc);
}

EXPORT BOOL WINAPI _DeleteObject(HGDIOBJ ho) {
    return ::DeleteObject(ho);
}

EXPORT int WINAPI _EndDoc(HDC hdc) {
    return ::EndDoc(hdc);
}

EXPORT int WINAPI _EndPage(HDC hdc) {
    return ::EndPage(hdc);
}

EXPORT BOOL WINAPI _EndPath(HDC hdc) {
    return ::EndPath(hdc);
}

EXPORT int WINAPI _EnumFontFamiliesExW(HDC hdc, LPLOGFONTW lpLogfont, FONTENUMPROCW lpProc, LPARAM lParam, DWORD dwFlags) {
    return ::EnumFontFamiliesExW(hdc, lpLogfont, lpProc, lParam, dwFlags);
}

EXPORT HPEN WINAPI _ExtCreatePen(
    DWORD iPenStyle,
    DWORD cWidth,
    LOGBRUSH* plbrush,
    DWORD cStyle,
    DWORD* pstyle) {
    return ::ExtCreatePen(iPenStyle, cWidth, plbrush, cStyle, pstyle);
}

EXPORT HRGN WINAPI _ExtCreateRegion(XFORM* lpx, DWORD nCount, RGNDATA* lpData) {
    return ::ExtCreateRegion(lpx, nCount, lpData);
}

EXPORT int WINAPI _ExtEscape(
    HDC hdc,
    int iEscape,
    int cjInput,
    LPCSTR lpInData,
    int cjOutput,
    LPSTR lpOutData) {
    return ::ExtEscape(hdc, iEscape, cjInput, lpInData, cjOutput, lpOutData);
}

EXPORT int WINAPI _ExtSelectClipRgn(HDC hdc, HRGN hrgn, int mode) {
    return ::ExtSelectClipRgn(hdc, hrgn, mode);
}

EXPORT BOOL WINAPI _ExtTextOutW(HDC hdc, 
    int x, 
    int y, 
    UINT options, 
    RECT* lprect, 
    LPCWSTR lpString, 
    UINT c, 
    INT* lpDx) {
    return ::ExtTextOutW(hdc, x, y, options, lprect, lpString,c, lpDx);
}

EXPORT BOOL WINAPI _FillPath(HDC hdc) {
    return ::FillPath(hdc);
}

EXPORT BOOL WINAPI _GdiFlush() {
    return ::GdiFlush();
}

EXPORT BOOL WINAPI _GetCharABCWidthsW(HDC hdc,
    UINT wFirst,
    UINT wLast,
    LPABC lpABC) {
    return ::GetCharABCWidthsW(hdc, wFirst, wLast, lpABC);
}

EXPORT BOOL WINAPI _GetCharWidth32A(HDC hdc, 
    UINT iFirst, 
    UINT iLast, 
    LPINT lpBuffer) {
    return ::GetCharWidth32A(hdc, iFirst, iLast, lpBuffer);
}

EXPORT BOOL WINAPI _GetCharWidthI(HDC hdc,
    UINT giFirst,
    UINT cgi,
    LPWORD pgi,
    LPINT piWidths) {
    return ::GetCharWidthI(hdc, giFirst, cgi, pgi, piWidths);
}

EXPORT int WINAPI _GetClipBox(HDC hdc, LPRECT lprect) {
    return ::GetClipBox(hdc, lprect);
}

EXPORT int WINAPI _GetClipRgn(HDC hdc, HRGN hrgn) {
    return ::GetClipRgn(hdc, hrgn);
}

EXPORT HGDIOBJ WINAPI _GetCurrentObject(HDC hdc, UINT type) {
    return ::GetCurrentObject(hdc, type);
}

EXPORT int WINAPI _GetDIBits(HDC hdc, HBITMAP hbm, UINT start, UINT cLines,
    LPVOID lpvBits, LPBITMAPINFO lpbmi, UINT usage) {
    return ::GetDIBits(hdc, hbm, start, cLines, lpvBits, lpbmi, usage);
}

EXPORT int WINAPI _GetDeviceCaps(HDC hdc, int index) {
    return ::GetDeviceCaps(hdc, index);
}

EXPORT DWORD WINAPI _GetFontData(HDC     hdc,
    DWORD   dwTable,
    DWORD   dwOffset,
    PVOID pvBuffer,
    DWORD   cjBuffer) {
    return ::GetFontData(hdc, dwTable, dwOffset, pvBuffer, cjBuffer);
}

EXPORT DWORD WINAPI _GetFontUnicodeRanges(HDC hdc, LPGLYPHSET lpgs) {
    return ::GetFontUnicodeRanges(hdc, lpgs);
}

EXPORT DWORD WINAPI _GetGlyphIndicesW(HDC hdc, LPCWSTR lpstr, int c, LPWORD pgi, DWORD fl) {
    return ::GetGlyphIndicesW(hdc, lpstr, c, pgi, fl);
}

EXPORT DWORD WINAPI _GetGlyphOutlineW(HDC hdc,
    UINT uChar,
    UINT fuFormat,
    LPGLYPHMETRICS lpgm,
    DWORD cjBuffer,
    LPVOID pvBuffer,
    CONST MAT2* lpmat2) {
    return ::GetGlyphOutlineW(hdc, uChar, fuFormat, lpgm, cjBuffer, pvBuffer, lpmat2);
}

EXPORT int WINAPI _GetGraphicsMode(HDC hdc) {
    return ::GetGraphicsMode(hdc);
}

EXPORT BOOL WINAPI _GetICMProfileW(HDC hdc, LPDWORD pBufSize,
    LPWSTR pszFilename) {
    return ::GetICMProfileW(hdc, pBufSize, pszFilename);
}

EXPORT int WINAPI _GetObjectW(HANDLE h, int c, LPVOID pv) {
    return ::GetObjectW(h, c, pv);
}

EXPORT UINT WINAPI _GetOutlineTextMetricsA(HDC hdc,
    UINT cjCopy,
    LPOUTLINETEXTMETRICA potm) {
    return ::GetOutlineTextMetricsA(hdc, cjCopy, potm);
}

EXPORT UINT WINAPI _GetOutlineTextMetricsW(HDC hdc,
    UINT cjCopy,
    LPOUTLINETEXTMETRICW potm) {
    return ::GetOutlineTextMetricsW(hdc, cjCopy, potm);
}

EXPORT COLORREF WINAPI _GetPixel(HDC hdc, int x, int y) {
    return ::GetPixel(hdc, x, y);
}

EXPORT int WINAPI _GetRandomRgn(HDC hdc, HRGN hrgn, INT i) {
    return ::GetRandomRgn(hdc, hrgn, i);
}

EXPORT DWORD WINAPI _GetRegionData(HRGN hrgn,
    DWORD nCount,
    LPRGNDATA lpRgnData) {
    return ::GetRegionData(hrgn, nCount, lpRgnData);
}

EXPORT HGDIOBJ WINAPI _GetStockObject(int i) {
    return ::GetStockObject(i);
}

EXPORT BOOL WINAPI _GetTextExtentPoint32W(HDC hdc,
    LPCWSTR lpString,
    int c,
    LPSIZE psizl) {
    return ::GetTextExtentPoint32W(hdc, lpString, c, psizl);
}

EXPORT BOOL WINAPI _GetTextExtentPointI(HDC hdc, LPWORD pgiIn, int cgi, LPSIZE psize) {
    return ::GetTextExtentPointI(hdc, pgiIn, cgi, psize);
}

EXPORT int WINAPI _GetTextFaceW(HDC hdc, int c, LPWSTR lpName) {
    return ::GetTextFaceW(hdc, c, lpName);
}

EXPORT BOOL WINAPI _GetTextMetricsA(HDC hdc, LPTEXTMETRICA lptm) {
    return ::GetTextMetricsA(hdc, lptm);
}

EXPORT BOOL WINAPI _GetTextMetricsW(HDC hdc, LPTEXTMETRICW lptm) {
    return ::GetTextMetricsW(hdc, lptm);
}

EXPORT BOOL WINAPI _GetViewportOrgEx(HDC hdc, LPPOINT lppoint) {
    return ::GetViewportOrgEx(hdc, lppoint);
}

EXPORT BOOL WINAPI _GetWorldTransform(HDC hdc, LPXFORM lpxf) {
    return ::GetWorldTransform(hdc, lpxf);
}

EXPORT int WINAPI _IntersectClipRect(HDC hdc, int left, int top, int right, int bottom) {
    return ::IntersectClipRect(hdc, left, top, right, bottom);
}

EXPORT BOOL WINAPI _LineTo(HDC hdc, int x, int y) {
    return ::LineTo(hdc, x, y);
}

EXPORT BOOL WINAPI _ModifyWorldTransform(HDC hdc, XFORM* lpxf, DWORD mode) {
    return ::ModifyWorldTransform(hdc, lpxf, mode);
}

EXPORT BOOL WINAPI _MoveToEx(HDC hdc, int x, int y, LPPOINT lppt) {
    return ::MoveToEx(hdc, x, y, lppt);
}

EXPORT int WINAPI _OffsetRgn(HRGN hrgn, int x, int y) {
    return ::OffsetRgn(hrgn, x, y);
}

EXPORT BOOL WINAPI _PolyBezierTo(HDC hdc, POINT* apt, DWORD cpt) {
    return ::PolyBezierTo(hdc, apt, cpt);
}

EXPORT BOOL WINAPI _RemoveFontMemResourceEx(HANDLE h) {
    return ::RemoveFontMemResourceEx(h);
}

EXPORT BOOL WINAPI _RestoreDC(HDC hdc, int nSavedDC) {
    return ::RestoreDC(hdc, nSavedDC);
}

EXPORT int WINAPI _SaveDC(HDC hdc) {
    return ::SaveDC(hdc);
}

EXPORT BOOL WINAPI _SelectClipPath(HDC hdc, int mode) {
    return ::SelectClipPath(hdc, mode);
}

EXPORT int WINAPI _SelectClipRgn(HDC hdc, HRGN hrgn) {
    return ::SelectClipRgn(hdc, hrgn);
}

EXPORT HGDIOBJ WINAPI _SelectObject(HDC hdc, HGDIOBJ h) {
    return ::SelectObject(hdc, h);
}

EXPORT COLORREF WINAPI _SetBkColor(HDC hdc, COLORREF color) {
    return ::SetBkColor(hdc, color);
}

EXPORT int WINAPI _SetBkMode(HDC hdc, int mode) {
    return ::SetBkMode(hdc, mode);
}

EXPORT BOOL WINAPI _SetBrushOrgEx(HDC hdc, int x, int y, LPPOINT lppt) {
    return ::SetBrushOrgEx(hdc, x, y, lppt);
}

EXPORT int WINAPI _SetGraphicsMode(HDC hdc, int iMode) {
    return ::SetGraphicsMode(hdc, iMode);
}

EXPORT int WINAPI _SetMapMode(HDC hdc, int iMode) {
    return ::SetMapMode(hdc, iMode);
}

EXPORT BOOL WINAPI _SetMiterLimit(HDC hdc, FLOAT limit, PFLOAT old) {
    return ::SetMiterLimit(hdc, limit, old);
}

EXPORT COLORREF WINAPI _SetPixel(HDC hdc, int x, int y, COLORREF color) {
    return ::SetPixel(hdc, x, y, color);
}

EXPORT BOOL WINAPI _SetPixelFormat(HDC hdc, int format, PIXELFORMATDESCRIPTOR* ppfd) {
    return ::SetPixelFormat(hdc, format, ppfd);
}

EXPORT int WINAPI _SetPolyFillMode(HDC hdc, int mode) {
    return ::SetPolyFillMode(hdc, mode);
}

EXPORT int WINAPI _SetStretchBltMode(HDC hdc, int mode) {
    return ::SetStretchBltMode(hdc, mode);
}

EXPORT UINT WINAPI _SetTextAlign(HDC hdc, UINT align) {
    return ::SetTextAlign(hdc, align);
}

EXPORT COLORREF WINAPI _SetTextColor(HDC hdc, COLORREF color) {
    return ::SetTextColor(hdc, color);
}

EXPORT BOOL WINAPI _SetViewportOrgEx(HDC hdc, 
    int x, 
    int y, 
    LPPOINT lppt) {
    return ::SetViewportOrgEx(hdc, x, y, lppt);
}

EXPORT BOOL WINAPI _SetWorldTransform(HDC hdc, XFORM* lpxf) {
    return ::SetWorldTransform(hdc, lpxf);
}

EXPORT int WINAPI _StartDocW(HDC hdc, DOCINFOW* lpdi) {
    return ::StartDocW(hdc, lpdi);
}

EXPORT int WINAPI _StartPage(HDC hdc) {
    return ::StartPage(hdc);
}

EXPORT BOOL WINAPI _StretchDIBits(HDC hdc, 
    int xDest, 
    int yDest, 
    int DestWidth, 
    int DestHeight, 
    int xSrc, 
    int ySrc, 
    int SrcWidth, 
    int SrcHeight,
    VOID* lpBits, 
    BITMAPINFO* lpbmi, 
    UINT iUsage, 
    DWORD rop) {
    return ::StretchDIBits(hdc, xDest, yDest, DestWidth, DestHeight, xSrc, ySrc, SrcWidth, SrcHeight, lpBits, lpbmi, iUsage, rop);
}

EXPORT BOOL WINAPI _StrokePath(HDC hc) {
    return ::StrokePath(hc);
}

EXPORT BOOL WINAPI _SwapBuffers(HDC hc) {
    return ::SwapBuffers(hc);
}

EXPORT BOOL WINAPI _UnrealizeObject(HGDIOBJ h) {
    return ::UnrealizeObject(h);
}

EXPORT BOOL WINAPI _WidenPath(HDC hdc) {
    return ::WidenPath(hdc);
}



///////

EXPORT int WINAPI _zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz_LAST(LPCSTR lpString) {
    return 0x386;
}


}

