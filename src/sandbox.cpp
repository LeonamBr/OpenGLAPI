#include "shaderLibrary.h"
#include "meshFactory.h"
#include "macros.h"
#include "eventbus.h"
#include "windowSystem.h"
#include "camera.h"
#include "cameraController.h"
#include "log.h"
#include "inputmanager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

EventBus bus;
WindowSystem window;
ShaderLibrary shaderLibrary;

std::shared_ptr<Mesh> quad;
std::shared_ptr<Mesh> triangle;
Camera camera(45.0f, 800.0f/600.0f, 0.1f, 100.0f);
CameraController cameraController(camera);

glm::vec3 camPosition(0.0f, 0.0f, 3.0f);
glm::mat4 projection;
glm::mat4 view;

struct Transform
{
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 rotation = glm::vec3(0.0f);
    glm::vec3 scale = glm::vec3(1.0f);

    glm::mat4 GetMatrix() const
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);

        model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

        model = glm::scale(model, scale);
        return model;
    }
};

Transform model1;
Transform model2;

void moveQuad(const KeyPressedEvent& e) {
    if (e.keycode == ENGINE_KEY_W)
        model1.position += .01;
    else if (e.keycode == ENGINE_KEY_S)
        model1.position.y -= 0.01f;

    if (e.keycode == ENGINE_KEY_D)
        model1.position.x += 0.01f;
    else if (e.keycode == ENGINE_KEY_A)
        model1.position.x -= 0.01f;

    if (e.keycode == ENGINE_KEY_LEFT)
        model1.rotation.z += 1.0f;
    else if (e.keycode == ENGINE_KEY_RIGHT)
        model1.rotation.z -= 1.0f;

    if(e.keycode == ENGINE_KEY_ESCAPE)
        window.~WindowSystem();
}

void scaleQuad(const ScrollEvent& e) {
    if (e.yoffset > 0) {
        model1.scale += glm::vec3(0.01f);
    } else if (e.yoffset < 0) {
        model1.scale -= glm::vec3(0.01f);
        model1.scale.x = std::max(model1.scale.x, 0.01f);
        model1.scale.y = std::max(model1.scale.y, 0.01f);
    }
}

int main() {
    Log::Init();
    window.Init(800, 600, "Shader Test", bus);

    // Shader via ShaderLibrary
    shaderLibrary.Load("basic", "assets/shader/basic.vertex", "assets/shader/basic.fragment");
    shaderLibrary.Load("model", "assets/shader/shader.vertex", "assets/shader/basic.fragment");

    // Criar meshes
    quad = MeshFactory::CreateQuad();
    triangle = MeshFactory::CreateTriangle();

    projection = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f);

    // Registrar eventos
    BIND_EVENT(bus, KeyPressedEvent, moveQuad);
    BIND_EVENT(bus, ScrollEvent, scaleQuad);

    BIND_EVENT(bus, KeyPressedEvent, cameraController.OnKeyPressed);
    BIND_EVENT(bus, KeyReleasedEvent, cameraController.OnKeyReleased);
    BIND_EVENT(bus, MouseMovedEvent, cameraController.OnMouseMoved);
    BIND_EVENT(bus, ScrollEvent, cameraController.OnScroll);

    float lastFrameTime = 0.0f;

    // Loop de execução
    while (!window.ShouldClose()) {
        
        float currentFrameTime = glfwGetTime();
        float deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
        cameraController.OnUpdate(deltaTime);

        // Atualiza matrices
        view = camera.GetViewMatrix();
        projection = camera.GetProjectionMatrix();

        // Renderização
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        auto shader = shaderLibrary.Get("model");
        shader->Bind();
        shader->SetMat4("u_Projection", projection);
        shader->SetMat4("u_View", view);
        shader->SetMat4("u_Model", model1.GetMatrix());

        quad->Draw();

        shader->SetMat4("u_Model", model2.GetMatrix());

        triangle->Draw();

        window.PollEvents();
        window.SwapBuffers();
    }

    return 0;
}
