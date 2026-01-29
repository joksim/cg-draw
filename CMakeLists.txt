cmake_minimum_required(VERSION 4.0)
project(cg-draw)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.32.10
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL2)

#FetchContent_Declare(
#        SDL2_image
#        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
#        GIT_TAG release-2.8.8
#        GIT_SHALLOW TRUE
#        GIT_PROGRESS TRUE
#)

# START ADDITION
#set(SDL2IMAGE_INSTALL OFF)
set(BUILD_SHARED_LIBS FALSE)
# END ADDITION

#FetchContent_MakeAvailable(SDL2_image)

add_executable(cg-draw main.cpp)
target_link_libraries(cg-draw SDL2::SDL2main SDL2::SDL2-static
        # SDL2_image::SDL2_image-static
)