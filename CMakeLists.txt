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

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_SHARED_LIBS FALSE)
set(LIBS
        SDL3::SDL3
)

file(COPY ${PROJECT_SOURCE_DIR}/res
        DESTINATION ${PROJECT_BINARY_DIR}/src/
)


add_subdirectory(src)