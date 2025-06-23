#ifndef MESH_H
#define MESH_H

#include <memory>
#include "vertexArray.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "bufferLayout.h"

class Mesh {
public:
    Mesh(float* vertices, uint32_t vertexSize, const BufferLayout& layout,
         uint32_t* indices = nullptr, uint32_t indexCount = 0);
    ~Mesh() = default;

    void Draw() const;

    const std::shared_ptr<VertexArray>& GetVertexArray() const { return m_VertexArray; }

private:
    std::shared_ptr<VertexArray> m_VertexArray;
    std::shared_ptr<VertexBuffer> m_VertexBuffer;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
    uint32_t m_IndexCount = 0;
};

#endif