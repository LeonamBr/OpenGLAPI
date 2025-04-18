#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
    Camera(float fov, float aspectRatio, float nearClip, float farClip);

    void SetPosition(const glm::vec3& position);
    const glm::vec3& GetPosition() const;

    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix() const;

    void ProcessMouseMovement(float xOffset, float yOffset);
    void ProcessMouseScroll(float yOffset);

private:
    void UpdateCameraVectors();

private:
    glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 m_Front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 m_Right = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 m_WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float m_Yaw = -90.0f;    // Olhando para -Z
    float m_Pitch = 0.0f;
    float m_Fov = 45.0f;

    float m_AspectRatio;
    float m_NearClip;
    float m_FarClip;
};

#endif // CAMERA_H
