#pragma once
#include "Window.h"
#include "Timer.h"

class App
{
public:
	App();
	~App();

	int StartApp();
	void CloseApp();

private:
	void Update();

public:
	float DeltaTime;
	float TestTimer;
	bool TestActive;

private:
	Window _window;
	Timer _timer;
};
