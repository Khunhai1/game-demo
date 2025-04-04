cmake_minimum_required(VERSION 3.20)
project(game-project CXX)

set(CMAKE_CXX_STANDARD 17)

if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "")
endif()

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)
find_package(flecs REQUIRED CONFIG)

add_executable(game src/main.cpp)

target_link_libraries(game PRIVATE
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
    SDL3_image::SDL3_image
    flecs::flecs
)
