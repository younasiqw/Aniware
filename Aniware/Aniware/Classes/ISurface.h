#pragma once

#include "..\Globals\Globals.h"
#include "..\Classes\Color.h"

namespace SDK {

	class ISurface {
	public:

		void DrawSetColor(Color col) {

			typedef void(__thiscall *OrigFn)(void*, Color);
			Aniware::Utilities::VirtualFunction<OrigFn>(this, 14)(this, col);

		}

		void DrawFilledRect(int x0, int y0, int x1, int y1) {

			typedef void(__thiscall *OrigFn)(void*, int, int, int, int);
			Aniware::Utilities::VirtualFunction<OrigFn>(this, 16)(this, x0, y0, x1, y1);

		}

		void DrawOutlinedRect(int x0, int y0, int x1, int y1) {

			typedef void(__thiscall *OrigFn)(void*, int, int, int, int);
			Aniware::Utilities::VirtualFunction<OrigFn>(this, 18)(this, x0, y0, x1, y1);

		}
	};
}