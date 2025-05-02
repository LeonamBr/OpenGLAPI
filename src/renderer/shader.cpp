#include "shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include "log.h"

Shader::Shader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
    : m_Name(name), m_VertexPath(vertexPath), m_FragmentPath(fragmentPath) {

    std::string vertexSource = PreprocessShader(ReadFile(vertexPath), std::filesystem::path(vertexPath).parent_path().string());
    std::string fragmentSource = PreprocessShader(ReadFile(fragmentPath), std::filesystem::path(fragmentPath).parent_path().string());
    m_IsValid = Compile(vertexSource, fragmentSource);
}

Shader::~Shader() {
    if (m_RendererID != 0)
        glDeleteProgram(m_RendererID);
}

bool Shader::Reload() {
    LOG_INFO("Reloading shader: {}", m_Name);

    std::string vertexSource = PreprocessShader(ReadFile(m_VertexPath), std::filesystem::path(m_VertexPath).parent_path().string());
    std::string fragmentSource = PreprocessShader(ReadFile(m_FragmentPath), std::filesystem::path(m_FragmentPath).parent_path().string());

    if (m_RendererID != 0)
        glDeleteProgram(m_RendererID);

    m_UniformLocationCache.clear();
    m_IsValid = Compile(vertexSource, fragmentSource);
    return m_IsValid;
}

bool Shader::IsValid() const {
    return m_IsValid && m_RendererID != 0;
}

std::string Shader::ReadFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        LOG_ERROR("Erro ao abrir shader: {}", path);
        return "";
    }

    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

std::string Shader::PreprocessShader(const std::string& source, const std::string& parentDir) {
    std::istringstream iss(source);
    std::stringstream output;
    std::string line;

    while (std::getline(iss, line)) {
        if (line.find("#include") != std::string::npos) {
            size_t start = line.find("\"") + 1;
            size_t end = line.find_last_of("\"");
            std::string includePath = parentDir + "/" + line.substr(start, end - start);
            output << PreprocessShader(ReadFile(includePath), std::filesystem::path(includePath).parent_path().string());
        } else {
            output << line << '\n';
        }
    }

    return output.str();
}

uint32_t Shader::CompileShader(uint32_t type, const std::string& source) {
    uint32_t shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info[512];
        glGetShaderInfoLog(shader, 512, nullptr, info);
        LOG_ERROR("Falha ao compilar shader ({}): {}", (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"), info);
    }

    return shader;
}

bool Shader::Compile(const std::string& vertexSrc, const std::string& fragmentSrc) {
    if (vertexSrc.empty() || fragmentSrc.empty()) {
        LOG_ERROR("Shader source vazio!" );
        return false;
    }

    uint32_t vertex = CompileShader(GL_VERTEX_SHADER, vertexSrc);
    uint32_t fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vertex);
    glAttachShader(m_RendererID, fragment);
    glLinkProgram(m_RendererID);

    int success;
    glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
    if (!success) {
        char info[512];
        glGetProgramInfoLog(m_RendererID, 512, nullptr, info);
        LOG_ERROR("Falha ao linkar shader program: {}", info);
        return false;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return true;
}

void Shader::Bind() const {
    if (IsValid())
        glUseProgram(m_RendererID);
}

void Shader::Unbind() const {
    glUseProgram(0);
}

int Shader::GetUniformLocation(const std::string& name) const {
    if (m_UniformLocationCache.contains(name))
        return m_UniformLocationCache[name];

    int location = glGetUniformLocation(m_RendererID, name.c_str());
    if (location == -1)
        LOG_WARN("Uniform '{}' não encontrado no shader '{}'", name, m_Name);

    m_UniformLocationCache[name] = location;
    return location;
}

void Shader::SetInt(const std::string& name, int value) const {
    if (IsValid())
        glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetFloat(const std::string& name, float value) const {
    if (IsValid())
        glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetVec3(const std::string& name, const glm::vec3& value) const {
    if (IsValid())
        glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
}

void Shader::SetVec4(const std::string& name, const glm::vec4& value) const {
    if (IsValid())
        glUniform4f(GetUniformLocation(name), value.r, value.g, value.b, value.a);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& value) const {
    if (IsValid())
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
}