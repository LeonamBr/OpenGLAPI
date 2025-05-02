#ifndef WINDOW_SYSTEM_H
#define WINDOW_SYSTEM_H

#include <string>
#include "renderContext.h"
#include "openGLContext.h"
#include <GLFW/glfw3.h>
#include "eventbus.h"

class WindowSystem {
public:
    WindowSystem();
    ~WindowSystem();

    void Init(unsigned int width, unsigned int height, const std::string& title, EventBus& bus);
    void PollEvents();
    void SwapBuffers();

    bool ShouldClose() const;

    unsigned int GetWidth() const { return m_Data.Width; }
    unsigned int GetHeight() const { return m_Data.Height; }
    GLFWwindow* GetNativeWindow() const { return m_WindowHandle; }

private:
    void Shutdown();
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseMovedCallback(GLFWwindow* window, double xpos, double ypos);
    static void MouseScrolledCallback(GLFWwindow* window, double xoffset, double yoffset);
    static void WindowCloseCallback(GLFWwindow* window);

private:
    GLFWwindow* m_WindowHandle;
    RenderContext* m_RenderContext;

    struct WindowData {
        unsigned int Width, Height;
        std::string Title;
        EventBus* eventBus;
    } m_Data;
};

#endif