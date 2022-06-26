#include "src/Application.h"
#include "src/Main.h"

class BasicApp : public Sirius::Application
{
public:
    virtual void OnRender() override
    {
        ImGui::ShowDemoWindow();
    }
};

Sirius::Application* CreateApplication(int argc, char** argv)
{
    Sirius::AppInfo appInfo;
    appInfo.Title = "Basic App";

    return new BasicApp(appInfo);
}
