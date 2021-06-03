#pragma once

#include <vector>

#include "SDL.h"
#include "interfaces/IDrawable.h"

class GUI_Window
{
	private:
		std::vector<IDrawable*> drawableElements;
		int width;
		int height;
		const char* windowTitle;
	public:
		~GUI_Window();

		/*
		* Render the Window
		*/
		void render(SDL_Renderer* renderer);

		/*
		* Get the reference to an element from the render-stack or NULL if the element is out of range.
		*/
		IDrawable* getElement(int pos);

		/*
		* Add an element to the render-stack of the window
		*/
		int addElement(IDrawable* drawableElement);

		/*
		* Remove an element from the render-stack at position x
		*/
		void removeElement(int pos);

		/*
		* Clear the entire render-stack
		*/
		void clearElements();
};

