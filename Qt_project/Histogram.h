#ifndef __HISTOGRAM_H__
#define __HISTOGRAM_H__
#include"filter.h"

class Histogram :protected Filter {
    int histogram_values[256] = { 0 };
    double scale = 0;
    vector<int> look_up_table;
    int sum = 0;
    void histogram(vector<uint8_t> pixel_data, size_t size);
public:
    Histogram();
    Histogram(vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    void eq_histogram();
};
#endif
