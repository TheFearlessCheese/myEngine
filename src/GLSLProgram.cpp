#include "GLSLProgram.h"

namespace myEngine
    {
    //Public

    GLSLProgram::GLSLProgram(): _vertexShaderID(0), _fragmentShaderID(0), _numAttributes(0)
    {
    }

    GLSLProgram::~GLSLProgram()
    {
    }

    void GLSLProgram::compileShaders(const std::string &vertexShaderFilepath, const std::string &fragmentShaderFilepath)
    {
        // Create program object
        _programID = glCreateProgram();
        
        //Create Vertex Shader
        _vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        //Created Vertex Shader error checking
        if (_vertexShaderID == 0)
        {
            fatalError("Failed to create Vertex Shader!");
        }

        //Create Fragment Shader
        _fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        //Created Fragment Shader error checking
        if (_fragmentShaderID == 0)
        {
            fatalError("Failed to create Fragment Shader!");
        }

        //Compile shaders
        compileShader(vertexShaderFilepath, _vertexShaderID);
        compileShader(fragmentShaderFilepath, _fragmentShaderID);
    }



    void GLSLProgram::linkShaders()
    {

        //Attach our shaders to our program
        glAttachShader(_programID, _vertexShaderID);
        glAttachShader(_programID, _fragmentShaderID);

        //Link our program
        glLinkProgram(_programID);


        //Error checking shaders got linked
        GLint isLinked = 0;
        glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<char> errorLog(maxLength);
            glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);
            
            glDeleteProgram(_programID);
            
            glDeleteShader(_vertexShaderID);
            glDeleteShader(_fragmentShaderID);

            std::printf("%s\n", &(errorLog[0]));
            fatalError("Shaders failed to link!");
        }

        //Detach shaders after a successful link and delete shader IDs
        glDetachShader(_programID, _vertexShaderID);
        glDetachShader(_programID, _fragmentShaderID);

        glDeleteShader(_vertexShaderID);
        glDeleteShader(_fragmentShaderID);
    }

    void GLSLProgram::addAttribute(const std::string &attributeName)
    {
        //Bind attribute location
        glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());
    }

    GLint GLSLProgram::getUniformLocation(const std::string &uniformName)
    {
        //Get uniform location
        GLint location = glGetUniformLocation(_programID, uniformName.c_str());
        //Get uniform location error checking
        if (location == GL_INVALID_INDEX)
        {
            fatalError("Uniform " + uniformName + " not found in shader!");
        }

        return location;
    }

    void GLSLProgram::use()
    {
        //Enable shader and all its attributes
        glUseProgram(_programID);
        for (int i = 0; i < _numAttributes; i++)
        {
            glEnableVertexAttribArray(i);
        }
    }

    void GLSLProgram::unuse()
    {
        //Disable shader and all its attributes
        glUseProgram(0);
        for (int i = 0; i < _numAttributes; i++)
        {
            glDisableVertexAttribArray(i);
        }
    }

    //Private 

    void GLSLProgram::compileShader(const std::string &filepath, GLuint &id)
    {
        //Load code from shader files
        std::ifstream shaderFile(filepath);
        //Load code from shader files error cheking
        if(shaderFile.fail())
        {
            perror(filepath.c_str());
            fatalError("Failed to open " + filepath + "\n");
        }

        //Read data from shader file to one string
        std::string fileContents = "";
        std::string line;

        while(std::getline(shaderFile, line))
        {
            fileContents += line + "\n";
        }

        shaderFile.close();

        //Set shader source and compile
        const char* contentPtr = fileContents.c_str();
        glShaderSource(id, 1, &contentPtr, nullptr);

        glCompileShader(id);

        //Shader file error checking
        GLint success = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);

        if (success == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<char> errorLog(maxLength);
            glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

            glDeleteShader(id);
            
            std::printf ("%s\n", &(errorLog[0]));
            fatalError(filepath + " failed to compile!");
        }

    }
}