#include "renderer.h"
#include "renderCommand.h"

Renderer::SceneData Renderer::s_SceneData;

void Renderer::Init()
{
    RenderCommand::Init();
}

void Renderer::BeginScene(const Camera& camera)
{
    s_SceneData.View = camera.GetViewMatrix();
    s_SceneData.Projection = camera.GetProjectionMatrix();
}

void Renderer::EndScene()
{
    // Por agora, nada. Futuramente pode limpar buffers de submissão ou lidar com batches.
}

void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<Mesh>& mesh, const glm::mat4& transform)
{
    shader->Bind();
    shader->SetMat4("u_View", s_SceneData.View);
    shader->SetMat4("u_Projection", s_SceneData.Projection);
    shader->SetMat4("u_Model", transform);
    mesh->Draw();
}