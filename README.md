# OpenGLAPI

Bem-vindo ao **OpenGLAPI**! Este é um projeto de estudo e construção de uma mini-engine gráfica modularizada, baseada em **OpenGL 4.6**, escrita em **C++** puro com foco em:

- Arquitetura limpa e separada por responsabilidades
- Sistema de eventos robusto
- Controle de entrada (keyboard/mouse) desacoplado
- Modularização de rendering pipeline
- Flexibilidade para expansão futura (ECS, RendererAPI, Scene system)


## Estrutura do Projeto

```
src/
├── core/          # Base do sistema: logs, keycodes, macros
├── event/         # EventBus e eventos customizados
├── input/         # CameraController e InputManager (futuro)
├── openGL/        # Contexto OpenGL puro (GLFW + GLAD)
├── renderer/      # Mesh, Shader e sistemas de renderização
├── utils/         # Utilidades de conversão e helpers
├── window/        # Sistema de janela separado (WindowSystem)
└── sandbox.cpp   # Ambiente de testes principal
assets/
├── shader/        # Shaders GLSL (.vertex e .fragment)
vendor/
├── glad/
├── glfw/
├── glm/
├── spdlog/
```


## Tecnologias Utilizadas

- **C++20**
- **OpenGL 4.6**
- **GLFW** (para gerenciamento de janelas e input)
- **GLAD** (loader de funções OpenGL)
- **spdlog** (sistema de log profissional)
- **GLM** (matemática para gráficos 3D)


## Como Compilar

1. Certifique-se de ter instalado:
   - CMake
   - MinGW ou outro compilador C++

2. Clone o repositório com submodules:

```bash
git clone --recurse-submodules https://github.com/seu-usuario/OpenGLAPI.git
```

3. Compile:

```bash
mkdir build
cd build
cmake ..
make
```

4. Execute:

```bash
./OpenGL_API
```


## Estado Atual

- [x] Sistema de eventos com EventBus
- [x] Sistema de logging modularizado
- [x] Gerenciamento de janela separado de render
- [x] Rendering básico de formas (triângulo e quads)
- [x] Câmera 3D controlada por mouse e teclado
- [x] DeltaTime no game loop
- [x] Shaders separados e gerenciados
- [ ] Mesh estruturado para múltiplos atributos (em andamento)
- [ ] Sistema de ShaderLibrary (em planejamento)


## Roadmap Futuro

- [ ] Refatorar Mesh para ser flexível (Positions, Normals, TexCoords)
- [ ] Implementar ShaderLibrary
- [ ] Implementar RendererAPI e RenderCommand
- [ ] Sistema de Entities e Components
- [ ] Sistema de Scene e SceneManager
- [ ] Suporte para Textures
- [ ] Lighting básico (Phong, Directional light)


## Licença

Este projeto é aberto para aprendizado e evolução pessoal. Não possui licença comercial ainda.


## Autor

Desenvolvido por **[Seu Nome ou Nick]**, com apoio e feedback construtivo no processo de estudo de engines gráficas e arquiteturas de software.

---

**OpenGLAPI** ❤️ Construindo passo a passo, sem pressa, mas com qualidade!

