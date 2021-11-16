#pragma once

#include <SDL2/SDL.h>

namespace myEngine
{
    class FPSLimiter
    {
    public:
        FPSLimiter();

        void init(float maxFPS);
        //Setters
        void setMaxFPS(float maxFPS) {_maxFPS = maxFPS;}


        void begin();
        float end(); //will return current FPS

    private:
        void calculateFPS();

        float _fps;
        float _frameTime;
        float _maxFPS;
        unsigned int _startTicks;

    };
}