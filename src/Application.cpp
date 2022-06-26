#include "Application.h"

namespace Sirius {
    Application::Application(const AppInfo& appInfo) : m_appInfo(appInfo) {
        Initialize();
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
    }

    void Application::Close()
    {
    }

    void Application::Initialize()
    {

    }

    void Application::Shutdown()
    {
    }
}