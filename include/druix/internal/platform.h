#pragma once

#include "setup.h"

#if defined(DX_BACKEND_VULKAN)
    #include "vk/lib-data.h"
#endif

#define DX_BACKEND_NAMESPACE vulkan

namespace dx
{
    namespace dxIntern
    {
        
        struct dxLib
        {
            DX_BACKEND_NAMESPACE::Device device;
        };

        extern dxLib g_Lib;

    } // namespace dxIntern
} // namespace dx