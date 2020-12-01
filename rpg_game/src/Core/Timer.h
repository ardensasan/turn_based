#ifndef TIMER_H
#define TIMER_H
#include "SDL.h"
class Timer
{
public:
	static Timer* GetInstance();
	void Delay();
private:
	Timer();
	static Timer* s_Instance;
	int frameTime;
	uint32_t  frameStart;
};
#endif

