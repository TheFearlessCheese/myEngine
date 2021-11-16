#include "Sprite.h"

namespace myEngine
    {
    //Public 
    Sprite::Sprite(): _vboID(0)
    {
    }

    Sprite::~Sprite()
    {
        //Get rid of Buffer when done
        if(_vboID != 0)
        {
            glDeleteBuffers(1, &_vboID);
        }
    }

    void Sprite::init(float x, float y, float width, float height, const std::string texturePath)
    {
        //Set private variables for sprite
        _x = x;
        _y = y;
        _width = width;
        _height = height;

        _texture = ResourceManager::getTexture(texturePath);

        //Generate Vertex Buffer Object
        if (_vboID == 0)
        {
            glGenBuffers(1, &_vboID);
        }

        //Create Vertex Data
        Vertex vertexData[6];

        // First Triangle position and UV
        vertexData[0].setPosition(x+width, y+height);
        vertexData[0].setUV(1.0f, 1.0f);

        vertexData[1].setPosition(x, y+height);
        vertexData[1].setUV(0.0f, 1.0f);

        vertexData[2].setPosition(x, y);
        vertexData[2].setUV(0.0f, 0.0f);

        //Second Triangle position and UV
        vertexData[3].setPosition(x, y);
        vertexData[3].setUV(0.0f, 0.0f);

        vertexData[4].setPosition(x+width, y);
        vertexData[4].setUV(1.0f, 0.0f);

        vertexData[5].setPosition(x+width, y+height);
        vertexData[5].setUV(1.0f, 1.0f);

        //Set colors of Triangles
        for (int i = 0; i < 6; i++)
        {
            vertexData[i].setColor(255, 0, 255, 255);
        }
        
        //Changing some colors
        vertexData[1].setColor(0, 0, 255, 255);
        vertexData[4].setColor(0, 255, 0, 255);

        //Bind the Buffer, upload the Buffer Data, then unbined it
        glBindBuffer(GL_ARRAY_BUFFER, _vboID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Sprite::draw()
    {
        glBindTexture(GL_TEXTURE_2D, _texture.id);
        
        glBindBuffer(GL_ARRAY_BUFFER, _vboID);


        //Draw
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    //Private
}