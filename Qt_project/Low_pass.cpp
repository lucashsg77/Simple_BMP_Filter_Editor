#include"Low_pass.h"

Low_pass::Low_pass() {

}

Low_pass::Low_pass(int img_height, int img_width, vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
    width = img_width;
    height = img_height;
}

void Low_pass::gaussian_blur_kernel_creation(int radius)
{
    col_kernel = row_kernel = 2 * radius + 1;
    right_limit = (row_kernel - 1) / 2, left_limit = -(right_limit);
    kernel_1d.resize(row_kernel * col_kernel);
    // According to one of the formulas for the gaussian blur filter, for each sigma used, there must be 3 pixels of distance in the kernel
    // so for sigma = 2, we need to have 6 pixels of distance in the kernel thus giving us a 13x13 kernel, if sigma = 1, the kernel must be 7x7, sigma = 3, the kernel must be 19x19
    // and so on, but as blurrring is a lengthy operation with large kernels an/or high resolution images, we usually increase sigma to increase blur, but for better quality the previous rule is used
    // that being, there needs to be 3 pixels apart per sigma.
    double sigma = radius / 3.0;
    double r, s = 3.0 * sigma * sigma;
    for (int x = left_limit; x <= right_limit; ++x) {
        for (int y = left_limit; y <= right_limit; ++y) {

            r = sqrt((x * x) + (y * y));
            kernel_1d[((x + -(left_limit)) * (row_kernel)) + (y + -(left_limit))] = (exp(-(r * r) / s)) / (M_PI * s);
        }

    }

}

void Low_pass::box_blur_kernel_creation(int radius)
{
    col_kernel = row_kernel = 2 * radius + 1;
    right_limit = (row_kernel - 1) / 2, left_limit = -(right_limit);
    kernel_1d.resize(row_kernel * col_kernel);
    int tam = (int)kernel_1d.size();
    // the box blur is very simple, it is basically an average of the surrounding pixels. Inside your kernel you only have the number 1 divided by the number of elements in the kernel.
    // an example would be a 3x3 kernel, that would give us a kernel with only 1/9, a 4x4 would result in a 1/16 only kernel, a ColxRow gives us a 1/col*row only kernel.
    for (int i = 0; i < tam; i++) {
        kernel_1d[i] = 1.0 / (row_kernel * col_kernel);
    }

}

void Low_pass::box_blur(int radius) {
    box_blur_kernel_creation(radius);
    modified_image_bits = convolution(pixel_data, modified_image_bits, kernel_1d, width, height, row_kernel, right_limit);
}

void Low_pass::gaussian_blur(int radius) {
    gaussian_blur_kernel_creation(radius);
    modified_image_bits = convolution(pixel_data, modified_image_bits, kernel_1d, width, height, row_kernel, right_limit);
}

void Low_pass::smoothing() {
    box_blur_kernel_creation(1);
    modified_image_bits = convolution(pixel_data, modified_image_bits, kernel_1d, width, height, row_kernel, right_limit);
}

void Low_pass::median(int radius) {
    modified_image_bits = median_convolution(pixel_data, modified_image_bits, width, height, radius);
}

vector<uint8_t> Low_pass::filtered_pixel_data(){
    return modified_image_bits;
    modified_image_bits.clear();
}
