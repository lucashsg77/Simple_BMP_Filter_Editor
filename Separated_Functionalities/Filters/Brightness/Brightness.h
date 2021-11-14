#pragma once

#ifndef __BRIGHTNESS_H__
#define __BRIGHTNESS_H__

#include "filter.h"

class Brightness: public Filter{

public:
    Brightness(vector<uint8_t> img_pixel_data);
    void brightness_filter(uint8_t bright);
    virtual vector<uint8_t> filtered_pixel_data();
};
#endif
