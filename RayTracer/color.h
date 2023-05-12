#pragma once

#include "vec3.h"

#include <iostream>

void write(std::ofstream &file, color pixel) {
	file << static_cast<int>(225.999 * pixel.X()) << ' '
		 << static_cast<int>(225.999 * pixel.Y()) << ' '
		 << static_cast<int>(225.999 * pixel.Z()) << '\n';
}