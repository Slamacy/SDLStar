#pragma once

#include "GUI/GUI_Window.h"
#include "Audio/SP_AudioDeviceManager.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "assert.h"
#include <vector>

enum class GAME_STATE {
	BOOT,
	LOADING,
	MENU,
	INGAME,
	PAUSED,
	FINISHING
};

class Context
{
private:
	Context();
	~Context();
	GAME_STATE current_state;
	std::vector<GUI_Window*> window_stack;
	SP_AudioDeviceManager* playbackManager;
	SP_AudioDeviceManager* recordingManager;
	SDL_Window* root_window;
	SDL_Renderer* root_renderer;

public:
	static Context& receive() { static Context ctx; return ctx; };
	void set_state(GAME_STATE state);
	void push_window(GUI_Window* window);
	void revert_window(int steps = 1);
	static int Loop(void *ptr);

	GAME_STATE get_state();
};

