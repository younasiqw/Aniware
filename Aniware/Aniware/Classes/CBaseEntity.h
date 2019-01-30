#pragma once

#include "..\Classes\Vector.h"
#include "..\Classes\CBaseEntity.h"

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

		float Flags() {

			return GetValue<float>(0x104);

		}	
		
		int Health() {

			return 0;

		}

		int Team() {

			return 0;

		}

		Vector Origin() {

			return Vector(0, 0, 0);

		}

		bool isValid() {

			if (!(this->Health() > 0))
				return false;

			if (!(this->Team() > 1))
				return false;

			return true;

		}

		// GetFlags
		// GetOrigin
		// GetEyePos
		// GetTeam
		// GetHealth

	};
}