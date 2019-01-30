#include "CBhop.h"

namespace Aniware {

	void CBhop::Initialise() {

		if (!g_pCmd or !g_pLoc)
			return;

		if (g_pCmd->buttons & IN_JUMP and g_pLoc->Flags() > FL_INAIR) {

			g_pCmd->buttons |= IN_JUMP;

		}
	}
}