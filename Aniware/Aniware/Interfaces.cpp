#include "Interfaces.h"

namespace Aniware {

	SDK::ISurface * g_pSurface() {
		
		SDK::ISurface * m_pSurface = (SDK::ISurface*)g_pCUtilities->GetInterface((char*)"vguimatsurface.dll", (char*)"VGUI_Surface031");
		
		printf("\n     [*] Found m_pSurface : %i\n", (int)m_pSurface);
		return m_pSurface;

	}

	SDK::IVEngineClient * g_pEngine() {

		SDK::IVEngineClient * m_pEngine = (SDK::IVEngineClient*)g_pCUtilities->GetInterface((char*)"engine.dll", (char*)"VEngineClient014");

		printf("     [*] Found m_pEngine : %i\n", (int)m_pEngine);
		return m_pEngine;

	}

	SDK::IClientEntityList * g_pEntityList() {
	
		SDK::IClientEntityList * m_pEntityList = (SDK::IClientEntityList*)g_pCUtilities->GetInterface((char*)"client_panorama.dll", (char*)"VClientEntityList003");

		printf("     [*] Found m_pEntityList : %i\n\n", (int)m_pEntityList);
		return m_pEntityList;
	
	}
}