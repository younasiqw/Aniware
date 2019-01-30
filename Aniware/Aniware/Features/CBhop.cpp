#include "CBhop.h"

namespace Aniware {

	void CBhop::Initialise(SDK::CUserCmd* pCmd, SDK::CBaseEntity* pLocal) {

		if (!pCmd or !pLocal)
			return;

		if (pCmd->buttons & IN_JUMP and pLocal->Flags() > FL_INAIR) {

			pCmd->buttons |= IN_JUMP;

		}
	}
}