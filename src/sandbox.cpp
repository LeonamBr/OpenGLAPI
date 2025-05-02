#include "log.h"
#include "windowSystem.h"
#include "eventbus.h"
#include "macros.h"
#include "clock.h"
#include "shader.h"
#include "shaderLibrary.h"
#include "meshFactory.h"
#include "renderer.h"
#include "renderCommand.h"
#include "camera.h"
#include "cameraController.h"
#include "event.h"
#include "keyCodes.h"

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

    window.Init(1280, 720, "Sandbox Layout Dinâmico", bus);
    BIND_EVENT(bus, WindowCloseEvent, OnWindowClose);
    BIND_EVENT(bus, WindowResizeEvent, OnWindowResize);
    BIND_EVENT(bus, KeyPressedEvent, OnKeyPressed);
    BIND_EVENT(bus, KeyReleasedEvent, OnKeyReleased);
    BIND_EVENT(bus, MouseMovedEvent, OnMouseMoved);
    BIND_EVENT(bus, ScrollEvent, OnMouseScrolled);

    Renderer::Init();

    ShaderLibrary shaderLib;
    auto shader = shaderLib.Load("basic", "assets/shader/shader.vertex", "assets/shader/basic.fragment");

    auto triangle = MeshFactory::CreateTriangle();
    auto quad = MeshFactory::CreateQuad();

    while (!window.ShouldClose()) {
        Clock::Update();
        float deltaTime = Clock::GetDeltaTime();

        window.PollEvents();
        cameraController.OnUpdate(deltaTime);

        RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
        RenderCommand::Clear();

        Renderer::BeginScene(camera);

        glm::mat4 modelTriangle = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, 0.0f));
        Renderer::Submit(shader, triangle, modelTriangle);

        glm::mat4 modelQuad = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.0f, 0.0f));
        Renderer::Submit(shader, quad, modelQuad);

        Renderer::EndScene();

        window.SwapBuffers();
    }

    return 0;
}
