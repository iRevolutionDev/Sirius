#pragma once
#include "common.hpp"
#include "window.hpp"

namespace Sirius
{
    inline int main(const int argc, char** argv)
    {
        while (g_running)
        {
            const auto win = create_window(argc, argv);
            win->run();
            delete win;
        }

        return 0;
    }
}
