#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, float aspectRatio, float nearClip, float farClip)
    : m_FOV(fov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip)
{
    m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
    UpdateViewMatrix();
}

void Camera::SetFocalPoint(const glm::vec3& focalPoint)
{
    m_FocalPoint = focalPoint;
    UpdateViewMatrix();
}

void Camera::SetDistance(float distance)
{
    m_Distance = distance;
    UpdateViewMatrix();
}

void Camera::SetRotation(float yaw, float pitch)
{
    m_Yaw = yaw;
    m_Pitch = pitch;
    UpdateViewMatrix();
}

void Camera::SetViewportSize(float width, float height)
{
    m_AspectRatio = width / height;
    m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
}

void Camera::UpdateViewMatrix()
{
    glm::vec3 direction;
    direction.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    direction.y = sin(glm::radians(m_Pitch));
    direction.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    direction = glm::normalize(direction);

    m_Position = m_FocalPoint - direction * m_Distance;
    m_ViewMatrix = glm::lookAt(m_Position, m_FocalPoint, m_Up);
}