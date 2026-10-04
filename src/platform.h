#pragma once

#include "druix/pub-fwd.h"

namespace dx
{
    namespace dxIntern
    {
        namespace vulkan{}
        namespace d3d12{}
        namespace metal{}
    }
}


#define DX_PLATFORM_WIN32 0
#define DX_PLATFORM_LINUX 0
#define DX_PLATFORM_MACOS 0
#define DX_PLATFORM_FUCHSIA 0


#if defined(_WIN32)
    #undef DX_PLATFORM_WIN32
    #define DX_PLATFORM_WIN32 1

    #if !defined(NOMINMAX)
        #define NOMINMAX

    #endif

#elif defined(__ANDROID__)
    #undef DX_PLATFORM_ANDROID
    #define DX_PLATFORM_ANDROID 1

#elif defined(__APPLE__) || defined(__MACH__)
    #undef DX_PLATFORM_MACOS
    #define DX_PLATFORM_MACOS 1

#elif defined(__Fuchsia__)
    #undef DX_PLATFORM_FUCHSI
    #define DX_PLATFORM_FUCHSIA 1

#elif defined(__linux__)
    #undef DX_PLATFORM_LINUX
    #define DX_PLATFORM_LINUX 1

#else
    #error "The platform you are using is not supported !"

#endif



#define DX_BACKEND_VULKAN


#if defined(DX_BACKEND_VULKAN)
    #define DX_BACKEND_NAMESPACE vulkan


    #if DX_PLATFORM_WIN32
        #define VK_USE_PLATFORM_WIN32_KHR

    #elif DX_PLATFORM_ANDROID
        #define VK_US_PLAFTORM_KHR

    #elif DX_PLATFORM_LINUX
        #define VK_USE_PLATFORM_WAYLAND_KHR
        #define VK_USE_PLATFORM_WAYLAND_XLIB
        #define VK_USE_PLATFORM_WAYLAND_SCB

    #endif
    
#elif DX_BACKEND_D3D12
    #define DX_BACKEND_NAMESPACE d3d12

#elif DX_BACKEND_METAL
    #define DX_BACKEND_NAMESPACE metal
    
#endif



