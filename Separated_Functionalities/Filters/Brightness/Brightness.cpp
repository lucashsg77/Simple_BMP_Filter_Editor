
#include "Brightness.h"

Brightness::Brightness(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}
//Simply add the bright value to every single pixel the image
void Brightness::brightness_filter(uint8_t bright) {

    for (int i = 0; i < (int)pixel_data.size()-1; i++)
    {
        pixel_data[i] = (uint8_t)check_value(pixel_data[i] + bright);
    }
}
vector<uint8_t> Brightness::filtered_pixel_data(){
    return pixel_data;
}
