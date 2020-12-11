#ifndef ENGINE_H
#define ENGINE_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
class Engine
{
public:
	inline static Engine* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new Engine();
		}
		return s_Instance;
	}
	void Init();
	inline bool IsRunning() { return isRunning; }
	inline SDL_Renderer* GetRenderer() { return renderer; }
	inline int GetScreenWidth() { return screenWidth; }
	inline int GetScreenHeight() { return screenHeight; }
	bool GetFullScreen() { return fullScreen; }
	void SetScreenWidth(int width) { screenWidth = width; }
	void SetScreenHeight(int height) { screenHeight = height; }
	void SetFullScreen(bool b) { fullScreen = b; }
	void HandleEvents();
	void SetGameState(int i);
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
	int gameState; //0 = no menu/in game, 1 = main menu, 2 = settings, 3 = paused, 4 = change resolution
};

#endif // !ENGINE_H