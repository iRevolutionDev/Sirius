#include <Sirius/main.hpp>

#include "Sirius/application.hpp"
#include "demo.hpp"

Sirius::window* Sirius::create_window(int, char**)
{
    const auto current_window = new window(
        window_info{
            .title = "Basic App",
            .width = 800,
            .height = 600
        }
    );

    const auto app = new application();

    app->push_layer<demo>();

    current_window->set_app(app);
    return current_window;
}
