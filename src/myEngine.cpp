#include "myEngine.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>

namespace myEngine
{
	void init()
	{
		//Initialize SDL
		SDL_Init(SDL_INIT_EVERYTHING);

		//Set to double buffer (no flickering)
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	}
}