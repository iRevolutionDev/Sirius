#pragma once

#include <vector>
#include <memory>
#include <string>
#include <functional>

#include "imgui.h"

struct GLFWwindow;

namespace Sirius {

    struct AppInfo {
        std::string Title;
        int Width;
        int Height;
    };

    class Application
    {
    public:
        Application(const AppInfo& appInfo = AppInfo());
        ~Application();

        void Run();
        void Close();

        virtual void OnKeyEvent([[maybe_unused]] int Key, [[maybe_unused]] int scanCode, [[maybe_unused]] int Action, [[maybe_unused]] int Mods) {}

        virtual void OnRender() {}

        GLFWwindow* GetWindow() const { return m_window; }

    private:
        void Initialize();
        void Shutdown();

    private:
        AppInfo m_appInfo;
        bool m_isRunning;

        GLFWwindow* m_window = nullptr;
    };

    Application* CreateApplication(int argc, char** argv);
}
