#include "MediaLoader.h"
#include <stdio.h>
#include <SDL3_image/SDL_image.h>

MediaLoader::MediaLoader()
{
}

MediaLoader::~MediaLoader()
{
}

SDL_Surface* MediaLoader::LoadImage(const char* filePath, SDL_PixelFormat* pixelFormat)
{
	SDL_Surface* surface = IMG_Load(filePath);

	if (surface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", filePath, SDL_GetError());
		return NULL;
	}

	SDL_Surface* optimisedSurface = SDL_ConvertSurface(surface, *pixelFormat);

	if (optimisedSurface == NULL)
	{
		printf("Unable to optimise image %s! SDL_image Error: %s\n", filePath, SDL_GetError());
	}
	else
	{
		SDL_DestroySurface(surface);
		surface = optimisedSurface;
	}

	return surface;
}
