#include "Vertical_Mirror.h"

Vertical_Mirror::Vertical_Mirror(int img_height, int img_width, vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
    width = img_width;
    height = img_height;
}

void Vertical_Mirror::vertical_mirror_filter() {

    mirror_vertical.resize(pixel_data.size());

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {

            mirror_vertical [(x * width + y) * 3] = pixel_data[((height - 1 - x) * width + y) * 3];
            mirror_vertical[(x * width + y) * 3 + 1] = pixel_data[((height - 1 - x) * width + y) * 3 + 1];
            mirror_vertical[(x * width + y) * 3 + 2] = pixel_data[((height - 1 - x) * width + y) * 3 + 2];

        }
    }

}

vector<uint8_t>  Vertical_Mirror::filtered_pixel_data(){
    return mirror_vertical;
}
