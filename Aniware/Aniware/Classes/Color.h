#pragma once

namespace SDK {

	class Color {
	public:

		float r, g, b, a;

		Color(float R, float G, float B, float A) {

			r = R, g = G, b = B, a = A;

		}

		Color(float R, float G, float B) {

			r = R, g = G, b = B, a = 255.f;

		}
	};
}