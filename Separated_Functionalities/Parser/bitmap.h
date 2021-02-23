#ifndef BITMAP_H
#define BITMAP_H
#include <algorithm>
#define M_PI 3.14159265358979323846
#include <string>
#include<cmath>
#include"image.h"

using namespace std;

#pragma pack(push, 1)                // Guarantees 14 bytes in every compiler

#  define BM_TYPE 0x4D42             //Check that the image format is acceptable "BM"
#  define BI_RGB       0             /* No compression - straight BGR data */
#  define BI_RLE8      1             /* 8-bit run-length compression */
#  define BI_RLE4      2             /* 4-bit run-length compression */
#  define BI_BITFIELDS 3             /* RGB bitmap with RGB masks */

struct BMPFileHeader {

    uint16_t file_type = 0x4D42;               // File type always BM which is
    uint32_t file_size = 0;               // Size of the file (in bytes)
    uint16_t reserved1 = 0;               // Reserved, always 0
    uint16_t reserved2 = 0;              // Reserved, always 0
    uint32_t offset_data = 0;           // Start position of pixel data (bytes from the beginning of the file)
};

struct BMPInfoHeader {

    uint32_t size = 0;                      // Size of this header (in bytes)
    int32_t width = 0;                      // width of bitmap in pixels
    int32_t height = 0;                     // height of bitmap in pixel
    uint16_t planes = 1;                    // No. of planes for the target device, this is always 1
    uint16_t bit_count = 0;                 // No. of bits per pixel
    uint32_t compression = 0;               // 0(24 bits) or 3(32 bits) - uncompressed.
    uint32_t size_image = 0;                // 0 - for uncompressed images
    int32_t x_pixels_per_meter = 0;
    int32_t y_pixels_per_meter = 0;
    uint32_t colors_used = 0;               // No. color indexes in the color table. Use 0 for the max number of colors allowed by bit_count
    uint32_t colors_important = 0;          // No. of colors used for displaying the bitmap. If 0 all colors are required
};

struct BMPRGB_Mask {

    uint32_t red_mask{ 0x00ff0000 }; // Bit mask red channel(0x00ff0000)
    uint32_t green_mask{ 0x0000ff00 }; // Bit mask green channel(0x0000ff00)
    uint32_t blue_mask{ 0x000000ff }; // Bit mask blue channel(0x000000ff)
    uint32_t cor_space_type{ 0x73524742 }; // Default "sRGB" (0x73524742)
    uint32_t unused[16]{ 0 }; // Unused for sRGB cor space
};

#pragma pack(pop)

class Bitmap:public Image {
private:
    BMPRGB_Mask rgb_mask;
    uint32_t row_stride = 0;
    BMPFileHeader file_header;
    BMPInfoHeader info_header;
    vector<uint8_t> pixel_data;
    int32_t height = 0, width = 0;


    uint32_t make_stride_aligned(uint32_t align_stride);
    void write_headers_and_data(ofstream& of, vector<uint8_t>data);
    void write_headers(ofstream& of);
    void read_non_padded_data(ifstream& file);
    void read_padded_data(ifstream& file);
    void read_info_file_headers(ifstream& file);
    void adjust_file_header();

public:

    Bitmap();
    Bitmap(const char* filename);
    virtual void read(const char* filename);
    virtual void write(const char* filename, vector<uint8_t> data);
    virtual vector<uint8_t> img_pixel_data();
    virtual int32_t img_height();
    virtual int32_t img_width();


};
#endif // BITMAP_H
