#include "hzpch.h"

#include "Linux64Window.h"

namespace Hazel
{

    static bool s_GLFWInitialized = false;

    Window *Window::Create(const WindowProps &props)
    {
        return new Linux64Window(props);
    }

    Hazel::Linux64Window::Linux64Window(const WindowProps &props)
    {
        Init(props);
    }

    Hazel::Linux64Window::~Linux64Window()
    {
        Shutdown();
    }

    void Hazel::Linux64Window::Init(const WindowProps &props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        HZ_CORE_INFO("Creating window {0} ({1},{2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            HZ_CORE_ASSERT(success, "Could not intialize GLFW!");

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void Hazel::Linux64Window::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void Hazel::Linux64Window::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void Hazel::Linux64Window::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool Hazel::Linux64Window::IsVSync() const
    {
        return m_Data.VSync;
    }
}
