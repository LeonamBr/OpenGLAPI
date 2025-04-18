#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include "Camera.h"
#include "event.h"

class CameraController {
public:
    CameraController(Camera& camera);

    void OnUpdate(float dt);
    void OnKeyPressed(const KeyPressedEvent& e);
    void OnKeyReleased(const KeyReleasedEvent& e);
    void OnMouseMoved(const MouseMovedEvent& e);
    void OnScroll(const ScrollEvent& e);

private:
    Camera& m_Camera;
    float m_MovementSpeed = 2.5f;
    float m_MouseSensitivity = 0.1f;
    bool m_FirstMouse = true;
    float m_LastX = 400.0f; // inicializar no meio da tela (800/2)
    float m_LastY = 300.0f; // inicializar no meio da tela (600/2)

    // Flags para controle contínuo
    bool m_MoveForward = false;
    bool m_MoveBackward = false;
    bool m_MoveLeft = false;
    bool m_MoveRight = false;
};

#endif // CAMERA_CONTROLLER_H
