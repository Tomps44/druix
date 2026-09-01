#define DX_BACKEND_VULKAN
#include "druix/druix.h"

#include <iostream>

int main() 
{
    // The API might potentially look like that (unfinished) :

    if (!dx::Init())
    {
        std::cerr << "Couldn't initialize druix !\n";
        return -1;
    }

    dx::HNativeWindow hwnd = dx::CreateHNativeWindow(void*);
    dx::HSurface hsurf = dx::CreateHSurface(hwnd);

    // *the user handles window events*

    dx::ClearHSurface(hsurf, ...);

    dx::HCommand drawCommand;

    // ...


    // *the user handles window events*

    dx::DestroyHSurface(hsurf);
    dx::Shutdown();

    // End of API presentation

    

    
    


    return 0;
}