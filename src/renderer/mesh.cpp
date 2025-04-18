#include "mesh.h"
#include <glad/glad.h>

Mesh::Mesh(float* vertices, uint32_t vertexSize, uint32_t* indices, uint32_t indexCount)
    : m_IndexCount(indexCount)
{
    m_VertexArray = std::make_shared<VertexArray>();

    auto vertexBuffer = std::make_shared<VertexBuffer>(vertices, vertexSize);
    m_VertexArray->AddVertexBuffer(vertexBuffer);

    if (indices && indexCount > 0) {
        auto indexBuffer = std::make_shared<IndexBuffer>(indices, indexCount);
        m_VertexArray->SetIndexBuffer(indexBuffer);
    }

    // Calcula vertexCount baseado no formato fixo atual (6 floats por vertex)
    m_VertexCount = vertexSize / (6 * sizeof(float));
}

void Mesh::Draw() const {
    m_VertexArray->Bind();

    if (m_IndexCount > 0) {
        glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, nullptr);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, m_VertexCount);
    }
}

