#include <iostream>
#include <fstream>

int main() {

	const int width = 256;
	const int height = 256;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << width << ' ' << height << "\n255\n";

	for (int i = height - 1; i >= 0; i--) {
		std::cerr << "\rScanlines remaining " << i << ' ' << std::flush;
		for (int j = 0; j < width; j++) {
			auto r = double(j) / (width - 1);
			auto g = double(i) / (height - 1);
			auto b = 0.25;

			int ir = static_cast<int>(225.999 * r);
			int ig = static_cast<int>(225.999 * g);
			int ib = static_cast<int>(225.999 * b);

			file << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	std::cerr << "\nDone.\n";
	file.close();
}