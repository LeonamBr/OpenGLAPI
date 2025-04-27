#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H

#include "renderContext.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGLContext : public RenderContext {
public:
    OpenGLContext(GLFWwindow* windowHandle);

    void Init() override;
    void SwapBuffers() override;

private:
    GLFWwindow* m_WindowHandle;
};

#endif