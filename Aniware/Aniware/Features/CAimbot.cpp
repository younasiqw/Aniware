#include "CAimbot.h"

namespace Aniware {

	int CAimbot::GetPlayerIndex() {

		for (int i = 0; i <= g_pEngine->GetMaxClients(); i++) {

			SDK::CBaseEntity * pEntity = (SDK::CBaseEntity*)g_pEntityList->GetClientEntity(i);

			if (!pEntity or !pEntity->isValid())
				continue;

			if (!pEntity->Team() != g_pLoc->Team())
				continue;

			return i;

		}
	}

	void CAimbot::Initialise() {

		if (!g_pCmd or !g_pLoc)
			return;

		/* Aimbot routine */
		
	}
}
