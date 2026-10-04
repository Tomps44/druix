#include "druix/init.h"
#include "./global-lib.h"

namespace dx
{
    namespace dxIntern
    {
        dxLib g_Lib = dxLib{};
    }

    bool Init(const AppInitInfo& initInfo)
    {
        return dxIntern::g_Lib.device.Init(initInfo.appName, initInfo.appVersion);
    }
}