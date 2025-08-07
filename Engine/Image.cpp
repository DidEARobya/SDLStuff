#include "Image.h"
#include "MediaLoader.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_test.h>
#include <SDL3/SDL_rect.h>

Image::Image(SDL_Renderer* renderer, float x, float y, float w, float h)
{
	_renderer = std::shared_ptr<SDL_Renderer>(renderer);
	_rect = new SDL_FRect{ x, y, w, h };
}
Image::~Image()
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;
	_rect = NULL;
}

void Image::SetImage(const char* filePath, SDL_PixelFormat pixelFormat)
{
	if (_renderer.get() == NULL)
	{
		printf("Image had invalid renderer! SDL Error: %s\n", SDL_GetError());
		return;
	}

	MediaLoader* mediaLoader = new MediaLoader();
	SDL_Surface* surface = mediaLoader->LoadImage(filePath, &pixelFormat);
	delete mediaLoader;

	if (surface == NULL)
	{
		return;
	}

	_texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);
	SDL_DestroySurface(surface);

	if (_texture == NULL)
	{
		printf("Image failed to create texture from surface! SDL Error: %s\n", SDL_GetError());
	}
}

void Image::DrawImage()
{
	SDL_RenderTexture(_renderer.get(), _texture, NULL, _rect);
}
