#include "shaderLibrary.h"
#include <cassert>

void ShaderLibrary::Add(const std::shared_ptr<Shader>& shader) {
    const std::string& name = shader->GetName();
    if (Exists(name)) {
        assert(false && "Shader already exists!");
    }
    m_Shaders[name] = shader;
}

std::shared_ptr<Shader> ShaderLibrary::Load(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath) {
    auto shader = std::make_shared<Shader>(name, vertexPath, fragmentPath);
    Add(shader);
    return shader;
}

std::shared_ptr<Shader> ShaderLibrary::Get(const std::string& name) {
    if (!Exists(name)) {
        assert(false && "Shader not found!");
    }
    return m_Shaders.at(name);
}

bool ShaderLibrary::Exists(const std::string& name) const {
    return m_Shaders.find(name) != m_Shaders.end();
}
