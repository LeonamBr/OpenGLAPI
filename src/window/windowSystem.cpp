#include "WindowSystem.h"
#include <log.h>
#include <event.h>
#include <stdexcept>

WindowSystem::WindowSystem() {
    if (!glfwInit())
        throw std::runtime_error("Falha ao inicializar GLFW");
}

WindowSystem::~WindowSystem() {
    glfwTerminate();
}

void WindowSystem::Init(int width, int height, const char* title, EventBus& bus) {
    m_Bus = &bus;
    m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!m_Window)
        throw std::runtime_error("Falha ao criar a janela GLFW!");

    glfwSetWindowUserPointer(m_Window, this);
    SetGLFWCallbacks(m_Window);

    m_Context = std::make_unique<OpenGLContext>(m_Window);
    m_Context->Init();
}

void WindowSystem::PollEvents() {
    glfwPollEvents();
}

void WindowSystem::SwapBuffers() {
    m_Context->SwapBuffers();
}

bool WindowSystem::ShouldClose() const {
    return glfwWindowShouldClose(m_Window);
}

GLFWwindow* WindowSystem::GetNativeWindow() const {
    return m_Window;
}

void WindowSystem::SetGLFWCallbacks(GLFWwindow* window) {
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCursorPosCallback(window, CursorCallback);
    glfwSetFramebufferSizeCallback(window, ResizeCallback);
}

void WindowSystem::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    auto* self = static_cast<WindowSystem*>(glfwGetWindowUserPointer(window));
    if (!self || !self->m_Bus) return;

    if (action == GLFW_PRESS || action == GLFW_REPEAT)
        self->m_Bus->Emit(KeyPressedEvent{ key, action == GLFW_REPEAT });
    else if (action == GLFW_RELEASE)
        self->m_Bus->Emit(KeyReleasedEvent{ key });
}

void WindowSystem::CursorCallback(GLFWwindow* window, double xpos, double ypos) {
    auto* self = static_cast<WindowSystem*>(glfwGetWindowUserPointer(window));
    if (self && self->m_Bus)
        self->m_Bus->Emit(MouseMovedEvent{ (float)xpos, (float)ypos });
}

void WindowSystem::ResizeCallback(GLFWwindow* window, int width, int height) {
    auto* self = static_cast<WindowSystem*>(glfwGetWindowUserPointer(window));
    if (self && self->m_Bus) {
        self->m_Bus->Emit(WindowResizeEvent{ width, height });
        self->m_Context->Resize(width, height);
    }
}