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

        virtual void on_render()
        {
        }

        virtual void on_attach()
        {
        }

        virtual void on_detach()
        {
        }

        virtual void on_update()
        {
        }

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
