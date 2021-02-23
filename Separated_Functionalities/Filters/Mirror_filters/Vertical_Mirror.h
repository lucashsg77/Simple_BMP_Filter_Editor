#pragma once

#ifndef __VERTICAL_MIRROR_H__
#define __VERTICAL_MIRROR_H__

#include "filter.h"

class Vertical_Mirror :public Filter {

    vector<uint8_t> mirror_vertical;
public:
    Vertical_Mirror(int img_height, int img_width, vector<uint8_t> img_pixel_data);
    void vertical_mirror_filter();
    virtual vector<uint8_t> filtered_pixel_data();
};
#endif
