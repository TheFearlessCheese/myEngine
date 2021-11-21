#pragma once

#include <glm/glm.hpp>
#include <unordered_map>

namespace myEngine
{
    class InputManager
    {
    public:
        InputManager();
        ~InputManager();

        void pressKey(unsigned int keyID);
        void releaseKey(unsigned int keyID);

        //setters
        void setMouseCoords(float x, float y);

        //getters
        glm::vec2 getMouseCoords() const {return _mouseCoords;}

        bool isKeyPressed(unsigned int keyID);

    private:
        std::unordered_map<unsigned int, bool> _keyMap; 
        glm::vec2 _mouseCoords;
    };
    
}