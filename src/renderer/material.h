#ifndef MATERIAL_H
#define MATERIAL_H

#include "shader.h"
#include "texture2D.h"

#include <glm/glm.hpp>
#include <unordered_map>
#include <memory>
#include <string>

class Material {
public:
    Material(std::shared_ptr<Shader> shader);

    void Bind() const;

    void Set(const std::string& name, const glm::mat4& mat);
    void Set(const std::string& name, const glm::vec4& vec);
    void Set(const std::string& name, const glm::vec3& vec);
    void Set(const std::string& name, float value);
    void Set(const std::string& name, int value);
    void SetTexture(const std::string& name, std::shared_ptr<Texture2D> texture, uint32_t slot);

    const std::shared_ptr<Shader>& GetShader() const { return m_Shader; }

private:
    std::shared_ptr<Shader> m_Shader;
    std::unordered_map<std::string, std::shared_ptr<Texture2D>> m_Textures;
    std::unordered_map<std::string, uint32_t> m_TextureSlots;
};

#endif