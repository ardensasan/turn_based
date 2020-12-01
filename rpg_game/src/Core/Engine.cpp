#include "Engine.h"
Engine* Engine::s_instance = nullptr;
Engine::Engine() {
	window = nullptr;
	renderer = nullptr;
	screenWidth = 1024;
	screenHeight = 576;
	fullScreen = false;
	isRunning = false;
}

Engine* Engine::GetInstance() {
	if (s_instance == nullptr) {
		s_instance = new Engine();

	}
	return s_instance;
}

void Engine::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG) != 0 && TTF_Init() != 0) {
		SDL_Log("Failed to initialize libraries");
	}
	else {
		window = SDL_CreateWindow("turn_based_rpg", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, fullScreen ? 1:4);
		if (window == nullptr) {
			SDL_Log("Failed to create window");
		}
		else {
			renderer = SDL_CreateRenderer(window, -1, (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
			if (renderer == nullptr) {
				SDL_Log("Failed to create renderer");
			}
			else {
				isRunning = true;
			}
		}
	}
}

void Engine::HandleEvents() {

}

void Engine::Update() {

}

void Engine::Render() {

}

void Engine::Clean() {

}