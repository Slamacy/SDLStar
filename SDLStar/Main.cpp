#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "assert.h"
#include <iostream>

#include "Audio/SP_AudioDeviceManager.h"

int main(int argc, char** argv) {

	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];

		if (strcmp(arg, "--debug")) {
			std::cout << "Debug" << std::endl;
			SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
		}
	}

	/* initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0) {
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

	
	// create Drawer and Game Manager objs here and set up loop

	SP_AudioDeviceManager* manager_playback = new SP_AudioDeviceManager(0);
	SP_AudioDeviceManager* manager_recording = new SP_AudioDeviceManager(1);

	SDL_Colour cBlack = { 255, 255, 255 };

	TTF_Font* vietnamPro = TTF_OpenFont("../Resources/fonts/BeVietnamPro/BeVietnamPro-Black.ttf", 500);

	SDL_Surface* text = TTF_RenderUTF8_Solid(vietnamPro, "SingParty", cBlack);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, text);
	SDL_RenderCopy(renderer, textTexture, NULL, NULL);
	SDL_RenderPresent(renderer);

	SDL_Event currentEvent;
	while (true)
	{
		SDL_PollEvent(&currentEvent);
		if (currentEvent.type == SDL_QUIT) {
			break;
		}
	}


	delete manager_playback;
	delete manager_recording;

	TTF_CloseFont(vietnamPro);

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}
