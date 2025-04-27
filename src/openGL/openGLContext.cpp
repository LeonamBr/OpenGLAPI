#include "openGLContext.h"
#include "log.h"

OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
    : m_WindowHandle(windowHandle)
{
}

void OpenGLContext::Init()
{
    glfwMakeContextCurrent(m_WindowHandle);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    LOG_INFO("OpenGL Info:");
    LOG_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
    LOG_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
    LOG_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
}

void OpenGLContext::SwapBuffers()
{
    glfwSwapBuffers(m_WindowHandle);
}
