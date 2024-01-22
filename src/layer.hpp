#pragma once

namespace Sirius
{
    class layer
    {
    public:
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
    };
}
