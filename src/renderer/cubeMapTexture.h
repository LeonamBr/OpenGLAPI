#ifndef CUBEMAP_TEXTURE_H
#define CUBEMAP_TEXTURE_H

#include <glad/glad.h>
#include <string>
#include <array>
#include <memory>
#include "imageLoader.h"

class CubeMapTexture {
public:
    CubeMapTexture(const std::string& right,
                   const std::string& left,
                   const std::string& top,
                   const std::string& bottom,
                   const std::string& front,
                   const std::string& back);
    ~CubeMapTexture();

    void Bind(uint32_t slot = 0) const;
    void Unbind() const;

    inline uint32_t GetID() const { return m_RendererID; }

private:
    uint32_t m_RendererID = 0;
};

#endif