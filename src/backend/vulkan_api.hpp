#pragma once
#include "common.hpp"

namespace Sirius
{
    class vulkan_api
    {
    public:
        vulkan_api();
        ~vulkan_api();

        vulkan_api(const vulkan_api&) = delete;
        vulkan_api& operator=(const vulkan_api&) = delete;

        vulkan_api(vulkan_api&&) = delete;
        vulkan_api& operator=(vulkan_api&&) = delete;

    private:
        void init();
        void destroy() const;

        void create_instance();
        void enumarate_physical_devices();

        VkInstance m_instance;
        VkDevice m_device;
        std::vector<const char*> m_instance_extensions_buffer;
        std::vector<const char*> m_instance_layers_buffer;

        uint32_t m_physical_device_count;
        std::vector<VkPhysicalDevice> m_physical_devices;

    public:
        [[nodiscard]] VkInstance get_instance() const noexcept { return m_instance; }
        [[nodiscard]] VkDevice get_device() const noexcept { return m_device; }

        [[nodiscard]] VkPhysicalDevice get_physical_device(const uint32_t index) const noexcept
        {
            return m_physical_devices[index];
        }

        VkSurfaceKHR m_surface{};
    };
}
