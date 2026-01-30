cmake_minimum_required(VERSION 4.0)
project(cg-draw)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.4.0
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL3)


set(BUILD_SHARED_LIBS FALSE)

add_executable(cg-draw main.cpp)

target_link_libraries(cg-draw SDL3::SDL3
)