#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <cstdint>
#include "bufferLayout.h"

class VertexBuffer {
public:
    VertexBuffer(float* data, uint32_t size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

    void SetLayout(const BufferLayout& layout);
    const BufferLayout& GetLayout() const;

private:
    uint32_t m_RendererID = 0;
    BufferLayout m_Layout;
};

#endif