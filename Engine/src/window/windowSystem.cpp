#include "windowSystem.h"
#include "log.h"
#include "macros.h"
#include "event.h"

WindowSystem::WindowSystem()
    : m_WindowHandle(nullptr), m_RenderContext(nullptr)
{
}

WindowSystem::~WindowSystem()
{
    Shutdown();
}

void WindowSystem::Init(unsigned int width, unsigned int height, const std::string& title, EventBus& bus)
{
    m_Data.Width = width;
    m_Data.Height = height;
    m_Data.Title = title;
    m_Data.eventBus = &bus;

    if (!glfwInit()) {
        LOG_CRITICAL("Could not initialize GLFW!");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_WindowHandle = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
    if (!m_WindowHandle) {
        LOG_CRITICAL("Failed to create GLFW window!");
        glfwTerminate();
        return;
    }

    m_RenderContext = new OpenGLContext(m_WindowHandle);
    m_RenderContext->Init();

    glfwSetWindowUserPointer(m_WindowHandle, &m_Data);

    glfwSetFramebufferSizeCallback(m_WindowHandle, FramebufferSizeCallback);
    glfwSetKeyCallback(m_WindowHandle, KeyCallback);
    glfwSetCursorPosCallback(m_WindowHandle, MouseMovedCallback);
    glfwSetScrollCallback(m_WindowHandle, MouseScrolledCallback);
    glfwSetWindowCloseCallback(m_WindowHandle, WindowCloseCallback);
}

void WindowSystem::PollEvents()
{
    glfwPollEvents();
}

void WindowSystem::SwapBuffers()
{
    m_RenderContext->SwapBuffers();
}

bool WindowSystem::ShouldClose() const
{
    return glfwWindowShouldClose(m_WindowHandle);
}

void WindowSystem::Shutdown()
{
    glfwDestroyWindow(m_WindowHandle);
    glfwTerminate();
}

void WindowSystem::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    data.Width = width;
    data.Height = height;
    glViewport(0, 0, width, height);

    WindowResizeEvent event(width, height);
    data.eventBus->Emit(event);
}

void WindowSystem::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    if (action == GLFW_PRESS) {
        KeyPressedEvent event(key);
        data.eventBus->Emit(event);
    }
    else if (action == GLFW_RELEASE) {
        KeyReleasedEvent event(key);
        data.eventBus->Emit(event);
    }
}

void WindowSystem::MouseMovedCallback(GLFWwindow* window, double xpos, double ypos)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    MouseMovedEvent event((float)xpos, (float)ypos);
    data.eventBus->Emit(event);
}

void WindowSystem::MouseScrolledCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    ScrollEvent event((float)xoffset, (float)yoffset);
    data.eventBus->Emit(event);
}

void WindowSystem::WindowCloseCallback(GLFWwindow* window)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    WindowCloseEvent event;
    data.eventBus->Emit(event);
}