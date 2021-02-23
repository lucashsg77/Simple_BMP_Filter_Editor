#pragma once

#ifndef __SATURATIONRGB_H__
#define __SATURATIONRGB_H__

#include "filter.h"

class SaturationRGB :public Filter {

    uint8_t blue, green, red;
public:
    SaturationRGB(vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    void saturationRGB(string input, uint8_t value);
};
#endif
