#ifndef __CONVOLUTION_H__
#define __CONVOLUTION_H__
#include"filter.h"

class Convolution:public Filter{

public:

    Convolution();
    vector<uint8_t> convolution(vector<uint8_t> pixel_data, vector<uint8_t> modified_image_bytes, vector<double> kernel_1d, int width, int height, int row_kernel, int right_limit);
    vector<uint8_t> median_convolution(vector<uint8_t> pixel_data, vector<uint8_t> modified_image_bits, int width, int height, int radius);

private:
    void sort_median_vectors();

    double convolution_b = 0, convolution_g = 0, convolution_r = 0, sum_Kernel = 0;
    uint8_t median_value = 0;
    vector<uint8_t> median_vector_r, median_vector_g, median_vector_b;
};
#endif

