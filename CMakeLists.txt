cmake_minimum_required(VERSION 3.27)
project(Sirius VERSION 0.1.0 DESCRIPTION "Sirius is a lightweight C++ library for creating rendering applications.")

# Project Directories
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(PUBLIC_HEADER_DIR "${PROJECT_SOURCE_DIR}/include")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

# Scripts Packages
message(STATUS "Fetching packages...")
include(scripts/sdl2.cmake)
include(scripts/imgui.cmake)

# Project Files
file(GLOB_RECURSE SRC_FILES
        "${SRC_DIR}/**.cpp"
        "${SRC_DIR}/**.hpp"
        "${SRC_DIR}/**.h"
)
file(GLOB_RECURSE PUBLIC_HEADER_FILES
        "${PUBLIC_HEADER_DIR}/**.hpp"
)

# Project Library
add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${PUBLIC_HEADER_FILES})

# Packages
find_package(Threads REQUIRED)

# Compiler Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)

source_group(TREE "${SRC_DIR}" PREFIX "src" FILES ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE "${PUBLIC_HEADER_DIR}/Sirius/")
target_precompile_headers(${PROJECT_NAME} PRIVATE "${SRC_DIR}/common.hpp")
target_include_directories(${PROJECT_NAME} PUBLIC "${SRC_DIR}")

target_include_directories(${PROJECT_NAME} PUBLIC
        "${SRC_DIR}"
        "${imgui_SOURCE_DIR}"
        "${SDL2_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} PUBLIC
        imgui
        ${CMAKE_THREAD_LIBS_INIT}
        SDL2::SDL2
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADER_FILES}")
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC "${PUBLIC_HEADER_DIR}")

add_subdirectory(examples)

# Platform Macros
if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC SIRIUS_PLATFORM_WINDOWS)
elseif (UNIX)
    target_compile_definitions(${PROJECT_NAME} PUBLIC SIRIUS_PLATFORM_LINUX)
endif ()