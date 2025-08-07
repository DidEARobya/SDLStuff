#pragma once
#include <sstream>

struct SDL_Renderer;
struct SDL_FRect;
struct SDL_Texture;
enum SDL_PixelFormat;

class Image
{
public:
	Image(SDL_Renderer* renderer, float x, float y, float w, float h);
	~Image();

	void SetImage(const char* filePath, SDL_PixelFormat pixelFormat);
	void DrawImage();

private:
	std::shared_ptr<SDL_Renderer> _renderer = NULL;
	SDL_Texture* _texture = NULL;
	SDL_FRect* _rect;
};