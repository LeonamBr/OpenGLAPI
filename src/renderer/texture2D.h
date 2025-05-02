#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include <string>
#include <glad/glad.h>

class Texture2D {
public:
    Texture2D(const std::string& path);
    ~Texture2D();

    void Bind(uint32_t slot = 0) const;
    void Unbind() const;

    inline uint32_t GetWidth() const { return m_Width; }
    inline uint32_t GetHeight() const { return m_Height; }
    inline uint32_t GetID() const { return m_RendererID; }
    inline const std::string& GetPath() const { return m_Path; }

private:
    std::string m_Path;
    uint32_t m_Width = 0, m_Height = 0;
    uint32_t m_RendererID = 0;
    GLenum m_InternalFormat = 0, m_DataFormat = 0;
};

#endif