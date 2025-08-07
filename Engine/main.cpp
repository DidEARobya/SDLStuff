#include "App.h"
#include <stdio.h>
#include <conio.h>
#include <SDL3/SDL.h>

int main(int argc, char* args[])
{
	if (App{}.StartApp() == -1)
	{
		printf("Application Crashed: %s\n", SDL_GetError());
		_getch();
	};
	
	SDL_Quit();
	return -1;
}