#pragma once

#ifndef __HV_MIRROR_H__
#define __HV_MIRROR_H__

#include "filter.h"

class HV_Mirror :public Filter{

    vector<uint8_t> mirror_hv;
public:
    HV_Mirror(int img_height, int img_width, vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    HV_Mirror();
    void hv_mirror_filter();
};
#endif
