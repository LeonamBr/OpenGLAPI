#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "macros.h"
#include "core/log.h"
#include "window/windowSystem.h"
#include "renderer/shader.h"
#include "event/eventbus.h"
#include "renderer/meshFactory.h"
#include <event.h>
#include <keyCodes.h>

struct Transform {
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 rotation = glm::vec3(0.0f); // Euler angles in degrees
    glm::vec3 scale    = glm::vec3(0.1f);

    glm::mat4 GetMatrix() const {
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

void moveQuad(const KeyPressedEvent& e);
void scaleQuad(const ScrollEvent& e);

int main() {
    Log::Init();
    EventBus bus;
    WindowSystem window;
    window.Init(800, 600, "Shader Test", bus);
    BIND_EVENT(bus, KeyPressedEvent, moveQuad);
    BIND_EVENT(bus, ScrollEvent, scaleQuad);

    Shader shader("ColorTriangle", "assets/shader/basic.vertex", "assets/shader/basic.fragment");
    Mesh triangle = MeshFactory::CreateTriangle();



    while (!window.ShouldClose()) {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();

        shader.SetMat4("u_Model", t1.GetMatrix());
        triangle.Draw();

        window.PollEvents();
        window.SwapBuffers();
    }

    return 0;
}

void moveQuad(const KeyPressedEvent &e)
{

    if(e.keycode == ENGINE_KEY_W )
        t1.position.y += .01f;
    else if(e.keycode == ENGINE_KEY_S)
        t1.position.y -= .01f;
    if(e.keycode == ENGINE_KEY_D )
        t1.position.x += .01f;
    else if(e.keycode == ENGINE_KEY_A)
        t1.position.x -= .01f;

    if(e.keycode == ENGINE_KEY_LEFT)
        t1.rotation.z += 5.0f;
    else if(e.keycode == ENGINE_KEY_RIGHT)
        t1.rotation.z -= 5.0f;

}

void scaleQuad(const ScrollEvent &e)
{

    if(e.yoffset > 0){
        t1.scale.y += .01f;
        t1.scale.x += .01f;
    }
    else if(e.yoffset < 0){
        t1.scale.y -= .01f;
        t1.scale.x -= .01f;
    }

}
