#ifndef __LOW_PASS_H__
#define __LOW_PASS_H__
#include"filter.h"
#include"Convolution.h"
class Low_pass :public Convolution {

public:

    Low_pass();
    Low_pass(int img_height, int img_width, vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();

    void median(int radius);
    void box_blur(int radius);
    void gaussian_blur(int radius);
    void smoothing();

private:
    void gaussian_blur_kernel_creation(int radius);
    void box_blur_kernel_creation(int radius);

    int right_limit = 0, left_limit = 0, row_kernel = 0, col_kernel = 0;

    vector<uint8_t> modified_image_bits;
    vector<double> kernel_1d;
};
#endif
