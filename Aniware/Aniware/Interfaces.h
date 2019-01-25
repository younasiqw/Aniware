#pragma once

#include "..\Aniware\Classes\ISurface.h"
#include "..\Aniware\Classes\IVEngineClient.h"
#include "..\Aniware\Classes\IClientEntityList.h"
#include "..\Aniware\Classes\IClientMode.h"
#include "..\Aniware\Classes\IPanel.h"

namespace Aniware {

	extern SDK::IPanel * g_pPanel;
	extern SDK::ISurface * g_pSurface;
	extern SDK::IVEngineClient * g_pEngine;
	extern SDK::IClientEntityList * g_pEntityList;
	extern SDK::IBaseClientDLL * g_pClient;
	extern SDK::IClientMode * g_pClientMode;

	namespace Interfaces {

		void Initialise();

	}
}