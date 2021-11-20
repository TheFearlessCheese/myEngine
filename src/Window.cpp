#include "Window.h"

namespace myEngine
{
	Window::Window()
	{
	}

	Window::~Window()
	{
	}

	void Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
	{
		Uint32 flags = SDL_WINDOW_OPENGL;

		if (currentFlags & INVISIBLE)
		{
			flags |= SDL_WINDOW_HIDDEN;
		}
		if (currentFlags & FULLSCREEN)
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}
		if (currentFlags & BORDERLESS)
		{
			flags |= BORDERLESS;
		}

		//Create window
		_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, currentFlags);

		//Error checking for window
		if (_sdlWindow == nullptr)
		{
			fatalError("SDL Window could not be created!");
		}

		//Create SDL_GLContext
		SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);

		//Error checking SDL_GLContext
		if (glContext == nullptr)
		{
			fatalError("SDL_GL Context could not be created!");
		}

		//Initialize GLEW and get extensions
		glewExperimental = GL_TRUE;
		GLenum error = glewInit();

		//Glew initialization error check
		if (error != GLEW_OK)
		{
			fatalError("Could not initialize glew!");
		}

		//Print OpenGL version
		std::printf("*** OpenGL version: %s ***\n", glGetString(GL_VERSION));

		//Background color
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

		//Set VSync
		SDL_GL_SetSwapInterval(1);

		//Enable alpha blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void Window::swapBuffer()
	{
		//Flush what we drew in buffer to screen
		SDL_GL_SwapWindow(_sdlWindow); 
	}
}