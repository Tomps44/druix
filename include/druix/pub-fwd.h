#pragma once

#include <cstdint>

namespace dx
{
    typedef uint16_t dxUUID;
    typedef uint16_t dxGEN;
}


#define DX_MAKE_HANDLE(name) \
    struct name              \
    {                        \
        ::dx::dxUUID uid;    \
        ::dx::dxGEN gen;     \
    };


#if defined(DX_BACKEND_VULKAN)
    #define GLB_SET_COORDINATE_SYSTEM_LH
    #define GLB_SET_Z_RANGE_0_1
    #define GLB_SET_Y_AXIS_DOWNWARDS
    #define GLB_SET_ROTATION_ORDER_YXZ
    #define GLB_SET_ROTATION_TYPE_INTRINSIC
    #define GLB_FORCE_SIMD_SSE2
    #include "glb/glb.h"
    
#elif DX_BACKEND_D3D12
    #define GLB_SET_COORDINATE_SYSTEM_LH
    #define GLB_SET_Z_RANGE_0_1
    #define GLB_SET_Y_AXIS_UPWARDS
    #define GLB_SET_ROTATION_ORDER_YXZ
    #define GLB_SET_ROTATION_TYPE_INTRINSIC
    #define GLB_FORCE_SIMD_SSE2
    #include "glb/glb.h"
    

#elif DX_BACKEND_METAL
    #define DX_BACKEND_NAMESPACE metal

    #define GLB_SET_COORDINATE_SYSTEM_LH
    #define GLB_SET_Z_RANGE_0_1
    #define GLB_SET_Y_AXIS_UPWARDS
    #define GLB_SET_ROTATION_ORDER_YXZ
    #define GLB_SET_ROTATION_TYPE_INTRINSIC
    #define GLB_FORCE_SIMD_SSE2
    #include "glb/glb.h"
    
#endif

