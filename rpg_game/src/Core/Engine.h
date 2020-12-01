#ifndef Engine_H
#define Engine_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
class Engine
{
public:
	static Engine* GetInstance();
	void Init();
	inline bool IsRunning() { return isRunning; }
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
private:
	Engine();
	static Engine* s_instance;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int screenWidth, screenHeight;
	bool fullScreen;
};

#endif // !ENGINE_H