#ifndef __ROTATE_H__
#define __ROTATE_H__

#include "filter.h"

class Rotate :public Filter {
    vector<uint8_t> rotate;
public:
    Rotate(int img_height, int img_width, vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    void rotate_filter(double degree);
};
#endif
