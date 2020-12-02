#include "Timer.h"
#include "SDL.h"
Timer* Timer::s_Instance = nullptr;
const int FPS = 60;
const int FRAMEDELAY = 1000 / FPS;
Timer::Timer() {
	frameTime = 0;
	frameStart = 0;
	return;
}

void Timer::Delay() {
	frameTime = SDL_GetTicks() - frameStart;
	if (FRAMEDELAY > frameTime) {
		SDL_Delay(FRAMEDELAY - frameTime);
	}
	frameStart = SDL_GetTicks();
	return;
}