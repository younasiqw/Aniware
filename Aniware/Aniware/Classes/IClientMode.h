#pragma once

#include "..\Classes\IClientEntity.h"

namespace SDK {

	class IClientMode {
	public:
	
		bool ShouldDrawEntity(IClientEntity *pEnt) {
		
			typedef bool(__thiscall *OrigFn)(void*, IClientEntity*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 14)(this, pEnt);

		}
	};
}