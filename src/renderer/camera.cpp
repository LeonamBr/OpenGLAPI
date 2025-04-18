#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, float aspectRatio, float nearClip, float farClip)
    : m_Fov(fov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip) {}

void Camera::SetPosition(const glm::vec3& position) {
    m_Position = position;
}

const glm::vec3& Camera::GetPosition() const {
    return m_Position;
}

glm::mat4 Camera::GetViewMatrix() const {
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

glm::mat4 Camera::GetProjectionMatrix() const {
    return glm::perspective(glm::radians(m_Fov), m_AspectRatio, m_NearClip, m_FarClip);
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset) {
    const float sensitivity = 0.5f;
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    m_Yaw += xOffset;
    m_Pitch += yOffset;

    // Limitar o pitch para evitar flip da câmera
    if (m_Pitch > 89.0f)
        m_Pitch = 89.0f;
    if (m_Pitch < -89.0f)
        m_Pitch = -89.0f;

    UpdateCameraVectors();
}

void Camera::ProcessMouseScroll(float yOffset) {
    m_Fov -= yOffset;
    if (m_Fov < 1.0f)
        m_Fov = 1.0f;
    if (m_Fov > 90.0f)
        m_Fov = 90.0f;
}

void Camera::UpdateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Front = glm::normalize(front);

    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
    m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}
