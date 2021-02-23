#include "SaturationRGB.h"

SaturationRGB::SaturationRGB(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}

void SaturationRGB::saturationRGB(string input, uint8_t value) {

    if (input == "blue") {

        blue = value;

        for (int i = 0; i < (int)pixel_data.size() - 3; i += 3) {
            //Blue
            pixel_data[i] = (uint8_t)check_value(pixel_data[i] + blue);
        }
    }

    else if (input == "green") {

        green = value;

        for (int i = 1; i < (int)pixel_data.size() - 2; i += 3) {
            //Green
            pixel_data[i] = (uint8_t)check_value(pixel_data[i] + green);
        }
    }

    else if (input == "red") {

        red = value;

        for (int i = 2; i < (int)pixel_data.size() - 1; i += 3) {
            //Red
            pixel_data[i] = (uint8_t)check_value(pixel_data[i] + red);
        }
    }
}

vector<uint8_t> SaturationRGB::filtered_pixel_data(){
    return pixel_data;
}
