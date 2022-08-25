#pragma once

#include <vector>
#include <memory>
#include <string>
#include <functional>

#include "WindowInfo.h"
#include "Application.h"

struct GLFWwindow;

namespace Sirius {

    class Window
    {
    public:
        Window(const WindowInfo& appInfo = WindowInfo());
        ~Window();

        void Run();
        void Close();

        void RunApp(Application* app) { m_App = app; }
       
        GLFWwindow* GetWindow() const { return m_window; }

    private:
        void Initialize();
        void Shutdown();

    private:
        WindowInfo m_winInfo;
        bool m_isRunning;
        Application* m_App;

        GLFWwindow* m_window = nullptr;
    };

    Window* CreateWindowApp(int argc, char** argv);
}
