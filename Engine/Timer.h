#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	float Mark();
	float TimeElapsed() const;

private:
	std::chrono::steady_clock::time_point _last;
};
