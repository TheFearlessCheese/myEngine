#pragma once
#include <string>
#include <GL/glew.h>
#include <fstream>
#include <vector>
#include "EngineErrors.h"

namespace myEngine
{
    class GLSLProgram
    {

    public:
        GLSLProgram();
        ~GLSLProgram();

        void compileShaders(const std::string &vertexShaderFilepath, const std::string &fragmentShaderFilepath);

        void linkShaders();

        void addAttribute(const std::string &attributeName);

        GLint getUniformLocation(const std::string &uniformName);

        void use();
        void unuse();
        
    private:

        GLuint _programID;
        GLuint _vertexShaderID;
        GLuint _fragmentShaderID;

        int _numAttributes;

        void compileShader(const std::string &filepath, GLuint &id); 
    };
}


