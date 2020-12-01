#include "Engine.h"
#include "../Input/InputListener.h"
#include "../Interface/Menu.h"
Engine* Engine::s_Instance = nullptr;
Engine::Engine() {
	window = nullptr;
	renderer = nullptr;
	screenWidth = 1024;
	screenHeight = 576;
	fullScreen = false;
	isRunning = false;
	return;
}

Engine* Engine::GetInstance() {
	if (s_Instance == nullptr) {
		s_Instance = new Engine();
	}
	return s_Instance;
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
		}
	}
	return;
}

void Engine::HandleEvents() {
	InputListener::GetInstance()->Listen();
	return;
}

void Engine::Update() {
	return;
}

void Engine::Render() {
	SDL_RenderClear(renderer);
	Menu::GetInstance()->Render();
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
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	return;
}
