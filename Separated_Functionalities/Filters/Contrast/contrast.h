#pragma once

#ifndef __CONTRAST_H__
#define __CONTRAST_H__

#include "filter.h"

class Contrast : public Filter {

public:
    Contrast(vector<uint8_t> img_pixel_data);
    void contrast_filter(double contrast);
    virtual vector<uint8_t> filtered_pixel_data();
};
#endif
