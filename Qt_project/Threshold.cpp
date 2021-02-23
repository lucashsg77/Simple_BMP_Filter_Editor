#include "Threshold.h"

Threshold::Threshold(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}

void Threshold::threshold_filter(int threshold_value) {

    for (int i = 0; i < (int)pixel_data.size(); i += 3)
    {
        b = pixel_data[i];
        g = pixel_data[i + 1];
        r = pixel_data[i + 2];

        y = (r + g + b) / 3;

        if (threshold_value >= y) {
            b = g = r = 255;
        }

        else {
            b = g = r = 0;
        }

        pixel_data[i] = (uint8_t)b;
        pixel_data[i + 1] = (uint8_t)g;
        pixel_data[i + 2] = (uint8_t)r;
    }
}

vector<uint8_t> Threshold::filtered_pixel_data(){
    return pixel_data;
}
