#include "TextureCache.h"


namespace myEngine
{
    TextureCache::TextureCache()
    {
    }

    TextureCache::~TextureCache()
    {
    }

    GLTexture TextureCache::getTexture(std::string texturePath)
    {
        //Lookup the texture in the map
        auto mit = _textureMap.find(texturePath);

        //Check if its not in the map
        if (mit == _textureMap.end())
        {
            //Load new texture
            GLTexture newTexture = ImageLoader::loadPNG(texturePath);

            //Insert into map
            _textureMap.insert(make_pair(texturePath, newTexture));

            //TEST
            std::cout << "Loaded Texture!\n";
            
            return newTexture;
        }
        
        //Return texture
        return mit->second;
    }
}