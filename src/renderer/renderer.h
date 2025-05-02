#ifndef RENDERER_H
#define RENDERER_H

#include "camera.h"
#include "shader.h"
#include "mesh.h"
#include "material.h"
#include <glm/glm.hpp>
#include <memory>

class Renderer {
public:
    static void Init();

    static void BeginScene(const Camera& camera);
    static void EndScene();

    static void Submit(std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh, const glm::mat4& modelMatrix);
    static void Submit(std::shared_ptr<Shader> shader, std::shared_ptr<Mesh> mesh, const glm::mat4& modelMatrix);

private:
    struct SceneData {
        glm::mat4 ViewMatrix;
        glm::mat4 ProjectionMatrix;
        glm::mat4 ViewProjectionMatrix;
    };

    static SceneData s_SceneData;
};

#endif 