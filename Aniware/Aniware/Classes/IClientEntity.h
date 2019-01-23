#pragma once

#include "..\Utilities\Globals.h"

namespace SDK {

	class IClientEntity {
	public:

		bool IsDormant() {

			void *pNetworked = (void*)(this + 0x8);
			typedef bool(__thiscall *OrigFn)(void*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(pNetworked, 9)(pNetworked);

		}

		int EntIndex() {

			void *pNetworked = (void*)(this + 0x8);
			typedef int(__thiscall *OrigFn)(void*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(pNetworked, 10)(pNetworked);

		}
	};
}