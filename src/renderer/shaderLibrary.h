#ifndef SHADER_LIBRARY_H
#define SHADER_LIBRARY_H

#include <string>
#include <unordered_map>
#include <memory>
#include "shader.h"

class ShaderLibrary {
public:
    ShaderLibrary() = default;
    ~ShaderLibrary() = default;

    void Add(const std::shared_ptr<Shader>& shader);
    std::shared_ptr<Shader> Load(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
    std::shared_ptr<Shader> Get(const std::string& name);

    bool Exists(const std::string& name) const;

private:
    std::unordered_map<std::string, std::shared_ptr<Shader>> m_Shaders;
};

#endif // SHADER_LIBRARY_H
