#include "mesh.h"
#include <glad/glad.h>

Mesh::Mesh(float* vertices, uint32_t vertexSize, const BufferLayout& layout,
           uint32_t* indices, uint32_t indexCount)
    : m_IndexCount(indexCount)
{
    m_VertexArray = std::make_shared<VertexArray>();

    m_VertexBuffer = std::make_shared<VertexBuffer>(vertices, vertexSize);
    m_VertexBuffer->SetLayout(layout);
    m_VertexArray->AddVertexBuffer(m_VertexBuffer);

    if (indices && indexCount > 0) {
        m_IndexBuffer = std::make_shared<IndexBuffer>(indices, indexCount);
        m_VertexArray->SetIndexBuffer(m_IndexBuffer);
    }
}

void Mesh::Draw() const {
    m_VertexArray->Bind();

    if (m_IndexBuffer)
        glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, nullptr);
    else
        glDrawArrays(GL_TRIANGLES, 0, 3);
}
