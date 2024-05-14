#pragma once

extern Hazel::Application *Hazel::CreateApplication();

int main(int, char **)
{
    Hazel::Log::Init();

    HZ_CORE_WARN("Initialize logger!");
    HZ_INFO("Hello {0}", 2024);
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}