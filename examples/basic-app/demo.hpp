#pragma once
#include "layer.hpp"
#include "imgui.h"

class demo final : public Sirius::layer
{
public:
    void on_render() override
    {
        ImGui::ShowDemoWindow();
    }
};
