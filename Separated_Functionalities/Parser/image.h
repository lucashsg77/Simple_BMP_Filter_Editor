#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

class Image {

public:
    virtual void read(const char* img) = 0;
    virtual void write(const char* img, vector<uint8_t> pixel_data) = 0;
    virtual vector<uint8_t> img_pixel_data() = 0;
    virtual int32_t img_height() = 0;
    virtual int32_t img_width() = 0;
};
#endif
