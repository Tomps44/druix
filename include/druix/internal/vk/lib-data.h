#pragma once

#include "../setup.h"

#include <vulkan/vulkan.h>

namespace dx::dxIntern::vulkan
{
    struct Device
    {
        VkInstance instance;
        VkPhysicalDevice gpu;
        VkDevice device;
    };
} // namespace dx::dxIntern::vulkan

