#ifndef MESH_FACTORY_H
#define MESH_FACTORY_H

#include <memory>
#include "mesh.h"

class MeshFactory {
public:
    static std::shared_ptr<Mesh> CreateTriangle();
    static std::shared_ptr<Mesh> CreateQuad();
};

#endif
