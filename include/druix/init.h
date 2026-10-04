#pragma once

#include "pub-fwd.h"

namespace dx
{
    struct AppInitInfo
    {
        const char* appName = "Druix Application";
        uint32_t appVersion = 1;
    };

    bool Init(const AppInitInfo& appInfo);
    void Shutdown();
}