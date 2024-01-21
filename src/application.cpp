#include "application.hpp"
#include "common.hpp"
#include "window.hpp"

#include <SDL2/SDL.h>

Sirius::application::application()
{
    if (
        constexpr uint32_t init_flags = {
            SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER
        };
        SDL_Init(init_flags) != 0
    )
    {
        m_exit_code = 1;
        throw std::runtime_error(std::format("SDL_Init failed: {}", SDL_GetError()));
    }
}

Sirius::application::~application()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_Quit();
}

void Sirius::application::run(const window* window)
{
    if (m_exit_code != 0) return;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io{ImGui::GetIO()};

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplSDL2_InitForSDLRenderer(
        window->get_window(),
        window->get_renderer()
    );

    ImGui_ImplSDLRenderer2_Init(window->get_renderer());

    while (m_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            switch (event.type)
            {
            case SDL_QUIT:
                m_running = false;
                break;
            default: break;
            }
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        for (const auto& layer : m_layers)
        {
            layer->on_update();
            layer->on_render();
        }

        ImGui::Render();

        SDL_SetRenderDrawColor(window->get_renderer(), 0, 0, 0, 255);
        SDL_RenderClear(window->get_renderer());

        ImGui_ImplSDLRenderer2_RenderDrawData(
            ImGui::GetDrawData()
        );

        SDL_RenderPresent(window->get_renderer());
    }
}

void Sirius::application::quit()
{
    m_running = false;
}

void Sirius::application::push_layer(std::unique_ptr<layer> layer)
{
    m_layers.emplace_back(std::move(layer));
    m_layers.back()->on_attach();
}

void Sirius::application::pop_layer()
{
    m_layers.pop_back();
}
