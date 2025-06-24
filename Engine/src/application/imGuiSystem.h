#ifndef IMGUISYSTEM_H
#define IMGUISYSTEM_H

#include <imgui.h>
#include <GLFW/glfw3.h>

class ImGuiSystem {
public:
    static void Init(GLFWwindow* window);
    static void BeginFrame();
    static void EndFrame();
    static void Shutdown();
};

#endif
