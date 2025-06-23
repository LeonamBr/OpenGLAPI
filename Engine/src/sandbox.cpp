#include "engine/engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

static EventBus bus;
static WindowSystem window;

static Camera camera(45.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
static CameraController cameraController(camera);

void OnWindowClose(const WindowCloseEvent&) {
    LOG_INFO("Fechando janela...");
}

void OnWindowResize(const WindowResizeEvent& e) {
    camera.SetViewportSize((float)e.width, (float)e.height);
}

void OnKeyPressed(const KeyPressedEvent& e) {
    cameraController.OnKeyPressed(e);
}

void OnKeyReleased(const KeyReleasedEvent& e) {
    cameraController.OnKeyReleased(e);
}

void OnMouseMoved(const MouseMovedEvent& e) {
    cameraController.OnMouseMoved(e);
}

void OnMouseScrolled(const ScrollEvent& e) {
    cameraController.OnScroll(e);
}

int main() {
    Log::Init();
    Clock::Init();

    window.Init(1280, 720, "Sandbox com Skybox", bus);
    BIND_EVENT(bus, WindowCloseEvent, OnWindowClose);
    BIND_EVENT(bus, WindowResizeEvent, OnWindowResize);
    BIND_EVENT(bus, KeyPressedEvent, OnKeyPressed);
    BIND_EVENT(bus, KeyReleasedEvent, OnKeyReleased);
    BIND_EVENT(bus, MouseMovedEvent, OnMouseMoved);
    BIND_EVENT(bus, ScrollEvent, OnMouseScrolled);

    Renderer::Init();

    ShaderLibrary shaderLib;
    auto skyboxShader = shaderLib.Load("skybox", "assets/shader/skybox.vertex", "assets/shader/skybox.fragment");

    // Usa a mesma textura checker para todos os lados do cubemap
    auto checkerTexture = std::make_shared<Texture2D>("assets/textures/checker.png");
    auto cubemap = std::make_shared<CubeMapTexture>(
        "assets/textures/checker_64x64.png",
        "assets/textures/checker_64x64.png",
        "assets/textures/checker_64x64.png",
        "assets/textures/checker_64x64.png",
        "assets/textures/checker_64x64.png",
        "assets/textures/checker_64x64.png"
    );

    auto skyboxMesh = MeshFactory::CreateCube();
    auto skyboxMat = std::make_shared<Material>(skyboxShader);
    skyboxMat->SetCubeMap("u_Skybox", cubemap, 0);

    // Mesh de teste com awesomeface (fora do loop)
    auto mesh = MeshFactory::CreateTexturedQuad();
    auto shader = shaderLib.Load("textured", "assets/shader/shader.vertex", "assets/shader/shader.fragment");
    auto texture = std::make_shared<Texture2D>("assets/textures/awesomeface.png");

    auto material = std::make_shared<Material>(shader);
    material->SetTexture("u_Texture", texture, 0);

    float timeAccumulator = 0.0f;
    int frameCount = 0;

    glfwSwapInterval(0);

    while (!window.ShouldClose()) {
        Clock::Update();
        float deltaTime = Clock::GetDeltaTime();

        timeAccumulator += deltaTime;
        frameCount++;

        window.PollEvents();
        cameraController.OnUpdate(deltaTime);

        RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
        RenderCommand::Clear();

        Renderer::BeginScene(camera);
        Renderer::SubmitSkybox(skyboxMat, skyboxMesh, camera);

        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.0f));
        Renderer::Submit(material, mesh, model);
        Renderer::EndScene();

        if (timeAccumulator >= 1.0f) {
        LOG_INFO("FPS: {0}", frameCount);

        timeAccumulator = 0.0f;
        frameCount = 0;
        }

        window.SwapBuffers();
    }

    return 0;
}
