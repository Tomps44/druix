#pragma once

#if defined(DX_BACKEND_VULKAN)
    #include "./vk/device.h"

#elif defined(DX_BACKEND_D3D12)
    #include "./d3d12/device.h"
    
#endif

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