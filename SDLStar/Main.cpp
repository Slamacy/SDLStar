#include "SDL.h"
#include <iostream>

#include "Context.h"
#include "Windows/MainMenu.cpp"

int main(int argc, char** argv) {

	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];

		if (strcmp(arg, "--debug")) {
			std::cout << "Debug" << std::endl;
			SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
		}
	}
	// Initialize Context
	Context::receive();
	SDL_CreateThread(Context::Loop, "mainLoop", (void *)NULL);
	Context::receive().push_window(new MainMenuWindow());
	return 0;
}