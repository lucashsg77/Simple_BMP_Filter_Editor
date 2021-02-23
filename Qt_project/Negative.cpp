
#include "Negative.h"

Negative::Negative(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}

void Negative::negative_filter() {

    for (int i = 0; i < (int)pixel_data.size() - 1; i++) {

        pixel_data[i] = (uint8_t)(255 - pixel_data[i]);
    }
}

vector<uint8_t> Negative::filtered_pixel_data(){
    return pixel_data;
}
