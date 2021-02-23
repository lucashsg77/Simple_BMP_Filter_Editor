#pragma once

#ifndef __SEPIA_H__
#define __SEPIA_H__

#include "filter.h"

class Sepia :public Filter {

public:
    Sepia(vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    void sepia_filter();
};
#endif
