include(FetchContent)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.90
        GIT_PROGRESS TRUE
)

message(STATUS "Fetching imgui...")
FetchContent_GetProperties(imgui)
if (NOT imgui_POPULATED)
    FetchContent_Populate(imgui)

    file(GLOB SRC_IMGUI
            "${imgui_SOURCE_DIR}/*.cpp"
            "${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp"
            "${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp"
            "${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer2.cpp"
    )

    add_library(imgui STATIC ${SRC_IMGUI})
    source_group(TREE ${imgui_SOURCE_DIR} PREFIX "imgui" FILES ${SRC_IMGUI})
    target_include_directories(imgui PUBLIC
            "${imgui_SOURCE_DIR}"
            "${imgui_SOURCE_DIR}/backends"
            "${imgui_SOURCE_DIR}/misc/cpp"
            "${SDL2_SOURCE_DIR}/include"
    )
endif ()
set_property(TARGET imgui PROPERTY CXX_STANDARD 23)