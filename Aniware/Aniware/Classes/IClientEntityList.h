#pragma once

#include "..\Classes\IClientEntity.h"
#include "..\Globals\Globals.h"

namespace SDK {

	class IClientEntityList {
	public:

		IClientEntity* GetClientEntity(int entNum) {

			typedef IClientEntity*(__thiscall *OrigFn)(void*, int);
			return Aniware::Utilities::VirtualFunction<OrigFn>(this, 3)(this, entNum);

		}

		int GetHighestEntityIndex() {

			typedef int(__thiscall *OrigFn)(void*);
			return Aniware::Utilities::VirtualFunction<OrigFn>(this, 6)(this);

		}
	};
}