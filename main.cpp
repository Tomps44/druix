#include "druix/druix.h"

#include <iostream>


int main() 
{
    // The API might potentially look like that (unfinished) :

    dx::AppInitInfo initInfo {
        .appName = "Druix App",
        .appVersion = 1000
    }

    if (!dx::Init(initInfo))
    {
        std::cerr << "Couldn't initialize druix !\n";
        return -1;
    }
    

    // dx::HSurfaceDesc surfDesc{
    //     .nativeWindowSize = glb::Vec2u{640, 360},
    //     .surfaceSize = glb::Vec2u{320, 180},
    //     .surfaceOffset = glb::Vec2u{320, 180}
    // };

    // dx::HSurface hsurf = dx::CreateHSurface(surfDesc);

    // dx::HSurfaceID id = 1;
    // if (!dx::CreateHSurface(id, surfDesc))
    // {
    //     std::cout << "Couldn't create dx::HSurface !\n";
    // }


    // dx::ClearHSurface(id, ...);

    // dx::HCommand drawCommand;

    // dx::SubmitHCommand(id, drawCommand) 


    // *the user handles window events*

    // dx::DestroyHSurface(id);
    // dx::Shutdown();

    // // End of API presentation


    return 0;
}