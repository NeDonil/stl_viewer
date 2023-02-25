cmake_minimum_required(VERSION 3.21)
project(stl_viewer)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    src
    )

file(GLOB all_sources
	"src/*.h"
	"src/*.cpp"
)

add_executable(stl_viewer
    ${all_sources}
)

