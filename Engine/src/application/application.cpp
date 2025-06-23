#include "Application.h"
#include "renderCommand.h"
#include "log.h"
#include "event/event.h"

Application::Application() {
    assert(!s_Instance && "Application já foi instanciada!");
    s_Instance = this;
}

void Application::Set(Application* instance) {
    s_Instance = instance;
}

Application& Application::Get() {
    assert(s_Instance && "Application não foi instanciada!");
    return *s_Instance;
}

void Application::RegisterInterface(const std::string& name, std::unique_ptr<Interface> iface) {
    m_Registry.Register(name, std::move(iface));
}

void Application::Run() {
    
    m_Window.Init(1280, 720, "Caramelo Engine", m_eventBus);
    BIND_EVENT(m_eventBus, WindowCloseEvent, OnWindowClose);
    BIND_EVENT(m_eventBus, WindowResizeEvent, OnWindowResize);
    BIND_EVENT(m_eventBus, KeyPressedEvent, OnKeyPressed);
    BIND_EVENT(m_eventBus, KeyReleasedEvent, OnKeyReleased);
    BIND_EVENT(m_eventBus, MouseMovedEvent, OnMouseMoved);
    BIND_EVENT(m_eventBus, ScrollEvent, OnMouseScrolled);
    Renderer::Init();
    OnInit();
    Clock::Init();

    static float timer = 0.0f;
    static int frames = 0;

    m_Registry.OnAttachAll();

    while (!m_Window.ShouldClose()) {
        Clock::Update();
        float dt = Clock::GetDeltaTime();

        timer += dt;
        frames++;

        if (timer >= 1.0f) {
            LOG_INFO("FPS: {0}", frames);
            frames = 0;
            timer = 0.0f;
        }

        m_Window.PollEvents();
        m_CameraController.OnUpdate(dt);

        m_Registry.UpdateAll(dt);

        RenderCommand::SetClearColor({0.1f, 0.1, 0.1, 1.0f});
        RenderCommand::Clear();
        Renderer::BeginScene(m_Camera);

        m_Registry.RenderAll();

        Renderer::EndScene();
        m_Window.SwapBuffers();
    }

    m_Registry.OnDetachAll();
}

void Application::SetCamera(Camera& camera)
{
    m_Camera = camera;
}

void Application::OnWindowClose(const WindowCloseEvent &)
{
    LOG_INFO("Fechando janela...");
}

void Application::OnWindowResize(const WindowResizeEvent& e) {
    m_Camera.SetViewportSize((float)e.width, (float)e.height);
}

void Application::OnKeyPressed(const KeyPressedEvent& e) {
    m_CameraController.OnKeyPressed(e);
}

void Application::OnKeyReleased(const KeyReleasedEvent& e) {
    m_CameraController.OnKeyReleased(e);
}

void Application::OnMouseMoved(const MouseMovedEvent& e) {
    m_CameraController.OnMouseMoved(e);
}

void Application::OnMouseScrolled(const ScrollEvent& e) {
    m_CameraController.OnScroll(e);
}