#ifndef TIMER_H
#define TIMER_H
#include "SDL.h"
class Timer
{
public:
	inline static Timer* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new Timer();
		return s_Instance;
	}
	void Delay();
private:
	Timer();
	static Timer* s_Instance;
	int frameTime;
	uint32_t  frameStart;
};
#endif

