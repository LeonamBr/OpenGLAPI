// ==== windowSystem.cpp ====

#include "windowSystem.h"
#include "log.h"
#include "macros.h"
#include "event.h"

WindowSystem::WindowSystem()
    : m_WindowHandle(nullptr), m_RenderContext(nullptr)
{
}

WindowSystem::~WindowSystem()
{
    Shutdown();
}

void WindowSystem::Init(unsigned int width, unsigned int height, const std::string& title, EventBus& bus)
{
    m_Data.Width = width;
    m_Data.Height = height;
    m_Data.Title = title;
    m_Data.eventBus = &bus;

    if (!glfwInit()) {
        LOG_CRITICAL("Could not initialize GLFW!");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_WindowHandle = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
    if (!m_WindowHandle) {
        LOG_CRITICAL("Failed to create GLFW window!");
        glfwTerminate();
        return;
    }

    m_RenderContext = new OpenGLContext(m_WindowHandle);
    m_RenderContext->Init();

    glfwSetWindowUserPointer(m_WindowHandle, &m_Data);

    glfwSetFramebufferSizeCallback(m_WindowHandle, FramebufferSizeCallback);
    glfwSetKeyCallback(m_WindowHandle, KeyCallback);
    glfwSetCursorPosCallback(m_WindowHandle, MouseMovedCallback);
    glfwSetScrollCallback(m_WindowHandle, MouseScrolledCallback);
    glfwSetWindowCloseCallback(m_WindowHandle, WindowCloseCallback);
}

void WindowSystem::PollEvents()
{
    glfwPollEvents();
}

void WindowSystem::SwapBuffers()
{
    m_RenderContext->SwapBuffers();
}

bool WindowSystem::ShouldClose() const
{
    return glfwWindowShouldClose(m_WindowHandle);
}

void WindowSystem::Shutdown()
{
    glfwDestroyWindow(m_WindowHandle);
    glfwTerminate();
}

void WindowSystem::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    data.Width = width;
    data.Height = height;
    glViewport(0, 0, width, height);

    WindowResizeEvent event(width, height);
    data.eventBus->Emit(event);
}

void WindowSystem::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    if (action == GLFW_PRESS) {
        KeyPressedEvent event(key);
        data.eventBus->Emit(event);
    }
    else if (action == GLFW_RELEASE) {
        KeyReleasedEvent event(key);
        data.eventBus->Emit(event);
    }
}

void WindowSystem::MouseMovedCallback(GLFWwindow* window, double xpos, double ypos)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    MouseMovedEvent event((float)xpos, (float)ypos);
    data.eventBus->Emit(event);
}

void WindowSystem::MouseScrolledCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    ScrollEvent event((float)xoffset, (float)yoffset);
    data.eventBus->Emit(event);
}

void WindowSystem::WindowCloseCallback(GLFWwindow* window)
{
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    WindowCloseEvent event;
    data.eventBus->Emit(event);
}


// ==== camera.cpp ====

#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, float aspectRatio, float nearClip, float farClip)
    : m_FOV(fov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip)
{
    m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
    UpdateViewMatrix();
}

void Camera::SetFocalPoint(const glm::vec3& focalPoint)
{
    m_FocalPoint = focalPoint;
    UpdateViewMatrix();
}

void Camera::SetDistance(float distance)
{
    m_Distance = distance;
    UpdateViewMatrix();
}

void Camera::SetRotation(float yaw, float pitch)
{
    m_Yaw = yaw;
    m_Pitch = pitch;
    UpdateViewMatrix();
}

void Camera::SetViewportSize(float width, float height)
{
    m_AspectRatio = width / height;
    m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
}

void Camera::UpdateViewMatrix()
{
    glm::vec3 direction;
    direction.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    direction.y = sin(glm::radians(m_Pitch));
    direction.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    direction = glm::normalize(direction);

    m_Position = m_FocalPoint - direction * m_Distance;
    m_ViewMatrix = glm::lookAt(m_Position, m_FocalPoint, m_Up);
}

// ==== mesh.cpp ====

#include "mesh.h"
#include <glad/glad.h>

Mesh::Mesh(float* vertices, uint32_t vertexSize, const BufferLayout& layout,
           uint32_t* indices, uint32_t indexCount)
    : m_IndexCount(indexCount)
{
    m_VertexArray = std::make_shared<VertexArray>();

    m_VertexBuffer = std::make_shared<VertexBuffer>(vertices, vertexSize);
    m_VertexBuffer->SetLayout(layout);
    m_VertexArray->AddVertexBuffer(m_VertexBuffer);

    if (indices && indexCount > 0) {
        m_IndexBuffer = std::make_shared<IndexBuffer>(indices, indexCount);
        m_VertexArray->SetIndexBuffer(m_IndexBuffer);
    }
}

void Mesh::Draw() const {
    m_VertexArray->Bind();

    if (m_IndexBuffer)
        glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, nullptr);
    else
        glDrawArrays(GL_TRIANGLES, 0, 3);
}


// ==== meshFactory.cpp ====

#include "meshFactory.h"
#include "bufferLayout.h"

std::shared_ptr<Mesh> MeshFactory::CreateTriangle() {
    static float vertices[] = {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f
    };

    BufferLayout layout = {
        { ShaderDataType::Float3, "a_Position" },
        { ShaderDataType::Float3, "a_Color" }
    };

    return std::make_shared<Mesh>(vertices, sizeof(vertices), layout);
}

std::shared_ptr<Mesh> MeshFactory::CreateQuad() {
    static float vertices[] = {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f
    };

    static uint32_t indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    BufferLayout layout = {
        { ShaderDataType::Float3, "a_Position" },
        { ShaderDataType::Float3, "a_Color" }
    };

    return std::make_shared<Mesh>(vertices, sizeof(vertices), layout, indices, 6);
}

// ==== renderCommand.cpp ====

#include "renderCommand.h"
#include <glad/glad.h>

void RenderCommand::Init()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void RenderCommand::SetClearColor(const glm::vec4& color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}

void RenderCommand::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderCommand::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount)
{
    vertexArray->Bind();
    uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}

// ==== renderer.cpp ====

#include "renderer.h"
#include "renderCommand.h"

Renderer::SceneData Renderer::s_SceneData;

void Renderer::Init()
{
    RenderCommand::Init();
}

void Renderer::BeginScene(const Camera& camera)
{
    s_SceneData.View = camera.GetViewMatrix();
    s_SceneData.Projection = camera.GetProjectionMatrix();
}

void Renderer::EndScene()
{
    // Por agora, nada. Futuramente pode limpar buffers de submissão ou lidar com batches.
}

void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<Mesh>& mesh, const glm::mat4& transform)
{
    shader->Bind();
    shader->SetMat4("u_View", s_SceneData.View);
    shader->SetMat4("u_Projection", s_SceneData.Projection);
    shader->SetMat4("u_Model", transform);
    mesh->Draw();
}

// ==== shader.cpp ====

#include "shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include "log.h"

Shader::Shader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
    : m_Name(name), m_VertexPath(vertexPath), m_FragmentPath(fragmentPath) {

    std::string vertexSource = PreprocessShader(ReadFile(vertexPath), std::filesystem::path(vertexPath).parent_path().string());
    std::string fragmentSource = PreprocessShader(ReadFile(fragmentPath), std::filesystem::path(fragmentPath).parent_path().string());
    m_IsValid = Compile(vertexSource, fragmentSource);
}

Shader::~Shader() {
    if (m_RendererID != 0)
        glDeleteProgram(m_RendererID);
}

bool Shader::Reload() {
    LOG_INFO("Reloading shader: {}", m_Name);

    std::string vertexSource = PreprocessShader(ReadFile(m_VertexPath), std::filesystem::path(m_VertexPath).parent_path().string());
    std::string fragmentSource = PreprocessShader(ReadFile(m_FragmentPath), std::filesystem::path(m_FragmentPath).parent_path().string());

    if (m_RendererID != 0)
        glDeleteProgram(m_RendererID);

    m_UniformLocationCache.clear();
    m_IsValid = Compile(vertexSource, fragmentSource);
    return m_IsValid;
}

bool Shader::IsValid() const {
    return m_IsValid && m_RendererID != 0;
}

std::string Shader::ReadFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        LOG_ERROR("Erro ao abrir shader: {}", path);
        return "";
    }

    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

std::string Shader::PreprocessShader(const std::string& source, const std::string& parentDir) {
    std::istringstream iss(source);
    std::stringstream output;
    std::string line;

    while (std::getline(iss, line)) {
        if (line.find("#include") != std::string::npos) {
            size_t start = line.find("\"") + 1;
            size_t end = line.find_last_of("\"");
            std::string includePath = parentDir + "/" + line.substr(start, end - start);
            output << PreprocessShader(ReadFile(includePath), std::filesystem::path(includePath).parent_path().string());
        } else {
            output << line << '\n';
        }
    }

    return output.str();
}

uint32_t Shader::CompileShader(uint32_t type, const std::string& source) {
    uint32_t shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info[512];
        glGetShaderInfoLog(shader, 512, nullptr, info);
        LOG_ERROR("Falha ao compilar shader ({}): {}", (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"), info);
    }

    return shader;
}

bool Shader::Compile(const std::string& vertexSrc, const std::string& fragmentSrc) {
    if (vertexSrc.empty() || fragmentSrc.empty()) {
        LOG_ERROR("Shader source vazio!" );
        return false;
    }

    uint32_t vertex = CompileShader(GL_VERTEX_SHADER, vertexSrc);
    uint32_t fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vertex);
    glAttachShader(m_RendererID, fragment);
    glLinkProgram(m_RendererID);

    int success;
    glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
    if (!success) {
        char info[512];
        glGetProgramInfoLog(m_RendererID, 512, nullptr, info);
        LOG_ERROR("Falha ao linkar shader program: {}", info);
        return false;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return true;
}

void Shader::Bind() const {
    if (IsValid())
        glUseProgram(m_RendererID);
}

void Shader::Unbind() const {
    glUseProgram(0);
}

int Shader::GetUniformLocation(const std::string& name) const {
    if (m_UniformLocationCache.contains(name))
        return m_UniformLocationCache[name];

    int location = glGetUniformLocation(m_RendererID, name.c_str());
    if (location == -1)
        LOG_WARN("Uniform '{}' não encontrado no shader '{}'", name, m_Name);

    m_UniformLocationCache[name] = location;
    return location;
}

void Shader::SetInt(const std::string& name, int value) const {
    if (IsValid())
        glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetFloat(const std::string& name, float value) const {
    if (IsValid())
        glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetVec3(const std::string& name, const glm::vec3& value) const {
    if (IsValid())
        glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
}

void Shader::SetVec4(const std::string& name, const glm::vec4& value) const {
    if (IsValid())
        glUniform4f(GetUniformLocation(name), value.r, value.g, value.b, value.a);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& value) const {
    if (IsValid())
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
}

// ==== shaderLibrary.cpp ====

#include "shaderLibrary.h"
#include <cassert>

void ShaderLibrary::Add(const std::shared_ptr<Shader>& shader) {
    const std::string& name = shader->GetName();
    if (Exists(name)) {
        assert(false && "Shader already exists!");
    }
    m_Shaders[name] = shader;
}

std::shared_ptr<Shader> ShaderLibrary::Load(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath) {
    auto shader = std::make_shared<Shader>(name, vertexPath, fragmentPath);
    Add(shader);
    return shader;
}

std::shared_ptr<Shader> ShaderLibrary::Get(const std::string& name) {
    if (!Exists(name)) {
        assert(false && "Shader not found!");
    }
    return m_Shaders.at(name);
}

bool ShaderLibrary::Exists(const std::string& name) const {
    return m_Shaders.find(name) != m_Shaders.end();
}

// ==== vertexArray.cpp ====

#include "vertexArray.h"
#include <glad/glad.h>
#include "log.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::Bind() const {
    glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}

void VertexArray::ConfigureAttribute(uint32_t index, const BufferElement& element, uint32_t stride) {
    glEnableVertexAttribArray(index);

    GLenum glBaseType = GL_FLOAT; // padrão, pode ser expandido futuramente
    switch (element.Type) {
        case ShaderDataType::Float:
        case ShaderDataType::Float2:
        case ShaderDataType::Float3:
        case ShaderDataType::Float4:
        case ShaderDataType::Mat3:
        case ShaderDataType::Mat4:
            glBaseType = GL_FLOAT;
            break;
        case ShaderDataType::Int:
        case ShaderDataType::Int2:
        case ShaderDataType::Int3:
        case ShaderDataType::Int4:
            glBaseType = GL_INT;
            break;
        case ShaderDataType::Bool:
            glBaseType = GL_BOOL;
            break;
        default:
            LOG_ERROR("Tipo de ShaderDataType não suportado ainda em VertexArray");
            return;
    }

    glVertexAttribPointer(
        index,
        element.GetComponentCount(),
        glBaseType,
        element.Normalized ? GL_TRUE : GL_FALSE,
        stride,
        reinterpret_cast<const void*>(static_cast<intptr_t>(element.Offset))
    );
}

void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
    Bind();
    vertexBuffer->Bind();

    const auto& layout = vertexBuffer->GetLayout();
    for (const auto& element : layout.GetElements()) {
        ConfigureAttribute(m_VertexAttribIndex, element, layout.GetStride());
        m_VertexAttribIndex++;
    }

    m_VertexBuffers.push_back(vertexBuffer);
    Unbind();
}

void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
    Bind();
    indexBuffer->Bind();
    m_IndexBuffer = indexBuffer;
    Unbind();
}
// ==== vertexBuffer.cpp ====

#include "vertexBuffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(float* data, uint32_t size) {
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::SetLayout(const BufferLayout& layout) {
    m_Layout = layout;
}

const BufferLayout& VertexBuffer::GetLayout() const {
    return m_Layout;
}


// ==== openGLContext.cpp ====

##include "openGLContext.h"
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


// ==== cameraController.cpp ====

#include "cameraController.h"
#include <glm/glm.hpp>

CameraController::CameraController(Camera& camera)
    : m_Camera(camera) {}

void CameraController::OnUpdate(float deltaTime) {
    glm::vec3 focal = m_Camera.GetFocalPoint();
    glm::vec3 right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), glm::normalize(focal - m_Camera.GetPosition())));
    glm::vec3 forward = glm::normalize(focal - m_Camera.GetPosition());

    if (m_MoveForward)
        focal += glm::vec3(0.0f, m_MovementSpeed * deltaTime, 0.0f);
    if (m_MoveBackward)
        focal -= glm::vec3(0.0f, m_MovementSpeed * deltaTime, 0.0f);
    if (m_MoveLeft)
        focal -= right * m_MovementSpeed * deltaTime;
    if (m_MoveRight)
        focal += right * m_MovementSpeed * deltaTime;
    if (m_MoveIn)
        focal += forward * m_MovementSpeed * deltaTime;
    if (m_MoveOut)
        focal -= forward * m_MovementSpeed * deltaTime;

    m_Camera.SetFocalPoint(focal);
}

void CameraController::OnKeyPressed(const KeyPressedEvent& e) {
    switch (e.keycode) {
        case ENGINE_KEY_W: m_MoveForward = true; break;
        case ENGINE_KEY_S: m_MoveBackward = true; break;
        case ENGINE_KEY_A: m_MoveLeft = true; break;
        case ENGINE_KEY_D: m_MoveRight = true; break;
        case ENGINE_KEY_E: m_MoveIn = true; break;
        case ENGINE_KEY_Q: m_MoveOut = true; break;
        case ENGINE_KEY_LEFT_CONTROL:
            m_MouseControlActive = true;
            LockMouse();
            break;
    }
}

void CameraController::OnKeyReleased(const KeyReleasedEvent& e) {
    switch (e.keycode) {
        case ENGINE_KEY_W: m_MoveForward = false; break;
        case ENGINE_KEY_S: m_MoveBackward = false; break;
        case ENGINE_KEY_A: m_MoveLeft = false; break;
        case ENGINE_KEY_D: m_MoveRight = false; break;
        case ENGINE_KEY_E: m_MoveIn = false; break;
        case ENGINE_KEY_Q: m_MoveOut = false; break;
        case ENGINE_KEY_LEFT_CONTROL:
            m_MouseControlActive = false;
            UnlockMouse();
            break;
    }
}

void CameraController::OnMouseMoved(const MouseMovedEvent& e) {
    if (!m_MouseControlActive)
        return;

    if (m_FirstMouse) {
        m_LastX = e.x;
        m_LastY = e.y;
        m_FirstMouse = false;
    }

    float xOffset = (e.x - m_LastX) * m_MouseSensitivity;
    float yOffset = (m_LastY - e.y) * m_MouseSensitivity;
    m_LastX = e.x;
    m_LastY = e.y;

    float yaw = m_Camera.GetYaw() + xOffset;
    float pitch = m_Camera.GetPitch() + yOffset;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    m_Camera.SetRotation(yaw, pitch);
}

void CameraController::OnScroll(const ScrollEvent& e) {
    float distance = glm::length(m_Camera.GetPosition() - m_Camera.GetFocalPoint());
    distance -= e.yoffset * m_ZoomSensitivity;
    if (distance < 1.0f) distance = 1.0f;
    if (distance > 100.0f) distance = 100.0f;

    m_Camera.SetDistance(distance);
}

void CameraController::LockMouse() {
    GLFWwindow* nativeWindow = glfwGetCurrentContext();
    if (nativeWindow)
        glfwSetInputMode(nativeWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void CameraController::UnlockMouse() {
    GLFWwindow* nativeWindow = glfwGetCurrentContext();
    if (nativeWindow)
        glfwSetInputMode(nativeWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

// ==== log.cpp ====

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>


std::shared_ptr<spdlog::logger> Log::s_Logger;
    
void Log::Init(){

    spdlog::set_pattern("%^[%T] %n: %v%$");

    s_Logger = spdlog::stdout_color_mt("Log");
    s_Logger->set_level(spdlog::level::trace);

}

// ===== sandbox.cpp =====

#include "log.h"
#include "windowSystem.h"
#include "eventbus.h"
#include "macros.h"
#include "clock.h"
#include "shader.h"
#include "meshFactory.h"
#include "camera.h"
#include "cameraController.h"
#include "event.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

static EventBus bus;
static WindowSystem window;

static Camera camera(45.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
static CameraController cameraController(camera);

void OnWindowClose(const WindowCloseEvent&) {
    LOG_INFO("Fechando janela...");
}

void OnWindowResize(const WindowResizeEvent& e) {
    camera.SetViewportSize((float)e.width, (float)e.height);
}

void OnKeyPressed(const KeyPressedEvent& e) {
    cameraController.OnKeyPressed(e);
}

void OnKeyReleased(const KeyReleasedEvent& e) {
    cameraController.OnKeyReleased(e);
}

void OnMouseMoved(const MouseMovedEvent& e) {
    cameraController.OnMouseMoved(e);
}

void OnMouseScrolled(const ScrollEvent& e) {
    cameraController.OnScroll(e);
}

int main() {
    Log::Init();
    Clock::Init();

    window.Init(1280, 720, "Sandbox Layout Dinâmico", bus);
    bus.Subscribe<WindowCloseEvent>(REGISTER_EVENT(OnWindowClose));
    bus.Subscribe<WindowResizeEvent>(REGISTER_EVENT(OnWindowResize));
    bus.Subscribe<KeyPressedEvent>(REGISTER_EVENT(OnKeyPressed));
    bus.Subscribe<KeyReleasedEvent>(REGISTER_EVENT(OnKeyReleased));
    bus.Subscribe<MouseMovedEvent>(REGISTER_EVENT(OnMouseMoved));
    bus.Subscribe<ScrollEvent>(REGISTER_EVENT(OnMouseScrolled));

    auto shader = std::make_shared<Shader>("basic", "assets/shader/shader.vertex", "assets/shader/basic.fragment");

    auto triangle = MeshFactory::CreateTriangle();
    auto quad = MeshFactory::CreateQuad();

    while (!window.ShouldClose()) {
        Clock::Update();
        float deltaTime = Clock::GetDeltaTime();

        window.PollEvents();
        cameraController.OnUpdate(deltaTime);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader->Bind();
        shader->SetMat4("u_Projection", camera.GetProjectionMatrix());
        shader->SetMat4("u_View", camera.GetViewMatrix());

        glm::mat4 identity = glm::mat4(1.0f);

        glm::mat4 modelTriangle = glm::translate(identity, glm::vec3(-0.5f, 0.0f, 0.0f));
        shader->SetMat4("u_Model", modelTriangle);
        triangle->Draw();

        glm::mat4 modelQuad = glm::translate(identity, glm::vec3(0.5f, 0.0f, 0.0f));
        shader->SetMat4("u_Model", modelQuad);
        quad->Draw();

        window.SwapBuffers();
    }

    return 0;
}

