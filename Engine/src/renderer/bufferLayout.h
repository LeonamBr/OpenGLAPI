#ifndef BUFFER_LAYOUT_H
#define BUFFER_LAYOUT_H

#include <string>
#include <vector>
#include <cstdint>
#include <initializer_list>
#include <cassert>


enum class ShaderDataType {
    None = 0, Float, Float2, Float3, Float4,
    Mat3, Mat4,
    Int, Int2, Int3, Int4,
    Bool
};

static uint32_t ShaderDataTypeSize(ShaderDataType type) {
    switch (type) {
        case ShaderDataType::Float:   return 4;
        case ShaderDataType::Float2:  return 4 * 2;
        case ShaderDataType::Float3:  return 4 * 3;
        case ShaderDataType::Float4:  return 4 * 4;
        case ShaderDataType::Mat3:    return 4 * 3 * 3;
        case ShaderDataType::Mat4:    return 4 * 4 * 4;
        case ShaderDataType::Int:     return 4;
        case ShaderDataType::Int2:    return 4 * 2;
        case ShaderDataType::Int3:    return 4 * 3;
        case ShaderDataType::Int4:    return 4 * 4;
        case ShaderDataType::Bool:    return 1;
    }
    assert(false && "ShaderDataType desconhecido!");
    return 0;
}

struct BufferElement {
    std::string Name;
    ShaderDataType Type;
    uint32_t Size;
    uint32_t Offset;
    bool Normalized;

    BufferElement() = default;

    BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
        : Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized) {}

    uint32_t GetComponentCount() const {
        switch (Type) {
            case ShaderDataType::Float:  return 1;
            case ShaderDataType::Float2: return 2;
            case ShaderDataType::Float3: return 3;
            case ShaderDataType::Float4: return 4;
            case ShaderDataType::Mat3:   return 9;
            case ShaderDataType::Mat4:   return 16;
            case ShaderDataType::Int:    return 1;
            case ShaderDataType::Int2:   return 2;
            case ShaderDataType::Int3:   return 3;
            case ShaderDataType::Int4:   return 4;
            case ShaderDataType::Bool:   return 1;
        }
        assert(false && "ShaderDataType desconhecido!");
        return 0;
    }
};

class BufferLayout {
public:
    BufferLayout() = default;

    BufferLayout(const std::initializer_list<BufferElement>& elements)
        : m_Elements(elements) {
        CalculateOffsetsAndStride();
    }

    inline uint32_t GetStride() const { return m_Stride; }
    inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }

private:
    void CalculateOffsetsAndStride() {
        uint32_t offset = 0;
        m_Stride = 0;
        for (auto& element : m_Elements) {
            element.Offset = offset;
            offset += element.Size;
            m_Stride += element.Size;
        }
    }

private:
    std::vector<BufferElement> m_Elements;
    uint32_t m_Stride = 0;
};

#endif