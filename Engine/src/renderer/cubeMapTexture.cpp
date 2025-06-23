#include "cubeMapTexture.h"
#include "log.h"

CubeMapTexture::CubeMapTexture(const std::string& right,
                               const std::string& left,
                               const std::string& top,
                               const std::string& bottom,
                               const std::string& front,
                               const std::string& back) {

    std::array<std::string, 6> faces = { right, left, top, bottom, front, back };

    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_RendererID);

    for (unsigned int i = 0; i < faces.size(); i++) {
        LoadedImage img = LoadImage(faces[i], false);
        if (img.data) {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                         0, GL_RGB, img.width, img.height, 0, GL_RGB, GL_UNSIGNED_BYTE, img.data);
            FreeImage(img.data);
        } else {
            LOG_ERROR("Falha ao carregar textura do cubemap: {}", faces[i]);
        }
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

CubeMapTexture::~CubeMapTexture() {
    glDeleteTextures(1, &m_RendererID);
}

void CubeMapTexture::Bind(uint32_t slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_RendererID);
}

void CubeMapTexture::Unbind() const {
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}
