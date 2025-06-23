#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include <glad/glad.h>

class Shader {
public:
    Shader() = default;
    Shader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVec3(const std::string& name, const glm::vec3& value) const;
    void SetVec4(const std::string& name, const glm::vec4& value) const;
    void SetMat4(const std::string& name, const glm::mat4& value) const;

    bool Reload();
    bool IsValid() const;

    const std::string& GetName() const { return m_Name; }

private:
    static std::string ReadFile(const std::string& path);
    static std::string PreprocessShader(const std::string& source, const std::string& parentDir);

    uint32_t CompileShader(uint32_t type, const std::string& source);
    bool Compile(const std::string& vertexSource, const std::string& fragmentSource);
    int GetUniformLocation(const std::string& name) const;

private:
    mutable std::unordered_map<std::string, int> m_UniformLocationCache;

    uint32_t m_RendererID = 0;
    std::string m_Name;
    std::string m_VertexPath;
    std::string m_FragmentPath;
    bool m_IsValid = false;
};

#endif