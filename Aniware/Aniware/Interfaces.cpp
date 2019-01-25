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

			g_pCUtilities->ConsoleLog("Getting interfaces"); {

				if (!g_pPanel)
					g_pPanel = (SDK::IPanel*)g_pCUtilities->GetInterface((char*)"vgui2.dll", (char*)"VGUI_Panel009");

				if (!g_pSurface)
					g_pSurface = (SDK::ISurface*)g_pCUtilities->GetInterface((char*)"vguimatsurface.dll", (char*)"VGUI_Surface031");

				if (!g_pEngine)
					g_pEngine = (SDK::IVEngineClient*)g_pCUtilities->GetInterface((char*)"engine.dll", (char*)"VEngineClient014");

				if (!g_pClient)
					g_pClient = (SDK::IBaseClientDLL*)g_pCUtilities->GetInterface((char*)"client_panorama.dll", (char*)"VClient018");

				if (!g_pClientMode)
					g_pClientMode = **(SDK::IClientMode***)((*(DWORD**)g_pClient)[10] + 0x5);

				if (!g_pEntityList)
					g_pEntityList = (SDK::IClientEntityList*)g_pCUtilities->GetInterface((char*)"client_panorama.dll", (char*)"VClientEntityList003");

			} g_pCUtilities->ConsoleLog("Interfaces grabbed");
		}

	}
}