cmake_minimum_required(VERSION 3.27)
project(Sirius VERSION 0.1.0 DESCRIPTION "Sirius is a lightweight C++ library for creating rendering applications.")

# Project Directories
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(PUBLIC_HEADER_DIR "${PROJECT_SOURCE_DIR}/include")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

# Project Files
file(GLOB_RECURSE SRC_FILES
        "${SRC_DIR}/**.cpp"
        "${SRC_DIR}/**.hpp"
)
file(GLOB_RECURSE PUBLIC_HEADER_FILES
        "${PUBLIC_HEADER_DIR}/**.hpp"
)

# Project Library
add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${PUBLIC_HEADER_FILES})

# Packages
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Vulkan
find_package(Vulkan REQUIRED)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

# Scripts Packages
message(STATUS "Fetching packages...")
include(scripts/glfw.cmake)
include(scripts/glad.cmake)
include(scripts/imgui.cmake)

# Compiler Options
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)

target_include_directories(${PROJECT_NAME} PRIVATE "${PUBLIC_HEADER_DIR}/Sirius/")
target_precompile_headers(${PROJECT_NAME} PRIVATE "${SRC_DIR}/common.hpp")
target_include_directories(${PROJECT_NAME} PUBLIC "${SRC_DIR}")

target_include_directories(${PROJECT_NAME} PRIVATE
        "${imgui_SOURCE_DIR}"
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