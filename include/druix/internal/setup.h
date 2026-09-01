#pragma once

#include <cstdint>

namespace dx
{
    namespace dxIntern
    {
        namespace vulkan{}
        namespace d3d12{}
        namespace metal{}

        struct dxLib;
    }

    typedef uint16_t UUID;
}


#define DX_MAKE_HANDLE(name) \
    struct name              \
    {                        \
        ::dx::UUID uid;      \
        uint16_t gen;        \
    };



#ifdef DX_BACKEND_VULKAN
    #define DX_BACKEND_NAMESPACE vulkan

    #define GLB_SET_COORDINATE_SYSTEM_LH
    #define GLB_SET_Z_RANGE_0_1
    #define GLB_SET_Y_AXIS_DOWNWARDS
    #define GLB_SET_ROTATION_ORDER_YXZ
    #define GLB_SET_ROTATION_TYPE_INTRINSIC
    #define GLB_FORCE_SIMD_SSE2
    #include "glb/glb.h"
    
// #elif DX_BACKEND_D3D12
//     #define DX_BACKEND_NAMESPACE d3d12

//     #define GLB_SET_COORDINATE_SYSTEM_LH
//     #define GLB_SET_Z_RANGE_0_1
//     #define GLB_SET_Y_AXIS_UPWARDS
//     #define GLB_SET_ROTATION_ORDER_YXZ
//     #define GLB_SET_ROTATION_TYPE_INTRINSIC
//     #define GLB_FORCE_SIMD_SSE2
//     #include "glb/glb.h"
    

// #elif DX_BACKEND_METAL
//     #define DX_BACKEND_NAMESPACE metal

//     #define GLB_SET_COORDINATE_SYSTEM_LH
//     #define GLB_SET_Z_RANGE_0_1
//     #define GLB_SET_Y_AXIS_UPWARDS
//     #define GLB_SET_ROTATION_ORDER_YXZ
//     #define GLB_SET_ROTATION_TYPE_INTRINSIC
//     #define GLB_FORCE_SIMD_SSE2
//     #include "glb/glb.h"
    

#else
    #error Please specify a renderer backend. The supported ones are : ( *fill this list when any backend works* )

#endif



#include <vector>
#include <string>
#include <filesystem>
#include <array>
#include <cstdint>
#include <cmath>
#include <string>
#include <string_view>