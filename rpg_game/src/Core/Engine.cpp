#include "Engine.h"
#include "../Input/InputListener.h"
#include "../Interface/Menu/MainMenu.h"
#include "../Interface/Menu/Settings.h"
#include "../Graphics/TextureManager.h"
Engine* Engine::s_Instance = nullptr;
Engine::Engine() {
	window = nullptr;
	renderer = nullptr;
	screenWidth = 1024;
	screenHeight = 576;
	fullScreen = false;
	isRunning = false;
	menuState = 1;
	return;
}

void Engine::Init() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	window = SDL_CreateWindow("turn_based_rpg", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, fullScreen ? 1:4);
	if (window == nullptr) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Window Error",
			"Failed to create window. Please reinstall the program.",
			NULL);
	}
	else {
		renderer = SDL_CreateRenderer(window, -1, (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
		if (renderer == nullptr) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
				"Renderer Error",
				"Failed to create renderer. Please reinstall the program.",
				NULL);
		}
		else {
			isRunning = true;
			MainMenu::GetInstance();
			Settings::GetInstance(); // load settings
			menuState = 1;
		}
	}
	return;
}

void Engine::HandleEvents() {
	InputListener::GetInstance()->Listen();
	return;
}

void Engine::SetMenuState(int i) {
	menuState = i;
	return;
}

void Engine::Update() {
	if (menuState == 1)
		MainMenu::GetInstance()->Update();
	else if (menuState == 2)
		Settings::GetInstance()->Update();
	else if (menuState == 4) { //initialize with new resolution
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		window = nullptr;
		renderer = nullptr;
		Init();
	}
	return;
}

void Engine::Render() {
	SDL_RenderClear(renderer);
	if (menuState == 1)
		MainMenu::GetInstance()->Render();
	if (menuState == 2)
		Settings::GetInstance()->Render();
	TextureManager::GetInstance()->Draw();
	SDL_RenderPresent(renderer);
	return;
}

void Engine::Quit() {
	isRunning = false;
	return;
}

void Engine::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = nullptr;
	renderer = nullptr;
	MainMenu::GetInstance()->Clean();
	Settings::GetInstance()->Clean();
	TextureManager::GetInstance()->Clean();
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	return;
}
