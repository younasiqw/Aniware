#include <Windows.h>
#include <iostream>

namespace Aniware {

	VOID WINAPI DllSetupConsole() {

		AllocConsole();

		freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

		SetConsoleTitleA(" ( Aniware Debug Console ) ");

	}

	VOID WINAPI DllSetup(HINSTANCE module_handle) {

		DisableThreadLibraryCalls(module_handle);

		DllSetupConsole();

		// Call options manager.

		// Call hook manager.

	}
}

BOOL WINAPI DllMain(HINSTANCE module_handle, DWORD call_reason, LPVOID reserved_parameter) {

	if (call_reason == DLL_PROCESS_ATTACH) {

		Aniware::DllSetup(module_handle);

	}
	else if (call_reason == DLL_PROCESS_DETACH) {

		FreeLibraryAndExitThread(module_handle, 1);

	}

	return TRUE;
}