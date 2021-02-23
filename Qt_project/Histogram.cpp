#include"Histogram.h"

Histogram::Histogram() {

}

Histogram::Histogram(vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
}
//counts how many times a given value is repeated in the bits of the image, i.e: if i have 100x the value 10 the histogram[10] = 100.

void Histogram::histogram(vector<uint8_t> pixel_data, size_t size) {

    for (int i = 0; i < (int)size; ++i) {
        histogram_values[pixel_data[i]]++;
    }

}

//it creates a lookup table and call the function to create the histogram, from there it goes through the image bit per bit replacing the value of the bit for the one stored at that position in
//the look up table, i.e: if bit pixel_data[30] = 158 and look_up_table[158] = 145 we would have that pixel_data[30] = 145 now.

void Histogram::eq_histogram() {
    look_up_table.resize(256, 0);
    histogram(pixel_data, pixel_data.size());
    int i = 0;
    while (!histogram_values[i]) {
        ++i;
    }

    if (histogram_values[i] == (int)pixel_data.size()) {
        for (int j = 0; j < (int)pixel_data.size(); ++j) {
            pixel_data[j] = i;
        }
    }

    scale = (255.0) / (pixel_data.size() - histogram_values[i]);
    i++;
    for (; i < 256; ++i) {
        sum += histogram_values[i];
        look_up_table[i] = max(0, min(int(round(sum * scale)), 255));
    }

    for (int i = 0; i < (int)pixel_data.size(); ++i) {
        pixel_data[i] = look_up_table[pixel_data[i]];
    }
}

vector<uint8_t> Histogram::filtered_pixel_data(){
    return pixel_data;
}
