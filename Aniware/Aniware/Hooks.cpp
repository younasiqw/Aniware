#include "Hooks.h"

namespace Aniware {

	std::unique_ptr <SDK::VFTableHook> g_pPanelHook = nullptr;
	std::unique_ptr <SDK::VFTableHook> g_pEngineHook = nullptr;
	std::unique_ptr <SDK::VFTableHook> g_pClientModeHook = nullptr;

	void Hooks::Initialise() {

		g_pPanelHook = std::make_unique<SDK::VFTableHook>((SDK::PPDWORD)g_pPanel, true);
		g_pEngineHook = std::make_unique<SDK::VFTableHook>((SDK::PPDWORD)g_pEngine, true);
		g_pClientModeHook = std::make_unique<SDK::VFTableHook>((SDK::PPDWORD)g_pClientMode, true);

	}


	void Hooks::Restore() {

		g_pPanelHook->RestoreTable();
		g_pEngineHook->RestoreTable();
		g_pClientModeHook->RestoreTable();

	}
}