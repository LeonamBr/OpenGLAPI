#ifndef ENGINE_MESH_FACTORY_H
#define ENGINE_MESH_FACTORY_H

#include "mesh.h"

class MeshFactory {
public:
    static Mesh CreateTriangle();
    static Mesh CreateQuad();

};

#endif