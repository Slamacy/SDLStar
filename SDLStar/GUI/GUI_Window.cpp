#include "GUI_Window.h"

GUI_Window::~GUI_Window() {
	drawableElements.clear();
}

void GUI_Window::render(SDL_Renderer* renderer) {
	for (int i = 0; i < drawableElements.size(); i++) {
		drawableElements.at(i)->draw(renderer);
	}

	SDL_RenderPresent(renderer);
}

IDrawable* GUI_Window::getElement(int pos) {
	if (pos < 0 || pos >= drawableElements.size())
		return NULL;
	else
		return drawableElements.at(pos);
}

int GUI_Window::addElement(IDrawable* drawableElement) {
	int pos = drawableElements.size();
	drawableElements.push_back(drawableElement);
	return pos;
}

void GUI_Window::removeElement(int pos) {
	drawableElements.erase(drawableElements.begin() + pos);
}

void GUI_Window::clearElements() {
	drawableElements.clear();
}