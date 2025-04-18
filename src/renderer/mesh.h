#ifndef MESH_H
#define MESH_H

#include "vertexArray.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include <glm/glm.hpp>

class Mesh {
    public:
        Mesh(float* vertices, uint32_t vertexSize, uint32_t* indices = nullptr, uint32_t indexCount = 0);
        ~Mesh() = default;
    
        void Draw() const;
    
    private:
        std::shared_ptr<VertexArray> m_VertexArray;
        uint32_t m_VertexCount = 0;
        uint32_t m_IndexCount = 0;
    };
    

#endif
