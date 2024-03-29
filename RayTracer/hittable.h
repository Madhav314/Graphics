#pragma once

#include "ray.h"

struct hit_record {
	point p;
	vec3 normal;
	double t;
};

class hittable {
	public:
		virtual bool hit(const ray& r, double t_min, double t_max, hit_record& record) const = 0;
};