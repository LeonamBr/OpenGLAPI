# OpenGLAPI

Bem-vindo ao **OpenGLAPI**! Este é um projeto de estudo e construção de uma mini-engine gráfica modularizada, desenvolvida do zero com C++ e OpenGL. A arquitetura é inspirada em princípios de design modernos, com foco em clareza, organização e escalabilidade. O projeto serve como base para a criação futura de um editor visual ou jogo próprio.

## 📁 Estrutura do Projeto

```
src/
├── core/          # Base do sistema: logs, macros, clock
├── event/         # EventBus e eventos customizados
├── input/         # CameraController e gerenciamento de entrada
├── renderer/      # Shaders, Mesh, Texture, Renderer, Material, CubeMap
├── window/        # Sistema de janela GLFW
├── engine/        # Header centralizador de includes
├── sandbox.cpp    # Ponto de entrada principal
assets/
├── textures/      # Texturas usadas nos materiais e skybox
├── shader/        # GLSL shaders
```

## 🚀 Tecnologias Utilizadas

- C++20
- OpenGL 4.6
- GLFW
- GLAD
- GLM
- spdlog
- stb_image

## 🛠 Instruções para Compilar

```bash
git clone --recurse-submodules https://github.com/LeonamBr/OpenGLAPI.git
cd OpenGLAPI
mkdir build && cd build
cmake ..
make -j
./OpenGL_API
```

## ✅ Estado Atual

- [x] Sistema de eventos com EventBus
- [x] Logging modularizado com spdlog
- [x] Sistema de janela com GLFW separado
- [x] Contexto OpenGL com GLAD
- [x] ShaderLibrary funcional com cache
- [x] RenderCommand e abstração
- [x] Renderer::Submit para Shader e Material
- [x] MeshFactory para gerar quad e cubo
- [x] Camera 3D com Controller
- [x] Sistema de materiais e textura unificada
- [x] Skybox com CubeMap checkerboard orientado
- [x] ImageLoader centralizado para textura
- [x] Atualização dinâmica de deltaTime com Clock

## 📌 Roadmap

- [ ] Seleção de objetos com Raycasting
- [ ] Sistema de cena com entidades/componentes (ECS)
- [ ] GUI com Dear ImGui para editor
- [ ] Iluminação básica (Phong Directional/Point)
- [ ] Sombras com Shadow Mapping
- [ ] Save/Load de cena com JSON
- [ ] Plugin system e extensibilidade

## 🧠 Filosofia do Projeto

Projetado com base em experimentação real, refatoração consciente e práticas modernas de engenharia de software. Cada módulo é testável de forma independente e segue padrões claros. Nenhuma linha de código foi escrita por atalhos — tudo foi entendido, construído e validado passo a passo.

## 📄 Licença

Este projeto é aberto para aprendizado, estudo e expansão pessoal. Faça fork, modifique e experimente à vontade!

## ✍️ Autor

Desenvolvido por **[LeonamBr](https://github.com/LeonamBr)** com base em pesquisa, testes e estruturação manual linha por linha.
