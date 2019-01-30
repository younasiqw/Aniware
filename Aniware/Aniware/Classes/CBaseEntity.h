#pragma once

#include "..\Classes\Vector.h"

namespace SDK {

	class CBaseEntity {
	private:

		template <class T>
		T GetPointer(const int offset) {

			return reinterpret_cast<T*>(reinterpret_cast<std::uintptr_t>(this) + offset);
		
		}
	
		template <class T>
		T GetValue(const int offset) {
			
			return *reinterpret_cast<T*>(reinterpret_cast<std::uintptr_t>(this) + offset);
		
		}

	public:

		

		// GetFlags
		// GetOrigin
		// GetEyePos
		// GetTeam
		// GetHealth

	};
}