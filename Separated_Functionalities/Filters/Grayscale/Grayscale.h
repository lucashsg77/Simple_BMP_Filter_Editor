#pragma once

#ifndef __GRAYSCALE_H__
#define __GRAYSCALE_H__

#include "filter.h"

class Grayscale : public Filter {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t y = 0;

public:
    Grayscale(vector<uint8_t> img_pixel_data);
    Grayscale();
    virtual vector<uint8_t> filtered_pixel_data();
    void grayscale_filter();
};
#endif
