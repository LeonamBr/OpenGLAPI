#ifndef ENGINE_MESH_H
#define ENGINE_MESH_H

#include <vector>
#include <glad/glad.h>

class Mesh {
public:
    Mesh(const float* vertices, size_t size, unsigned int stride);
    ~Mesh();

    void Bind() const;
    void Unbind() const;
    void Draw() const;

private:
    GLuint m_VAO = 0;
    GLuint m_VBO = 0;
    GLsizei m_VertexCount = 0;
};

#endif