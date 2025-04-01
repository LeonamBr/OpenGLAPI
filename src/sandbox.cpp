#include <string>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void vertexBuffer();

const GLuint width = 800;
const GLuint height = 600;
GLuint VBO, VAO, EBO;

std::string vertex = R"(#version 330 core
                        layout (location = 0) in vec3 aPos;

                        void main()
                        {
                          gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
                          })";

int main (int argc, char** argv)
{

    if(!glfwInit())
    {
        std::cout << "erro ao iniciar glfw" << std::endl;
    }

    glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Hello window", nullptr, nullptr);

    if(!window)
    {
        std::cout << "Erro ao criar janela" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    


    while(!glfwWindowShouldClose(window)) 
    {

        glClearColor(0.95f, 0.0f, 0.95f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();  

    }

    glfwTerminate();

    return 0;

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 

void vertexBuffer()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    }; 
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
}
