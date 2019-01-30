#pragma once

#include "..\Classes\CClientClass.h"
#include "..\Globals\Globals.h"

namespace SDK {

	class IBaseClientDLL {
	public:
		
		ClientClass* GetAllClasses() {

			typedef ClientClass*(__thiscall *OrigFn)(void*);
			return Aniware::Utilities::VirtualFunction<OrigFn>(this, 8)(this);
		
		}
	};

	class IClientEntity {
	public:

		bool IsDormant() {

			void *pNetworked = (void*)(this + 0x8);
			typedef bool(__thiscall *OrigFn)(void*);
			return Aniware::Utilities::VirtualFunction<OrigFn>(pNetworked, 9)(pNetworked);

		}

		int EntIndex() {

			void *pNetworked = (void*)(this + 0x8);
			typedef int(__thiscall *OrigFn)(void*);
			return Aniware::Utilities::VirtualFunction<OrigFn>(pNetworked, 10)(pNetworked);

		}
	};
}