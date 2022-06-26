
extern Sirius::Application* CreateApplication(int argc, char** argv);
bool g_isRunning = true;

namespace Sirius {
    int Main(int argc, char** argv)
    {
        while g_isRunning)
        {
            auto app = CreateApplication(argc, argv);
            app->Run();
            delete app;
        }
        return 0;
    }
}

#ifdef _WIN32
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    return Sirius::Main(__argc, __argv);
}
#elif
int main(int argc, char** argv)
{
    return Sirius::Main(argc, argv);
}
#endif