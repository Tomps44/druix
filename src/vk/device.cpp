#include "device.h"

namespace dx::dxIntern::vulkan
{
    bool Device::Init(const char* appName, uint32_t appVersion)
    {
        VkApplicationInfo appCi 
        {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pApplicationName = appName,
            .applicationVersion = appVersion,
            .apiVersion = VK_API_VERSION_1_3,
        };

        const char* const extensionNames[2] = 
        {
        #if DX_PLATFORM_WIN32
            "VK_KHR_surface", "VK_KHR_win32_surface"

        #elif 

        #endif
        };


        VkInstanceCreateInfo instanceCi
        {
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pApplicationInfo = &appCi,
            .enabledExtensionCount = 2,
            .ppEnabledExtensionNames = extensionNames,
            
        };

        VkResult result{};

        if (vkCreateInstance(&instanceCi, nullptr, &instance) != VK_SUCCESS))
        {
            
        }


    
        
    }
}