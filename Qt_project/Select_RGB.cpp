#include "Select_RGB.h"

Select_RGB::Select_RGB(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}

void Select_RGB::selectRGB_filter(string input) {

    if (input == "blue") {

        for (int i = 0; i < (int)pixel_data.size(); i += 3) {
            pixel_data[i] = pixel_data[i];
            pixel_data[i + 1] = pixel_data[i];
            pixel_data[i + 2] = pixel_data[i];
        }
    }

    else if (input == "green") {

        for (int i = 0; i < (int)pixel_data.size(); i += 3) {
            pixel_data[i] = pixel_data[i + 1];
            pixel_data[i + 1] = pixel_data[i + 1];
            pixel_data[i + 2] = pixel_data[i + 1];
        }
    }

    else if (input == "red") {

        for (int i = 0; i < (int)pixel_data.size(); i += 3) {
            pixel_data[i] = pixel_data[i + 2];
            pixel_data[i + 1] = pixel_data[i + 2];
            pixel_data[i + 2] = pixel_data[i + 2];
        }
    }
    else {
        throw runtime_error("Illegal input!");
    }
}

vector<uint8_t> Select_RGB::filtered_pixel_data(){
    return pixel_data;
}
