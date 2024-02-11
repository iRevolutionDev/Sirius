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

        /**
         * @brief Starts the window's main loop.
         *
         * This function starts the window's main loop, which handles events and updates the window's state.
         * @note This function is const, meaning it does not modify the state of the window object.
         */
        void run() const;

        /**
         * @brief Closes the window.
         *
         * This function closes the window and cleans up any resources associated with it.
         * @note This function is const, meaning it does not modify the state of the window object.
         */
        void close() const;

        /**
         * @brief Sets the application associated with the window.
         *
         * This function sets the application object associated with the window. The application object is used to handle events and manage the window's state.
         * @param app A pointer to the application object to associate with the window.
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void set_app(application* app) noexcept { m_app = app; }

        [[nodiscard]] SDL_Renderer* get_renderer() const noexcept { return m_renderer; }
        [[nodiscard]] SDL_Window* get_window() const noexcept { return m_window; }
        [[nodiscard]] application* get_app() const noexcept { return m_app; }

    private:
        [[nodiscard]] float get_scale() const;
        void init();

        window_info m_info;
        bool m_running;
        application* m_app{};

        SDL_Window* m_window{};
        SDL_Renderer* m_renderer{};
    };

    window* create_window(int argc, char** argv);
}
