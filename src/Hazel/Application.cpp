#include "hzpch.h"

#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
namespace Hazel
{
    Hazel::Application::Application()
    {
    }

    Hazel::Application::~Application()
    {
    }

    void Hazel::Application::Run()
    {
        while (true)
        {
            std::cout << "running..." << std::endl;
            sleep(3);

            WindowResizeEvent e(1280, 720);
            if (e.IsInCategory(EventCategory::Application))
            {
                HZ_INFO(e.ToString());
            }
        }
    }

}