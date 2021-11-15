#pragma once
#include <GL/glew.h>
#include <string>
#include <cstddef>
#include "Vertex.h"
#include "GLTexture.h"
#include "ResourceManager.h"

namespace myEngine
{
    class Sprite
    {
    public:
        Sprite(/* args */);
        ~Sprite();

        void init(float x, float y, float width, float height, const std::string texturePath);
        void draw();

    private:
        int _x;
        int _y;
        int _width;
        int _height;
        GLuint _vboID;
        GLTexture _texture;
    };
}