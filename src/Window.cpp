#include "Window.h"

namespace Sirius 
{
    Window::Window(const WindowInfo& winInfo) 
        : m_winInfo(winInfo) 
    {
        Initialize();
    }

    Window::~Window()
    {
    }

    void Window::Run()
    {
    }

    void Window::Close()
    {
    }

    void Window::Initialize()
    {

    }

    void Window::Shutdown()
    {
    }
}