#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <string>
#include <cassert>
#include "engine/engine.h"

class Application {
public:
    Application();
    virtual ~Application() = default;

    void Run();
    virtual void OnInit() = 0;

    void RegisterInterface(const std::string& name, std::unique_ptr<Interface> iface);

    static Application& Get();
    static void Set(Application* instance);
    static EventBus& getEventBus() {return Application::Get().getEventBus();}
    static const Camera& GetCamera() { return Get().m_Camera; }
    void SetCamera(Camera& camera);

private:
    void OnWindowClose(const WindowCloseEvent&);
    void OnWindowResize(const WindowResizeEvent& e);
    void OnKeyPressed(const KeyPressedEvent& e);
    void OnKeyReleased(const KeyReleasedEvent& e);
    void OnMouseMoved(const MouseMovedEvent& e);
    void OnMouseScrolled(const ScrollEvent& e);

protected:
    WindowSystem m_Window;
    Camera m_Camera = Camera(45.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
    CameraController m_CameraController = CameraController(m_Camera);
    InterfaceRegistry m_Registry;
    EventBus m_eventBus;

private:
    static inline Application* s_Instance = nullptr;
};

#endif