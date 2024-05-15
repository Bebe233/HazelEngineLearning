#include "Window.h"
#include "Hazel/Events/ApplicationEvent.h"
namespace Hazel
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

    private:
        bool OnWindowClose(WindowCloseEvent& e);
    };

    Application *CreateApplication();
}; // namespace Hazel
