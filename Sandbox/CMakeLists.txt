# Cria o executável da sandbox
add_executable(SandboxApp
    src/SandboxApp.cpp
)

# Linka com a engine
target_link_libraries(SandboxApp PRIVATE OpenGLEngine)

# Adiciona os includes próprios + includes da engine
target_include_directories(SandboxApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/Engine/src
)

# Define onde o binário vai ser gerado
set_target_properties(SandboxApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
