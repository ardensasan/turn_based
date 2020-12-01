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
	inline SDL_Renderer* GetRenderer() { return renderer; }
	inline int GetScreenWidth() { return screenWidth; }
	inline int GetScreenHeight() { return screenHeight; }
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	void Quit();
private:
	Engine();
	static Engine* s_Instance;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int screenWidth, screenHeight;
	bool fullScreen;
};

#endif // !ENGINE_H