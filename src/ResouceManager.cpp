#include "ResourceManager.h"

namespace myEngine
{
    TextureCache ResourceManager::_textureCache;


    GLTexture ResourceManager::getTexture(std::string texturePath)
    {
        return _textureCache.getTexture(texturePath);
    }
}