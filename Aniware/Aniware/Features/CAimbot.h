#pragma once

#include "..\Interfaces.h"
#include "..\Classes\CInput.h"
#include "..\Classes\CBaseEntity.h"

namespace Aniware {

	class CAimbot {
	private:

		int GetPlayerIndex();

	public:

		void Initialise();

	};
}