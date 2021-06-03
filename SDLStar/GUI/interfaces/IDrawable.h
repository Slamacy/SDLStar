#pragma once

#include "SDL.h"

/*
* A Drawable Element
*/
class IDrawable {
	public:
		virtual void draw(SDL_Renderer* renderer) = 0;
};