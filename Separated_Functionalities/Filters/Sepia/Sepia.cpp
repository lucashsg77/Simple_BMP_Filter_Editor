#include "Sepia.h"
#include <math.h>
#include <iostream>

Sepia::Sepia(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}

void Sepia::sepia_filter() {

    for (int i = 0; i < (int)pixel_data.size(); i += 3) {
        //BGR
        int NB, NG, NR = 0;
        NB =  int ((0.131*pixel_data[i]) + (0.534*pixel_data[i + 1]) + (0.272*pixel_data[i + 2]));
        NG = int ((0.168*pixel_data[i]) + (0.686*pixel_data[i + 1]) + (0.349*pixel_data[i + 2]));
        NR = int ((0.189*pixel_data[i]) + (0.769*pixel_data[i + 1]) + (0.393*pixel_data[i + 2]));

        //BLUE
        pixel_data[i] = (uint8_t)check_value(NB);
        //GREEN
        pixel_data[i + 1] = (uint8_t)check_value(NG);
        //RED
        pixel_data[i + 2] = (uint8_t)check_value(NR);

    }
}

vector<uint8_t> Sepia::filtered_pixel_data(){
    return pixel_data;
}
