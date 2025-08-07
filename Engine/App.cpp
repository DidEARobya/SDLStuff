#include "App.h"
#include "MediaLoader.h"
#include <SDL3/SDL.h>
#include <SDL3/Sdl_test.h>
#include "Image.h"

App::App() : _window(800, 600, "Main App")
{
}

App::~App()
{
}

int App::StartApp()
{
	//TestActive = true;

	Image* background = new Image(_window.GetRenderer(), 0.0f, 0.0f, 400.0f, 300.0f);
	background->SetImage("FUCKYOUDEAGES.bmp", SDL_PIXELFORMAT_ARGB128_FLOAT);
	_window.SetImage(background);

	SDL_Event event;
	bool quit = false;

	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			if (_window.IsValid() == false)
			{
				return -1;
			}

			if (event.type == SDL_EVENT_QUIT)
			{
				quit = true;
				CloseApp();
			}

			Update();
		}
	}

	return 0;
}

void App::CloseApp()
{
	SDL_Quit();
}

void App::Update()
{
	//DeltaTime = _timer.Mark();
	_window.Update();
	_window.SetName(std::to_string(_timer.TimeElapsed()));

	if (TestActive == true)
	{
		TestTimer += DeltaTime;

		if (TestTimer >= 5.0f)
		{
			TestActive = false;
		}
	}

	_window.EndFrame();
}
