include(FetchContent)

FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.28.5
)

message(STATUS "Fetching SDL2...")
FetchContent_GetProperties(SDL2)
if (NOT SDL2_POPULATED)
    FetchContent_Populate(SDL2)

    set(SDL_SHARED OFF CACHE BOOL "" FORCE)
    set(SDL_STATIC ON CACHE BOOL "" FORCE)

    add_subdirectory(${sdl2_SOURCE_DIR} ${sdl2_BINARY_DIR})
endif ()