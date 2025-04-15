#ifndef ENGINE_OPENGL_CONTEXT_H
#define ENGINE_OPENGL_CONTEXT_H

#include <RenderContext.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGLContext : public RenderContext {
public:
    OpenGLContext(GLFWwindow* window);
    void Init() override;
    void SwapBuffers() override;
    void Resize(int width, int height) override;

private:
    GLFWwindow* m_Window;
};

#endif