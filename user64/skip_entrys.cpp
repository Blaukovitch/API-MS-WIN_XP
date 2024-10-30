//[80_PA] ELF, cracklab/exelab, 2023-2024
//FLAG
//214
extern "C"
{
	EXPORT BOOL WINAPI _AdjustWindowRectEx(LPRECT lpRect,
		DWORD dwStyle,
		BOOL bMenu,
		DWORD dwExStyle)
	{
		return  ::AdjustWindowRectEx(lpRect,
			dwStyle,
			bMenu,
			dwExStyle);
	}

	EXPORT HDC WINAPI _BeginPaint(HWND hWnd,
		LPPAINTSTRUCT lpPaint)
	{
		return  ::BeginPaint(hWnd, lpPaint);
	}

	EXPORT BOOL WINAPI _BringWindowToTop(HWND hWnd)
	{
		return  ::BringWindowToTop(hWnd);
	}

	EXPORT LRESULT WINAPI _CallNextHookEx(HHOOK hhk,
		int nCode,
		WPARAM wParam,
		LPARAM lParam)
	{
		return  ::CallNextHookEx(hhk,
			nCode,
			wParam,
			lParam);
	}

	EXPORT LRESULT WINAPI _CallWindowProcW(WNDPROC lpPrevWndFunc,
		HWND hWnd,
		UINT Msg,
		WPARAM wParam,
		LPARAM lParam)
	{
		return  ::CallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam);
	}

	EXPORT LPWSTR WINAPI _CharLowerW(LPWSTR lpsz)
	{
		return  ::CharLowerW(lpsz);
	}

	EXPORT LPWSTR WINAPI _CharNextW(LPCWSTR lpsz)
	{
		return  ::CharNextW(lpsz);
	}

	EXPORT BOOL WINAPI _CharToOemBuffW(LPCWSTR lpszSrc,
		LPSTR lpszDst,
		DWORD cchDstLength)
	{
		return  ::CharToOemBuffW(lpszSrc,
			lpszDst,
			cchDstLength);
	}

	EXPORT LPWSTR WINAPI _CharUpperW(LPWSTR lpsz)
	{
		return  ::CharUpperW(lpsz);
	}

	EXPORT BOOL WINAPI _ClientToScreen(HWND hWnd,
		LPPOINT lpPoint)
	{
		return  ::ClientToScreen(hWnd,
			lpPoint);
	}

	EXPORT BOOL WINAPI _ClipCursor(CONST RECT* lpRect)
	{
		return  ::ClipCursor(lpRect);
	}

	EXPORT BOOL WINAPI _CloseClipboard(VOID)
	{
		return  ::CloseClipboard();
	}

	EXPORT BOOL WINAPI _CloseDesktop(HDESK hDesktop)
	{
		return  ::CloseDesktop(hDesktop);
	}

	EXPORT BOOL WINAPI _CloseTouchInputHandle(HTOUCHINPUT hTouchInput)
	{
		return  ::CloseTouchInputHandle(hTouchInput);
	}

	EXPORT BOOL WINAPI _CloseWindowStation(HWINSTA hWinSta)
	{
		return  ::CloseWindowStation(hWinSta);
	}

	EXPORT BOOL WINAPI _CreateCaret(HWND hWnd,
		HBITMAP hBitmap,
		int nWidth,
		int nHeight)
	{
		return  ::CreateCaret(hWnd,
			hBitmap,
			nWidth,
			nHeight);
	}

	EXPORT HDESK WINAPI _CreateDesktopW(LPCWSTR lpszDesktop,
		LPCWSTR lpszDevice,
		DEVMODEW* pDevmode,
		DWORD dwFlags,
		ACCESS_MASK dwDesiredAccess,
		LPSECURITY_ATTRIBUTES lpsa)
	{
		return  ::CreateDesktopW(lpszDesktop,
			lpszDevice,
			pDevmode,
			dwFlags,
			dwDesiredAccess,
			lpsa);
	}

	EXPORT HICON WINAPI _CreateIconIndirect(PICONINFO piconinfo)
	{
		return  ::CreateIconIndirect(piconinfo);
	}

	EXPORT HMENU WINAPI _CreatePopupMenu(VOID)
	{
		return  ::CreatePopupMenu();
	}

	EXPORT HWND WINAPI _CreateWindowExW(DWORD dwExStyle,
		LPCWSTR lpClassName,
		LPCWSTR lpWindowName,
		DWORD dwStyle,
		int X,
		int Y,
		int nWidth,
		int nHeight,
		HWND hWndParent,
		HMENU hMenu,
		HINSTANCE hInstance,
		LPVOID lpParam)
	{
		return  ::CreateWindowExW(dwExStyle,
			lpClassName,
			lpWindowName,
			dwStyle,
			X,
			Y,
			nWidth,
			nHeight,
			hWndParent,
			hMenu,
			hInstance,
			lpParam);
	}

	EXPORT HWINSTA WINAPI _CreateWindowStationW(LPCWSTR lpwinsta,
		DWORD dwFlags,
		ACCESS_MASK dwDesiredAccess,
		LPSECURITY_ATTRIBUTES lpsa)
	{
		return  ::CreateWindowStationW(lpwinsta,
			dwFlags,
			dwDesiredAccess,
			lpsa);
	}

	EXPORT HDDEDATA WINAPI _DdeClientTransaction(LPBYTE pData,
		DWORD cbData,
		HCONV hConv,
		HSZ hszItem,
		UINT wFmt,
		UINT wType,
		DWORD dwTimeout,
		LPDWORD pdwResult)
	{
		return  ::DdeClientTransaction(pData,
			cbData,
			hConv,
			hszItem,
			wFmt,
			wType,
			dwTimeout,
			pdwResult);
	}

	EXPORT HCONV WINAPI _DdeConnect(DWORD idInst,
		HSZ hszService,
		HSZ hszTopic,
		PCONVCONTEXT pCC)
	{
		return  ::DdeConnect(idInst,
			hszService,
			hszTopic,
			pCC);
	}

	EXPORT HSZ WINAPI _DdeCreateStringHandleW(DWORD idInst,
		LPCWSTR psz,
		int iCodePage)
	{
		return  ::DdeCreateStringHandleW(idInst,
			psz,
			iCodePage);
	}

	EXPORT BOOL WINAPI _DdeDisconnect(HCONV hConv)
	{
		return  ::DdeDisconnect(hConv);
	}

	EXPORT BOOL WINAPI _DdeFreeStringHandle(DWORD idInst,
		HSZ hsz)
	{
		return  ::DdeFreeStringHandle(idInst, hsz);
	}

	EXPORT UINT WINAPI _DdeGetLastError(DWORD idInst)
	{
		return  ::DdeGetLastError(idInst);
	}

	EXPORT UINT WINAPI _DdeInitializeW(LPDWORD pidInst,
		PFNCALLBACK pfnCallback,
		DWORD afCmd,
		DWORD ulRes)
	{
		return  ::DdeInitializeW(pidInst,
			pfnCallback,
			afCmd,
			ulRes);
	}

	EXPORT BOOL WINAPI _DdeUninitialize(DWORD idInst)
	{
		return  ::DdeUninitialize(idInst);
	}

	EXPORT LRESULT WINAPI _DefRawInputProc(PRAWINPUT* paRawInput,
		INT nInput,
		UINT cbSizeHeader)
	{
		return  ::DefRawInputProc(paRawInput,
			nInput,
			cbSizeHeader);
	}

	EXPORT LRESULT WINAPI _DefWindowProcW(HWND hWnd,
		UINT Msg,
		WPARAM wParam,
		LPARAM lParam)
	{
		return  ::DefWindowProcW(hWnd,
			Msg,
			wParam,
			lParam);
	}

	EXPORT BOOL WINAPI _DestroyCaret(VOID)
	{
		return  ::DestroyCaret();
	}

	EXPORT BOOL WINAPI _DestroyIcon(HICON hIcon)
	{
		return  ::DestroyIcon(hIcon);
	}


	EXPORT BOOL WINAPI _DestroyMenu(HMENU hMenu)
	{
		return  ::DestroyMenu(hMenu);
	}

	EXPORT BOOL WINAPI _DestroyWindow(HWND hWnd)
	{
		return  ::DestroyWindow(hWnd);
	}

	EXPORT LRESULT WINAPI _DispatchMessageW(CONST MSG* lpMsg)
	{
		return  ::DispatchMessageW(lpMsg);
	}

	EXPORT LONG WINAPI _DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_HEADER* requestPacket)
	{
		return  ::DisplayConfigGetDeviceInfo(requestPacket);
	}

	EXPORT BOOL WINAPI _DrawEdge(HDC hdc,
		LPRECT qrc,
		UINT edge,
		UINT grfFlags)
	{
		return  ::DrawEdge(hdc,
			qrc,
			edge,
			grfFlags);
	}

	EXPORT BOOL WINAPI _DrawFocusRect(HDC hDC,
		CONST RECT* lprc)
	{
		return  ::DrawFocusRect(hDC,
			lprc);
	}

	EXPORT BOOL WINAPI _DrawFrameControl(HDC hDC,
		LPRECT lRect,
		UINT u1,
		UINT u2)
	{
		return  ::DrawFrameControl(hDC,
			lRect,
			u1,
			u2);
	}

	EXPORT BOOL WINAPI _DrawIconEx(HDC hdc,
		int xLeft,
		int yTop,
		HICON hIcon,
		int cxWidth,
		int cyWidth,
		UINT istepIfAniCur,
		HBRUSH hbrFlickerFreeDraw,
		UINT diFlags)
	{
		return  ::DrawIconEx(hdc,
			xLeft,
			yTop,
			hIcon,
			cxWidth,
			cyWidth,
			istepIfAniCur,
			hbrFlickerFreeDraw,
			diFlags);
	}

	EXPORT BOOL WINAPI _EmptyClipboard(VOID)
	{
		return  ::EmptyClipboard();
	}

	EXPORT BOOL WINAPI _EnableMenuItem(HMENU hMenu,
		UINT uIDEnableItem,
		UINT uEnable)
	{
		return  ::EnableMenuItem(hMenu,
			uIDEnableItem,
			uEnable);
	}

	EXPORT BOOL WINAPI _EnableWindow(HWND hWnd,
		BOOL bEnable)
	{
		return  ::EnableWindow(hWnd,
			bEnable);
	}

	EXPORT BOOL WINAPI _EndPaint(HWND hWnd,
		CONST PAINTSTRUCT* lpPaint)
	{
		return  ::EndPaint(hWnd, lpPaint);
	}

	EXPORT BOOL WINAPI _EnumChildWindows(HWND hWndParent,
		WNDENUMPROC lpEnumFunc,
		LPARAM lParam)
	{
		return  ::EnumChildWindows(hWndParent,
			lpEnumFunc,
			lParam);
	}

	EXPORT BOOL WINAPI _EnumDisplayDevicesW(LPCWSTR lpDevice,
		DWORD iDevNum,
		PDISPLAY_DEVICEW lpDisplayDevice,
		DWORD dwFlags)
	{
		return  ::EnumDisplayDevicesW(lpDevice,
			iDevNum,
			lpDisplayDevice,
			dwFlags);
	}

	EXPORT BOOL WINAPI _EnumDisplayMonitors(HDC hdc,
		LPCRECT lprcClip,
		MONITORENUMPROC lpfnEnum,
		LPARAM dwData)
	{
		return  ::EnumDisplayMonitors(hdc,
			lprcClip,
			lpfnEnum,
			dwData);
	}

	EXPORT BOOL WINAPI _EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,
		DWORD iModeNum,
		DEVMODEW* lpDevMode,
		DWORD dwFlags)
	{
		return  ::EnumDisplaySettingsExW(lpszDeviceName,
			iModeNum,
			lpDevMode,
			dwFlags);
	}

	EXPORT BOOL WINAPI _EnumDisplaySettingsW(LPCWSTR lpszDeviceName,
		DWORD iModeNum,
		DEVMODEW* lpDevMode)
	{
		return  ::EnumDisplaySettingsW(lpszDeviceName,
			iModeNum,
			lpDevMode);
	}

	EXPORT BOOL WINAPI _EnumWindows(WNDENUMPROC lpEnumFunc,
		LPARAM lParam)
	{
		return  ::EnumWindows(lpEnumFunc, lParam);
	}

	EXPORT BOOL WINAPI _EqualRect(CONST RECT* lprc1,
		CONST RECT* lprc2)
	{
		return  ::EqualRect(lprc1, lprc2);
	}

	EXPORT int WINAPI _FillRect(HDC hDC,
		CONST RECT* lprc,
		HBRUSH hbr)
	{
		return  ::FillRect(hDC,
			lprc,
			hbr);
	}

	EXPORT HWND WINAPI _FindWindowExW(HWND hWndParent,
		HWND hWndChildAfter,
		LPCWSTR lpszClass,
		LPCWSTR lpszWindow)
	{
		return  ::FindWindowExW(hWndParent,
			hWndChildAfter,
			lpszClass,
			lpszWindow);
	}

	EXPORT HWND WINAPI _FindWindowW(LPCWSTR lpClassName,
		LPCWSTR lpWindowName)
	{
		return  ::FindWindowW(lpClassName, lpWindowName);
	}

	EXPORT BOOL WINAPI _FlashWindowEx(PFLASHWINFO pfwi)
	{
		return  ::FlashWindowEx(pfwi);
	}

	EXPORT int WINAPI _FrameRect(HDC hDC,
		CONST RECT* lprc,
		HBRUSH hbr)
	{
		return  ::FrameRect(hDC,
			lprc,
			hbr);
	}

	EXPORT HWND WINAPI _GetActiveWindow(VOID)
	{
		return  ::GetActiveWindow();
	}

	EXPORT HWND WINAPI _GetAncestor(HWND hwnd,
		UINT gaFlags)
	{
		return  ::GetAncestor(hwnd, gaFlags);
	}

	EXPORT SHORT WINAPI _GetAsyncKeyState(int vKey)
	{
		return  ::GetAsyncKeyState(vKey);
	}

	EXPORT HWND WINAPI _GetCapture(VOID)
	{
		return  ::GetCapture();
	}

	EXPORT UINT WINAPI _GetCaretBlinkTime(VOID)
	{
		return  ::GetCaretBlinkTime();
	}

	EXPORT BOOL WINAPI _GetClassInfoExW(HINSTANCE hInstance,
		LPCWSTR lpszClass,
		LPWNDCLASSEXW lpwcx)
	{
		return  ::GetClassInfoExW(hInstance, lpszClass, lpwcx);
	}

	EXPORT ULONG_PTR WINAPI _GetClassLongPtrW(HWND hWnd,
		int nIndex)
	{
		return  ::GetClassLongPtrW(hWnd, nIndex);
	}

	EXPORT int WINAPI _GetClassNameW(HWND hWnd,
		LPWSTR lpClassName,
		int nMaxCount)
	{
		return  ::GetClassNameW(hWnd,
			lpClassName,
			nMaxCount);
	}

	EXPORT BOOL WINAPI _GetClientRect(HWND hWnd,
		LPRECT lpRect)
	{
		return  ::GetClientRect(hWnd, lpRect);
	}

	EXPORT HANDLE WINAPI _GetClipboardData(UINT uFormat)
	{
		return  ::GetClipboardData(uFormat);
	}

	EXPORT DWORD WINAPI _GetClipboardSequenceNumber(VOID)
	{
		return  ::GetClipboardSequenceNumber();
	}

	EXPORT BOOL WINAPI _GetCursorInfo(PCURSORINFO pci)
	{
		return  ::GetCursorInfo(pci);
	}

	EXPORT BOOL WINAPI _GetCursorPos(LPPOINT lpPoint)
	{
		return  ::GetCursorPos(lpPoint);
	}

	EXPORT HDC WINAPI _GetDC(HWND hWnd)
	{
		return  ::GetDC(hWnd);
	}

	EXPORT HWND WINAPI _GetDesktopWindow(VOID)
	{
		return  ::GetDesktopWindow();
	}

	EXPORT LONG WINAPI _GetDisplayConfigBufferSizes(UINT32 flags,
		UINT32* numPathArrayElements,
		UINT32* numModeInfoArrayElements)
	{
		return  ::GetDisplayConfigBufferSizes(flags,
			numPathArrayElements,
			numModeInfoArrayElements);
	}

	EXPORT UINT WINAPI _GetDoubleClickTime(VOID)
	{
		return  ::GetDoubleClickTime();
	}

	EXPORT HWND WINAPI _GetFocus(VOID)
	{
		return  ::GetFocus();
	}

	EXPORT HWND WINAPI _GetForegroundWindow(VOID)
	{
		return  ::GetForegroundWindow();
	}

	EXPORT DWORD WINAPI _GetGuiResources(HANDLE hProcess,
		DWORD uiFlags)
	{
		return  ::GetGuiResources(hProcess, uiFlags);
	}

	EXPORT BOOL WINAPI _GetIconInfo(HICON hIcon,
		PICONINFO piconinfo)
	{
		return  ::GetIconInfo(hIcon, piconinfo);
	}

	EXPORT SHORT WINAPI _GetKeyState(int nVirtKey)
	{
		return  ::GetKeyState(nVirtKey);
	}

	EXPORT HKL WINAPI _GetKeyboardLayout(DWORD idThread)
	{
		return  ::GetKeyboardLayout(idThread);
	}

	EXPORT int WINAPI _GetKeyboardLayoutList(int nBuff,
		HKL FAR* lpList)
	{
		return  ::GetKeyboardLayoutList(nBuff, lpList);
	}

	EXPORT BOOL WINAPI _GetKeyboardLayoutNameW(LPWSTR pwszKLID)
	{
		return  ::GetKeyboardLayoutNameW(pwszKLID);
	}

	EXPORT BOOL WINAPI _GetKeyboardState(PBYTE lpKeyState)
	{
		return  ::GetKeyboardState(lpKeyState);
	}

	EXPORT BOOL WINAPI _GetLastInputInfo(PLASTINPUTINFO plii)
	{
		return  ::GetLastInputInfo(plii);
	}

	EXPORT BOOL WINAPI _GetLayeredWindowAttributes(HWND hwnd,
		COLORREF* pcrKey,
		BYTE* pbAlpha,
		DWORD* pdwFlags)
	{
		return  ::GetLayeredWindowAttributes(hwnd,
			pcrKey,
			pbAlpha,
			pdwFlags);
	}

	EXPORT BOOL WINAPI _GetMenuInfo(HMENU hmenu,
		LPMENUINFO lpMenuInfo)
	{
		return  ::GetMenuInfo(hmenu, lpMenuInfo);
	}

	EXPORT int WINAPI _GetMenuItemCount(HMENU hMenu)
	{
		return  ::GetMenuItemCount(hMenu);
	}

	EXPORT BOOL WINAPI _GetMenuItemInfoW(HMENU hmenu,
		UINT item,
		BOOL fByPosition,
		LPMENUITEMINFOW lpmii)
	{
		return  ::GetMenuItemInfoW(hmenu,
			item,
			fByPosition,
			lpmii);
	}

	EXPORT LPARAM WINAPI _GetMessageExtraInfo(VOID)
	{
		return  ::GetMessageExtraInfo();
	}

	EXPORT DWORD WINAPI _GetMessagePos(VOID)
	{
		return  ::GetMessagePos();
	}

	EXPORT LONG WINAPI _GetMessageTime(VOID)
	{
		return  ::GetMessageTime();
	}

	EXPORT BOOL WINAPI _GetMonitorInfoA(HMONITOR hMonitor,
		LPMONITORINFO lpmi)
	{
		return  ::GetMonitorInfoA(hMonitor, lpmi);
	}

	EXPORT BOOL WINAPI _GetMonitorInfoW(HMONITOR hMonitor,
		LPMONITORINFO lpmi)
	{
		return  ::GetMonitorInfoW(hMonitor, lpmi);
	}

	EXPORT HWND WINAPI _GetParent(HWND hWnd)
	{
		return  ::GetParent(hWnd);
	}

	EXPORT HWINSTA WINAPI _GetProcessWindowStation(VOID)
	{
		return  ::GetProcessWindowStation();
	}

	EXPORT HANDLE WINAPI _GetPropW(HWND hWnd,
		LPCWSTR lpString)
	{
		return  ::GetPropW(hWnd, lpString);
	}

	EXPORT DWORD WINAPI _GetQueueStatus(UINT flags)
	{
		return  ::GetQueueStatus(flags);
	}

	EXPORT UINT WINAPI _GetRawInputData(HRAWINPUT hRawInput,
		UINT uiCommand,
		LPVOID pData,
		PUINT pcbSize,
		UINT cbSizeHeader)
	{
		return  ::GetRawInputData(hRawInput,
			uiCommand,
			pData,
			pcbSize,
			cbSizeHeader);
	}

	EXPORT UINT WINAPI _GetRawInputDeviceInfoW(HANDLE hDevice,
		UINT uiCommand,
		LPVOID pData,
		PUINT pcbSize)
	{
		return  ::GetRawInputDeviceInfoW(hDevice,
			uiCommand,
			pData,
			pcbSize);
	}

	EXPORT UINT WINAPI _GetRawInputDeviceList(PRAWINPUTDEVICELIST pRawInputDeviceList,
		PUINT puiNumDevices,
		UINT cbSize)
	{
		return  ::GetRawInputDeviceList(pRawInputDeviceList,
			puiNumDevices,
			cbSize);
	}

	EXPORT DWORD WINAPI _GetSysColor(int nIndex)
	{
		return  ::GetSysColor(nIndex);
	}

	EXPORT HBRUSH WINAPI _GetSysColorBrush(int nIndex)
	{
		return  ::GetSysColorBrush(nIndex);
	}

	EXPORT HMENU WINAPI _GetSystemMenu(HWND hWnd,
		BOOL bRevert)
	{
		return  ::GetSystemMenu(hWnd, bRevert);
	}

	EXPORT int WINAPI _GetSystemMetrics(int nIndex)
	{
		return  ::GetSystemMetrics(nIndex);
	}

	EXPORT HDESK WINAPI _GetThreadDesktop(DWORD dwThreadId)
	{
		return  ::GetThreadDesktop(dwThreadId);
	}

	EXPORT BOOL WINAPI _GetUserObjectInformationW(HANDLE hObj,
		int nIndex,
		PVOID pvInfo,
		DWORD nLength,
		LPDWORD lpnLengthNeeded)
	{
		return  ::GetUserObjectInformationW(hObj,
			nIndex,
			pvInfo,
			nLength,
			lpnLengthNeeded);
	}

	EXPORT HWND WINAPI _GetWindow(HWND hWnd,
		UINT uCmd)
	{
		return  ::GetWindow(hWnd, uCmd);
	}

	EXPORT HDC WINAPI _GetWindowDC(HWND hWnd)
	{
		return  ::GetWindowDC(hWnd);
	}

	EXPORT LONG_PTR WINAPI _GetWindowLongPtrW(HWND hWnd,
		int nIndex)
	{
		return  ::GetWindowLongPtrW(hWnd, nIndex);
	}

	EXPORT LONG WINAPI _GetWindowLongW(HWND hWnd,
		int nIndex)
	{
		return  ::GetWindowLongW(hWnd, nIndex);
	}

	EXPORT BOOL WINAPI _GetWindowPlacement(HWND hWnd,
		WINDOWPLACEMENT* lpwndpl)
	{
		return  ::GetWindowPlacement(hWnd,
			lpwndpl);
	}

	EXPORT BOOL WINAPI _GetWindowRect(HWND hWnd,
		LPRECT lpRec)
	{
		return  ::GetWindowRect(hWnd, lpRec);
	}

	EXPORT int WINAPI _GetWindowRgn(HWND hWnd,
		HRGN hRgn)
	{
		return  ::GetWindowRgn(hWnd, hRgn);
	}

	EXPORT int WINAPI _GetWindowTextLengthW(HWND hWnd)
	{
		return  ::GetWindowTextLengthW(hWnd);
	}

	EXPORT int WINAPI _GetWindowTextW(HWND hWnd,
		LPWSTR lpString,
		int nMaxCount)
	{
		return  ::GetWindowTextW(hWnd,
			lpString,
			nMaxCount);
	}

	EXPORT DWORD WINAPI _GetWindowThreadProcessId(HWND hWnd,
		LPDWORD lpdwProcessId)
	{
		return  ::GetWindowThreadProcessId(hWnd, lpdwProcessId);
	}

	EXPORT BOOL WINAPI _InflateRect(LPRECT lprc,
		int dx,
		int dy)
	{
		return  ::InflateRect(lprc,
			dx,
			dy);
	}

	EXPORT BOOL WINAPI _InsertMenuItemW(HMENU hmenu,
		UINT item,
		BOOL fByPosition,
		LPCMENUITEMINFOW lpmi)
	{
		return  ::InsertMenuItemW(hmenu,
			item,
			fByPosition,
			lpmi);
	}

	EXPORT BOOL WINAPI _IntersectRect(LPRECT lprcDst,
		CONST RECT* lprcSrc1,
		CONST RECT* lprcSrc2)
	{
		return  ::IntersectRect(lprcDst,
			lprcSrc1,
			lprcSrc2);
	}

	EXPORT BOOL WINAPI _InvalidateRect(HWND hWnd,
		CONST RECT* lpRect,
		BOOL bErase)
	{
		return  ::InvalidateRect(hWnd,
			lpRect,
			bErase);
	}

	EXPORT BOOL WINAPI _InvertRect(HDC hDC,
		CONST RECT* lprc)
	{
		return  ::InvertRect(hDC,
			lprc);
	}

	EXPORT BOOL WINAPI _IsChild(HWND hWndParent,
		HWND hWnd)
	{
		return  ::IsChild(hWndParent, hWnd);
	}

	EXPORT BOOL WINAPI _IsClipboardFormatAvailable(UINT format)
	{
		return  ::IsClipboardFormatAvailable(format);
	}

	EXPORT BOOL WINAPI _IsIconic(HWND hWnd)
	{
		return  ::IsIconic(hWnd);
	}

	EXPORT BOOL WINAPI _IsRectEmpty(CONST RECT* lprc)
	{
		return  ::IsRectEmpty(lprc);
	}

	EXPORT BOOL WINAPI _IsWindow(HWND hWnd)
	{
		return  ::IsWindow(hWnd);
	}

	EXPORT BOOL WINAPI _IsWindowEnabled(HWND hWnd)
	{
		return  ::IsWindowEnabled(hWnd);
	}

	EXPORT BOOL WINAPI _IsWindowVisible(HWND hWnd)
	{
		return  ::IsWindowVisible(hWnd);
	}

	EXPORT BOOL WINAPI _IsZoomed(HWND hWnd)
	{
		return  ::IsZoomed(hWnd);
	}

	EXPORT BOOL WINAPI _KillTimer(HWND hWnd,
		UINT_PTR uIDEvent)
	{
		return  ::KillTimer(hWnd, uIDEvent);
	}

	EXPORT HCURSOR WINAPI _LoadCursorW(HINSTANCE hInstance,
		LPCWSTR lpCursorName)
	{
		return  ::LoadCursorW(hInstance,
			lpCursorName);
	}

	EXPORT HICON WINAPI _LoadIconW(HINSTANCE hInstance,
		LPCWSTR lpIconName)
	{
		return  ::LoadIconW(hInstance, lpIconName);
	}

	EXPORT HANDLE WINAPI _LoadImageW(HINSTANCE hInst,
		LPCWSTR name,
		UINT type,
		int cx,
		int cy,
		UINT fuLoad)
	{
		return  ::LoadImageW(hInst,
			name,
			type,
			cx,
			cy,
			fuLoad);
	}

	EXPORT int WINAPI _LoadStringW(HINSTANCE hInstance,
		UINT uID,
		LPWSTR lpBuffer,
		int cchBufferMax)
	{
		return  ::LoadStringW(hInstance,
			uID,
			lpBuffer,
			cchBufferMax);
	}

	EXPORT UINT WINAPI _MapVirtualKeyExW(UINT uCode,
		UINT uMapType,
		HKL dwhkl)
	{
		return  ::MapVirtualKeyExW(uCode,
			uMapType,
			dwhkl);
	}

	EXPORT UINT WINAPI _MapVirtualKeyW(UINT uCode,
		UINT uMapType)
	{
		return  ::MapVirtualKeyW(uCode, uMapType);
	}

	EXPORT int WINAPI _MapWindowPoints(HWND hWndFrom,
		HWND hWndTo,
		LPPOINT lpPoints,
		UINT cPoints)
	{
		return  ::MapWindowPoints(hWndFrom,
			hWndTo,
			lpPoints,
			cPoints);
	}

	EXPORT BOOL WINAPI _MessageBeep(UINT uType)
	{
		return  ::MessageBeep(uType);
	}

	EXPORT int WINAPI _MessageBoxW(HWND hWnd,
		LPCWSTR lpText,
		LPCWSTR lpCaption,
		UINT uType)
	{
		return  ::MessageBoxW(hWnd,
			lpText,
			lpCaption,
			uType);
	}

	EXPORT HMONITOR WINAPI _MonitorFromPoint(POINT pt,
		DWORD dwFlags)
	{
		return  ::MonitorFromPoint(pt, dwFlags);
	}

	EXPORT HMONITOR WINAPI _MonitorFromRect(LPCRECT lprc,
		DWORD dwFlags)
	{
		return  ::MonitorFromRect(lprc, dwFlags);
	}

	EXPORT HMONITOR WINAPI _MonitorFromWindow(HWND hwnd,
		DWORD dwFlags)
	{
		return  ::MonitorFromWindow(hwnd, dwFlags);
	}

	EXPORT BOOL WINAPI _MoveWindow(HWND hWnd,
		int X,
		int Y,
		int nWidth,
		int nHeight,
		BOOL bRepaint)
	{
		return  ::MoveWindow(hWnd,
			X,
			Y,
			nWidth,
			nHeight,
			bRepaint);
	}

	EXPORT DWORD WINAPI _MsgWaitForMultipleObjectsEx(DWORD nCount,
		CONST HANDLE* pHandles,
		DWORD dwMilliseconds,
		DWORD dwWakeMask,
		DWORD dwFlags)
	{
		return  ::MsgWaitForMultipleObjectsEx(nCount,
			pHandles,
			dwMilliseconds,
			dwWakeMask,
			dwFlags);
	}

	EXPORT void WINAPI _NotifyWinEvent(DWORD event,
		HWND  hwnd,
		LONG  idObject,
		LONG  idChild)
	{
		return  ::NotifyWinEvent(event,
			hwnd,
			idObject,
			idChild);
	}

	EXPORT BOOL WINAPI _OemToCharA(LPCSTR pSrc,
		LPSTR pDst)
	{
		return  ::OemToCharA(pSrc, pDst);
	}

	EXPORT BOOL WINAPI _OemToCharBuffA(LPCSTR lpszSrc,
		LPSTR lpszDst,
		DWORD cchDstLength)
	{
		return  ::OemToCharBuffA(lpszSrc,
			lpszDst,
			cchDstLength);
	}

	EXPORT BOOL WINAPI _OffsetRect(LPRECT lprc,
		int dx,
		int dy)
	{
		return  ::OffsetRect(lprc,
			dx,
			dy);
	}

	EXPORT BOOL WINAPI _OpenClipboard(HWND hWndNewOwner)
	{
		return  ::OpenClipboard(hWndNewOwner);
	}

	EXPORT HDESK WINAPI _OpenInputDesktop(DWORD dwFlags,
		BOOL fInherit,
		ACCESS_MASK dwDesiredAccess)
	{
		return  ::OpenInputDesktop(dwFlags,
			fInherit,
			dwDesiredAccess);
	}

	EXPORT BOOL WINAPI _PeekMessageW(LPMSG lpMsg,
		HWND hWnd,
		UINT wMsgFilterMin,
		UINT wMsgFilterMax,
		UINT wRemoveMsg)
	{
		return  ::PeekMessageW(lpMsg,
			hWnd,
			wMsgFilterMin,
			wMsgFilterMax,
			wRemoveMsg);
	}

	EXPORT BOOL WINAPI _PostMessageW(HWND hWnd,
		UINT Msg,
		WPARAM wParam,
		LPARAM lParam)
	{
		return  ::PostMessageW(hWnd,
			Msg,
			wParam,
			lParam);
	}

	EXPORT void WINAPI _PostQuitMessage(int nExitCode)
	{
		return  ::PostQuitMessage(nExitCode);
	}

	EXPORT BOOL WINAPI _PostThreadMessageW(DWORD idThread,
		UINT Msg,
		WPARAM wParam,
		LPARAM lParam)
	{
		return  ::PostThreadMessageW(idThread,
			Msg,
			wParam,
			lParam);
	}

	EXPORT BOOL WINAPI _PrintWindow(HWND hwnd,
		HDC hdcBlt,
		UINT nFlags)
	{
		return  ::PrintWindow(hwnd,
			hdcBlt,
			nFlags);
	}

	EXPORT BOOL WINAPI _PtInRect(RECT* lprc,
		POINT pt)
	{
		return  ::PtInRect(lprc, pt);
	}

	EXPORT LONG WINAPI _QueryDisplayConfig(UINT32 flags,
		UINT32* numPathArrayElements,
		DISPLAYCONFIG_PATH_INFO* pathArray,
		UINT32* numModeInfoArrayElements,
		DISPLAYCONFIG_MODE_INFO* modeInfoArray,
		DISPLAYCONFIG_TOPOLOGY_ID* currentTopologyId)
	{
		return  ::QueryDisplayConfig(flags,
			numPathArrayElements,
			pathArray,
			numModeInfoArrayElements,
			modeInfoArray,
			currentTopologyId);
	}

	EXPORT BOOL WINAPI _RedrawWindow(HWND hWnd,
		CONST RECT* lprcUpdate,
		HRGN hrgnUpdate,
		UINT flags)
	{
		return  ::RedrawWindow(hWnd,
			lprcUpdate,
			hrgnUpdate,
			flags);
	}

	EXPORT ATOM WINAPI _RegisterClassExW(CONST WNDCLASSEXW* pWndClassEx)
	{
		return  ::RegisterClassExW(pWndClassEx);
	}

	EXPORT UINT WINAPI _RegisterClipboardFormatW(LPCWSTR lpszFormat)
	{
		return  ::RegisterClipboardFormatW(lpszFormat);
	}

	EXPORT HDEVNOTIFY WINAPI _RegisterDeviceNotificationW(HANDLE hRecipient,
		LPVOID NotificationFilter,
		DWORD Flag)
	{
		return  ::RegisterDeviceNotificationW(hRecipient,
			NotificationFilter,
			Flag);
	}

	EXPORT BOOL WINAPI _RegisterHotKey(HWND hWnd,
		int id,
		UINT fsModifiers,
		UINT vk)
	{
		return  ::RegisterHotKey(hWnd,
			id,
			fsModifiers,
			vk);
	}

	EXPORT HPOWERNOTIFY WINAPI _RegisterPowerSettingNotification(HANDLE hRecipient,
		LPCGUID PowerSettingGuid,
		DWORD Flags)
	{
		return  ::RegisterPowerSettingNotification(hRecipient,
			PowerSettingGuid,
			Flags);
	}

	EXPORT BOOL WINAPI _RegisterRawInputDevices(PCRAWINPUTDEVICE pRawInputDevices,
		UINT uiNumDevices,
		UINT cbSize)
	{
		return  ::RegisterRawInputDevices(pRawInputDevices,
			uiNumDevices,
			cbSize);
	}

	EXPORT BOOL WINAPI _RegisterTouchWindow(HWND hwnd,
		ULONG ulFlags)
	{
		return  ::RegisterTouchWindow(hwnd,
			ulFlags);
	}

	EXPORT UINT WINAPI _RegisterWindowMessageW(LPCWSTR lpString)
	{
		return  ::RegisterWindowMessageW(lpString);
	}

	EXPORT BOOL WINAPI _ReleaseCapture(VOID)
	{
		return  ::ReleaseCapture();
	}

	EXPORT int WINAPI _ReleaseDC(HWND hWnd,
		HDC hDC)
	{
		return  ::ReleaseDC(hWnd, hDC);
	}

	EXPORT HANDLE WINAPI _RemovePropW(HWND hWnd,
		LPCWSTR lpString)
	{
		return  ::RemovePropW(hWnd, lpString);
	}

	EXPORT BOOL WINAPI _ScreenToClient(HWND hWnd,
		LPPOINT lpPoint)
	{
		return  ::ScreenToClient(hWnd, lpPoint);
	}

	EXPORT UINT WINAPI _SendInput(UINT cInputs,                     // number of input in the array
		LPINPUT pInputs,  // array of inputs
		int cbSize)
	{
		return  ::SendInput(cInputs, pInputs, cbSize);
	}

	EXPORT LRESULT WINAPI _SendMessageTimeoutW(HWND hWnd,
		UINT Msg,
		WPARAM wParam,
		LPARAM lParam,
		UINT fuFlags,
		UINT uTimeout,
		PDWORD_PTR lpdwResult)
	{
		return  ::SendMessageTimeoutW(hWnd,
			Msg,
			wParam,
			lParam,
			fuFlags,
			uTimeout,
			lpdwResult);
	}

	EXPORT LRESULT WINAPI _SendMessageW(HWND hWnd,
		UINT Msg,
		WPARAM wParam,
		LPARAM lParam)
	{
		return  ::SendMessageW(hWnd,
			Msg,
			wParam,
			lParam);
	}

	EXPORT HWND WINAPI _SetCapture(HWND hWnd)
	{
		return  ::SetCapture(hWnd);
	}

	EXPORT BOOL WINAPI _SetCaretPos(int X,
		int Y)
	{
		return  ::SetCaretPos(X, Y);
	}

	EXPORT HANDLE WINAPI _SetClipboardData(UINT uFormat,
		HANDLE hMem)
	{
		return  ::SetClipboardData(uFormat, hMem);
	}

	EXPORT HCURSOR WINAPI _SetCursor(HCURSOR hCursor)
	{
		return  ::SetCursor(hCursor);
	}

	EXPORT BOOL WINAPI _SetCursorPos(int X,
		int Y)
	{
		return  ::SetCursorPos(X, Y);
	}

	EXPORT HWND WINAPI _SetFocus(HWND hWnd)
	{
		return  ::SetFocus(hWnd);
	}

	EXPORT BOOL WINAPI _SetForegroundWindow(HWND hWnd)
	{
		return  ::SetForegroundWindow(hWnd);
	}

	EXPORT BOOL WINAPI _SetKeyboardState(LPBYTE lpKeyState)
	{
		return  ::SetKeyboardState(lpKeyState);
	}

	EXPORT BOOL WINAPI _SetMenuDefaultItem(HMENU hMenu,
		UINT uItem,
		UINT fByPos)
	{
		return  ::SetMenuDefaultItem(hMenu, uItem, fByPos);
	}

	EXPORT BOOL WINAPI _SetMenuInfo(HMENU hMenu,
		LPCMENUINFO lMenuInfo)
	{
		return  ::SetMenuInfo(hMenu, lMenuInfo);
	}

	EXPORT BOOL WINAPI _SetMenuItemInfoW(HMENU hmenu,
		UINT item,
		BOOL fByPositon,
		LPCMENUITEMINFOW lpmii)
	{
		return  ::SetMenuItemInfoW(hmenu,
			item,
			fByPositon,
			lpmii);
	}

	EXPORT HWND WINAPI _SetParent(HWND hWndChild,
		HWND hWndNewParent)
	{
		return  ::SetParent(hWndChild, hWndNewParent);
	}

	EXPORT BOOL WINAPI _SetProcessDPIAware(VOID)
	{
		return  ::SetProcessDPIAware();
	}

	EXPORT BOOL WINAPI _SetProcessWindowStation(HWINSTA hWinSta)
	{
		return  ::SetProcessWindowStation(hWinSta);
	}

	EXPORT BOOL WINAPI _SetPropW(HWND hWnd,
		LPCWSTR lpString,
		HANDLE hData)
	{
		return  ::SetPropW(hWnd,
			lpString,
			hData);
	}

	EXPORT BOOL WINAPI _SetRect(LPRECT lprc,
		int xLeft,
		int yTop,
		int xRight,
		int yBottom)
	{
		return  ::SetRect(lprc,
			xLeft,
			yTop,
			xRight,
			yBottom);
	}

	EXPORT BOOL WINAPI _SetThreadDesktop(HDESK hDesktop)
	{
		return  ::SetThreadDesktop(hDesktop);
	}

	EXPORT UINT_PTR WINAPI _SetTimer(HWND hWnd,
		UINT_PTR nIDEvent,
		UINT uElapse,
		TIMERPROC lpTimerFunc)
	{
		return  ::SetTimer(hWnd,
			nIDEvent,
			uElapse,
			lpTimerFunc);
	}

	EXPORT HWINEVENTHOOK WINAPI _SetWinEventHook(DWORD eventMin,
		DWORD eventMax,
		HMODULE hmodWinEventProc,
		WINEVENTPROC pfnWinEventProc,
		DWORD idProcess,
		DWORD idThread,
		DWORD dwFlags)
	{
		return  ::SetWinEventHook(eventMin,
			eventMax,
			hmodWinEventProc,
			pfnWinEventProc,
			idProcess,
			idThread,
			dwFlags);
	}

	EXPORT LONG_PTR WINAPI _SetWindowLongPtrW(HWND hWnd,
		int nIndex,
		LONG_PTR dwNewLong)
	{
		return  ::SetWindowLongPtrW(hWnd,
			nIndex,
			dwNewLong);
	}

	EXPORT LONG WINAPI _SetWindowLongW(HWND hWnd,
		int nIndex,
		LONG dwNewLong)
	{
		return  ::SetWindowLongW(hWnd,
			nIndex,
			dwNewLong);
	}

	EXPORT BOOL WINAPI _SetWindowPlacement(HWND hWnd,
		CONST WINDOWPLACEMENT* lpwndpl)
	{
		return  ::SetWindowPlacement(hWnd, lpwndpl);
	}

	EXPORT BOOL WINAPI _SetWindowPos(HWND hWnd,
		HWND hWndInsertAfter,
		int X,
		int Y,
		int cx,
		int cy,
		UINT uFlags)
	{
		return  ::SetWindowPos(hWnd,
			hWndInsertAfter,
			X,
			Y,
			cx,
			cy,
			uFlags);
	}

	EXPORT int WINAPI _SetWindowRgn(HWND hWnd,
		HRGN hRgn,
		BOOL bRedraw)
	{
		return  ::SetWindowRgn(hWnd,
			hRgn,
			bRedraw);
	}

	EXPORT BOOL WINAPI _SetWindowTextW(HWND hWnd,
		LPCWSTR lpString)
	{
		return  ::SetWindowTextW(hWnd, lpString);
	}

	EXPORT HHOOK WINAPI _SetWindowsHookExW(int idHook,
		HOOKPROC lpfn,
		HINSTANCE hmod,
		DWORD dwThreadId)
	{
		return  ::SetWindowsHookExW(idHook,
			lpfn,
			hmod,
			dwThreadId);
	}

	EXPORT int WINAPI _ShowCursor(BOOL bShow)
	{
		return  ::ShowCursor(bShow);
	}

	EXPORT BOOL WINAPI _ShowWindow(HWND hWnd,
		int nCmdShow)
	{
		return  ::ShowWindow(hWnd, nCmdShow);
	}

	EXPORT BOOL WINAPI _SystemParametersInfoW(UINT uiAction,
		UINT uiParam,
		PVOID pvParam,
		UINT fWinIni)
	{
		return  ::SystemParametersInfoW(uiAction,
			uiParam,
			pvParam,
			fWinIni);
	}

	EXPORT int WINAPI _ToUnicodeEx(UINT wVirtKey,
		UINT wScanCode,
		CONST BYTE* lpKeyState,
		LPWSTR pwszBuff,
		int cchBuff,
		UINT wFlags,
		HKL dwhkl)
	{
		return  ::ToUnicodeEx(wVirtKey,
			wScanCode,
			lpKeyState,
			pwszBuff,
			cchBuff,
			wFlags,
			dwhkl);
	}

	EXPORT BOOL WINAPI _TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack)
	{
		return  ::TrackMouseEvent(lpEventTrack);
	}

	EXPORT BOOL WINAPI _TrackPopupMenu(HMENU hMenu,
		UINT uFlags,
		int x,
		int y,
		int nReserved,
		HWND hWnd,
		CONST RECT* prcRect)
	{
		return  ::TrackPopupMenu(hMenu,
			uFlags,
			x,
			y,
			nReserved,
			 hWnd,
			prcRect);
	}

	EXPORT BOOL WINAPI _TranslateMessage(CONST MSG* lpMsg)
	{
		return  ::TranslateMessage(lpMsg);
	}

	EXPORT BOOL WINAPI _UnhookWinEvent(HWINEVENTHOOK hWinEventHook)
	{
		return  ::UnhookWinEvent(hWinEventHook);
	}

	EXPORT BOOL WINAPI _UnhookWindowsHookEx(HHOOK hhk)
	{
		return  ::UnhookWindowsHookEx(hhk);
	}

	EXPORT BOOL WINAPI _UnregisterClassW(LPCWSTR lpClassName,
		HINSTANCE hInstance)
	{
		return  ::UnregisterClassW(lpClassName, hInstance);
	}

	EXPORT BOOL WINAPI _UnregisterDeviceNotification(HDEVNOTIFY Handle)
	{
		return  ::UnregisterDeviceNotification(Handle);
	}

	EXPORT BOOL WINAPI _UnregisterHotKey(HWND hWnd,
		int id)
	{
		return  ::UnregisterHotKey(hWnd, id);
	}

	EXPORT BOOL WINAPI _UnregisterPowerSettingNotification(HWND hWnd)
	{
		return  ::UnregisterPowerSettingNotification(hWnd);
	}

	EXPORT BOOL WINAPI _UpdateLayeredWindow(HWND hWnd,
		HDC hdcDst,
		POINT* pptDst,
		SIZE* psize,
		HDC hdcSrc,
		POINT* pptSrc,
		COLORREF crKey,
		BLENDFUNCTION* pblend,
		DWORD dwFlags)
	{
		return  ::UpdateLayeredWindow(hWnd,
			hdcDst,
			pptDst,
			psize,
			hdcSrc,
			pptSrc,
			crKey,
			pblend,
			dwFlags);
	}

	EXPORT HWND WINAPI _WindowFromPoint(POINT Point)
	{
		return  ::WindowFromPoint(Point);
	}

	//117
	EXPORT BOOL WINAPI _AllowSetForegroundWindow(DWORD dwProcessId)
	{
		return  ::AllowSetForegroundWindow(dwProcessId);
	}

	EXPORT BOOL WINAPI _EnumThreadWindows(DWORD dwThreadId,
		WNDENUMPROC lpfn,
		LPARAM lParam)
	{
		return  ::EnumThreadWindows(dwThreadId,
			lpfn,
			lParam);
	}

	EXPORT DWORD WINAPI _GetClassLongW(HWND hWnd,
		int nIndex)
	{
		return  ::GetClassLongW(hWnd,
			nIndex);
	}

	//electron mail

	/*
Минимальная версия клиента 	Windows 7 [только классические приложения]
Минимальная версия сервера 	Windows Server 2008 R2 [только классические приложения]
Целевая платформа 	Windows
Header 	winuser.h (включая Windows.h)
Библиотека 	User32.lib
DLL 	User32.dll
Набор API 	ext-ms-win-ntuser-gui-l1-3-0 (появилась в Windows 10 версии 10.0.10240)
	*/
	EXPORT DWORD WINAPI _ChangeWindowMessageFilterEx(HWND hwnd,                                         // Window
		UINT message,                                      // WM_ message
		DWORD action,                                      // Message filter action value
		PCHANGEFILTERSTRUCT pChangeFilterStruct)
	{
		return  ::ChangeWindowMessageFilterEx(hwnd,                                         // Window
			message,                                      // WM_ message
			action,                                      // Message filter action value
			pChangeFilterStruct);
	}

	//original skip
	EXPORT LPSTR WINAPI _CharUpperA(PSTR lpsz)
	{
		return  ::CharUpperA(lpsz);
	}

	EXPORT HICON WINAPI _CopyIcon(HICON hIcon)
	{
		return  ::CopyIcon(hIcon);
	}

	EXPORT BOOL WINAPI _GetMessageW(LPMSG lpMsg,
		HWND hWnd,
		UINT wMsgFilterMin,
		UINT wMsgFilterMax)
	{
		return  ::GetMessageW(lpMsg,
			hWnd,
			wMsgFilterMin,
			wMsgFilterMax);
	}

	EXPORT ATOM WINAPI _RegisterClassW(CONST WNDCLASSW* lpWndClass)
	{
		return  ::RegisterClassW(lpWndClass);
	}

	EXPORT DWORD WINAPI _SetClassLongPtrW(HWND hWnd,
		int nIndex,
		LONG dwNewLong)
	{
		return  ::SetClassLongPtrW(hWnd,
			nIndex,
			dwNewLong);
	}

	EXPORT BOOL WINAPI _SetLayeredWindowAttributes(HWND hwnd,
		COLORREF crKey,
		BYTE bAlpha,
		DWORD dwFlags)
	{
		return  ::SetLayeredWindowAttributes(hwnd,
			crKey,
			bAlpha,
			dwFlags);
	}

	EXPORT BOOL WINAPI _SetRectEmpty(LPRECT lprc)
	{
		return  ::SetRectEmpty(lprc);
	}

	EXPORT BOOL WINAPI _SetWindowDisplayAffinity(HWND hWnd,
		DWORD dwAffinity)
	{
		return  ::SetWindowDisplayAffinity(hWnd,
			dwAffinity);
	}

	EXPORT BOOL WINAPI _SendNotifyMessageW(HWND hWnd,
		UINT Msg,
		WPARAM wParam,
		LPARAM lParam)
	{
		return  ::SendNotifyMessageW(hWnd,
			Msg,
			wParam,
			lParam);
	}

	EXPORT DWORD WINAPI _WaitForInputIdle(HANDLE hProcess,
		DWORD dwMilliseconds)
	{
		return  ::WaitForInputIdle(hProcess,
			dwMilliseconds);
	}

	EXPORT DWORD WINAPI _wsprintfW(LPWSTR a1,
		LPCWSTR a2,
		...)
	{
		return  ::wsprintfW(a1, a2);
	}

	//opera_browser.dll
	EXPORT BOOL WINAPI _AddClipboardFormatListener(HWND hwnd)
	{
		return  ::AddClipboardFormatListener(hwnd);
	}

	EXPORT HANDLE WINAPI _CopyImage(HANDLE h,
		UINT type,
		int cx,
		int cy,
		UINT flags)
	{
		return  ::CopyImage(h,
			type,
			cx,
			cy,
			flags);
	}

	EXPORT BOOL WINAPI _DestroyCursor(HCURSOR hCursor)
	{
		return  ::DestroyCursor(hCursor);
	}

	EXPORT HWND WINAPI _FindWindowA(LPCSTR lpClassName,
		LPCSTR lpWindowName)
	{
		return  ::FindWindowA(lpClassName, lpWindowName);
	}

	EXPORT int WINAPI _MessageBoxA(HWND hWnd,
		LPCSTR lpText,
		LPCSTR lpCaption,
		UINT uType)
	{
		return  ::MessageBoxA(hWnd,
			lpText,
			lpCaption,
			uType);
	}

	EXPORT HWINSTA WINAPI _OpenWindowStationA(LPCSTR lpszWinSta,
		BOOL fInherit,
		ACCESS_MASK dwDesiredAccess)
	{
		return  ::OpenWindowStationA(lpszWinSta,
			fInherit,
			dwDesiredAccess);
	}

	EXPORT BOOL WINAPI _RemoveClipboardFormatListener(HWND hwnd)
	{
		return  ::RemoveClipboardFormatListener(hwnd);
	}

	EXPORT SHORT WINAPI _VkKeyScanExW(WCHAR ch,
		HKL dwhkl)
	{
		return  ::VkKeyScanExW(ch, dwhkl);
	}

	//spotify
	EXPORT HMENU WINAPI _GetMenu(HWND hWnd)
	{
		return  ::GetMenu(hWnd);
	}

	EXPORT HWND WINAPI _GetTopWindow(HWND hWnd)
	{
		return  ::GetTopWindow(hWnd);
	}

	//EDGE 120
	EXPORT BOOL WINAPI _AttachThreadInput(DWORD idAttach,
		DWORD idAttachTo,
		BOOL fAttach)
	{
		return  ::AttachThreadInput(idAttach,
			idAttachTo,
			fAttach);
	}

	EXPORT HWND WINAPI _ChildWindowFromPointEx(HWND hwnd,
		POINT pt,
		UINT flags)
	{
		return  ::ChildWindowFromPointEx(hwnd,
			pt,
			flags);
	}
	
	EXPORT BOOL WINAPI _DdeAbandonTransaction(DWORD idInst,
		HCONV hConv,
		DWORD idTransaction)
	{
		return  ::DdeAbandonTransaction(idInst,
			hConv,
			idTransaction);
	}
		
	EXPORT BOOL WINAPI _DeregisterShellHookWindow(HWND hwnd)
	{
		return  ::DeregisterShellHookWindow(hwnd);
	}
		
		
	EXPORT BOOL WINAPI _GetGUIThreadInfo(DWORD idThread,
		PGUITHREADINFO pgui)
	{
		return  ::GetGUIThreadInfo(idThread, pgui);
	}
		
	EXPORT HWND WINAPI _GetShellWindow(void)
	{
		return  ::GetShellWindow();
	}
		
	EXPORT BOOL WINAPI _GetWindowDisplayAffinity(HWND hWnd,
		DWORD* pdwAffinity)
	{
		return  ::GetWindowDisplayAffinity(hWnd,
			pdwAffinity);
	}
		
	EXPORT DWORD WINAPI _InSendMessageEx(LPVOID lpReserved)
	{
		return  ::InSendMessageEx(lpReserved);
	}
	

	EXPORT BOOL WINAPI _InsertMenuW(HMENU hMenu,
		UINT uPosition,
		UINT uFlags,
		UINT_PTR uIDNewItem,
		LPCWSTR lpNewItem)
	{
		return  ::InsertMenuW(hMenu,
			uPosition,
			uFlags,
			uIDNewItem,
			lpNewItem);
	}
	
	EXPORT BOOL WINAPI _IsHungAppWindow(HWND hwnd)
	{
		return  ::IsHungAppWindow(hwnd);
	}
	

		
	EXPORT UINT WINAPI _PrivateExtractIconsW(LPCWSTR szFileName,
		int nIconIndex,
		int cxIcon,
		int cyIcon,
		HICON* phicon,
		UINT* piconid,
		UINT nIcons,
		UINT flags)
	{
		return  ::PrivateExtractIconsW(szFileName,
			nIconIndex,
			cxIcon,
			cyIcon,
			phicon,
			piconid,
			nIcons,
			flags);
	}

	EXPORT UINT WINAPI _RegisterShellHookWindow(HWND hwnd)
	{
		return  ::RegisterShellHookWindow(hwnd);
	}
		
	EXPORT BOOL WINAPI _RemoveMenu(HMENU hMenu,
		UINT uPosition,
		UINT uFlags)
	{
		return  ::RemoveMenu(hMenu,
			uPosition,
			uFlags);
	}

	EXPORT HWND WINAPI _SetActiveWindow(HWND hWnd)
	{
		return  ::SetActiveWindow(hWnd);
	}
		
	EXPORT BOOL WINAPI _UpdateWindow(HWND hWnd)
	{
		return  ::UpdateWindow(hWnd);
	}

	EXPORT HWND WINAPI _GetLastActivePopup(HWND hWnd)
	{
		return  ::GetLastActivePopup(hWnd);
	}
	
		
	//EDGE 120.0.2210.77

	EXPORT HWND WINAPI _FindWindowExA(HWND hWndParent,
		HWND hWndChildAfter,
		LPCSTR lpszClass,
		LPCSTR lpszWindow)
	{
		return  ::FindWindowExA(hWndParent, hWndChildAfter, lpszClass, lpszWindow);
	}

	EXPORT HWND WINAPI _GetNextDlgTabItem(HWND hDlg,
		HWND hCtl,
		BOOL bPrevious)
	{
		return  ::GetNextDlgTabItem(hDlg, hCtl, bPrevious);
	}

	EXPORT DWORD WINAPI _SetClassLongW(HWND hWnd,
		int nIndex,
		LONG dwNewLong)
	{
		return  ::SetClassLongW(hWnd, nIndex, dwNewLong);
	}

	EXPORT DWORD WINAPI _GetWindowRgnBox(HWND hWnd,
		LPRECT lprc)
	{
		return  ::GetWindowRgnBox(hWnd, lprc);
	}
	
	//VIVALDI
	EXPORT HWND WINAPI _CreateDialogParamW(HINSTANCE hInstance,
		LPCWSTR lpTemplateName,
		HWND hWndParent,
		DLGPROC lpDialogFunc,
		LPARAM dwInitParam)
	{
		return  ::CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam);
	}

	EXPORT HWND WINAPI _GetDlgItem(HWND hDlg,
		int nIDDlgItem)
	{
		return  ::GetDlgItem(hDlg, nIDDlgItem);
	}
	
	EXPORT BOOL WINAPI _IsDialogMessageW(HWND hDlg,
		LPMSG lpMsg)
	{
		return  ::IsDialogMessageW(hDlg, lpMsg);
	}

	EXPORT BOOL WINAPI _WaitMessage()
	{
		return  ::WaitMessage();
	}


	EXPORT BOOL WINAPI _FlashWindow(HWND hWnd,
		BOOL bInvert)
	{
		return  ::FlashWindow(hWnd, bInvert);
	}

	EXPORT BOOL WINAPI _GetRawInputDeviceInfoA(HANDLE hDevice,
		UINT uiCommand,
		PVOID pData,
		PUINT pcbSize)
	{
		return  ::GetRawInputDeviceInfoA(hDevice, uiCommand, pData, pcbSize);
	}

	EXPORT BOOL WINAPI _ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,
		DEVMODEW* lpDevMode,
		HWND hwnd,
		DWORD dwflags,
		LPVOID lParam)
	{
		return  ::ChangeDisplaySettingsExW(lpszDeviceName, lpDevMode, hwnd, dwflags, lParam);
	}

	EXPORT BOOL WINAPI _ToUnicode(UINT wVirtKey,
		UINT wScanCode,
		CONST BYTE* lpKeyState,
		LPWSTR pwszBuff,
		int cchBuff,
		UINT wFlags)
	{
		return  ::ToUnicode(wVirtKey, wScanCode, lpKeyState, pwszBuff, cchBuff, wFlags);
	}

	EXPORT BOOL WINAPI _MsgWaitForMultipleObjects(DWORD nCount,
		CONST HANDLE* pHandles,
		BOOL fWaitAll,
		DWORD dwMilliseconds,
		DWORD dwWakeMask)
	{
		return  ::MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask);
	}

	//FFOX 131.0
	EXPORT HKL WINAPI _ActivateKeyboardLayout(HKL hkl,
		UINT Flags)
	{
		return ::ActivateKeyboardLayout(hkl, Flags);
	}

	EXPORT BOOL WINAPI _AnimateWindow(HWND hWnd,
		DWORD dwTime,
		DWORD dwFlags)
	{
		return ::AnimateWindow(hWnd, dwTime, dwFlags);
	}

	EXPORT long WINAPI _BroadcastSystemMessageW(DWORD flags,
		LPDWORD lpInfo,
		UINT Msg,
		WPARAM wParam,
		LPARAM lParam)
	{
		return ::BroadcastSystemMessageW(flags, lpInfo, Msg, wParam, lParam);
	}

	EXPORT BOOL WINAPI _CloseGestureInfoHandle(HGESTUREINFO hGestureInfo)
	{
		return ::CloseGestureInfoHandle(hGestureInfo);
	}

	EXPORT BOOL WINAPI _GetClassInfoW(HINSTANCE hInstance,
		LPCWSTR lpClassName,
		LPWNDCLASSW lpWndClass)
	{
		return ::GetClassInfoW(hInstance, lpClassName, lpWndClass);
	}

	EXPORT BOOL WINAPI _GetClassWord(HWND hWnd,
		int nIndex)
	{
		return ::GetClassWord(hWnd, nIndex);
	}

	EXPORT int WINAPI _GetClipboardFormatNameW(UINT format,
		LPWSTR lpszFormatName,
		int cchMaxCount)
	{
		return ::GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount);
	}

	EXPORT int WINAPI _GetGestureInfo(HGESTUREINFO hGestureInfo,
		PGESTUREINFO pGestureInfo)
	{
		return ::GetGestureInfo(hGestureInfo, pGestureInfo);
	}

	EXPORT BOOL WINAPI _GetKeyboardLayoutNameA(LPSTR pwszKLID)
	{
		return ::GetKeyboardLayoutNameA(pwszKLID);
	}

	EXPORT BOOL WINAPI _GetTouchInputInfo(HTOUCHINPUT hTouchInput,               // input event handle; from touch message lParam
		UINT cInputs,                          // number of elements in the array
		PTOUCHINPUT pInputs,  // array of touch inputs
		int cbSize)
	{
		return ::GetTouchInputInfo(hTouchInput, cInputs, pInputs, cbSize);
	}

	EXPORT BOOL WINAPI _GetUpdateRect(HWND hWnd,
		LPRECT lpRect,
		BOOL bErase)
	{
		return ::GetUpdateRect(hWnd, lpRect, bErase);
	}

	EXPORT BOOL WINAPI _InSendMessage(VOID)
	{
		return ::InSendMessage();
	}

	EXPORT HKL WINAPI _LoadKeyboardLayoutA(LPCSTR pwszKLID,
		UINT Flags)
	{
		return ::LoadKeyboardLayoutA(pwszKLID, Flags);
	}

	EXPORT BOOL WINAPI _ReplyMessage(LRESULT lResult)
	{
		return ::ReplyMessage(lResult);
	}

	EXPORT BOOL WINAPI _SetGestureConfig(HWND hwnd,                                     // window for which configuration is specified
		DWORD dwReserved,                              // reserved, must be 0
		UINT cIDs,                                     // count of GESTURECONFIG structures
		PGESTURECONFIG pGestureConfig,    // array of GESTURECONFIG structures, dwIDs will be processed in the
															// order specified and repeated occurances will overwrite previous ones
		UINT cbSize)
	{
		return ::SetGestureConfig(hwnd, dwReserved, cIDs, pGestureConfig, cbSize);
	}

	EXPORT BOOL WINAPI _SetSysColors(int cElements,
		CONST INT* lpaElements,
		CONST COLORREF* lpaRgbValues)
	{
		return ::SetSysColors(cElements, lpaElements, lpaRgbValues);
	}

	EXPORT BOOL WINAPI _ShowCaret(HWND hWnd)
	{
		return ::ShowCaret(hWnd);
	}

	EXPORT BOOL WINAPI _SystemParametersInfoA(UINT uiAction,
		UINT uiParam,
		PVOID pvParam,
		UINT fWinIni)
	{
		return ::SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni);
	}

	EXPORT BOOL WINAPI _UnloadKeyboardLayout(HKL hkl)
	{
		return ::UnloadKeyboardLayout(hkl);
	}

	EXPORT BOOL WINAPI _ValidateRect(HWND hWnd,
		CONST RECT* lpRect)
	{
		return ::ValidateRect(hWnd, lpRect);
	}

	EXPORT void _keybd_event(
		BYTE      bVk,
		BYTE      bScan,
		DWORD     dwFlags,
		ULONG_PTR dwExtraInfo
	) {
		return keybd_event(bVk, bScan, dwFlags, dwExtraInfo);
	}

	
}
