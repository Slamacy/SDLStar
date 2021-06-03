#pragma once

#include "SDL.h"

SDL_Rect paintSurface(SDL_Renderer* renderer, SDL_Surface* surface, int x, int y) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect textureTransform;

	SDL_QueryTexture(texture, NULL, NULL, &textureTransform.w, &textureTransform.h);
	textureTransform.x = x;
	textureTransform.y = y;

	SDL_RenderCopy(renderer, texture, NULL, &textureTransform);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	return textureTransform;
}

SDL_Rect paintTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {
	SDL_Rect textureTransform;

	SDL_QueryTexture(texture, NULL, NULL, &textureTransform.w, &textureTransform.h);
	textureTransform.x = x;
	textureTransform.y = y;

	SDL_RenderCopy(renderer, texture, NULL, &textureTransform);
	return textureTransform;
}