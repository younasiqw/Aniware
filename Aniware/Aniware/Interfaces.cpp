#include "Interfaces.h"

namespace Aniware {

	SDK::IPanel * g_pPanel = nullptr;
	SDK::ISurface * g_pSurface = nullptr;
	SDK::IVEngineClient * g_pEngine = nullptr;
	SDK::IBaseClientDLL * g_pClient = nullptr;
	SDK::IClientMode * g_pClientMode = nullptr;
	SDK::IClientEntityList * g_pEntityList = nullptr;

	namespace Interfaces {

		void Initialise() {

			Aniware::Utilities::ConsoleLog("Getting interfaces"); {
				
				g_pPanel = Aniware::Utilities::GetInterface <SDK::IPanel> ((char*)"vgui2.dll", (char*)"VGUI_Panel009");
				g_pSurface = Aniware::Utilities::GetInterface <SDK::ISurface> ((char*)"vguimatsurface.dll", (char*)"VGUI_Surface031");
				g_pEngine = Aniware::Utilities::GetInterface <SDK::IVEngineClient> ((char*)"engine.dll", (char*)"VEngineClient014");
				g_pClient = Aniware::Utilities::GetInterface <SDK::IBaseClientDLL> ((char*)"client_panorama.dll", (char*)"VClient018");
				g_pClientMode = **(SDK::IClientMode***)((*(DWORD**)g_pClient)[10] + 0x5);
				g_pEntityList = Aniware::Utilities::GetInterface <SDK::IClientEntityList> ((char*)"client_panorama.dll", (char*)"VClientEntityList003");

			} Aniware::Utilities::ConsoleLog("Interfaces grabbed");
		}

	}
}