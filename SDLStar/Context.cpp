#include "Context.h"

Context::Context() {
	set_state(GAME_STATE::BOOT);

	/* initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0) {
		assert(0 && "Failed to initialize video!");
		exit(-1);
	}

	//Create application window and renderer
	//Improvements: make resolution const
	SDL_Window* window = SDL_CreateWindow("SingParty", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, 1920, 1080);

	if (!window) {
		assert(0 && "Failed to create window!");
		exit(-1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");

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

	// Create Audio Device Managers
	playbackManager = new SP_AudioDeviceManager(SDL_FALSE);
	recordingManager = new SP_AudioDeviceManager(SDL_TRUE);
}

Context::~Context() {
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Context::set_state(GAME_STATE state) {
	current_state = state;
}

void Context::push_window(GUI_Window* window)
{
	window_stack.push_back(window);
}

void Context::revert_window(int steps)
{
	if (steps <= window_stack.size()) {
		window_stack.erase(window_stack.end() - steps, window_stack.end() - 1);
	}
}

SDL_Event* cEvent;

int Context::Loop(void *ptr)
{
	while(true){
		Uint32 frameStart = SDL_GetTicks();
		bool rendering = false;

		if (receive().window_stack.size() > 0) {
			SDL_RenderClear(receive().root_renderer);
			receive().window_stack.back()->render(receive().root_renderer);
			rendering = true;
		}
		SDL_PollEvent(cEvent);
		if (cEvent->type == SDL_EventType::SDL_QUIT) {
			return 0;
		}
		if(rendering)
			SDL_RenderPresent(receive().root_renderer);

		Uint32 frameTime = SDL_GetTicks() - frameStart;
		if (10 > frameTime) {
			SDL_Delay(10 - frameTime);
		}
	}
	return 0;
}

GAME_STATE Context::get_state() {
	return current_state;
}