#include "Hooks.h"

namespace Aniware {

	std::unique_ptr <SDK::VFTableHook> g_pPanelHook = nullptr;
	std::unique_ptr <SDK::VFTableHook> g_pEngineHook = nullptr;
	std::unique_ptr <SDK::VFTableHook> g_pClientModeHook = nullptr;

	namespace Functions {

		bool __fastcall hkCreateMove(float sample_frametime, SDK::CUserCmd* createmove_cmd) {

			if (!createmove_cmd->command_number)
				return false;

			g_pCmd = createmove_cmd;
			g_pCmd->viewangles = SDK::QAngle(0, 0, 0);

			return false;
		}

		float __stdcall hkViewModelFOV() {

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