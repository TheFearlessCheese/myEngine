#include "InputManager.h"

namespace myEngine
{
    InputManager::InputManager():
        _mouseCoords(0.0f)
    {
    }
    
    InputManager::~InputManager()
    {
    }

    void InputManager::update()
    {
        //Loop through and copy keyMap to previousKeyMap
        for(auto& it:_keyMap)
        {
            _previousKeyMap[it.first] = it.second;
        }
    }

    void InputManager::pressKey(unsigned int keyID)
    {
        _keyMap[keyID] = true;
    }
    
    void InputManager::releaseKey(unsigned int keyID)
    {
        _keyMap[keyID] = false;
    }
    
    void InputManager::setMouseCoords(float x, float y)
    {
        _mouseCoords.x = x;
        _mouseCoords.y = y;
    }
    
    bool InputManager::isKeyDown(unsigned int keyID)
    {
        auto it = _keyMap.find(keyID);
        if (it != _keyMap.end())
        {
            return it->second;
        }
        return false;
    }

    bool InputManager::isKeyPressed(unsigned int keyID)
    {
        bool isPressed;
        if(isKeyDown(keyID) == true && wasKeyDown(keyID) == false)
        {
            return true;
        }
        return false;
    }

    bool InputManager::wasKeyDown(unsigned int keyID)
    {
        auto it = _previousKeyMap.find(keyID);
        if (it != _previousKeyMap.end())
        {
            return it->second;
        }
        return false;
    }
}