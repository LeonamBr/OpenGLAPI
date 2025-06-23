// ==== Macros.h ====

#ifndef ENGINE_EVENT_MACROS_H
#define ENGINE_EVENT_MACROS_H

#include <eventbus.h>

#define REGISTER_EVENT(fn) [](const auto& e) { fn(e); }

#define LOG_EVENT_AS_STRING() [](const auto& e) { LOG_INFO("Evento: {}", ToString(e)); }

#define BIND_EVENT(bus, type, handler) \
    bus.Subscribe<type>([&](const type& e) { handler(e); })

#endif

// ===== windowSystem.h =====

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

// ==== clock.h ====

#ifndef CLOCK_H
#define CLOCK_H

#include <GLFW/glfw3.h>

class Clock
{
public:
    static void Init()
    {
        m_LastTime = glfwGetTime();
        m_CurrentTime = m_LastTime;
        m_DeltaTime = 0.0f;
    }

    static void Update()
    {
        m_CurrentTime = glfwGetTime();
        m_DeltaTime = static_cast<float>(m_CurrentTime - m_LastTime);
        m_LastTime = m_CurrentTime;
    }

    static double GetTime()
    {
        return m_CurrentTime;
    }

    static float GetTimef()
    {
        return static_cast<float>(m_CurrentTime);
    }

    static float GetDeltaTime()
    {
        return m_DeltaTime;
    }

private:
    static inline double m_CurrentTime = 0.0;
    static inline double m_LastTime = 0.0;
    static inline float m_DeltaTime = 0.0f;
};

#endif

// ==== keyCodesUtils.h ====

#ifndef ENGINE_KEYCODE_UTILS_H
#define ENGINE_KEYCODE_UTILS_H

#include <string>
#include <sstream>
#include "KeyCodes.h"

inline std::string KeyCodeToString(int keycode)
{
    switch (keycode)
    {
        // Alfabeto
        case ENGINE_KEY_A: return "A";
        case ENGINE_KEY_B: return "B";
        case ENGINE_KEY_C: return "C";
        case ENGINE_KEY_D: return "D";
        case ENGINE_KEY_E: return "E";
        case ENGINE_KEY_F: return "F";
        case ENGINE_KEY_G: return "G";
        case ENGINE_KEY_H: return "H";
        case ENGINE_KEY_I: return "I";
        case ENGINE_KEY_J: return "J";
        case ENGINE_KEY_K: return "K";
        case ENGINE_KEY_L: return "L";
        case ENGINE_KEY_M: return "M";
        case ENGINE_KEY_N: return "N";
        case ENGINE_KEY_O: return "O";
        case ENGINE_KEY_P: return "P";
        case ENGINE_KEY_Q: return "Q";
        case ENGINE_KEY_R: return "R";
        case ENGINE_KEY_S: return "S";
        case ENGINE_KEY_T: return "T";
        case ENGINE_KEY_U: return "U";
        case ENGINE_KEY_V: return "V";
        case ENGINE_KEY_W: return "W";
        case ENGINE_KEY_X: return "X";
        case ENGINE_KEY_Y: return "Y";
        case ENGINE_KEY_Z: return "Z";

        // Números
        case ENGINE_KEY_0: return "0";
        case ENGINE_KEY_1: return "1";
        case ENGINE_KEY_2: return "2";
        case ENGINE_KEY_3: return "3";
        case ENGINE_KEY_4: return "4";
        case ENGINE_KEY_5: return "5";
        case ENGINE_KEY_6: return "6";
        case ENGINE_KEY_7: return "7";
        case ENGINE_KEY_8: return "8";
        case ENGINE_KEY_9: return "9";

        // Pontuação
        case ENGINE_KEY_SPACE: return "Space";
        case ENGINE_KEY_APOSTROPHE: return "'";
        case ENGINE_KEY_COMMA: return ",";
        case ENGINE_KEY_MINUS: return "-";
        case ENGINE_KEY_PERIOD: return ".";
        case ENGINE_KEY_SLASH: return "/";
        case ENGINE_KEY_SEMICOLON: return ";";
        case ENGINE_KEY_EQUAL: return "=";
        case ENGINE_KEY_LEFT_BRACKET: return "[";
        case ENGINE_KEY_BACKSLASH: return "\\";
        case ENGINE_KEY_RIGHT_BRACKET: return "]";
        case ENGINE_KEY_GRAVE_ACCENT: return "`";

        // Especiais
        case ENGINE_KEY_ENTER: return "Enter";
        case ENGINE_KEY_TAB: return "Tab";
        case ENGINE_KEY_BACKSPACE: return "Backspace";
        case ENGINE_KEY_ESCAPE: return "Escape";
        case ENGINE_KEY_INSERT: return "Insert";
        case ENGINE_KEY_DELETE: return "Delete";
        case ENGINE_KEY_HOME: return "Home";
        case ENGINE_KEY_END: return "End";
        case ENGINE_KEY_PAGE_UP: return "Page Up";
        case ENGINE_KEY_PAGE_DOWN: return "Page Down";
        case ENGINE_KEY_CAPS_LOCK: return "Caps Lock";
        case ENGINE_KEY_SCROLL_LOCK: return "Scroll Lock";
        case ENGINE_KEY_NUM_LOCK: return "Num Lock";
        case ENGINE_KEY_PRINT_SCREEN: return "Print Screen";
        case ENGINE_KEY_PAUSE: return "Pause";

        // Setas
        case ENGINE_KEY_LEFT: return "Arrow Left";
        case ENGINE_KEY_RIGHT: return "Arrow Right";
        case ENGINE_KEY_UP: return "Arrow Up";
        case ENGINE_KEY_DOWN: return "Arrow Down";

        // F1–F25
        case ENGINE_KEY_F1: return "F1";
        case ENGINE_KEY_F2: return "F2";
        case ENGINE_KEY_F3: return "F3";
        case ENGINE_KEY_F4: return "F4";
        case ENGINE_KEY_F5: return "F5";
        case ENGINE_KEY_F6: return "F6";
        case ENGINE_KEY_F7: return "F7";
        case ENGINE_KEY_F8: return "F8";
        case ENGINE_KEY_F9: return "F9";
        case ENGINE_KEY_F10: return "F10";
        case ENGINE_KEY_F11: return "F11";
        case ENGINE_KEY_F12: return "F12";
        case ENGINE_KEY_F13: return "F13";
        case ENGINE_KEY_F14: return "F14";
        case ENGINE_KEY_F15: return "F15";
        case ENGINE_KEY_F16: return "F16";
        case ENGINE_KEY_F17: return "F17";
        case ENGINE_KEY_F18: return "F18";
        case ENGINE_KEY_F19: return "F19";
        case ENGINE_KEY_F20: return "F20";
        case ENGINE_KEY_F21: return "F21";
        case ENGINE_KEY_F22: return "F22";
        case ENGINE_KEY_F23: return "F23";
        case ENGINE_KEY_F24: return "F24";
        case ENGINE_KEY_F25: return "F25";

        // Teclado numérico
        case ENGINE_KEY_KP_0: return "NumPad 0";
        case ENGINE_KEY_KP_1: return "NumPad 1";
        case ENGINE_KEY_KP_2: return "NumPad 2";
        case ENGINE_KEY_KP_3: return "NumPad 3";
        case ENGINE_KEY_KP_4: return "NumPad 4";
        case ENGINE_KEY_KP_5: return "NumPad 5";
        case ENGINE_KEY_KP_6: return "NumPad 6";
        case ENGINE_KEY_KP_7: return "NumPad 7";
        case ENGINE_KEY_KP_8: return "NumPad 8";
        case ENGINE_KEY_KP_9: return "NumPad 9";
        case ENGINE_KEY_KP_DECIMAL: return "NumPad .";
        case ENGINE_KEY_KP_DIVIDE: return "NumPad /";
        case ENGINE_KEY_KP_MULTIPLY: return "NumPad *";
        case ENGINE_KEY_KP_SUBTRACT: return "NumPad -";
        case ENGINE_KEY_KP_ADD: return "NumPad +";
        case ENGINE_KEY_KP_ENTER: return "NumPad Enter";
        case ENGINE_KEY_KP_EQUAL: return "NumPad =";

        // Modificadores
        case ENGINE_KEY_LEFT_SHIFT: return "Left Shift";
        case ENGINE_KEY_RIGHT_SHIFT: return "Right Shift";
        case ENGINE_KEY_LEFT_CONTROL: return "Left Ctrl";
        case ENGINE_KEY_RIGHT_CONTROL: return "Right Ctrl";
        case ENGINE_KEY_LEFT_ALT: return "Left Alt";
        case ENGINE_KEY_RIGHT_ALT: return "Right Alt";
        case ENGINE_KEY_LEFT_SUPER: return "Left Super";
        case ENGINE_KEY_RIGHT_SUPER: return "Right Super";
        case ENGINE_KEY_MENU: return "Menu";

        default:
            return "Unknown(" + std::to_string(keycode) + ")";
    }
}

#endif

// ==== camera.h ====

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
    Camera(float fov, float aspectRatio, float nearClip, float farClip);

    const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
    const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }

    const glm::vec3& GetPosition() const { return m_Position; }
    const glm::vec3& GetFocalPoint() const { return m_FocalPoint; }
    float GetYaw() const { return m_Yaw; }
    float GetPitch() const { return m_Pitch; }

    void SetFocalPoint(const glm::vec3& focalPoint);
    void SetDistance(float distance);
    void SetRotation(float yaw, float pitch);

    void SetViewportSize(float width, float height);


private:
    void UpdateViewMatrix();

private:
    glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
    glm::vec3 m_FocalPoint = { 0.0f, 0.0f, 0.0f };
    glm::vec3 m_Up = { 0.0f, 1.0f, 0.0f };

    float m_Yaw = -90.0f;
    float m_Pitch = 0.0f;

    float m_Distance = 3.0f;

    float m_FOV;
    float m_AspectRatio;
    float m_NearClip;
    float m_FarClip;

    glm::mat4 m_ViewMatrix;
    glm::mat4 m_ProjectionMatrix;
};

#endif

/// ==== mesh.h ====

#ifndef MESH_H
#define MESH_H

#include <memory>
#include "vertexArray.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "bufferLayout.h"

class Mesh {
public:
    Mesh(float* vertices, uint32_t vertexSize, const BufferLayout& layout,
         uint32_t* indices = nullptr, uint32_t indexCount = 0);
    ~Mesh() = default;

    void Draw() const;

    const std::shared_ptr<VertexArray>& GetVertexArray() const { return m_VertexArray; }

private:
    std::shared_ptr<VertexArray> m_VertexArray;
    std::shared_ptr<VertexBuffer> m_VertexBuffer;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
    uint32_t m_IndexCount = 0;
};

#endif

// ==== meshfactory.h ====

#ifndef MESH_FACTORY_H
#define MESH_FACTORY_H

#include <memory>
#include "mesh.h"

class MeshFactory {
public:
    static std::shared_ptr<Mesh> CreateTriangle();
    static std::shared_ptr<Mesh> CreateQuad();
    static std::shared_ptr<Mesh> CreateTexturedQuad();
    static std::shared_ptr<Mesh> CreateCube();
};

#endif

// ==== materialLibrary ====

#ifndef MATERIAL_LIBRARY_H
#define MATERIAL_LIBRARY_H

#include "material.h"
#include <unordered_map>
#include <string>
#include <memory>

class MaterialLibrary {
public:
    void Add(const std::string& name, const std::shared_ptr<Material>& material);
    std::shared_ptr<Material> Get(const std::string& name);
    bool Exists(const std::string& name) const;

private:
    std::unordered_map<std::string, std::shared_ptr<Material>> m_Materials;
};

#endif

// ==== renderCommand.h ====

#ifndef RENDER_COMMAND_H
#define RENDER_COMMAND_H

#include <glm/glm.hpp>
#include "vertexArray.h"

class RenderCommand {
public:
    static void Init();
    static void SetClearColor(const glm::vec4& color);
    static void Clear();
    static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount = 0);
};

#endif

// ==== renderContext.h ====

#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

class RenderContext {
public:
    virtual ~RenderContext() = default;

    virtual void Init() = 0;
    virtual void SwapBuffers() = 0;
};

#endif

// ==== renderer.h ====

#ifndef RENDERER_H
#define RENDERER_H

#include "camera.h"
#include "shader.h"
#include "mesh.h"
#include "material.h"
#include <glm/glm.hpp>
#include <memory>

class Renderer {
public:
    static void Init();

    static void BeginScene(const Camera& camera);
    static void EndScene();

    static void Submit(std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh, const glm::mat4& modelMatrix);
    static void Submit(std::shared_ptr<Shader> shader, std::shared_ptr<Mesh> mesh, const glm::mat4& modelMatrix);
    static void SubmitSkybox(std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh, const Camera& camera);

private:
    struct SceneData {
        glm::mat4 ViewMatrix;
        glm::mat4 ProjectionMatrix;
        glm::mat4 ViewProjectionMatrix;
    };

    static SceneData s_SceneData;
};

#endif

// ==== Sahder.h ====

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include <glad/glad.h>

class Shader {
public:
    Shader() = default;
    Shader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVec3(const std::string& name, const glm::vec3& value) const;
    void SetVec4(const std::string& name, const glm::vec4& value) const;
    void SetMat4(const std::string& name, const glm::mat4& value) const;

    bool Reload();
    bool IsValid() const;

    const std::string& GetName() const { return m_Name; }

private:
    static std::string ReadFile(const std::string& path);
    static std::string PreprocessShader(const std::string& source, const std::string& parentDir);

    uint32_t CompileShader(uint32_t type, const std::string& source);
    bool Compile(const std::string& vertexSource, const std::string& fragmentSource);
    int GetUniformLocation(const std::string& name) const;

private:
    mutable std::unordered_map<std::string, int> m_UniformLocationCache;

    uint32_t m_RendererID = 0;
    std::string m_Name;
    std::string m_VertexPath;
    std::string m_FragmentPath;
    bool m_IsValid = false;
};

#endif

//==== shaderLibrary.h ====

#ifndef SHADER_LIBRARY_H
#define SHADER_LIBRARY_H

#include <string>
#include <unordered_map>
#include <memory>
#include "shader.h"

class ShaderLibrary {
public:
    ShaderLibrary() = default;
    ~ShaderLibrary() = default;

    void Add(const std::shared_ptr<Shader>& shader);
    std::shared_ptr<Shader> Load(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
    std::shared_ptr<Shader> Get(const std::string& name);

    bool Exists(const std::string& name) const;

private:
    std::unordered_map<std::string, std::shared_ptr<Shader>> m_Shaders;
};

#endif // SHADER_LIBRARY_H


// ==== vertexArray.h ====

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <memory>
#include <vector>
#include <cstdint>
#include <string>

#include "vertexBuffer.h"
#include "indexBuffer.h"

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

    void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
    void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);

    const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }
    const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }

private:
    void ConfigureAttribute(uint32_t index, const BufferElement& element, uint32_t stride);

private:
    uint32_t m_RendererID = 0;
    uint32_t m_VertexAttribIndex = 0;
    std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
};

#endif

// ==== vertexBuffer.h ====

#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <cstdint>
#include "bufferLayout.h"

class VertexBuffer {
public:
    VertexBuffer(float* data, uint32_t size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

    void SetLayout(const BufferLayout& layout);
    const BufferLayout& GetLayout() const;

private:
    uint32_t m_RendererID = 0;
    BufferLayout m_Layout;
};

#endif

// ==== openGLContext.h ====

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

// ==== cameraController.h ====


#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include "camera.h"
#include "event.h"
#include "keyCodes.h"
#include <GLFW/glfw3.h>

class CameraController {
public:
    CameraController(Camera& camera);

    void OnUpdate(float deltaTime);
    void OnKeyPressed(const KeyPressedEvent& e);
    void OnKeyReleased(const KeyReleasedEvent& e);
    void OnMouseMoved(const MouseMovedEvent& e);
    void OnScroll(const ScrollEvent& e);

private:
    void LockMouse();
    void UnlockMouse();

private:
    Camera& m_Camera;

    float m_MovementSpeed = 2.5f;
    float m_MouseSensitivity = 0.1f;
    float m_ZoomSensitivity = 1.0f;

    bool m_MoveForward = false;
    bool m_MoveBackward = false;
    bool m_MoveLeft = false;
    bool m_MoveRight = false;
    bool m_MoveIn = false;
    bool m_MoveOut = false;

    bool m_FirstMouse = true;
    float m_LastX = 0.0f;
    float m_LastY = 0.0f;

    bool m_MouseControlActive = false;
};

#endif

// ==== bufferLayout.h ====

#ifndef BUFFER_LAYOUT_H
#define BUFFER_LAYOUT_H

#include <string>
#include <vector>
#include <cstdint>
#include <initializer_list>
#include <cassert>


enum class ShaderDataType {
    None = 0, Float, Float2, Float3, Float4,
    Mat3, Mat4,
    Int, Int2, Int3, Int4,
    Bool
};

static uint32_t ShaderDataTypeSize(ShaderDataType type) {
    switch (type) {
        case ShaderDataType::Float:   return 4;
        case ShaderDataType::Float2:  return 4 * 2;
        case ShaderDataType::Float3:  return 4 * 3;
        case ShaderDataType::Float4:  return 4 * 4;
        case ShaderDataType::Mat3:    return 4 * 3 * 3;
        case ShaderDataType::Mat4:    return 4 * 4 * 4;
        case ShaderDataType::Int:     return 4;
        case ShaderDataType::Int2:    return 4 * 2;
        case ShaderDataType::Int3:    return 4 * 3;
        case ShaderDataType::Int4:    return 4 * 4;
        case ShaderDataType::Bool:    return 1;
    }
    assert(false && "ShaderDataType desconhecido!");
    return 0;
}

struct BufferElement {
    std::string Name;
    ShaderDataType Type;
    uint32_t Size;
    uint32_t Offset;
    bool Normalized;

    BufferElement() = default;

    BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
        : Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized) {}

    uint32_t GetComponentCount() const {
        switch (Type) {
            case ShaderDataType::Float:  return 1;
            case ShaderDataType::Float2: return 2;
            case ShaderDataType::Float3: return 3;
            case ShaderDataType::Float4: return 4;
            case ShaderDataType::Mat3:   return 9;
            case ShaderDataType::Mat4:   return 16;
            case ShaderDataType::Int:    return 1;
            case ShaderDataType::Int2:   return 2;
            case ShaderDataType::Int3:   return 3;
            case ShaderDataType::Int4:   return 4;
            case ShaderDataType::Bool:   return 1;
        }
        assert(false && "ShaderDataType desconhecido!");
        return 0;
    }
};

class BufferLayout {
public:
    BufferLayout() = default;

    BufferLayout(const std::initializer_list<BufferElement>& elements)
        : m_Elements(elements) {
        CalculateOffsetsAndStride();
    }

    inline uint32_t GetStride() const { return m_Stride; }
    inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }

private:
    void CalculateOffsetsAndStride() {
        uint32_t offset = 0;
        m_Stride = 0;
        for (auto& element : m_Elements) {
            element.Offset = offset;
            offset += element.Size;
            m_Stride += element.Size;
        }
    }

private:
    std::vector<BufferElement> m_Elements;
    uint32_t m_Stride = 0;
};

#endif

// ==== event.h ====

#ifndef EVENTS_H
#define EVENTS_H

struct MouseMovedEvent {
    float x;
    float y;
};

struct KeyPressedEvent {
    int keycode;
    bool repeat;
};

struct KeyReleasedEvent {
    int keycode;
};

struct WindowResizeEvent {
    int width;
    int height;
};

struct WindowCloseEvent {};

struct ScrollEvent {
    double xoffset;
    double yoffset;
};

#endif

// ==== eventBus.h ====

#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include <memory>

class EventBus {
public:
    template<typename EventType>
    using HandlerFunc = std::function<void(const EventType&)>;

    template<typename EventType>
    void Subscribe(HandlerFunc<EventType> handler) {
        auto wrapper = [handler](const void* e) {
            handler(*static_cast<const EventType*>(e));
        };
        handlers[typeid(EventType)].push_back(wrapper);
    }

    template<typename EventType>
    void Emit(const EventType& event) const {
        auto it = handlers.find(typeid(EventType));
        if (it != handlers.end()) {
            for (const auto& handler : it->second) {
                handler(&event);
            }
        }
    }

private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const void*)>>> handlers;
};

#endif

// ==== eventToString.h ====

#ifndef EVENT_TO_STRING_H
#define EVENT_TO_STRING_H

#include <string>
#include <sstream>
#include "Event.h"

inline std::string ToString(const MouseMovedEvent& e) {
    std::stringstream ss;
    ss << "MouseMovedEvent(x=" << e.x << ", y=" << e.y << ")";
    return ss.str();
}

inline std::string ToString(const KeyPressedEvent& e) {
    std::stringstream ss;
    ss << "KeyPressedEvent(key=" << e.keycode << ", repeat=" << (e.repeat ? "true" : "false") << ")";
    return ss.str();
}

inline std::string ToString(const WindowResizeEvent& e) {
    std::stringstream ss;
    ss << "WindowResizeEvent(width=" << e.width << ", height=" << e.height << ")";
    return ss.str();
}

#endif

// ==== inputmanager.h

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "EventBus.h"
#include "Event.h"
#include "eventToString.h"
#include <iostream>
#include <log.h>
#include <keycodeUtils.h>

class InputManager {
public:
    void Register(EventBus& bus) {
        bus.Subscribe<MouseMovedEvent>([this](const MouseMovedEvent& e) {
            
        });

        bus.Subscribe<KeyPressedEvent>([this](const KeyPressedEvent& e) {
            
        });
    }

};

#endif

// ==== keyCodes.h ====

#ifndef ENGINE_KEYCODES_H
#define ENGINE_KEYCODES_H

#define ENGINE_KEY_SPACE              32
#define ENGINE_KEY_APOSTROPHE         39
#define ENGINE_KEY_COMMA              44
#define ENGINE_KEY_MINUS              45
#define ENGINE_KEY_PERIOD             46
#define ENGINE_KEY_SLASH              47
#define ENGINE_KEY_0                  48
#define ENGINE_KEY_1                  49
#define ENGINE_KEY_2                  50
#define ENGINE_KEY_3                  51
#define ENGINE_KEY_4                  52
#define ENGINE_KEY_5                  53
#define ENGINE_KEY_6                  54
#define ENGINE_KEY_7                  55
#define ENGINE_KEY_8                  56
#define ENGINE_KEY_9                  57
#define ENGINE_KEY_SEMICOLON          59
#define ENGINE_KEY_EQUAL              61
#define ENGINE_KEY_A                  65
#define ENGINE_KEY_B                  66
#define ENGINE_KEY_C                  67
#define ENGINE_KEY_D                  68
#define ENGINE_KEY_E                  69
#define ENGINE_KEY_F                  70
#define ENGINE_KEY_G                  71
#define ENGINE_KEY_H                  72
#define ENGINE_KEY_I                  73
#define ENGINE_KEY_J                  74
#define ENGINE_KEY_K                  75
#define ENGINE_KEY_L                  76
#define ENGINE_KEY_M                  77
#define ENGINE_KEY_N                  78
#define ENGINE_KEY_O                  79
#define ENGINE_KEY_P                  80
#define ENGINE_KEY_Q                  81
#define ENGINE_KEY_R                  82
#define ENGINE_KEY_S                  83
#define ENGINE_KEY_T                  84
#define ENGINE_KEY_U                  85
#define ENGINE_KEY_V                  86
#define ENGINE_KEY_W                  87
#define ENGINE_KEY_X                  88
#define ENGINE_KEY_Y                  89
#define ENGINE_KEY_Z                  90
#define ENGINE_KEY_LEFT_BRACKET       91
#define ENGINE_KEY_BACKSLASH          92
#define ENGINE_KEY_RIGHT_BRACKET      93
#define ENGINE_KEY_GRAVE_ACCENT       96
#define ENGINE_KEY_WORLD_1            161
#define ENGINE_KEY_WORLD_2            162

// Function keys
#define ENGINE_KEY_ESCAPE             256
#define ENGINE_KEY_ENTER              257
#define ENGINE_KEY_TAB                258
#define ENGINE_KEY_BACKSPACE          259
#define ENGINE_KEY_INSERT             260
#define ENGINE_KEY_DELETE             261
#define ENGINE_KEY_RIGHT              262
#define ENGINE_KEY_LEFT               263
#define ENGINE_KEY_DOWN               264
#define ENGINE_KEY_UP                 265
#define ENGINE_KEY_PAGE_UP            266
#define ENGINE_KEY_PAGE_DOWN          267
#define ENGINE_KEY_HOME               268
#define ENGINE_KEY_END                269
#define ENGINE_KEY_CAPS_LOCK          280
#define ENGINE_KEY_SCROLL_LOCK        281
#define ENGINE_KEY_NUM_LOCK           282
#define ENGINE_KEY_PRINT_SCREEN       283
#define ENGINE_KEY_PAUSE              284
#define ENGINE_KEY_F1                 290
#define ENGINE_KEY_F2                 291
#define ENGINE_KEY_F3                 292
#define ENGINE_KEY_F4                 293
#define ENGINE_KEY_F5                 294
#define ENGINE_KEY_F6                 295
#define ENGINE_KEY_F7                 296
#define ENGINE_KEY_F8                 297
#define ENGINE_KEY_F9                 298
#define ENGINE_KEY_F10                299
#define ENGINE_KEY_F11                300
#define ENGINE_KEY_F12                301
#define ENGINE_KEY_F13                302
#define ENGINE_KEY_F14                303
#define ENGINE_KEY_F15                304
#define ENGINE_KEY_F16                305
#define ENGINE_KEY_F17                306
#define ENGINE_KEY_F18                307
#define ENGINE_KEY_F19                308
#define ENGINE_KEY_F20                309
#define ENGINE_KEY_F21                310
#define ENGINE_KEY_F22                311
#define ENGINE_KEY_F23                312
#define ENGINE_KEY_F24                313
#define ENGINE_KEY_F25                314

// Keypad
#define ENGINE_KEY_KP_0               320
#define ENGINE_KEY_KP_1               321
#define ENGINE_KEY_KP_2               322
#define ENGINE_KEY_KP_3               323
#define ENGINE_KEY_KP_4               324
#define ENGINE_KEY_KP_5               325
#define ENGINE_KEY_KP_6               326
#define ENGINE_KEY_KP_7               327
#define ENGINE_KEY_KP_8               328
#define ENGINE_KEY_KP_9               329
#define ENGINE_KEY_KP_DECIMAL         330
#define ENGINE_KEY_KP_DIVIDE          331
#define ENGINE_KEY_KP_MULTIPLY        332
#define ENGINE_KEY_KP_SUBTRACT        333
#define ENGINE_KEY_KP_ADD             334
#define ENGINE_KEY_KP_ENTER           335
#define ENGINE_KEY_KP_EQUAL           336

// Modifiers
#define ENGINE_KEY_LEFT_SHIFT         340
#define ENGINE_KEY_LEFT_CONTROL       341
#define ENGINE_KEY_LEFT_ALT           342
#define ENGINE_KEY_LEFT_SUPER         343
#define ENGINE_KEY_RIGHT_SHIFT        344
#define ENGINE_KEY_RIGHT_CONTROL      345
#define ENGINE_KEY_RIGHT_ALT          346
#define ENGINE_KEY_RIGHT_SUPER        347
#define ENGINE_KEY_MENU               348

#endif

// ==== log.h ====

#ifndef LOG_H
#define LOG_H

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

class Log{

    public:

        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetLogger(){return s_Logger;}


    private:

        static std::shared_ptr<spdlog::logger> s_Logger;

    };

#define LOG_TRACE(...)      Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)      Log::GetLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...)       Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)       Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)      Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)   Log::GetLogger()->critical(__VA_ARGS__)

#endif

// ==== mouseKeyCodes.h ====

#ifndef ENGINE_MOUSEBUTTONCODES_H
#define ENGINE_MOUSEBUTTONCODES_H

#define ENGINE_MOUSE_BUTTON_1         0
#define ENGINE_MOUSE_BUTTON_2         1
#define ENGINE_MOUSE_BUTTON_3         2
#define ENGINE_MOUSE_BUTTON_4         3
#define ENGINE_MOUSE_BUTTON_5         4
#define ENGINE_MOUSE_BUTTON_6         5
#define ENGINE_MOUSE_BUTTON_7         6
#define ENGINE_MOUSE_BUTTON_8         7
#define ENGINE_MOUSE_BUTTON_LAST      ENGINE_MOUSE_BUTTON_8
#define ENGINE_MOUSE_BUTTON_LEFT      ENGINE_MOUSE_BUTTON_1
#define ENGINE_MOUSE_BUTTON_RIGHT     ENGINE_MOUSE_BUTTON_2
#define ENGINE_MOUSE_BUTTON_MIDDLE    ENGINE_MOUSE_BUTTON_3

#endif


// ==== texture2D.h ====

#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include <string>
#include <glad/glad.h>
#include "imageLoader.h"

class Texture2D {
public:
    Texture2D(const std::string& path);
    ~Texture2D();

    void Bind(uint32_t slot = 0) const;
    void Unbind() const;

    inline uint32_t GetWidth() const { return m_Width; }
    inline uint32_t GetHeight() const { return m_Height; }
    inline uint32_t GetID() const { return m_RendererID; }
    inline const std::string& GetPath() const { return m_Path; }

private:
    std::string m_Path;
    uint32_t m_Width = 0, m_Height = 0;
    uint32_t m_RendererID = 0;
    GLenum m_InternalFormat = 0, m_DataFormat = 0;
};

#endif

// ==== material.h ====

#ifndef MATERIAL_H
#define MATERIAL_H

#include "shader.h"
#include "texture2D.h"
#include "cubeMapTexture.h"

#include <glm/glm.hpp>
#include <unordered_map>
#include <memory>
#include <string>

class Material {
public:
    Material(std::shared_ptr<Shader> shader);

    void Bind() const;

    void Set(const std::string& name, const glm::mat4& mat);
    void Set(const std::string& name, const glm::vec4& vec);
    void Set(const std::string& name, const glm::vec3& vec);
    void Set(const std::string& name, float value);
    void Set(const std::string& name, int value);
    void SetTexture(const std::string& name, std::shared_ptr<Texture2D> texture, uint32_t slot);
    void SetCubeMap(const std::string& name, std::shared_ptr<CubeMapTexture> cubemap, uint32_t slot);

    const std::shared_ptr<Shader>& GetShader() const { return m_Shader; }

private:
    std::shared_ptr<Shader> m_Shader;
    std::unordered_map<std::string, std::shared_ptr<Texture2D>> m_Textures;
    std::unordered_map<std::string, uint32_t> m_TextureSlots;
    std::unordered_map<std::string, std::shared_ptr<CubeMapTexture>> m_CubeMaps;
};

#endif

// ==== engine.h ====

#include "log.h"
#include "windowSystem.h"
#include "eventbus.h"
#include "macros.h"
#include "clock.h"
#include "shader.h"
#include "shaderLibrary.h"
#include "meshFactory.h"
#include "renderer.h"
#include "renderCommand.h"
#include "camera.h"
#include "cameraController.h"
#include "texture2D.h"
#include "cubeMapTexture.h"
#include "material.h"
#include "materialLibrary.h"
#include "event.h"
#include "keyCodes.h"

//=== imageLoader.h ====

#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <string>

struct LoadedImage {
    unsigned char* data;
    int width;
    int height;
    int channels;
};

LoadedImage LoadImage(const std::string& path, bool flip = true);
void FreeImage(unsigned char* data);

#endif

// ==== cubeMapTexture.h ====

#ifndef CUBEMAP_TEXTURE_H
#define CUBEMAP_TEXTURE_H

#include <glad/glad.h>
#include <string>
#include <array>
#include <memory>
#include "imageLoader.h"

class CubeMapTexture {
public:
    CubeMapTexture(const std::string& right,
                   const std::string& left,
                   const std::string& top,
                   const std::string& bottom,
                   const std::string& front,
                   const std::string& back);
    ~CubeMapTexture();

    void Bind(uint32_t slot = 0) const;
    void Unbind() const;

    inline uint32_t GetID() const { return m_RendererID; }

private:
    uint32_t m_RendererID = 0;
};

#endif

// ==== InterfaceRegistry.h ====

#ifndef INTERFACE_REGISTRY_H
#define INTERFACE_REGISTRY_H

#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "Interface.h"

class InterfaceRegistry {
public:
    void Register(const std::string& name, std::unique_ptr<Interface> iface) {
        m_Entries.emplace_back(name, std::move(iface));
    }

    bool Exists(const std::string& name) const {
        return std::any_of(m_Entries.begin(), m_Entries.end(), [&](const auto& e) { return e.first == name; });
    }

    void EnableOnly(const std::string& name) {
        for (auto& [n, i] : m_Entries)
            i->SetActive(n == name);
    }

    void UpdateAll(float dt) {
        for (auto& [_, iface] : m_Entries)
            if (iface->IsActive()) iface->OnUpdate(dt);
    }

    void RenderAll() {
        for (auto& [_, iface] : m_Entries)
            if (iface->IsActive()) iface->OnRender();
    }

    void OnAttachAll() {
        for (auto& [_, iface] : m_Entries)
            iface->OnAttach();
    }

    void OnDetachAll() {
        for (auto& [_, iface] : m_Entries)
            iface->OnDetach();
    }

    void MoveToTop(const std::string& name) {
        auto it = std::find_if(m_Entries.begin(), m_Entries.end(), [&](auto& e) { return e.first == name; });
        if (it != m_Entries.end()) {
            auto entry = std::move(*it);
            m_Entries.erase(it);
            m_Entries.push_back(std::move(entry));
        }
    }

private:
    std::vector<std::pair<std::string, std::unique_ptr<Interface>>> m_Entries;
};

#endif

// ==== Interface.h ====

#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
public:
    virtual ~Interface() = default;

    virtual void OnAttach() {}
    virtual void OnUpdate(float dt) {}
    virtual void OnRender() {}
    virtual void OnDetach() {}

    void SetActive(bool active) { m_Active = active; }
    bool IsActive() const { return m_Active; }

private:
    bool m_Active = true;
};

#endif

// ==== application.h ====

#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <string>
#include <cassert>
#include "engine/engine.h"

class Application {
public:
    Application();
    virtual ~Application() = default;

    void Run();
    virtual void OnInit() = 0;

    void RegisterInterface(const std::string& name, std::unique_ptr<Interface> iface);

    static Application& Get();
    static void Set(Application* instance);
    static EventBus& getEventBus() {return Application::Get().getEventBus();}
    static const Camera& GetCamera() { return Get().m_Camera; }
    void SetCamera(Camera& camera);

private:
    void OnWindowClose(const WindowCloseEvent&);
    void OnWindowResize(const WindowResizeEvent& e);
    void OnKeyPressed(const KeyPressedEvent& e);
    void OnKeyReleased(const KeyReleasedEvent& e);
    void OnMouseMoved(const MouseMovedEvent& e);
    void OnMouseScrolled(const ScrollEvent& e);

protected:
    WindowSystem m_Window;
    Camera m_Camera = Camera(45.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
    CameraController m_CameraController = CameraController(m_Camera);
    InterfaceRegistry m_Registry;
    EventBus m_eventBus;

private:
    static inline Application* s_Instance = nullptr;
};

#endif