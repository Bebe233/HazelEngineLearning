#include "Window.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/ApplicationEvent.h"
namespace Hazel
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        void Run();

        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

    private:
        bool OnWindowClose(WindowCloseEvent &e);
    };

    Application *CreateApplication();
}; // namespace Hazel
