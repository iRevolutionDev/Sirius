#include "window.hpp"

#include <utility>

Sirius::window::window(window_info info)
    : m_info(std::move(info)),
      m_running(true)
{
}

Sirius::window::~window()
= default;

void Sirius::window::run()
{
}

void Sirius::window::close()
{
}
