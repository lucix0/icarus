cmake_minimum_required(VERSION 3.26)
project(Icarus LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# --- bgfx ---
set(BGFX_BUILD_EXAMPLES OFF CACHE BOOL "Build bgfx examples")
set(BGFX_BUILD_TOOLS    ON  CACHE BOOL "Build bgfx tools" FORCE)
FetchContent_Declare(
    bgfx
    GIT_REPOSITORY https://github.com/bkaradzic/bgfx.cmake.git
    GIT_TAG v1.166.9546-589
)
FetchContent_MakeAvailable(bgfx)

# --- GLFW ---
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.5.1
)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "")
FetchContent_MakeAvailable(glfw)

add_library(${PROJECT_NAME} STATIC
    src/stb_image.cpp
    include/icarus/stb_image.h

    src/application.cpp
    include/icarus/application.h

    src/deferred_renderer.cpp
    include/icarus/deferred_renderer.h

    src/material.cpp
    include/icarus/material.h

    src/shader_program.cpp
    include/icarus/shader_program.h

    src/texture.cpp
    include/icarus/texture.h
)
add_library(Icarus::Icarus ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    bgfx
    bx
    bimg
    glfw
)
