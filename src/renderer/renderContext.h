#ifndef ENGINE_RENDER_CONTEXT_H
#define ENGINE_RENDER_CONTEXT_H

class RenderContext {
public:
    virtual void Init() = 0;
    virtual void SwapBuffers() = 0;
    virtual void Resize(int width, int height) = 0;
    virtual ~RenderContext() = default;
};

#endif 