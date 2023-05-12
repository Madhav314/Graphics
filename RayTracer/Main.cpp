#include <iostream>
#include <fstream>
#include "vec3.h"
#include "color.h"

int main() {

	const int width = 256;
	const int height = 256;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << width << ' ' << height << "\n255\n";

	for (int i = height - 1; i >= 0; i--) {
		std::cerr << "\rScanlines remaining " << i << ' ' << std::flush;
		for (int j = 0; j < width; j++) {
			color pixel(double(i) / (width - 1), double(i) / (height - 1), 0.25);

			write(file, pixel);
		}
	}
	std::cerr << "\nDone.\n";
	file.close();
}