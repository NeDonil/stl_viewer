cmake_minimum_required(VERSION 3.21)
project(stl_viewer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/Glad)
add_subdirectory(vendor/imgui)

add_definitions(-DGLFW_INCLUDE_NONE -DENABLE_ASSERTS)

include_directories(
    src
    vendor/spdlog/include
    vendor/glfw/include
    vendor/Glad/include
    vendor/glm
    vendor/imgui
    )

file(GLOB all_sources
    "src/*.h"
    "src/*.cpp"
    "src/Core/*.h"
    "src/Core/*.cpp"
    "src/Graphics/*.h"
    "src/Graphics/*.cpp"
    "src/Platform/OpenGL/*.h"
    "src/Platform/OpenGL/*.cpp"
    "src/ViewerApplication/*.h"
    "src/ViewerApplication/*.cpp"
    "src/ImGui/*.cpp"
    "src/ImGui/*.h"
)

add_executable(stl_viewer
    ${all_sources}
)

target_link_libraries(stl_viewer spdlog glfw Glad imgui)

message(${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(
        TARGET stl_viewer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/assets
                ${CMAKE_CURRENT_BINARY_DIR}/assets )

