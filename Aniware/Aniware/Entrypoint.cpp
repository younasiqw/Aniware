#include <Windows.h>
#include <iostream>
#include <thread>

#include "..\Aniware\Globals\Globals.h"
#include "..\Aniware\Hooks\Hooks.h"
#include "..\Aniware\Interfaces.h"

namespace Aniware {

	HANDLE DllDetach, DllAttach;
	
	VOID WINAPI DllSetupConsole() {

		AllocConsole();

		freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

		SetConsoleTitleA(" [ Aniware Debug Console ] ");

	}

	VOID WINAPI DllSetup(HINSTANCE module_handle) {

		DisableThreadLibraryCalls(module_handle);

		DllSetupConsole();
		Utilities::ConsoleLog("Console initalised");

		Aniware::Interfaces::Initialise();
		Aniware::Hooks::Initialise();

	}

	VOID WINAPI DllExit(HINSTANCE module_handle) {

		while (true) {

			using namespace std::literals::chrono_literals;
			std::this_thread::sleep_for(5ms);

			if (GetAsyncKeyState(VK_END)) {

				fclose((FILE*)stdin);
				fclose((FILE*)stdout);

				CloseHandle(Aniware::DllDetach);
				HWND hw_ConsoleHwnd = GetConsoleWindow();

				FreeConsole();
				PostMessageW(hw_ConsoleHwnd, WM_CLOSE, 0, 0);

				Aniware::Hooks::Restore();
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