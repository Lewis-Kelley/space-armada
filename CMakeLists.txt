cmake_minimum_required(VERSION 2.6)
project(space-armada)
include(FindPkgConfig)

# enable_testing()

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

include_directories(${SDL2_INCLUDE_DIRS}
  ${SDL2IMAGE_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-g -O2 -Wall")

file(GLOB sources "src/*.cpp")

add_executable(space-armada ${sources})
target_link_libraries(space-armada ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
