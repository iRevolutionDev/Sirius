#pragma once
#include "Sirius/layer.hpp"
#include "imgui.h"

class demo final : public Sirius::layer
{
public:
    void on_init() override
    {
        // This function is called once when the layer is initialized
        // You can use this function to load resources or initialize variables here
        // For example, you can load a font here

        const auto& io = ImGui::GetIO();

        // Load the default font from the system
        io.Fonts->AddFontFromFileTTF(R"(C:\Windows\Fonts\arial.ttf)", 18);
        io.Fonts->AddFontFromFileTTF(R"(C:\Windows\Fonts\arialbd.ttf)", 18);
    }

    void on_render() override
    {
        ImGui::ShowDemoWindow();
    }
};
