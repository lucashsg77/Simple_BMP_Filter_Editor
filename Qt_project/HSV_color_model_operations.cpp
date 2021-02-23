#include"HSV_color_model_operations.h"

HSV::HSV(vector<uint8_t> img_pixel_data) {
    aux = pixel_data = img_pixel_data;
}

void HSV::saturationHSV(double input_percent) {

    for (int i = 0; i < (int)pixel_data.size(); i += 3) {
        red = pixel_data[i + 2];
        green = pixel_data[i + 1];
        blue = pixel_data[i];
        rgb_to_hsv(pixel_data[i + 2], pixel_data[i + 1], pixel_data[i]);
        S = (S * input_percent) + S;
        S = check_value((S * input_percent) + S, 0.0, 1.0);
        hsv_to_rgb(H, S, V);
        pixel_data[i] = (uint8_t)check_value(blue);
        pixel_data[i + 1] = (uint8_t)check_value(green);
        pixel_data[i + 2] = (uint8_t)check_value(red);
    }
}

void HSV::brightnessHSV(double input_percent) {
    for (int i = 0; i < (int)pixel_data.size(); i += 3) {
        rgb_to_hsv(pixel_data[i + 2], pixel_data[i + 1], pixel_data[i]);
        V = check_value((V * input_percent) + V, 0.0, 1.0);
        hsv_to_rgb(H, S, V);
        pixel_data[i] = (uint8_t)check_value(blue);
        pixel_data[i + 1] = (uint8_t)check_value(green);
        pixel_data[i + 2] = (uint8_t)check_value(red);
    }
}

void HSV::hsv_to_rgb(double H, double S, double V) {

    double reddb = 0.0, greendb = 0.0, bluedb = 0.0;
    double C = V * S;
    double X = C * (1.0 - fabs(fmod(H / 60.0, 2.0) - 1.0));
    double m = V - C;
    if (H >= 0.0 && H <= 60.0) {
        reddb = C;
        greendb = X;
        bluedb = 0.0;
    }
    else if (H >= 60.0 && H < 120.0) {
        reddb = X;
        greendb = C;
        bluedb = 0.0;
    }
    else if (H >= 120.0 && H < 180.0) {
        reddb = 0.0;
        greendb = C;
        bluedb = X;
    }
    else if (H >= 180.0 && H < 240.0) {
        reddb = 0.0;
        greendb = X;
        bluedb = C;
    }
    else if (H >= 240.0 && H < 300.0) {
        reddb = X;
        greendb = 0.0;
        bluedb = C;
    }
    else if (H >= 300.0 && H < 360.0) {
        reddb = C;
        greendb = 0.0;
        bluedb = X;
    }
    else {
        reddb = 0.0;
        greendb = 0.0;
        bluedb = 0.0;
    }

    red = int((reddb + m) * 255.0);
    green = int((greendb + m) * 255.0);
    blue = int((bluedb + m) * 255.0);
}

void HSV::rgb_to_hsv(uint8_t red, uint8_t green, uint8_t blue) {

    double cmax = max(max(red, green), blue);
    double cmin = min(min(red, green), blue);
    double delta = cmax - cmin;
    V = cmax / 255;
    if (delta == 0) H = 0;
    else if (cmax == red) H = 60.0 * (((green - blue) / delta));
    else if (cmax == green) H = 60.0 * (((blue - red) / delta) + 2.0);
    else if (cmax == blue) H = 60.0 * (((red - green) / delta) + 4.0);
    if (H < 0) H = H + 360.0;
    if (cmax == 0) S = 0;
    else if (cmax != 0) S = delta / cmax;
}

vector<uint8_t> HSV::filtered_pixel_data(){
    return pixel_data;
    pixel_data = aux;
}
