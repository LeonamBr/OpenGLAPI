#ifndef RENDERER_H
#define RENDERER_H

#include "camera.h"
#include "shader.h"
#include "mesh.h"

class Renderer {
public:
    static void Init();
    static void BeginScene(const Camera& camera);
    static void EndScene();
    static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<Mesh>& mesh, const glm::mat4& transform);

private:
    struct SceneData {
        glm::mat4 View;
        glm::mat4 Projection;
    };

    static SceneData s_SceneData;
};

#endif