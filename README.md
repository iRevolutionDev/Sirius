<h1 id="title" align="center">Sirius</h1>

<p align="center"><img src="https://socialify.git.ci/iRevolutionDev/Sirius/image?description=1&descriptionEditable=Lightweight%20multi%20platform%20imgui%20rendering%20framework&forks=1&issues=1&language=1&name=1&owner=1&pattern=Plus&stargazers=1&theme=Auto" alt="Sirius" width="640" height="320" /></p>

A rendering framework for imgui that is lightweight and works on multiple platforms. It is written in C++ and uses SDL2
for window creation and SDL Renderer for rendering.

## Features

- [x] Lightweight
- [x] Multi platform
- [x] Easy to use
- [x] Customizable
- [x] Fast
- [x] Open source

## Platforms

- [x] Windows
- [x] Linux
- [x] MacOS

## Dependencies

- [SDL2](https://www.libsdl.org/download-2.0.php)
- [ImGui](https://github.com/ocornut/imgui)

## Usage

```cpp
#include <Sirius/main.hpp>
#include "application.hpp"
#include "layer.hpp"
#include "imgui.h"

class demo final : public Sirius::layer
{
public:
    void on_render() override
    {
        ImGui::ShowDemoWindow();
    }
};


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
```

## License

Sirius is licensed under the [MIT License](https://mit-license.org/).