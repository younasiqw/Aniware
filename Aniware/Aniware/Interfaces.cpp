#include "Interfaces.h"

namespace Aniware {

	SDK::IPanel * g_pPanel() {

		SDK::IPanel * m_pPanel = (SDK::IPanel*)g_pCUtilities->GetInterface((char*)"vgui2.dll", (char*)"VGUI_Panel009");

		printf("\ng_pPanel %i", (int)m_pPanel);
		return m_pPanel;

	}

	SDK::ISurface * g_pSurface() {
		
		SDK::ISurface * m_pSurface = (SDK::ISurface*)g_pCUtilities->GetInterface((char*)"vguimatsurface.dll", (char*)"VGUI_Surface031");
		
		printf("\ng_pSurface %i", (int)m_pSurface);
		return m_pSurface;

	}

	SDK::IVEngineClient * g_pEngine() {

		SDK::IVEngineClient * m_pEngine = (SDK::IVEngineClient*)g_pCUtilities->GetInterface((char*)"engine.dll", (char*)"VEngineClient014");

		printf("\ng_pEngine %i", (int)m_pEngine);
		return m_pEngine;

	}

	SDK::IClientEntityList * g_pEntityList() {
	
		SDK::IClientEntityList * m_pEntityList = (SDK::IClientEntityList*)g_pCUtilities->GetInterface((char*)"client_panorama.dll", (char*)"VClientEntityList003");

		printf("\ng_pEntityList %i", (int)m_pEntityList);
		return m_pEntityList;
	
	}

	SDK::IBaseClientDLL * g_pClient() {

		SDK::IBaseClientDLL * m_pClient = (SDK::IBaseClientDLL*)g_pCUtilities->GetInterface((char*)"client_panorama.dll", (char*)"VClient018");

		printf("\ng_pClient %i", (int)m_pClient);
		return m_pClient;

	}

	SDK::IClientMode * g_pClientMode() {

		SDK::IClientMode * m_pClientMode = **(SDK::IClientMode***)((*(DWORD**)I::Client())[10] + 0x5);

		printf("\ng_pClientMode %i", (int)m_pClientMode);
		return m_pClientMode;


}