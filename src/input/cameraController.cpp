#include "cameraController.h"
#include "keyCodes.h"
#include "mouseKeyCodes.h"
#include <glm/glm.hpp>

CameraController::CameraController(Camera& camera)
    : m_Camera(camera)
{
}

void CameraController::OnUpdate(float deltaTime)
{
    glm::vec3 focal = m_Camera.GetFocalPoint();

    glm::vec3 right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), glm::normalize(focal - m_Camera.GetPosition())));
    glm::vec3 forward = glm::normalize(focal - m_Camera.GetPosition());

    if (m_MoveForward)
        focal += glm::vec3(0.0f, m_MovementSpeed * deltaTime, 0.0f);
    if (m_MoveBackward)
        focal -= glm::vec3(0.0f, m_MovementSpeed * deltaTime, 0.0f);
    if (m_MoveLeft)
        focal -= right * m_MovementSpeed * deltaTime;
    if (m_MoveRight)
        focal += right * m_MovementSpeed * deltaTime;
    if (m_MoveIn)
        focal += forward * m_MovementSpeed * deltaTime;
    if (m_MoveOut)
        focal -= forward * m_MovementSpeed * deltaTime;

    m_Camera.SetFocalPoint(focal);
}

void CameraController::OnKeyPressed(const KeyPressedEvent& e)
{
    switch (e.keycode) {
    case ENGINE_KEY_W: m_MoveForward = true; break;
    case ENGINE_KEY_S: m_MoveBackward = true; break;
    case ENGINE_KEY_A: m_MoveLeft = true; break;
    case ENGINE_KEY_D: m_MoveRight = true; break;
    case ENGINE_KEY_E: m_MoveIn = true; break;
    case ENGINE_KEY_Q: m_MoveOut = true; break;
    }
}

void CameraController::OnKeyReleased(const KeyReleasedEvent& e)
{
    switch (e.keycode) {
    case ENGINE_KEY_W: m_MoveForward = false; break;
    case ENGINE_KEY_S: m_MoveBackward = false; break;
    case ENGINE_KEY_A: m_MoveLeft = false; break;
    case ENGINE_KEY_D: m_MoveRight = false; break;
    case ENGINE_KEY_E: m_MoveIn = false; break;
    case ENGINE_KEY_Q: m_MoveOut = false; break;
    }
}

void CameraController::OnMouseMoved(const MouseMovedEvent& e)
{
    if (m_FirstMouse)
    {
        m_LastX = e.x;
        m_LastY = e.y;
        m_FirstMouse = false;
    }

    float xOffset = (e.x - m_LastX) * m_MouseSensitivity;
    float yOffset = (m_LastY - e.y) * m_MouseSensitivity;
    m_LastX = e.x;
    m_LastY = e.y;

    float yaw = m_Camera.GetYaw() + xOffset;
    float pitch = m_Camera.GetPitch() + yOffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    m_Camera.SetRotation(yaw, pitch);
}

void CameraController::OnScroll(const ScrollEvent& e)
{
    float distance = glm::length(m_Camera.GetPosition() - m_Camera.GetFocalPoint());
    distance -= e.yoffset * m_ZoomSensitivity;
    if (distance < 1.0f)
        distance = 1.0f;
    if (distance > 100.0f)
        distance = 100.0f;

    m_Camera.SetDistance(distance);
}
