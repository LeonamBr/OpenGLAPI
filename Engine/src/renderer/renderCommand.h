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