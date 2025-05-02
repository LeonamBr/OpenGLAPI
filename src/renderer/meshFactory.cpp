#include "meshFactory.h"
#include "bufferLayout.h"

std::shared_ptr<Mesh> MeshFactory::CreateTriangle() {
    static float vertices[] = {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f
    };

    BufferLayout layout = {
        { ShaderDataType::Float3, "a_Position" },
        { ShaderDataType::Float3, "a_Color" }
    };

    return std::make_shared<Mesh>(vertices, sizeof(vertices), layout);
}

std::shared_ptr<Mesh> MeshFactory::CreateQuad() {
    static float vertices[] = {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f
    };

    static uint32_t indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    BufferLayout layout = {
        { ShaderDataType::Float3, "a_Position" },
        { ShaderDataType::Float3, "a_Color" }
    };

    return std::make_shared<Mesh>(vertices, sizeof(vertices), layout, indices, 6);
}

std::shared_ptr<Mesh> MeshFactory::CreateTexturedQuad() {
    static float vertices[] = {
        -0.5f, -0.5f, 0.0f,  1, 0, 0,        0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,  0, 1, 0,        1.0f, 0.0f,
         0.5f,  0.5f, 0.0f,  0, 0, 1,        1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,  1, 1, 0,        0.0f, 1.0f
    };

    static uint32_t indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    BufferLayout layout = {
        { ShaderDataType::Float3, "a_Position" },
        { ShaderDataType::Float3, "a_Color" },
        { ShaderDataType::Float2, "a_TexCoord" }
    };

    return std::make_shared<Mesh>(vertices, sizeof(vertices), layout, indices, 6);
}

std::shared_ptr<Mesh> MeshFactory::CreateCube() {
    static float vertices[] = {
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f
    };

    static uint32_t indices[] = {
        0, 1, 2, 2, 3, 0, // back
        4, 5, 6, 6, 7, 4, // front
        4, 5, 1, 1, 0, 4, // left
        3, 2, 6, 6, 7, 3, // right
        4, 0, 3, 3, 7, 4, // top
        1, 5, 6, 6, 2, 1  // bottom
    };

    BufferLayout layout = {
        { ShaderDataType::Float3, "a_Position" }
    };

    return std::make_shared<Mesh>(vertices, sizeof(vertices), layout, indices, sizeof(indices) / sizeof(uint32_t));
}
