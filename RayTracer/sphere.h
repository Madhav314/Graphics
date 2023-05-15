#pragma once

#include "vec3.h"
#include "hittable.h"

class sphere : public hittable{

	public:	
		point center;
		double radius;

	public:
		sphere() {};
		sphere(point c, double r) : center(c), radius(r) {};

		virtual bool hit(const ray& r, double t_min, double t_max, hit_record& record) :const override {};

};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& record) {
	vec3 oc = r.Origin() - center;

	double a = dot(r.Direction(), r.Direction());
	double b = 2.0 * dot(oc, r.Direction());
	double c = dot(oc, oc) - (radius * radius);

	double d = (b * b) - (4 * a * c);

	if (d < 0) {
		return false;
	}

	double sqrt_d = std::sqrt(d);

	double root = (((- b / 2) - sqrt_d) / a);

	if (root < t_min || t_max < root) {
		root = (((-b / 2) - sqrt_d) / a);
		if (root < t_min || t_max < root) {
			return false;
		}
	}

	record.t = root;
	record.p = r.at(record.t);
	record.normal = ((record.p - center) / radius);

	return true;
};