#include "vertexArray.h"
#include <glad/glad.h>

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

void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
    Bind();
    vertexBuffer->Bind();

    // Layout fixo para position (3 floats) e color (3 floats) por enquanto
    glEnableVertexAttribArray(m_VertexAttribIndex);
    glVertexAttribPointer(m_VertexAttribIndex, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (const void*)0);

    m_VertexAttribIndex++;

    glEnableVertexAttribArray(m_VertexAttribIndex);
    glVertexAttribPointer(m_VertexAttribIndex, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (const void*)(3 * sizeof(float)));

    m_VertexAttribIndex++;

    m_VertexBuffers.push_back(vertexBuffer);

    Unbind();
}

void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
    Bind();
    indexBuffer->Bind();
    m_IndexBuffer = indexBuffer;
    Unbind();
}
