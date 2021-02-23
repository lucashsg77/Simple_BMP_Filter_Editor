#include "HV_Mirror.h"

HV_Mirror::HV_Mirror(int img_height, int img_width, vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
    width = img_width;
    height = img_height;
}

HV_Mirror::HV_Mirror() {

}

void HV_Mirror::hv_mirror_filter() {

    vector<uint8_t> mirror_h;

    mirror_h.resize(pixel_data.size());
    mirror_hv.resize(pixel_data.size());

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {

            mirror_h[(x * width + y) * 3] = pixel_data[((height - 1 - x) * width + y) * 3];
            mirror_h[(x * width + y) * 3 + 1] = pixel_data[((height - 1 - x) * width + y) * 3 + 1];
            mirror_h[(x * width + y) * 3 + 2] = pixel_data[((height - 1 - x) * width + y) * 3 + 2];
        }
    }

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {

            mirror_hv[(x * width + y) * 3] = mirror_h[(x * width + (width - 1 - y)) * 3];
            mirror_hv[((x * width + y) * 3) + 1] = mirror_h[((x * width + (width - 1 - y)) * 3) + 1];
            mirror_hv[((x * width + y) * 3) + 2] = mirror_h[((x * width + (width - 1 - y)) * 3) + 2];
        }
    }
}

vector<uint8_t> HV_Mirror::filtered_pixel_data(){
    return mirror_hv;
}
