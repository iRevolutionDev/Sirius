#pragma once
#include "window_info.hpp"

namespace Sirius
{
    class window
    {
    public:
        window() = delete;
        explicit window(window_info info);

        window(const window&) = delete;
        ~window();

        void run();
        void close();

    private:
        window_info m_info;
        bool m_running;
    };

    window* create_window(int argc, char** argv);
}
