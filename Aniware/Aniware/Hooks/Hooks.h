#pragma once

#include <memory>
#include "..\Classes\VTHook.h"
#include "..\Interfaces.h"

#include "..\Features\CBhop.h"
#include "..\Features\CAimbot.h"

namespace Aniware {

	namespace Hooks {

		void Initialise();
		void Restore();

	}

	extern std::unique_ptr <SDK::VFTableHook> g_pPanelHook;
	extern std::unique_ptr <SDK::VFTableHook> g_pEngineHook;
	extern std::unique_ptr <SDK::VFTableHook> g_pClientModeHook;

}