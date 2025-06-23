#include "imageLoader.h"
#include "log.h"
#include <stb_image.h>

LoadedImage LoadImage(const std::string& path, bool flip) {
    LoadedImage img = {};
    stbi_set_flip_vertically_on_load(flip ? 1 : 0);
    img.data = stbi_load(path.c_str(), &img.width, &img.height, &img.channels, 0);
    if (!img.data)
        LOG_ERROR("Falha ao carregar imagem: {}", path);
    return img;
}

void FreeImage(unsigned char* data) {
    stbi_image_free(data);
}
