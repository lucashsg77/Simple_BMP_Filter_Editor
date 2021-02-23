#pragma once

#ifndef __NEGATIVE_H__
#define __NEGATIVE_H__

#include "filter.h"

class Negative : public Filter {

public:
    Negative(vector<uint8_t> img_pixel_data);
    virtual vector<uint8_t> filtered_pixel_data();
    void negative_filter();
};
#endif
