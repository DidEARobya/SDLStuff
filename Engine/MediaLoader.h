#pragma once
#include <SDL3/SDL.h>

class MediaLoader
{
public:
	MediaLoader();
	~MediaLoader();

	SDL_Surface* LoadImage(const char* filePath, SDL_PixelFormat* pixelFormat);
};