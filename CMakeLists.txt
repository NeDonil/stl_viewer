cmake_minimum_required(VERSION 3.21)
project(stl_viewer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(vendor/spdlog)

include_directories(
    src
    vendor/spdlog/include
    )

file(GLOB all_sources
    "src/*.h"
    "src/*.cpp"
)

add_executable(stl_viewer
    ${all_sources}
)

target_link_libraries(stl_viewer spdlog)

