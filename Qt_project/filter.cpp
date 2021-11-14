#include "filter.h"

//this function is used to assure every value is within the acceptable range for that function, in the program is used mostly to assure every value is between 0-255 but it can be used for
//other values you just need to assign them to the parameters

double Filter::check_value(double value, double left_bound, double right_bound) {
    if (value <= left_bound)
        return left_bound;
    else if (value >= right_bound)
        return right_bound;
    else
        return value;
}

//To calculate the position in the vector as if it was a matrice the original formula would be: pos = y * w + x, but we multiply it by 3 because there are 3 channels(bgr), we also add the n
//at the end to get to the right position if n = 0 we get the blue value, n = 1 green value, n = 2 red value, given that the BMP files are stored in BGR format.
//So our formula is pos = (y * w * 3) + (x * 3 + n) for all non-edge pixels, when there are edge pixel cases you can ignore them, assume a value or "duplicate" the closest one, the function below
//"duplicates" the closest one, meaning that it gives the position if the edge pixel for every non-existing position.

int Filter::get_pos(int w, int h, int y, int x , int n)
{
        int pos = 0;
        //Pixels that are not at the edge of the image
        if (y >= 0 && y < h && x >= 0 && x < w){
            pos = (y * w * 3) + (x * 3 + n);
        }
        //Edge pixels
        else{
            if(y >= h && x >= w)
                pos = (3 * (h - 1) * w) +  ((w - 1) * 3 + n);
            else if(y < 0 && x < 0)
                pos = 0;
            else if(y < 0)
                pos = (x * 3 + n);
            else if(y >= h)
                pos = (3 * (h - 1) * w) + (x * 3 + n);
            else if(x < 0)
               pos = (y * w * 3) + n;
            else if(x >= w)
                pos = (y * w * 3) + ((w - 1) * 3 + n);
        }
        return pos;

}
