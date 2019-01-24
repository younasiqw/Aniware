#pragma once

#include "..\Aniware\Utilities\Globals.h"

namespace SDK {

	class IPanel {
	public:
		
		const char *GetName(unsigned int vguiPanel) {
		
			typedef const char *(__thiscall* OrigFn)(void*, unsigned int);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 36)(this, vguiPanel);
		
		}
	};
}
