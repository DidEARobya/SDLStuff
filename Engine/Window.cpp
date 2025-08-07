#include "Window.h"
#include <stdio.h>
#include <SDL3/SDL.h>
#include "Image.h"

Window::Window(int width, int height, const char* name)
{
	_window = SDL_CreateWindow(name, width, height, 0);

	if (_window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	_renderer = SDL_CreateRenderer(_window, NULL);

	if (_renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

Window::~Window()
{
	SDL_DestroyWindow(_window);
	_window = NULL;
}

SDL_Renderer* Window::GetRenderer()
{
	return _renderer;
}

void Window::SetName(const std::string& title)
{
	if (_window == NULL)
	{
		return;
	}

	SDL_SetWindowTitle(_window, title.c_str());
}


void Window::EndFrame()
{
	SDL_UpdateWindowSurface(_window);
}

void Window::SetImage(Image* image)
{
	_image = image;
}

void Window::Update()
{
	SDL_RenderClear(_renderer);
	
	if (_image != NULL)
	{
		_image->DrawImage();
	}

	SDL_RenderPresent(_renderer);
}

bool Window::IsValid()
{
	if (_window == NULL)
	{
		printf("Window was destroyed unexpectedly! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}
