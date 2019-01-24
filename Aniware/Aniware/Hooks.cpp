#include "Hooks.h"

namespace Aniware {

	Hooks g_Hooks;

	void Hooks::Init() {

		g_pCUtilities->ConsoleLog("Hooking in progress");

		// VMTHooks
		g_Hooks.pClientModeHook = std::make_unique<VMTHook>(g_pClientMode);
		g_Hooks.pSurfaceHook = std::make_unique<VMTHook>(g_pSurface);

		// Hook the table functions
		g_Hooks.pClientModeHook->Hook(24, Hooks::CreateMove);

		g_pCUtilities->ConsoleLog("Hooking completed!");
	}


	void Hooks::Restore() {

		g_pCUtilities->ConsoleLog("Restoring hooks"); {

			g_Hooks.pClientModeHook->Unhook(24);
		
		} g_pCUtilities->ConsoleLog("Restore completed");
	}


	bool __fastcall Hooks::CreateMove(SDK::IClientMode* thisptr, void* edx, float sample_frametime, SDK::CUserCmd* pCmd) {
		
		static auto oCreateMove = g_Hooks.pClientModeHook->GetOriginal<CreateMove_t>(24);
		oCreateMove(thisptr, edx, sample_frametime, pCmd);


		if (!pCmd || !pCmd->command_number)
			return oCreateMove;

		/*
		g::pCmd = pCmd;
		g::pLocalEntity = g_pEntityList->GetClientEntity(g_pEngine->GetLocalPlayer());
		if (!g::pLocalEntity)
			return oCreateMove;

		g_Misc.OnCreateMove();
		*/

		return false;
	}
}