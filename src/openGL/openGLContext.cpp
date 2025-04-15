#include "OpenGLContext.h"
#include <log.h>
#include <iostream>

OpenGLContext::OpenGLContext(GLFWwindow* window)
    : m_Window(window) {}

void OpenGLContext::Init() {

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwMakeContextCurrent(m_Window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    LOG_INFO("OpenGL Info:");
	LOG_INFO("  Vendor: {0}", (char*)glGetString(GL_VENDOR));
	LOG_INFO("  Renderer: {0}", (char*)glGetString(GL_RENDERER));
	LOG_INFO("  Version: {0}", (char*)glGetString(GL_VERSION));
}

void OpenGLContext::SwapBuffers() {
    glfwSwapBuffers(m_Window);
}

void OpenGLContext::Resize(int width, int height) {
    glViewport(0, 0, width, height);
}