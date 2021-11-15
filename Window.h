#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include "EngineErrors.h"

namespace myEngine
{
    enum WindowFlags {INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4};

    class Window
    {

    public:
        Window();
        ~Window();

        void create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);

        void swapBuffer();

    private:
        SDL_Window* _sdlWindow;

    };
}