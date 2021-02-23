#include "Horizontal_Mirror.h"

Horizontal_Mirror::Horizontal_Mirror(int img_height, int img_width, vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
    width = img_width;
    height = img_height;
}

Horizontal_Mirror::Horizontal_Mirror() {

}

void Horizontal_Mirror::horizontal_mirror_filter() {

    mirror_horizontal.resize(pixel_data.size());

    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {

            mirror_horizontal[(x * width + y) * 3] = pixel_data[(x * width + (width - 1 - y)) * 3];
            mirror_horizontal[((x * width + y) * 3) + 1] = pixel_data[((x * width + (width - 1 - y)) * 3) + 1];
            mirror_horizontal[((x * width + y) * 3) + 2] = pixel_data[((x * width + (width - 1 - y)) * 3) + 2];

        }
    }
}

vector<uint8_t> Horizontal_Mirror::filtered_pixel_data(){
    return mirror_horizontal;
}
