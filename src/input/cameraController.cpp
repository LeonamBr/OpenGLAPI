#include "CameraController.h"
#include <glm/glm.hpp>
#include "keyCodes.h"
#include "mouseKeyCodes.h"

CameraController::CameraController(Camera& camera)
    : m_Camera(camera) {}

void CameraController::OnUpdate(float dt) {
    glm::vec3 pos = m_Camera.GetPosition();
    glm::vec3 forward = glm::normalize(glm::vec3(m_Camera.GetViewMatrix()[0][2], m_Camera.GetViewMatrix()[1][2], m_Camera.GetViewMatrix()[2][2])) * -1.0f;
    glm::vec3 right = glm::normalize(glm::vec3(m_Camera.GetViewMatrix()[0][0], m_Camera.GetViewMatrix()[1][0], m_Camera.GetViewMatrix()[2][0]));

    if (m_MoveForward)
        pos += forward * m_MovementSpeed * dt;
    if (m_MoveBackward)
        pos -= forward * m_MovementSpeed * dt;
    if (m_MoveLeft)
        pos -= right * m_MovementSpeed * dt;
    if (m_MoveRight)
        pos += right * m_MovementSpeed * dt;

    m_Camera.SetPosition(pos);
}

void CameraController::OnKeyPressed(const KeyPressedEvent& e) {
    if (e.keycode == ENGINE_KEY_W)
        m_MoveForward = true;
    else if (e.keycode == ENGINE_KEY_S)
        m_MoveBackward = true;
    else if (e.keycode == ENGINE_KEY_A)
        m_MoveLeft = true;
    else if (e.keycode == ENGINE_KEY_D)
        m_MoveRight = true;
}

void CameraController::OnKeyReleased(const KeyReleasedEvent& e) {
    if (e.key == ENGINE_KEY_W)
        m_MoveForward = false;
    else if (e.key == ENGINE_KEY_S)
        m_MoveBackward = false;
    else if (e.key == ENGINE_KEY_A)
        m_MoveLeft = false;
    else if (e.key == ENGINE_KEY_D)
        m_MoveRight = false;
}

void CameraController::OnMouseMoved(const MouseMovedEvent& e) {
    if (m_FirstMouse) {
        m_LastX = e.x;
        m_LastY = e.y;
        m_FirstMouse = false;
    }

    float xOffset = e.x - m_LastX;
    float yOffset = m_LastY - e.y; // Invertido, porque y cresce de baixo pra cima na tela OpenGL

    m_LastX = e.x;
    m_LastY = e.y;

    m_Camera.ProcessMouseMovement(xOffset * m_MouseSensitivity, yOffset * m_MouseSensitivity);
}

void CameraController::OnScroll(const ScrollEvent& e) {
    m_Camera.ProcessMouseScroll(e.yoffset);
}
