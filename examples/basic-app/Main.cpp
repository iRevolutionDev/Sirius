#include "Window.h"
#include "Main.h"
#include "App.hpp"

Sirius::Window* Sirius::CreateWindowApp(int argc, char** argv)
{
    Sirius::WindowInfo windowInfo;
    windowInfo.Title = "Basic App";
    
    auto window = new Sirius::Window(windowInfo);
    window->RunApp(new BasicApp);
    
    return window;
}