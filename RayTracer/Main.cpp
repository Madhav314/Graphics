#include <iostream>
#include <fstream>
#include "vec3.h"
#include "color.h"
#include "ray.h"


int main() {

	const double aspect_ratio = 16.0 / 9.0;
	const int width = 400;
	const int height = static_cast<int>(width / aspect_ratio);

	double viewport_height = 2.0;
	double viewport_width = viewport_height * aspect_ratio;
	double focus = 1.0;

	point origin = point(0.0, 0.0, 0.0);

	vec3 camera_x = vec3(viewport_width, 0.0, 0.0);
	vec3 camera_y = vec3(0, viewport_width, 0.0);

	vec3 position = origin - (camera_x / 2.0) - (camera_y / 2.0) - vec3(0.0, 0.0, focus);


	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << width << ' ' << height << "\n255\n";

	for (int i = height - 1; i >= 0; i--) {
		std::cerr << "\rScanlines remaining " << i << ' ' << std::flush;
		for (int j = 0; j < width; j++) {

			double a = double(j) / (width - 1);
			double b = double(i) / (height - 1);

			ray r(origin, position + (a * camera_x) + (b * camera_y) - origin);

			color pixel = ray_color(r);

			write(file, pixel);
		}
	}
	std::cerr << "\nDone.\n";
	file.close();
}