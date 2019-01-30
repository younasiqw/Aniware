#include "Hooks.h"

using namespace SDK;

namespace Aniware {

	std::unique_ptr <CBhop> f_pBhop = nullptr;
	
	std::unique_ptr <VFTableHook> g_pPanelHook = nullptr;
	std::unique_ptr <VFTableHook> g_pEngineHook = nullptr;
	std::unique_ptr <VFTableHook> g_pClientModeHook = nullptr;

	namespace Functions {

		bool __fastcall hkCreateMove(float sample_frametime, SDK::CUserCmd* createmove_cmd) {

			g_pLoc = (CBaseEntity*)g_pEntityList->GetClientEntity(g_pEngine->GetLocalPlayer());

			if (!createmove_cmd->command_number or !g_pLoc)
				return false;

			g_pCmd = createmove_cmd;
			

			if (g_pEngine->isInGame()) {

				if(g_pSettings->bAutoBhop)
					f_pBhop->Initialise(g_pCmd, g_pLoc);

			}

			return false;
		}

		float __stdcall hkViewModelFOV() {

			return 100.f;

		}
	}

	void Hooks::Initialise() {

		Utilities::ConsoleLog("Initialising hooks"); {

			g_pPanelHook = std::make_unique<SDK::VFTableHook>((PPDWORD)g_pPanel, true);
			g_pEngineHook = std::make_unique<SDK::VFTableHook>((PPDWORD)g_pEngine, true);
			g_pClientModeHook = std::make_unique<SDK::VFTableHook>((PPDWORD)g_pClientMode, true);

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