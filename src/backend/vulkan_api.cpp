#include "vulkan_api.hpp"

Sirius::vulkan_api::vulkan_api()
    : m_instance(VK_NULL_HANDLE),
      m_device(VK_NULL_HANDLE),
      m_physical_device_count(0)
{
    init();
}

Sirius::vulkan_api::~vulkan_api()
{
    destroy();
}

void Sirius::vulkan_api::init()
{
    uint32_t glfw_extension_count = 0;
    const auto glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
    for (uint32_t i = 0; i < glfw_extension_count; ++i)
    {
        m_instance_extensions_buffer.push_back(glfw_extensions[i]);
    }

    create_instance();
    enumarate_physical_devices();

    if (m_physical_device_count == 0) throw std::runtime_error("No physical devices found");

    uint32_t graphics_queue_family_index = UINT32_MAX;

    vkGetPhysicalDeviceQueueFamilyProperties(m_physical_devices[0], &m_physical_device_count, nullptr);
    std::vector<VkQueueFamilyProperties> family_propertieses(m_physical_device_count);
    vkGetPhysicalDeviceQueueFamilyProperties(m_physical_devices[0], &m_physical_device_count,
                                             family_propertieses.data());

    for (uint32_t i = 0; i < m_physical_device_count; ++i)
    {
        if (family_propertieses[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
        {
            graphics_queue_family_index = i;
            break;
        }
    }


    if (graphics_queue_family_index == UINT32_MAX)
    {
        throw std::runtime_error("Failed to find queue families");
    }

    constexpr float queue_priority = 1.0f;
    VkDeviceQueueCreateInfo device_queue_create_info{};
    device_queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    device_queue_create_info.queueFamilyIndex = graphics_queue_family_index;
    device_queue_create_info.queueCount = 1;
    device_queue_create_info.pQueuePriorities = &queue_priority;

    VkDeviceCreateInfo device_create_info{};
    device_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_create_info.queueCreateInfoCount = 1;
    device_create_info.pQueueCreateInfos = &device_queue_create_info;
    device_create_info.enabledExtensionCount = 0;
    device_create_info.ppEnabledExtensionNames = m_instance_extensions_buffer.data();
    device_create_info.enabledLayerCount = 0;
    device_create_info.ppEnabledLayerNames = m_instance_layers_buffer.data();

    vkCreateDevice(m_physical_devices[0], &device_create_info, nullptr, &m_device);
}

void Sirius::vulkan_api::destroy() const
{
    vkDestroyInstance(m_instance, nullptr);
}

void Sirius::vulkan_api::create_instance()
{
    VkApplicationInfo application_info{};
    application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.apiVersion = VK_API_VERSION_1_2;
    application_info.pApplicationName = "Sirius";
    application_info.pEngineName = "Sirius";
    application_info.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
    application_info.engineVersion = VK_MAKE_VERSION(0, 0, 1);

    VkInstanceCreateInfo instance_create_info{};
    instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.pApplicationInfo = &application_info;
    instance_create_info.enabledExtensionCount = static_cast<uint32_t>(m_instance_extensions_buffer.size());
    instance_create_info.ppEnabledExtensionNames = m_instance_extensions_buffer.data();
    instance_create_info.enabledLayerCount = static_cast<uint32_t>(m_instance_layers_buffer.size());
    instance_create_info.ppEnabledLayerNames = m_instance_layers_buffer.data();

    vkCreateInstance(&instance_create_info, nullptr, &m_instance);
}

void Sirius::vulkan_api::enumarate_physical_devices()
{
    vkEnumeratePhysicalDevices(m_instance, &m_physical_device_count, nullptr);
    m_physical_devices.resize(m_physical_device_count);
    vkEnumeratePhysicalDevices(m_instance, &m_physical_device_count, m_physical_devices.data());
}
