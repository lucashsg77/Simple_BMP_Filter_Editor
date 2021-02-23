#include "bitmap.h"

using namespace std;

Bitmap::Bitmap() {

}

Bitmap::Bitmap(const char* fname) {
    read(fname);
}

void Bitmap::read_info_file_headers(ifstream& file) {
    file.read((char*)&file_header, sizeof(file_header));
    file.read((char*)&info_header, sizeof(info_header));
    height = info_header.height;
    width = info_header.width;
}

void Bitmap::adjust_file_header() {
    file_header.offset_data = sizeof(file_header) + sizeof(info_header);
    file_header.file_size = file_header.offset_data;
}

void Bitmap::read_non_padded_data(ifstream& file) {
    file.read((char*)pixel_data.data(), pixel_data.size());
    file_header.file_size += static_cast<uint32_t>(pixel_data.size());
}

void Bitmap::read_padded_data(ifstream& file) {
    row_stride = info_header.width * info_header.bit_count / 8;
    uint32_t new_stride = make_stride_aligned(4);
    vector<uint8_t> padding_row(new_stride - row_stride);
    for (int y = 0; y < info_header.height; ++y) {
        file.read((char*)(pixel_data.data() + row_stride * y), row_stride);
        file.read((char*)padding_row.data(), padding_row.size());
    }
    file_header.file_size += static_cast<uint32_t>(pixel_data.size()) + info_header.height * static_cast<uint32_t>(padding_row.size());
}

void Bitmap::read(const char* filename) {

    ifstream file(filename, ios_base::binary);

    if (filename) {


        read_info_file_headers(file);


        if (file_header.file_type != BM_TYPE || info_header.bit_count != 24 || info_header.compression != BI_RGB || info_header.planes != 1 || info_header.colors_important != 0) {
            throw runtime_error("Unrecognized file format!");

        }

        file.seekg(file_header.offset_data, file.beg);

        adjust_file_header();

        if (info_header.height < 0) {

            throw runtime_error("The program treats only BMP images starting at the bottom left");

        }

        pixel_data.resize(info_header.width * info_header.height * info_header.bit_count / 8);

        if (info_header.width % 4 == 0) {

            read_non_padded_data(file);

        }
        else {

            read_padded_data(file);

        }
    }

    else {

        throw runtime_error("Could not open image file!");

    }
}

void Bitmap::write(const char* filename, vector<uint8_t> data) {
    ofstream of{ filename, ios_base::binary };
    if (of) {
        if (info_header.bit_count == 24) {

            if (info_header.width % 4 == 0) {
                write_headers_and_data(of, data);
            }
            else {
                uint32_t new_stride = make_stride_aligned(4);
                vector<uint8_t> padding_row(new_stride - row_stride);
                write_headers(of);
                for (int y = 0; y < info_header.height; ++y) {
                    of.write((const char*)(data.data() + row_stride * y), row_stride);
                    of.write((const char*)padding_row.data(), padding_row.size());
                }
            }
        }
        else {
            throw runtime_error("The program handles only 24 bits per pixel in BMP images!");
        }
    }
    else {
        throw runtime_error("Could not open image file!");
    }
}

void Bitmap::write_headers(ofstream& of) {
    of.write((const char*)&file_header, sizeof(file_header));
    of.write((const char*)&info_header, sizeof(info_header));
}

void Bitmap::write_headers_and_data(ofstream& of, vector<uint8_t> data) {
    write_headers(of);
    of.write((const char*)data.data(), data.size());
}

uint32_t Bitmap::make_stride_aligned(uint32_t align_stride) {
    uint32_t new_stride = row_stride;
    while (new_stride % align_stride != 0) {
        new_stride++;
    }
    return new_stride;
}


vector<uint8_t> Bitmap::img_pixel_data() {
    return pixel_data;
}

int32_t Bitmap::img_height() {
    return height;
}

int32_t Bitmap::img_width() {
    return width;}
