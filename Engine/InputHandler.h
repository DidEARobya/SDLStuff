#pragma once
#include <SDL3/SDL_test.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	bool GetKeyPressed(SDL_Keycode key);
	bool GetKeyReleased(SDL_Keycode key);
	bool GetKeyHeld(SDL_Keycode key);

	void Update();
};