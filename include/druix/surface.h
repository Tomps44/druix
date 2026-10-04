#pragma once

#include "pub-fwd.h"

namespace dx
{
    DX_MAKE_HANDLE(HSurface)
    struct HSurfaceDesc
    {
        void* nativeWindowPtr;
        glb::Vec2u nativeWindowSize = glb::Vec2u{1, 1};

        glb::Vec2u surfaceSize = glb::Vec2u{0, 0};
        glb::Vec2u surfaceOffset = glb::Vec2u{0, 0};
    };

    HSurface CreateHSurface(const HSurfaceDesc& desc);
    void DestroyHSurface(HSurface surface);    
}