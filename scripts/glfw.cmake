include(FetchContent)

message(STATUS "Fetching GLFW")

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8
        GIT_PROGRESS TRUE
)

FetchContent_GetProperties(glfw)

if (NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    message(STATUS "Building GLFW")

    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif ()