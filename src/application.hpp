#pragma once

#include <SDL_events.h>

#include "layer.hpp"

namespace Sirius
{
    class window;

    class application
    {
    public:
        application();
        ~application();

        void run(const window* window);
        void quit();

        void on_event(const SDL_WindowEvent& event);

        void on_minimize();
        void on_maximize();

        template <typename T>
        void push_layer()
        {
            static_assert(std::is_base_of_v<layer, T>, "T must derive from layer");
            m_layers.emplace_back(std::make_unique<T>());
            m_layers.back()->on_attach();
        }

        void push_layer(std::unique_ptr<layer> layer);
        void pop_layer();
        void pop_layer(const layer* layer);

        [[nodiscard]] bool is_running() const { return m_running; }
        [[nodiscard]] bool is_minimized() const { return m_minimized; }

    private:
        int m_exit_code{};
        bool m_running{true};

        bool m_minimized{false};

        std::vector<std::unique_ptr<layer>> m_layers{};
        std::mutex m_layers_mutex{};
    };
}
