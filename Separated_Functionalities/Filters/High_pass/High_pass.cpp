#include"High_pass.h"

vector<uint8_t>High_pass::filtered_pixel_data(){
    return modified_image_bytes;
}

High_pass::High_pass(int img_height, int img_width, vector<uint8_t> img_pixel_data) {
    pixel_data = img_pixel_data;
    width = img_width;
    height = img_height;
}

void High_pass::kernel_creation(int radius)
{
    col_kernel = row_kernel = 2 * radius + 1;
    right_limit = (row_kernel - 1) / 2, left_limit = -(right_limit);
    kernel_1d.resize(row_kernel * col_kernel);
    int size = kernel_1d.size();
    //For the sharpen filter the sum of the kernel elements needs to be 1, what differs this filter from the smoothing one is that the contrast between the central pixel and it's neighbours needs to be enhanced,
    //therefore negative values or zeroes are attributed to the neighbour pixels.
    for (int i = 0; i < size; i++) {
        if (i == (size - 1) / 2) kernel_1d[i] = (row_kernel * col_kernel) - 4.0;
        else if (i == 0 || i == size - 1 || i == row_kernel - 1 || i == (col_kernel - 1) * (row_kernel - 1) + row_kernel - 1)  kernel_1d[i] = 0.0;
        else kernel_1d[i] = -1.0;
    }

}

void High_pass::high_pass(int radius) {
    kernel_creation(radius);
    modified_image_bytes = convolution(pixel_data, modified_image_bytes, kernel_1d, width, height, row_kernel, right_limit);
}
