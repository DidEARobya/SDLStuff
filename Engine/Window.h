#pragma once
#include <sstream>
#include <vector>

struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;
struct SDL_Rect;
class Image;

class Window
{
public:
	Window(int width, int height, const char* name);
	~Window();

	SDL_Renderer* GetRenderer();

	void SetName(const std::string& title);
	void EndFrame();
	void SetImage(Image* image);

	void Update();

	bool IsValid();

private:
	SDL_Window* _window = NULL;
	SDL_Renderer* _renderer = NULL;

	Image* _image;
};