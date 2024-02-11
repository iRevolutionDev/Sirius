#pragma once

namespace Sirius
{
    class window;

    class layer
    {
    public:
        friend class application;
        friend class window;

        virtual ~layer() = default;

        /**
         * @brief This function is called once when the layer is initialized.
         *
         * This function is used to load resources or initialize variables. It is called once when the layer is created.
         * @note This function is virtual and should be overridden in derived classes if needed.
         */
        virtual void on_init()
        {
        }

        /**
         * @brief This function is called every frame to render the layer.
         *
         * This function is used to draw the layer's content. It is called every frame during the application's main loop.
         * @note This function is virtual and should be overridden in derived classes if needed.
         */
        virtual void on_render()
        {
        }

        /**
         * @brief This function is called when the layer is attached to the application.
         *
         * This function is used to perform any setup required when the layer is added to the application's layer stack.
         * @note This function is virtual and should be overridden in derived classes if needed.
         */
        virtual void on_attach()
        {
        }

        /**
         * @brief This function is called when the layer is detached from the application.
         *
         * This function is used to perform any cleanup required when the layer is removed from the application's layer stack.
         * @note This function is virtual and should be overridden in derived classes if needed.
         */
        virtual void on_detach()
        {
        }

        /**
         * @brief This function is called every frame to update the layer.
         *
         * This function is used to update the layer's state. It is called every frame during the application's main loop.
         * @note This function is virtual and should be overridden in derived classes if needed.
         */
        virtual void on_update()
        {
        }

        /**
         * @brief This function is called when an event is received.
         *
         * This function is used to handle events. It is called whenever the application receives an event from the operating system.
         * @param event The event to handle.
         * @note This function is virtual and should be overridden in derived classes if needed.
         */
        virtual void on_event([[maybe_unused]] const SDL_Event& event)
        {
        }

        void set_window(const window* window)
        {
            m_window = window;
        }

        [[nodiscard]] const window* get_window() const
        {
            return m_window;
        }

    private:
        const window* m_window{};
    };
}
