#pragma once
#include "common.hpp"
#include "entrypoint.hpp"
#include "window.hpp"

extern Sirius::window* Sirius::create_window(int argc, char** argv);

#ifdef SIRIUS_PLATFORM_WINDOWS

#include <Windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    return Sirius::main(__argc, __argv);
}

#else

int main(int __argc, char** __argv)
{
    return Sirius::main(__argc, __argv);
}

#endif
