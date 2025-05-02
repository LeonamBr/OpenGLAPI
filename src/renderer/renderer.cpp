#include "renderer.h"
#include "renderCommand.h"

Renderer::SceneData Renderer::s_SceneData;

void Renderer::Init() {

    RenderCommand::Init();

}

void Renderer::BeginScene(const Camera& camera) {
    s_SceneData.ViewMatrix = camera.GetViewMatrix();
    s_SceneData.ProjectionMatrix = camera.GetProjectionMatrix();
    s_SceneData.ViewProjectionMatrix = s_SceneData.ProjectionMatrix * s_SceneData.ViewMatrix;
}

void Renderer::EndScene() {}

void Renderer::Submit(std::shared_ptr<Shader> shader, std::shared_ptr<Mesh> mesh, const glm::mat4& modelMatrix) {
    shader->Bind();
    shader->SetMat4("u_Model", modelMatrix);
    shader->SetMat4("u_View", s_SceneData.ViewMatrix);
    shader->SetMat4("u_Projection", s_SceneData.ProjectionMatrix);
    mesh->Draw();
}

void Renderer::Submit(std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh, const glm::mat4& modelMatrix) {
    material->Bind();
    material->Set("u_Model", modelMatrix);
    material->Set("u_View", s_SceneData.ViewMatrix);
    material->Set("u_Projection", s_SceneData.ProjectionMatrix);
    mesh->Draw();
}
