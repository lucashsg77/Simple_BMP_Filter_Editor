#ifndef __HIGH_PASS_H__
#define __HIGH_PASS_H__
#include "filter.h"
#include "Convolution.h"
class High_pass :public Convolution {

public:

    High_pass(int img_height, int img_width, vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    High_pass(const char* bmp);
    void high_pass(int radius);


private:

    void kernel_creation(int radius);

    int right_limit = 0, left_limit = 0, row_kernel = 0, col_kernel = 0;

    vector<double> kernel_1d;
    vector<uint8_t> modified_image_bytes;
};
#endif
