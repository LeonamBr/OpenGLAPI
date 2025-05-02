#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <string>

struct LoadedImage {
    unsigned char* data;
    int width;
    int height;
    int channels;
};

LoadedImage LoadImage(const std::string& path, bool flip = true);
void FreeImage(unsigned char* data);

#endif