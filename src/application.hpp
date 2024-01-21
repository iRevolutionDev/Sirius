#pragma once

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

        template <typename T>
        void push_layer()
        {
            static_assert(std::is_base_of_v<layer, T>, "T must derive from layer");
            m_layers.emplace_back(std::make_unique<T>());
            m_layers.back()->on_attach();
        }

        void push_layer(std::unique_ptr<layer> layer);
        void pop_layer();

    private:
        int m_exit_code{};
        bool m_running{true};

        std::vector<std::unique_ptr<layer>> m_layers{};
    };
}