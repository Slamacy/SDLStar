#include "GUI_Label.h"

#include <string>

void GUI_Label::draw(SDL_Renderer* renderer) {
	if (text == NULL) return;
	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_Rect renderRect;
	SDL_QueryTexture(tempTexture, NULL, NULL, &renderRect.w, &renderRect.h);
	renderRect.x = x;
	renderRect.y = y;
	SDL_RenderCopy(renderer, tempTexture, NULL, &renderRect);
}

void GUI_Label::set_text(const char* t) {
	text = t;
	if(textSurface)
		SDL_FreeSurface(textSurface);
	if (text == NULL) return;
	textSurface = TTF_RenderUTF8_Solid(font, text, colour);
}

void GUI_Label::set_colour(SDL_Colour colour)
{
	this->colour = colour;
}

SDL_Colour GUI_Label::get_colour()
{
	return this->colour;
}

void GUI_Label::set_pos(int* x, int* y)
{
	if (x != NULL)
		this->x = *x;
	if (y != NULL)
		this->y = *y;
}

void GUI_Label::get_pos(int* x, int* y)
{
	if(x != NULL)
		*x = this->x;
	if(y != NULL)
		*y = this->y;
}

GUI_Label::GUI_Label(const char* text, SDL_Colour colour, int x, int y, TTF_Font* f) {
	this->colour = colour;
	this->x = x;
	this->y = y;

	if (f == NULL) {
		f = TTF_OpenFont("../Resources/fonts/Brutel/Brutel-Black.ttf", 24);
	}
	font = f;

	set_text(text);
}

GUI_Label::~GUI_Label()
{
}
