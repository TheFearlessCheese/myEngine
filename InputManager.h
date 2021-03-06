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

        void update();

        void pressKey(unsigned int keyID);
        void releaseKey(unsigned int keyID);

        //setters
        void setMouseCoords(float x, float y);

        //getters
        glm::vec2 getMouseCoords() const {return _mouseCoords;}

        //Returns true if key is held down
        bool isKeyDown(unsigned int keyID);

        //Returns true if the key was just pressed
        bool isKeyPressed(unsigned int keyID);


    private:

        //If key was pressed
        bool wasKeyDown(unsigned int keyID);

        std::unordered_map<unsigned int, bool> _keyMap; 
        std::unordered_map<unsigned int, bool> _previousKeyMap; 
        glm::vec2 _mouseCoords;
    };
    
}