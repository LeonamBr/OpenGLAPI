#include "meshFactory.h"

// Cria um triângulo simples
std::shared_ptr<Mesh> MeshFactory::CreateTriangle() {
    static float vertices[] = {
        // Positions         // Colors
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
    };

    return std::make_shared<Mesh>(vertices, sizeof(vertices));
}

// Cria um quadrado com dois triângulos (usando índices)
std::shared_ptr<Mesh> MeshFactory::CreateQuad() {
    static float vertices[] = {
        // Positions         // Colors
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // Bottom Left
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // Bottom Right
         0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f, // Top Right
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, // Top Left
    };

    static uint32_t indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    return std::make_shared<Mesh>(vertices, sizeof(vertices), indices, 6);
}
