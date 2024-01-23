#include "window.hpp"
#include "common.hpp"
#include "application.hpp"

#include <SDL_render.h>
#include <SDL_video.h>

Sirius::window::window(window_info info)
    : m_info(std::move(info)),
      m_running(true)
{
    init();
}

Sirius::window::~window() noexcept
{
    close();
}

void Sirius::window::run() const
{
    if (m_app == nullptr)
        throw std::runtime_error("window::run() called without an application");

    m_app->run(this);
}

float Sirius::window::get_scale() const
{
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);

    int rw, rh;
    SDL_GetRendererOutputSize(m_renderer, &rw, &rh);

    const auto scale = (std::min)(
        static_cast<float>(rw) / static_cast<float>(w),
        static_cast<float>(rh) / static_cast<float>(h)
    );

    return scale;
}

void Sirius::window::init()
{
    constexpr auto window_flags = static_cast<SDL_WindowFlags>(
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );

    constexpr int window_x = SDL_WINDOWPOS_CENTERED;

    m_window = SDL_CreateWindow(
        m_info.title.c_str(),
        window_x,
        window_x,
        m_info.width,
        m_info.height,
        window_flags
    );

    constexpr auto renderer_flags = static_cast<SDL_RendererFlags>(
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED
    );

    m_renderer = SDL_CreateRenderer(m_window, -1, renderer_flags);

    if (m_renderer == nullptr)
        throw std::runtime_error(std::format("SDL_CreateRenderer failed: {}", SDL_GetError()));

    const auto scale = get_scale();
    SDL_RenderSetScale(m_renderer, scale, scale);
}

void Sirius::window::close() const
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    g_running = false;
}
