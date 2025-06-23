
#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include "renderer/camera.h"
#include "event/event.h"
#include "core/keyCodes.h"
#include <GLFW/glfw3.h>

class CameraController {
public:
    CameraController(Camera& camera);

    void SetCamera(Camera& camera);
    void OnUpdate(float deltaTime);
    void OnKeyPressed(const KeyPressedEvent& e);
    void OnKeyReleased(const KeyReleasedEvent& e);
    void OnMouseMoved(const MouseMovedEvent& e);
    void OnScroll(const ScrollEvent& e);

private:
    void LockMouse();
    void UnlockMouse();

private:
    Camera& m_Camera;

    float m_MovementSpeed = 2.5f;
    float m_MouseSensitivity = 0.1f;
    float m_ZoomSensitivity = 1.0f;

    bool m_MoveForward = false;
    bool m_MoveBackward = false;
    bool m_MoveLeft = false;
    bool m_MoveRight = false;
    bool m_MoveIn = false;
    bool m_MoveOut = false;

    bool m_FirstMouse = true;
    float m_LastX = 0.0f;
    float m_LastY = 0.0f;

    bool m_MouseControlActive = false;
};

#endif