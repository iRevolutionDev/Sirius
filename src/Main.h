#pragma once

#ifdef _PLATFORM_WINDOWS

extern Sirius::Application* Sirius::CreateApplication(int argc, char** argv);
bool g_isRunning = true;

namespace Sirius {
    int Main(int argc, char** argv)
    {
        while (g_isRunning)
        {
            auto app = Sirius::CreateApplication(argc, argv);
            app->Run();
            delete app;
        }
        return 0;
    }
}

#ifdef _DIST
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    return Sirius::Main(__argc, __argv);
}
#else
int main(int argc, char** argv)
{
    return Sirius::Main(argc, argv);
}
#endif

#endif