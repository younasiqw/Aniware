#include "Hooks.h"

namespace Aniware {

	std::unique_ptr <SDK::VFTableHook> g_pPanelHook = nullptr;
	std::unique_ptr <SDK::VFTableHook> g_pEngineHook = nullptr;
	std::unique_ptr <SDK::VFTableHook> g_pClientModeHook = nullptr;

	using CreateMoveFn = bool(__fastcall*) (SDK::IClientMode*, void*, float, SDK::CUserCmd*);
	using ViewModelFn = float(__stdcall*)(void*);

	namespace Functions {

		CreateMoveFn oCreateMove;
		bool __fastcall hkCreateMove(SDK::IClientMode* thisptr, void* edx, float sample_frametime, SDK::CUserCmd* pCmd) {

			oCreateMove(thisptr, edx, sample_frametime, pCmd);

			if (!pCmd || !pCmd->command_number)
				return oCreateMove;

			// Createmove features.

			return false;
		}

		ViewModelFn oViewModel;
		float __stdcall hkViewModelFOV() {

			oViewModel(g_pClientMode);
			return 100.f;

		}
	}

	void Hooks::Initialise() {

		Utilities::ConsoleLog("Initialising hooks"); {

			g_pPanelHook = std::make_unique<SDK::VFTableHook>((SDK::PPDWORD)g_pPanel, true);
			g_pEngineHook = std::make_unique<SDK::VFTableHook>((SDK::PPDWORD)g_pEngine, true);
			g_pClientModeHook = std::make_unique<SDK::VFTableHook>((SDK::PPDWORD)g_pClientMode, true);

		} Utilities::ConsoleLog("Hooks initialised");

		g_pClientModeHook->Hook(24, Functions::hkCreateMove);
		g_pClientModeHook->Hook(35, Functions::hkViewModelFOV);

	}

	void Hooks::Restore() {

		g_pPanelHook->RestoreTable();
		g_pEngineHook->RestoreTable();
		g_pClientModeHook->RestoreTable();

	}
}