#include "Application.h"
#include <iostream>
#include <unistd.h>
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
        }
    }

}