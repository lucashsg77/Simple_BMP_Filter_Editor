#include"Convolution.h"

Convolution::Convolution() {

}

//First 2 for loop goes through the image pixels, as the next 2 for loops goes through the same pixels but doing operations with the kernel as well.
vector<uint8_t> Convolution::convolution(vector<uint8_t> pixel_data, vector<uint8_t> modified_image_bits, vector<double> kernel_1d, int width, int height, int row_kernel, int right_limit) {
    modified_image_bits.resize(pixel_data.size());
    int left_limit = -right_limit;
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            sum_Kernel = 0;
            convolution_b = 0, convolution_g = 0, convolution_r = 0;
            for (int j = left_limit; j <= right_limit; ++j) {
                for (int i = left_limit; i <= right_limit; ++i) {

                        int y = (row + j);
                        int n = 0, x = (col + i);

                        convolution_b += pixel_data[get_pos(width, height, y, x, n)] * kernel_1d[((j + -(left_limit)) * (row_kernel)) + (i + -(left_limit))];
                        n++;
                        convolution_g += pixel_data[get_pos(width, height, y, x, n)] * kernel_1d[((j + -(left_limit)) * (row_kernel)) + (i + -(left_limit))];
                        n++;
                        convolution_r += pixel_data[get_pos(width, height, y, x, n)] * kernel_1d[((j + -(left_limit)) * (row_kernel)) + (i + -(left_limit))];
                        sum_Kernel += kernel_1d[((j + -(left_limit)) * (row_kernel)) + (i + -(left_limit))];
                }
                modified_image_bits[get_pos(width, height, row, col, 0)] = (uint8_t)check_value(convolution_b / sum_Kernel);
                modified_image_bits[get_pos(width, height, row, col, 1)] = (uint8_t)check_value(convolution_g / sum_Kernel);
                modified_image_bits[get_pos(width, height, row, col, 2)] = (uint8_t)check_value(convolution_r / sum_Kernel);
            }
        }
    }
    return modified_image_bits;
}
//Similar to the first function, the difference is the operation that goes on in the median filter that involves sorting as well.
vector<uint8_t> Convolution::median_convolution(vector<uint8_t> pixel_data, vector<uint8_t> modified_image_bits, int width, int height, int radius) {
    int right_limit = radius;
    int left_limit = -radius;
    int median_vectors_width = ((right_limit * 2) + 1);

    median_vector_r.resize(median_vectors_width * median_vectors_width);
    median_vector_g.resize(median_vectors_width * median_vectors_width);
    median_vector_b.resize(median_vectors_width * median_vectors_width);

    modified_image_bits.resize(pixel_data.size());

    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            for (int j = left_limit; j <= right_limit; ++j) {
                for (int i = left_limit; i <= right_limit; ++i) {

                    int y = (row + j);
                    int n = 0, x = (col + i);

                    median_vector_b[(j + right_limit) * median_vectors_width + (i + right_limit)] = pixel_data[get_pos(width, height, y, x, n)];
                    n++;
                    median_vector_g[(j + right_limit) * median_vectors_width + (i + right_limit)] = pixel_data[get_pos(width, height, y, x, n)];
                    n++;
                    median_vector_r[(j + right_limit) * median_vectors_width + (i + right_limit)] = pixel_data[get_pos(width, height, y, x, n)];
                }
            }
            sort_median_vectors();
            modified_image_bits[get_pos(width, height, row, col, 0)] = (uint8_t)median_vector_b[median_vector_b.size() / 2];
            modified_image_bits[get_pos(width, height, row, col, 1)] = (uint8_t)median_vector_g[median_vector_g.size() / 2];
            modified_image_bits[get_pos(width, height, row, col, 2)] = (uint8_t)median_vector_r[median_vector_r.size() / 2];
        }
    }
    return modified_image_bits;
}

void Convolution::sort_median_vectors()
{
    sort(median_vector_b.begin(), median_vector_b.end());
    sort(median_vector_g.begin(), median_vector_g.end());
    sort(median_vector_r.begin(), median_vector_r.end());
}
