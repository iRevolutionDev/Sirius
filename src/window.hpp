#pragma once
#include <SDL_render.h>
#include <SDL_video.h>

#include "window_info.hpp"

namespace Sirius
{
    class application;

    class window
    {
    public:
        window() = delete;
        explicit window(window_info info);

        window(const window&) = delete;
        ~window();

        void run() const;
        void close() const;
        void set_app(application* app) noexcept { m_app = app; }

        [[nodiscard]] SDL_Renderer* get_renderer() const noexcept { return m_renderer; }
        [[nodiscard]] SDL_Window* get_window() const noexcept { return m_window; }

    private:
        float get_scale() const;
        void init();

        window_info m_info;
        bool m_running;
        application* m_app{};

        SDL_Window* m_window{};
        SDL_Renderer* m_renderer{};
    };

    window* create_window(int argc, char** argv);
}
