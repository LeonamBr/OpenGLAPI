#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

class RenderContext {
public:
    virtual ~RenderContext() = default;

    virtual void Init() = 0;
    virtual void SwapBuffers() = 0;
};

#endif