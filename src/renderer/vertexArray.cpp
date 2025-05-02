#include "vertexArray.h"
#include <glad/glad.h>
#include "log.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::Bind() const {
    glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}

void VertexArray::ConfigureAttribute(uint32_t index, const BufferElement& element, uint32_t stride) {
    glEnableVertexAttribArray(index);

    GLenum glBaseType = GL_FLOAT; // padrão, pode ser expandido futuramente
    switch (element.Type) {
        case ShaderDataType::Float:
        case ShaderDataType::Float2:
        case ShaderDataType::Float3:
        case ShaderDataType::Float4:
        case ShaderDataType::Mat3:
        case ShaderDataType::Mat4:
            glBaseType = GL_FLOAT;
            break;
        case ShaderDataType::Int:
        case ShaderDataType::Int2:
        case ShaderDataType::Int3:
        case ShaderDataType::Int4:
            glBaseType = GL_INT;
            break;
        case ShaderDataType::Bool:
            glBaseType = GL_BOOL;
            break;
        default:
            LOG_ERROR("Tipo de ShaderDataType não suportado ainda em VertexArray");
            return;
    }

    glVertexAttribPointer(
        index,
        element.GetComponentCount(),
        glBaseType,
        element.Normalized ? GL_TRUE : GL_FALSE,
        stride,
        reinterpret_cast<const void*>(static_cast<intptr_t>(element.Offset))
    );
}

void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
    Bind();
    vertexBuffer->Bind();

    const auto& layout = vertexBuffer->GetLayout();
    for (const auto& element : layout.GetElements()) {
        ConfigureAttribute(m_VertexAttribIndex, element, layout.GetStride());
        m_VertexAttribIndex++;
    }

    m_VertexBuffers.push_back(vertexBuffer);
    Unbind();
}

void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
    Bind();
    indexBuffer->Bind();
    m_IndexBuffer = indexBuffer;
    Unbind();
}