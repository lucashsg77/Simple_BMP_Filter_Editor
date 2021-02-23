#pragma once

#ifndef __HSV_COLOR_MODEL_OPERATIONS_H__
#define __HSV_COLOR_MODEL_OPERATIONS_H__

#include "filter.h"

class HSV :public Filter {

    uint8_t blue, green, red;
    double V, S, H;
    vector<uint8_t> aux;
    void  hsv_to_rgb(double, double, double);
    void rgb_to_hsv(uint8_t, uint8_t, uint8_t);
public:
    HSV(vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    void saturationHSV(double input_percent);
    void brightnessHSV(double input_percent);
};
#endif
