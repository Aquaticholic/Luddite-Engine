#include "Luddite/Luddite.hpp"
#include "Luddite/Platform/Window/XCBWindow.hpp"

class TestApp : public Luddite::Application
{
public:
        TestApp()
        {
                LOG_INFO("Test Application starting");
                auto game_window = std::make_shared<Luddite::XCBWindow>();
                m_windows.emplace_back(game_window);
                // game_window->GetLayerStack()->PushLayer(std::make_shared<>)
                LOG_INFO("Window Created");
        }
        ~TestApp()
        {}
};

Luddite::Application* Luddite::CreateApplication()
{
        return new TestApp();
}
