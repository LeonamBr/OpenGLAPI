#include "texture2D.h"
#include "log.h"

Texture2D::Texture2D(const std::string& path)
    : m_Path(path)
{
    LoadedImage img = LoadImage(path, true);
    if (!img.data) return;

    m_Width = img.width;
    m_Height = img.height;

    m_InternalFormat = (img.channels == 4) ? GL_RGBA8 : GL_RGB8;
    m_DataFormat     = (img.channels == 4) ? GL_RGBA : GL_RGB;

    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, img.data);
    glGenerateMipmap(GL_TEXTURE_2D);

    FreeImage(img.data);
}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &m_RendererID);
}

void Texture2D::Bind(uint32_t slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture2D::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
