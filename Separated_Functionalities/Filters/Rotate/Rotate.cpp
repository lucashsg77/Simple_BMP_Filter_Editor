#include "Rotate.h"

Rotate::Rotate(int img_height, int img_width, vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
    width = img_width;
    height = img_height;
}

void Rotate::rotate_filter(double degree) {

    rotate.resize(width  * height * 3, 150);

    double radians = (degree * M_PI) / 180.0;

    double sin_theta = sin(radians);
    double cos_theta = cos(radians);

    double x0 = (height) / 2.0;
    double y0 = (width) / 2.0;

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {

            double a = x - x0;
            double b = y - y0;
            int xx = (a * cos_theta - b * sin_theta + x0);
            int yy = (b * cos_theta + a * sin_theta + y0);

            if (xx >= 0 && xx < height && yy >= 0 && yy < width) {
                rotate[(((x * width + y) * 3) + 0)] = pixel_data[((xx * width + yy) * 3) + 0];
                rotate[(((x * width + y) * 3) + 1)] = pixel_data[((xx * width + yy) * 3) + 1];
                rotate[(((x * width + y) * 3) + 2)] = pixel_data[((xx * width + yy) * 3) + 2];

            }
        }

    }
}

vector<uint8_t> Rotate::filtered_pixel_data(){
    return rotate;
}
