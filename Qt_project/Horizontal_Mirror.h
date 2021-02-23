#pragma once

#ifndef __HORIZONTAL_MIRROR_H__
#define __HORIZONTAL_MIRROR_H__

#include "filter.h"

class Horizontal_Mirror :public Filter {

    vector<uint8_t> mirror_horizontal;
public:
    Horizontal_Mirror(int img_height, int img_width, vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    Horizontal_Mirror();
    void horizontal_mirror_filter();
};
#endif
