#include "ImageLoader.h"

namespace myEngine
{

    GLTexture ImageLoader::loadPNG(std::string filePath)
    {
        GLTexture texture = {};
        std::vector<unsigned char> in;
        std::vector<unsigned char> out;
        unsigned long width, height;

        //Read file to the buffer
        if (IOManager::readFileToBuffer(filePath, in) == false)
        {
            fatalError("Failed to load PNG file to buffer!");
        }

        //Decode PNG
        int errorCode = decodePNG(out, width, height, &(in[0]), in.size());
        if (errorCode != 0)
        {
            fatalError("decodePNG failed with error: " + std::to_string(errorCode));
        }

        //Generate and bind to texture
        glGenTextures(1, &(texture.id));
        glBindTexture(GL_TEXTURE_2D, texture.id);

        //Upload image data to texture and set parameters
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        //Generate Mipmap
        glGenerateMipmap(GL_TEXTURE_2D);

        //Unbind current texture
        glBindTexture(GL_TEXTURE_2D, 0);

        //Add textures width and height
        texture.width = width;
        texture.height = height;
        return texture;

    }
}