#pragma once
#include "vec3.h"

class ray {
	public:
		point origin;
		vec3 direction;

	public:
		ray(){}
		
		ray(const point &origin, const vec3 &direction): origin(origin), direction(direction){}

		point Origin() const {
			return origin;
		}

		vec3 Direction() const {
			return direction;
		}

		point at(double t) const {
			return (origin + (t * direction));
		}
};

