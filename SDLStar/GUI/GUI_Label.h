#pragma once
#include "interfaces/IDrawable.h"

#include "SDL_ttf.h"

class GUI_Label : public IDrawable
{
	private:
		const char* text;
		SDL_Colour colour;
		int x, y;
		SDL_Surface* textSurface;
		TTF_Font* font;

	public:
		void draw(SDL_Renderer* renderer);

		/*
		* Update the text
		*/
		void set_text(const char* text);

		/*
		* Update the colour
		*/
		void set_colour(SDL_Colour colour);

		/*
		* Get the colour
		*/
		SDL_Colour get_colour();

		/*
		* Update the position.
		* Set any option to NULL to ignore.
		*/
		void set_pos(int* x, int* y);

		/*
		* Get the position.
		* Set any option to NULL to ignore.
		*/
		void get_pos(int* x, int* y);

		/*
		* Create a new GUI Label and show a text.
		* text - the Text to show
		* colour - the Colour to use for the text
		* int x - the pos X for the label
		* int y - the pos Y for the label
		* font - the font to use. Defaults to Brutel-Black.ttf 24pt
		*/
		GUI_Label(const char* text, SDL_Colour colour = { 0, 0, 0 }, int x = 0, int y = 0, TTF_Font* font = NULL);
		~GUI_Label();
};

