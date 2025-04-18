#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "log.h"
#include "windowSystem.h"
#include "shader.h"
#include "eventbus.h"
#include "meshFactory.h"
#include "Camera.h"
#include "CameraController.h"
#include "macros.h"
#include "event.h"
#include "keyCodes.h"
#include "mouseKeyCodes.h"

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

Transform t1;
Transform t2;

void moveQuad(const KeyPressedEvent& e) {
    if (e.keycode == ENGINE_KEY_W)
        t1.position.y += 0.01f;
    else if (e.keycode == ENGINE_KEY_S)
        t1.position.y -= 0.01f;

    if (e.keycode == ENGINE_KEY_D)
        t1.position.x += 0.01f;
    else if (e.keycode == ENGINE_KEY_A)
        t1.position.x -= 0.01f;

    if (e.keycode == ENGINE_KEY_LEFT)
        t1.rotation.z += 1.0f;
    else if (e.keycode == ENGINE_KEY_RIGHT)
        t1.rotation.z -= 1.0f;
}

void scaleQuad(const ScrollEvent& e) {
    if (e.yoffset > 0) {
        t1.scale += glm::vec3(0.01f);
    } else if (e.yoffset < 0) {
        t1.scale -= glm::vec3(0.01f);
        t1.scale.x = std::max(t1.scale.x, 0.01f);
        t1.scale.y = std::max(t1.scale.y, 0.01f);
    }
}

int main() {
    Log::Init();
    EventBus bus;
    WindowSystem window;
    window.Init(800, 600, "Shader Test", bus);

    Shader shader("ColorTriangle", "assets/shader/shader.vertex", "assets/shader/basic.fragment");
    Mesh triangle = MeshFactory::CreateTriangle();

    Camera camera(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    CameraController cameraController(camera);

    t2.position.x = 0.6f;
    t2.rotation.z = -45.0f;
    t2.scale = glm::vec3(1.25f);

    BIND_EVENT(bus, KeyPressedEvent, moveQuad);
    BIND_EVENT(bus, ScrollEvent, scaleQuad);

    BIND_EVENT(bus, KeyPressedEvent, cameraController.OnKeyPressed);
    BIND_EVENT(bus, KeyReleasedEvent, cameraController.OnKeyReleased);
    BIND_EVENT(bus, MouseMovedEvent, cameraController.OnMouseMoved);
    BIND_EVENT(bus, ScrollEvent, cameraController.OnScroll);

    float lastFrameTime = 0.0f;

    glfwSetInputMode(window.GetNativeWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    while (!window.ShouldClose()) {
        float currentFrameTime = glfwGetTime();
        float deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        cameraController.OnUpdate(deltaTime);

        shader.Bind();

        glm::mat4 view = camera.GetViewMatrix();
        glm::mat4 projection = camera.GetProjectionMatrix();

        shader.SetMat4("u_View", view);
        shader.SetMat4("u_Projection", projection);

        shader.SetMat4("u_Model", t1.GetMatrix());
        triangle.Draw();

        window.PollEvents();
        window.SwapBuffers();
    }

    return 0;
}
