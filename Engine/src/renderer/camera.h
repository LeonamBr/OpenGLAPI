#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
    Camera(float fov, float aspectRatio, float nearClip, float farClip);

    const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
    const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }

    const glm::vec3& GetPosition() const { return m_Position; }
    const glm::vec3& GetFocalPoint() const { return m_FocalPoint; }
    float GetYaw() const { return m_Yaw; }
    float GetPitch() const { return m_Pitch; }

    void SetFocalPoint(const glm::vec3& focalPoint);
    void SetDistance(float distance);
    void SetRotation(float yaw, float pitch);

    void SetViewportSize(float width, float height);


private:
    void UpdateViewMatrix();

private:
    glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
    glm::vec3 m_FocalPoint = { 0.0f, 0.0f, 0.0f };
    glm::vec3 m_Up = { 0.0f, 1.0f, 0.0f };

    float m_Yaw = -90.0f;
    float m_Pitch = 0.0f;

    float m_Distance = 3.0f;

    float m_FOV;
    float m_AspectRatio;
    float m_NearClip;
    float m_FarClip;

    glm::mat4 m_ViewMatrix;
    glm::mat4 m_ProjectionMatrix;
};

#endif