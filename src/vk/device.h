#pragma once

#include "../platform.h"
#include <vulkan/vulkan.h>


namespace dx::dxIntern::vulkan
{
    struct Device
    {
        VkInstance instance;
        VkPhysicalDevice gpu;
        VkDevice device;

        bool Init(const char* appName, uint32_t appVersion);
    };
} // namespace dx::dxIntern::vulkan

