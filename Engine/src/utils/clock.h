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