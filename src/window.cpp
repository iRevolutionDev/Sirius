#include "window.hpp"

#include <utility>

Sirius::window::window(window_info info)
    : m_info(std::move(info)),
      m_running(true),
      m_window(nullptr),
      m_api(nullptr)
{
    init();
}

Sirius::window::~window() noexcept
{
    close();
}

void Sirius::window::init()
{
    if (!glfwInit()) throw std::runtime_error("Failed to initialize GLFW");

    // TODO: Add support for other APIs (OpenGL, DirectX, Metal, etc.)
    if (!glfwVulkanSupported()) throw std::runtime_error("Vulkan is not supported");

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_window = glfwCreateWindow(
        m_info.width,
        m_info.height,
        m_info.title.c_str(),
        nullptr,
        nullptr
    );

    glfwGetFramebufferSize(m_window, &m_info.width, &m_info.height);

    m_api = new vulkan_api();

    if (const VkResult result = glfwCreateWindowSurface(m_api->get_instance(), m_window, nullptr, &m_api->m_surface);
        result != VK_SUCCESS)
        throw std::runtime_error("Failed to create window surface");
}

void Sirius::window::close()
{
    m_running = false;

    glfwTerminate();
    glfwDestroyWindow(m_window);
}


void Sirius::window::update()
{
}

void Sirius::window::run() const
{
    while (m_running)
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}
