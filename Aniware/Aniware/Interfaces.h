#pragma once

#include "..\Aniware\Classes\ISurface.h"
#include "..\Aniware\Classes\IVEngineClient.h"
#include "..\Aniware\Classes\IClientEntityList.h"

namespace Aniware {

	SDK::ISurface * g_pSurface();
	SDK::IVEngineClient * g_pEngine();
	SDK::IClientEntityList * g_pEntityList();

}