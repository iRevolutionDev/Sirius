#pragma once
#include "window_info.hpp"
#include "backend/vulkan_api.hpp"

namespace Sirius
{
    class window
    {
    public:
        window() = delete;
        explicit window(window_info info);

        window(const window&) = delete;
        ~window();

        void run() const;
        void close();

    private:
        void init();
        void update();

    private:
        window_info m_info;
        bool m_running;

        GLFWwindow* m_window;

        vulkan_api* m_api;
    };

    window* create_window(int argc, char** argv);
}
