#include <Sirius/main.hpp>

Sirius::window* Sirius::create_window(int, char**)
{
    return new window(window_info{});
}
