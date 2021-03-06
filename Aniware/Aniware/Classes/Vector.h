#pragma once

#include <sstream>
#include <intrin.h>

namespace SDK {

	struct Vector {

		float x, y, z;

		Vector() { x = 0, y = 0, z = 0; }
		Vector(float X, float Y, float Z) { x = X, y = Y, z = Z; }

	};

	typedef Vector QAngle;

}