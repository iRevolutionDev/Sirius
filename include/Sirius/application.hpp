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

        /**
         * @brief Pushes a new layer to the application.
         *
         * This function template creates a new layer of type T, adds it to the application's layer stack, and calls its on_attach function.
         * The type T must be a subclass of layer.
         *
         * @tparam T The type of the layer to be added. T must derive from layer.
         */
        template <typename T>
        void push_layer()
        {
            static_assert(std::is_base_of_v<layer, T>, "T must derive from layer");
            m_layers.emplace_back(std::make_unique<T>());
            m_layers.back()->on_attach();
        }

        /**
         * @brief Pushes a new layer to the application.
         *
         * This function takes a unique pointer to a layer, adds it to the application's layer stack.
         *
         * @param layer A unique pointer to the layer object to be added.
         */
        void push_layer(std::unique_ptr<layer> layer);

        /**
         * @brief Pops the top layer from the application.
         *
         * This function removes the top layer from the application's layer stack.
         */
        void pop_layer();

        /**
         * @brief Pops a specific layer from the application.
         *
         * This function removes a specific layer from the application's layer stack.
         *
         * @param layer A pointer to the layer object to be removed.
         */
        void pop_layer(const layer* layer);

        [[nodiscard]] bool is_running() const { return m_running; }
        [[nodiscard]] bool is_minimized() const { return m_minimized; }

    private:
        int m_exit_code{};
        bool m_running{true};
        const window* m_window{};

        bool m_minimized{false};

        std::vector<std::unique_ptr<layer>> m_layers{};
        std::mutex m_layers_mutex{};
    };
}
