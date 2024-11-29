//Eggsploit by coke

#include <Windows.h>
#include "resource.h"

HMODULE hInstance;

BOOL CALLBACK EnumWindowsFunction(HWND hWnd, LPARAM lParam) {
	DWORD dwPid;
	GetWindowThreadProcessId(hWnd, &dwPid);
	if (dwPid == lParam) {
		HMENU hMenu = LoadMenuA(hInstance, MAKEINTRESOURCEA(IDR_MENU1));
		SetMenu(hWnd, hMenu);
	}
	return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		hInstance = hModule;
		EnumWindows(EnumWindowsFunction, GetCurrentProcessId());
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

