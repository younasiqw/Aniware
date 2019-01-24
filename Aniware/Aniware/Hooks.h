#pragma once

#include <memory>

#include "..\Aniware\Classes\VTHook.h"
#include "..\Aniware\Classes\IClientEntity.h"
#include "..\Aniware\Classes\IClientEntityList.h"
#include "..\Aniware\Classes\ISurface.h"
#include "..\Aniware\Classes\IVEngineClient.h"
#include "..\Aniware\Classes\IClientMode.h"
#include "..\Aniware\Classes\CInput.h"
#include "..\Aniware\Interfaces.h"

namespace Aniware {

	namespace Hooks {

		void Initialise();
		void Restore();

	}

	extern std::unique_ptr <SDK::VFTableHook> g_pPanelHook;
	extern std::unique_ptr <SDK::VFTableHook> g_pEngineHook;
	extern std::unique_ptr <SDK::VFTableHook> g_pClientModeHook;

}