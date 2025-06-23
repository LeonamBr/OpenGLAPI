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