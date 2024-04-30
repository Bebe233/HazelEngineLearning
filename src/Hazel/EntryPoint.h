#pragma once

extern Hazel::Application *Hazel::CreateApplication();

int main(int, char **)
{
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}