#pragma once

#include <cmath>

class vec3 {
	public :
		double x;
		double y;
		double z;

	public:

		vec3(): x(0), y(0), z(0){}

		vec3(double x, double y, double z) : x(x), y(y), z(z){}

		double X() const {
			return x;
		}

		double Y() const {
			return y;
		}

		double Z() const {
			return z;
		}

		vec3 operator-() const {
			return vec3(-x, -y, -x);
		}

		vec3& operator+=(const vec3 &v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		vec3& operator*=(const double s) {
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}

		vec3& operator/=(const double s) {
			return *this *= 1 / s;
		}



		double length() const {
			return(std::sqrt(x*x * y*y * z*z));
		}

		
};

using color = vec3;
using point = vec3;


inline vec3 operator+(const vec3 &a, const vec3 &b) {
	return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline vec3 operator-(const vec3 &a, const vec3 &b) {
	return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline vec3 operator*(const vec3 &a, const vec3 &b) {
	return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

inline vec3 operator*(const vec3 &a, double s) {
	return vec3(a.x * s, a.y * s, a.z * s);
}

inline vec3 operator/(vec3 a, double s) {
	return a * (1 / s);
}

inline double dot(const vec3 &a, const vec3 &b) {
	return(a.x * b.x + a.y * b.y + a.z * b.z);
}

inline vec3 cross(const vec3 &a, const vec3 &b) {
	return vec3(a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x);
}

inline vec3 unit(vec3 v) {
	return v / v.length();
}