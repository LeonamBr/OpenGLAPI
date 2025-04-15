#include "OpenGLContext.h"
#include <iostream>

OpenGLContext::OpenGLContext(GLFWwindow* window)
    : m_Window(window) {}

void OpenGLContext::Init() {

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwMakeContextCurrent(m_Window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
}

void OpenGLContext::SwapBuffers() {
    glfwSwapBuffers(m_Window);
}

void OpenGLContext::Resize(int width, int height) {
    glViewport(0, 0, width, height);
}