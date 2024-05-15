#include "hzpch.h"

#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
    Hazel::Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Hazel::Application::~Application()
    {
    }

    void Hazel::Application::Run()
    {
        while (true)
        {
            while (m_Running)
            {
                glClearColor(1, 0, 1, 1);
                glClear(GL_COLOR_BUFFER_BIT);
                m_Window->OnUpdate();
            }
        }
    }

}