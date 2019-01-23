#pragma once

#include "..\Aniware\Classes\IClientEntity.h"
#include "..\Aniware\Utilities\Globals.h"

namespace SDK {

	class IClientEntityList {
	public:

		IClientEntity* GetClientEntity(int entNum) {

			typedef IClientEntity*(__thiscall *OrigFn)(void*, int);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 3)(this, entNum);

		}

		int GetHighestEntityIndex() {

			typedef int(__thiscall *OrigFn)(void*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 6)(this);

		}
	};
}