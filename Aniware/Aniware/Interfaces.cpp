#include "Interfaces.h"

namespace Aniware {

	SDK::IPanel * g_pPanel() {

		SDK::IPanel * m_pPanel = (SDK::IPanel*)g_pCUtilities->GetInterface((char*)"vgui2.dll", (char*)"VGUI_Panel009");

		printf("     g_pPanel %i\n", (int)m_pPanel);
		return m_pPanel;

	}

	SDK::ISurface * g_pSurface() {
		
		SDK::ISurface * m_pSurface = (SDK::ISurface*)g_pCUtilities->GetInterface((char*)"vguimatsurface.dll", (char*)"VGUI_Surface031");
		
		printf("     g_pSurface %i\n", (int)m_pSurface);
		return m_pSurface;

	}

	SDK::IVEngineClient * g_pEngine() {

		SDK::IVEngineClient * m_pEngine = (SDK::IVEngineClient*)g_pCUtilities->GetInterface((char*)"engine.dll", (char*)"VEngineClient014");

		printf("     g_pEngine %i\n", (int)m_pEngine);
		return m_pEngine;

	}

	SDK::IClientEntityList * g_pEntityList() {
	
		SDK::IClientEntityList * m_pEntityList = (SDK::IClientEntityList*)g_pCUtilities->GetInterface((char*)"client_panorama.dll", (char*)"VClientEntityList003");

		printf("     g_pEntityList %i\n", (int)m_pEntityList);
		return m_pEntityList;
	
	}

	SDK::IBaseClientDLL * g_pClient() {

		SDK::IBaseClientDLL * m_pClient = (SDK::IBaseClientDLL*)g_pCUtilities->GetInterface((char*)"client_panorama.dll", (char*)"VClient018");

		printf("     g_pClient %i\n", (int)m_pClient);
		return m_pClient;

	}

	SDK::IClientMode * g_pClientMode() {

		SDK::IClientMode * m_pClientMode = **(SDK::IClientMode***)((*(DWORD**)g_pClient())[10] + 0x5);

		printf("     g_pClientMode %i\n", (int)m_pClientMode);
		return m_pClientMode;

	}
}