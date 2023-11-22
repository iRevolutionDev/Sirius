include(FetchContent)

message(STATUS "Fetching GLAD")

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_PROGRESS TRUE
)

FetchContent_GetProperties(glad)

if (NOT glad_POPULATED)
    FetchContent_Populate(glad)

    message(STATUS "Building GLAD")

    add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
endif ()

target_link_libraries(Sirius glfw glad)