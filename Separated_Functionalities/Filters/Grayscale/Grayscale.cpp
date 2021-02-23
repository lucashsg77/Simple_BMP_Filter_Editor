#include "Grayscale.h"

Grayscale::Grayscale(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}

void Grayscale::grayscale_filter() {

    for (int i = 0; i < (int)pixel_data.size(); i += 3)
    {
        b = pixel_data[i];
        g = pixel_data[i + 1];
        r = pixel_data[i + 2];

        y = (r + g + b) / 3;

        pixel_data[i] = (uint8_t)check_value(y);
        pixel_data[i + 1] = (uint8_t)check_value(y);
        pixel_data[i + 2] = (uint8_t)check_value(y);

    }
}

vector<uint8_t> Grayscale::filtered_pixel_data(){
    return pixel_data;
}
