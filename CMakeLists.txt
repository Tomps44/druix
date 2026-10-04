cmake_minimum_required(VERSION 3.26)
project(druix)

# gammalgebra is my own math library
add_subdirectory(third-party/gammalgebra)


set(
    DRUIX_PUB_H

    include/druix/druix.h
    include/druix/init.h
    include/druix/surface.h
)
set(
    DRUIX_PRIV_H

    src/setup.h
    src/platform.h
)
set(
    DRUIX_SRC

    src/init.cpp
    src/surface.cpp
)



add_library(druix STATIC ${DRUIX_PUB_H} ${DRUIX_PRIV_H} ${DRUIX_SRC})
target_link_libraries(
    druix
    PUBLIC
    gammalgebra
)
target_include_directories(
    druix
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)




if(WIN32)
    set(DRUIX_DEFAULT_BACKEND "D3D12")

elseif(APPLE)
    set(DRUIX_DEFAULT_BACKEND "METAL")

elseif(UNIX)
    set(DRUIX_DEFAULT_BACKEND "VULKAN")
    
endif()

set(DRUIX_DEFAULT_BACKEND "VULKAN")

set(DRUIX_BACKEND ${DRUIX_DEFAULT_BACKEND} CACHE STRING "Renderer backend")
set_property(
    CACHE DRUIX_BACKEND PROPERTY STRINGS 
    "VULKAN"
    "D3D12"
    "METAL"
)

if (DRUIX_BACKEND STREQUAL "VULKAN")
    if(APPLE)
        message(FATAL_ERROR "Vulkan is not supported on Apple devices !")

    endif()

    message(STATUS "Druix will be built with Vulkan as its backend !")


    find_package(Vulkan REQUIRED)
    target_link_libraries(
        druix
        PRIVATE
        Vulkan::Vulkan
    )
    target_sources(druix PRIVATE src/vk/device.h) 
    target_compile_definitions(druix PRIVATE DX_BACKEND_VULKAN)

elseif (DRUIX_BACKEND STREQUAL "D3D12")
    if(NOT WIN32)
        message(FATAL_ERROR "DirectX12 is only supported on Windows-based devices !")
    
    endif()

    message(STATUS "Druix will be built with DirectX12 as its backend !")

    target_compile_definitions(druix PRIVATE DX_BACKEND_D3D12)

elseif (DRUIX_BACKEND STREQUAL "METAL")
    if(NOT MACOS)
        message(FATAL_ERROR "Metal is only supported on Apple devices !")
    
    endif()

    message(STATUS "Druix will be built with Metal as its backend !")

    target_compile_definitions(druix PRIVATE DX_BACKEND_METAL)

else()
    message(FATAL_ERROR "The specified value for DRUIX_BACKEND is not valid ! Please input either VULKAN, D3D12 or METAL")

endif()




add_executable(druix-tests main.cpp)

target_link_libraries(druix-tests PRIVATE druix)




