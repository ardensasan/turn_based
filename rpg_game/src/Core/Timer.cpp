#include "Timer.h"
#include "SDL.h"
Timer* Timer::s_Instance = nullptr;
const int FPS = 60;
const int FRAMEDELAY = 1000 / FPS;
Timer::Timer() {
	frameTime = 0;
	frameStart = 0;
}

Timer* Timer::GetInstance() {
	if (s_Instance == nullptr)
		s_Instance = new Timer();
	return s_Instance;
}

void Timer::Delay() {
	frameTime = SDL_GetTicks() - frameStart;
	if (FRAMEDELAY > frameTime) {
		SDL_Delay(FRAMEDELAY - frameTime);
	}
	frameStart = SDL_GetTicks();
}