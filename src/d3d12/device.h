#pragma once

#include "../setup.h"
#include <iostream>

namespace dx::dxIntern::d3d12
{
    struct Device
    {
        bool Init()
        {
            std::cout << "Building with D3D12 !\n";

            return true;
        }

        
    };

} // namespace dx::dxIntern::d3d12