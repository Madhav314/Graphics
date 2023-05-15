#pragma once

#include "vec3.h"
#include "ray.h"
#include <iostream>

void write(std::ofstream &file, color pixel) {
	file << static_cast<int>(225.999 * pixel.X()) << ' '
		 << static_cast<int>(225.999 * pixel.Y()) << ' '
		 << static_cast<int>(225.999 * pixel.Z()) << '\n';
}

bool sphere_hit(const point &center, double radius, const ray &r){
	vec3 oc = r.Origin() - center;

	double a = dot(r.Direction(), r.Direction());
	double b = 2.0 * dot(oc, r.Direction());
	double c = dot(oc, oc) - (radius * radius);

	double d = (b * b) - (4 * a * c);
	return (d > 0);
}

color ray_color(const ray &r) {
	if (sphere_hit(point(0.0, 0.0, -1.0), 0.3, r)) {
		return color(1.0, 0.0, 0.0);
	}

	vec3 unit_direction = unit(r.Direction());
	double t = 0.5 * (unit_direction.Y() + 1.0);
	return (((1.0 - t) * color(1.0, 1.0, 1.0)) + (t * color(0.5, 0.7, 1.0)));
}