cmake_minimum_required(VERSION 3.23)
project(druix)

find_package(Vulkan REQUIRED)

add_subdirectory(third-party/gammalgebra)
# add_subdirectory(third-party/glfw)

set(
    SOURCE_CPP_X
    src/temp.cpp
    # src/init.cpp
    # src/window.cpp
)
set(
    SOURCE_H_X
    include/druix/internal/setup.h
    include/druix/internal/platform.h
    include/druix/init.h
    include/druix/window.h
)

set(
    SOURCE_H_VK
    include/druix/internal/vk/lib-data.h
)

add_library(druix STATIC ${SOURCE_CPP_X} ${SOURCE_H_X})
target_link_libraries(
    druix 
    PUBLIC 
    gammalgebra 
    # glfw  
    Vulkan::Vulkan
)

target_include_directories(
    druix
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


add_executable(druix-tests main.cpp)

target_link_libraries(druix-tests PRIVATE druix)




