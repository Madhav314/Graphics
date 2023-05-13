#pragma once

#include "vec3.h"
#include "ray.h"
#include <iostream>

void write(std::ofstream &file, color pixel) {
	file << static_cast<int>(225.999 * pixel.X()) << ' '
		 << static_cast<int>(225.999 * pixel.Y()) << ' '
		 << static_cast<int>(225.999 * pixel.Z()) << '\n';
}

color ray_color(const ray& r) {
	vec3 unit_direction = unit(r.Direction());
	double t = 0.5 * (unit_direction.Y() + 1.0);
	return (((1.0 - t) * color(1.0, 1.0, 1.0)) + (t * color(0.5, 0.7, 1.0)));
}