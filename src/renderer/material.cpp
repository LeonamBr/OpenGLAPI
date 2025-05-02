#include "material.h"

Material::Material(std::shared_ptr<Shader> shader)
    : m_Shader(shader) {}

void Material::Bind() const {
    m_Shader->Bind();
    for (const auto& [name, texture] : m_Textures) {
        uint32_t slot = m_TextureSlots.at(name);
        texture->Bind(slot);
        m_Shader->SetInt(name, slot);
    }
}

void Material::Set(const std::string& name, const glm::mat4& mat) {
    m_Shader->SetMat4(name, mat);
}

void Material::Set(const std::string& name, const glm::vec4& vec) {
    m_Shader->SetVec4(name, vec);
}

void Material::Set(const std::string& name, const glm::vec3& vec) {
    m_Shader->SetVec3(name, vec);
}

void Material::Set(const std::string& name, float value) {
    m_Shader->SetFloat(name, value);
}

void Material::Set(const std::string& name, int value) {
    m_Shader->SetInt(name, value);
}

void Material::SetTexture(const std::string& name, std::shared_ptr<Texture2D> texture, uint32_t slot) {
    m_Textures[name] = texture;
    m_TextureSlots[name] = slot;
}
