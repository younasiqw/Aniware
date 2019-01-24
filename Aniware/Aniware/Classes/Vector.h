#pragma once

#include <sstream>
#include <intrin.h>

namespace SDK {

	typedef float vec_t;
	typedef Vector QAngle;

	class Vector {
	public:

		vec_t x, y, z;

		Vector(void);
		Vector(vec_t X, vec_t Y, vec_t Z);
		Vector(vec_t* clr);

		Vector& operator+=(const Vector& v) {

			x += v.x; y += v.y; z += v.z;
			return *this;

		}

		Vector& operator-=(const Vector& v) {

			x -= v.x; y -= v.y; z -= v.z;
			return *this;

		}

		Vector& operator*=(float fl) {

			x *= fl;
			y *= fl;
			z *= fl;
			return *this;

		}

		Vector& operator*=(const Vector& v) {

			x *= v.x;
			y *= v.y;
			z *= v.z;
			return *this;

		}

		Vector& operator/=(const Vector& v) {

			x /= v.x;
			y /= v.y;
			z /= v.z;
			return *this;

		}

		Vector&	operator+=(float fl) {

			x += fl;
			y += fl;
			z += fl;
			return *this;

		}

		Vector&	operator+(float fl) {

			x += fl;
			y += fl;
			z += fl;
			return *this;

		}

		Vector&	operator-(float fl) {

			x -= fl;
			y -= fl;
			z -= fl;
			return *this;

		}

		Vector&	operator/=(float fl) {

			x /= fl;
			y /= fl;
			z /= fl;
			return *this;

		}

		Vector&	operator-=(float fl) {

			x -= fl;
			y -= fl;
			z -= fl;
			return *this;

		}

		vec_t LengthSqr(void) const {

			return (x*x + y * y + z * z);

		}

		bool IsZero(float tolerance = 0.01f) const {

			return (x > -tolerance && x < tolerance &&
				y > -tolerance && y < tolerance &&
				z > -tolerance && z < tolerance);

		}

		bool IsZeroNoTol() const {

			return ((x == 0) && (y == 0) && (z == 0));

		}

		vec_t DistToSqr(const Vector &vOther) const {

			Vector delta;

			delta.x = x - vOther.x;
			delta.y = y - vOther.y;
			delta.z = z - vOther.z;

			return delta.LengthSqr();

		}

		vec_t	Length2D(void) const {

			return sqrt(x * x + y * y);

		}
	};
}