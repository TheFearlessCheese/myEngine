#pragma once

#include <string>
#include <vector>
#include "GLTexture.h"
#include "picoPNG.h"
#include "IOManager.h"
#include "EngineErrors.h"

namespace myEngine
{
   class ImageLoader
   {

   public:
      static GLTexture loadPNG(std::string filePath);
   };
}