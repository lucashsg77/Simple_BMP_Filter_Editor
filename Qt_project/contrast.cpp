#include "contrast.h"

vector<uint8_t>Contrast::filtered_pixel_data(){
    return pixel_data;
}

Contrast::Contrast(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}

void Contrast::contrast_filter(double contrast) {

    //formula for contrast, i being a slopeand x a color(R or G or B) and b is the brightness but as we want to control only the contrast b = 0.
    // in the program i is the parameter (contrast float) that is passed to the function.

    for (int i = 0; i < (int)pixel_data.size()-1; i++) {
        pixel_data[i] = (uint8_t)check_value((contrast * (pixel_data[i] - 128)) + 128);
    }
}
