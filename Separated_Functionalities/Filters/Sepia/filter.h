#ifndef __FILTER_H__
#define __FILTER_H__
#include<vector>
#include<string>
#include <algorithm>
#include<cmath>
#include <iostream>
#define M_PI 3.14159265358979323846
using namespace std;

class Filter{
public:
    double check_value(double value = 0.0, double left_bound = 0.0, double right_bound = 255.0);
    int get_pos(int w, int h, int  x, int  y, int n);
    virtual vector<uint8_t> filtered_pixel_data() = 0;
protected:
    vector<uint8_t> pixel_data;
    int height = 0, width = 0;
};
#endif
