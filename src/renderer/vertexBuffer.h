#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <cstdint>

class VertexBuffer {
public:
    VertexBuffer(float* data, uint32_t size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

private:
    uint32_t m_RendererID = 0;
};

#endif