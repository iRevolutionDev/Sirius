#include "Application.h"
#include "Main.h"

Sirius::Application* Sirius::CreateApplication(int argc, char** argv)
{
    Sirius::AppInfo appInfo;
    appInfo.Title = "Basic App";

    return new Sirius::Application(appInfo);
}