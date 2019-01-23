#include <Windows.h>
#include <iostream>
#include <chrono>

#include "..\Aniware\Utilities\Globals.h"
#include "..\Aniware\Utilities\Utilities.h"

// This is a comment. xxdd
namespace Aniware {

	HANDLE DllBegin, DllDetach;

	VOID WINAPI DllSetupConsole() {

		AllocConsole();

		freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

		SetConsoleTitleA(" [ Aniware Debug Console ] ");

	}

	VOID WINAPI DllSetup(HINSTANCE module_handle) {

		DisableThreadLibraryCalls(module_handle);

		DllSetupConsole();

		g_pCUtilities->ConsoleLog("Console Initalised");

	}

	VOID WINAPI DllExit(HINSTANCE module_handle) {

		while (true) {

			if (GetAsyncKeyState(VK_END)) {

				fclose((FILE*)stdin);
				fclose((FILE*)stdout);

				HWND hw_ConsoleHwnd = GetConsoleWindow();

				FreeConsole();
				PostMessageW(hw_ConsoleHwnd, WM_CLOSE, 0, 0);

				FreeLibraryAndExitThread(module_handle, 1);

			}
		}
	}
}

BOOL WINAPI DllMain(HINSTANCE module_handle, DWORD call_reason, LPVOID reserved_parameter) {

	if (call_reason == DLL_PROCESS_ATTACH) {

		Aniware::DllSetup(module_handle); {

			Aniware::DllDetach = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Aniware::DllExit, module_handle, NULL, nullptr);

		}
	}

	return TRUE;
}