#ifndef ENGINE_WINDOW_SYSTEM_H
#define ENGINE_WINDOW_SYSTEM_H

#include <memory>
#include <RenderContext.h>
#include <OpenGLContext.h>
#include <GLFW/glfw3.h>
#include <EventBus.h>

class WindowSystem {
public:
    WindowSystem();
    ~WindowSystem();

    void Init(int width, int height, const char* title, EventBus& bus);
    void PollEvents();
    void SwapBuffers();
    bool ShouldClose() const;
    GLFWwindow* GetNativeWindow() const;

private:
    GLFWwindow* m_Window = nullptr;
    EventBus* m_Bus = nullptr;
    std::unique_ptr<RenderContext> m_Context;

    static void SetGLFWCallbacks(GLFWwindow* window);
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void CursorCallback(GLFWwindow* window, double xpos, double ypos);
    static void ResizeCallback(GLFWwindow* window, int width, int height);
    static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
};

#endif