#pragma once

#ifndef __THRESHOLD_H__
#define __THRESHOLD_H__

#include "filter.h"

class Threshold :public Filter {

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t y = 0;

public:
    Threshold(vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    void threshold_filter(int threshold_value);
};
#endif
