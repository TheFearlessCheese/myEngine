#include "EngineErrors.h"

namespace myEngine
{
	extern void fatalError(std::string errorString)
	{
		//Print Error
		std::cout << errorString << std::endl;
		std::cout << "Enter any key to quit...\n";
		int temp;
		std::cin >> temp;
		SDL_Quit();
		exit(-1);
	}
}