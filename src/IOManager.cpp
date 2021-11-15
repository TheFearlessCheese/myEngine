#include "IOManager.h"

namespace myEngine
{
    bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer)
    {
        //Setup file
        std::ifstream file(filePath, std::ios::binary);
        //File setup error checking
        if(file.fail())
        {
            perror(filePath.c_str());
            return false;
        }

        //Seek to the end
        file.seekg(0, std::ios::end);

        //Set the file size
        int fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        //Make sure no header gives extra bytes
        fileSize -= file.tellg();

        //Read file to buffer
        buffer.resize(fileSize);
        file.read((char *)&(buffer[0]), fileSize);

        return true;
    }
}