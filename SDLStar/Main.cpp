#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "assert.h"
#include <iostream>

int main(int argc, char** argv) {
	/* initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		assert(0 && "Failed to initialize video!");
		exit(-1);
	}

	//Create application window and renderer
	//Improvements: make resolution const
	SDL_Window* window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!window) {
		assert(0 && "Failed to create window!");
		exit(-1);
	}

	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	if (TTF_Init() == -1) {
		assert(0 && "Failed to create ttf!");
		exit(-1);
	}

	//TODO
	//		Create Asset Manager Class for storing and classifying Visual & and Effect Assets
	//		Create Drawer Class to draw assets to screen
	//		Create Audio Manager
	//		Create User, Song, and whatever classes (we need to scope this shit once we know what we're doing)


	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}
