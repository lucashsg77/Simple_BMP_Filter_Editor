#pragma once

#ifndef __SELECT_RGB_H__
#define __SELECT_RGB_H__

#include "filter.h"

class Select_RGB :public Filter {

    uint8_t blue = 0, green = 0, red = 0;

public:
    Select_RGB(vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    void selectRGB_filter(string input);
};
#endif
