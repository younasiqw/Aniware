#pragma once

#include "..\Aniware\Classes\ISurface.h"
#include "..\Aniware\Classes\IVEngineClient.h"
#include "..\Aniware\Classes\IClientEntityList.h"
#include "..\Aniware\Classes\IClientMode.h"
#include "..\Aniware\Classes\IPanel.h"

namespace Aniware {

	SDK::IPanel * g_pPanel();
	SDK::ISurface * g_pSurface();
	SDK::IVEngineClient * g_pEngine();
	SDK::IClientEntityList * g_pEntityList();
	SDK::IBaseClientDLL * g_pClient();
	SDK::IClientMode * g_pClientMode();

}