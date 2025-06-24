#include "application/Application.h"

class SandboxInterface : public Interface {
public:
    void OnAttach() override {
        LOG_INFO("[Sandbox] Attach");

    ShaderLibrary shaderLib;
    auto skyboxShader = shaderLib.Load("skybox", "../assets/shader/skybox.vertex", "../assets/shader/skybox.fragment");

    auto cubemap = std::make_shared<CubeMapTexture>(
        "../assets/textures/checker_64x64_tiles_borda_preta.png",
        "../assets/textures/checker_64x64_tiles_borda_preta.png",
        "../assets/textures/checker_64x64_tiles_borda_preta.png",
        "../assets/textures/checker_64x64_tiles_borda_preta.png",
        "../assets/textures/checker_64x64_tiles_borda_preta.png",
        "../assets/textures/checker_64x64_tiles_borda_preta.png"
    );

    m_CubeMesh = MeshFactory::CreateCube();
    m_SkyboxMaterial = std::make_shared<Material>(skyboxShader);
    m_SkyboxMaterial->SetCubeMap("u_Skybox", cubemap, 0);

    // Mesh de teste com awesomeface (fora do loop)
    m_TexturedMesh = MeshFactory::CreateTexturedQuad();
    auto shader = shaderLib.Load("textured", "../assets/shader/shader.vertex", "../assets/shader/shader.fragment");
    auto texture = std::make_shared<Texture2D>("../assets/textures/awesomeface.png");

    m_TextureMaterial = std::make_shared<Material>(shader);
    m_TextureMaterial->SetTexture("u_Texture", texture, 0);
    }

    void OnRender() override {
        Renderer::SubmitSkybox(m_SkyboxMaterial, m_CubeMesh, Application::Get().GetCamera());
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.0f));
        Renderer::Submit(m_TextureMaterial, m_TexturedMesh, model);
    }

    void OnDetach() override {
        LOG_INFO("[Sandbox] Detach");
    }

    void UIRender() override {
    ImGui::Begin("Debug");
    ImGui::Text("FPS: %.2f", 1.0f / Clock::GetDeltaTime());
    ImGui::Text("Camera Pos: (%.2f, %.2f, %.2f)",
        Application::Get().GetCamera().GetPosition().x,
        Application::Get().GetCamera().GetPosition().y,
        Application::Get().GetCamera().GetPosition().z);
    ImGui::End();
}

private:
    std::shared_ptr<Mesh> m_TexturedMesh;
    std::shared_ptr<Material> m_TextureMaterial;

    std::shared_ptr<Mesh> m_CubeMesh;
    std::shared_ptr<Material> m_SkyboxMaterial;
};

class SandboxApp : public Application {
public:
    void OnInit() override {
        RegisterInterface("sandbox", std::make_unique<SandboxInterface>());
    }
};

Application* CreateApplication() {
    return new SandboxApp();
}
