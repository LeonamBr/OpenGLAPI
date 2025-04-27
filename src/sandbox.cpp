// ==== sandbox.cpp para testar WindowSystem desenhando Triângulo + Quadrado ====

#include "log.h"
#include "windowSystem.h"
#include "eventbus.h"
#include "macros.h"
#include "clock.h"
#include "shaderLibrary.h"
#include "meshFactory.h"
#include "camera.h"
#include "cameraController.h"
#include "keyCodes.h"
#include "mouseKeyCodes.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

static EventBus bus;
static WindowSystem window;

static Camera mainCamera(45.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
static CameraController cameraController(mainCamera);

void OnWindowResize(const WindowResizeEvent& e)
{
    mainCamera.SetViewportSize((float)e.width, (float)e.height);
}

void OnWindowClose(const WindowCloseEvent& e)
{
    LOG_INFO("Window close event received!");
}

void OnKeyPressed(const KeyPressedEvent& e)
{
    cameraController.OnKeyPressed(e);
}

void OnKeyReleased(const KeyReleasedEvent& e)
{
    cameraController.OnKeyReleased(e);
}

void OnMouseMoved(const MouseMovedEvent& e)
{
    cameraController.OnMouseMoved(e);
}

void OnMouseScrolled(const ScrollEvent& e)
{
    cameraController.OnScroll(e);
}

int main()
{
    Log::Init();
    Clock::Init();

    window.Init(1280, 720, "Sandbox Test Triângulo + Quadrado", bus);

    bus.Subscribe<WindowCloseEvent>(REGISTER_EVENT(OnWindowClose));
    bus.Subscribe<KeyPressedEvent>(REGISTER_EVENT(OnKeyPressed));
    bus.Subscribe<KeyReleasedEvent>(REGISTER_EVENT(OnKeyReleased));
    bus.Subscribe<MouseMovedEvent>(REGISTER_EVENT(OnMouseMoved));
    bus.Subscribe<ScrollEvent>(REGISTER_EVENT(OnMouseScrolled));
    BIND_EVENT(bus, WindowResizeEvent, OnWindowResize);

    ShaderLibrary shaders;
    shaders.Load("basic", "assets/shader/shader.vertex", "assets/shader/basic.fragment");

    auto triangle = MeshFactory::CreateTriangle();
    auto quad = MeshFactory::CreateQuad();

    glm::vec3 triangleColor = glm::vec3(1.0f, 1.0f, 0.0f); // Amarelo
    glm::vec3 quadColor = glm::vec3(1.0f, 0.0f, 0.0f);     // Vermelho

    static double fpsTimer = 0.0;
    static int frameCounter = 0;

    while (!window.ShouldClose())
    {
        Clock::Update();

        float deltaTime = Clock::GetDeltaTime();
        fpsTimer += deltaTime;
        frameCounter++;

        if (fpsTimer >= 1.0)
        {
            LOG_INFO("FPS: {0}", frameCounter);
            fpsTimer = 0.0;
            frameCounter = 0;
        }

        window.PollEvents();
        cameraController.OnUpdate(deltaTime);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        auto shader = shaders.Get("basic");
        shader->Bind();

        shader->SetMat4("u_Projection", mainCamera.GetProjectionMatrix());
        shader->SetMat4("u_View", mainCamera.GetViewMatrix());

        // Desenhar Quad Vermelho
        shader->SetVec3("u_Color", quadColor);
        shader->SetMat4("u_Model", glm::mat4(1.0f));
        quad->Draw();

        // Desenhar Triângulo Amarelo (um pouco na frente)
        shader->SetVec3("u_Color", triangleColor);
        shader->SetMat4("u_Model", glm::mat4(1.0f));
        triangle->Draw();

        window.SwapBuffers();
    }

    return 0;
}
