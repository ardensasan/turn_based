#include "Engine.h"
#include "../Input/InputListener.h"
#include "../Interface/Menu/MainMenu.h"
#include "../Interface/Menu/Settings.h"
#include "../Graphics/TextureManager.h"
#include "../Object/Player.h"
#include "../Map/MapParser.h"
Player* player;
Engine* Engine::s_Instance = nullptr;
Engine::Engine() {
	window = nullptr;
	renderer = nullptr;
	screenWidth = 1024;
	screenHeight = 576;
	fullScreen = false;
	isRunning = false;
	gameState = 1;
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	return;
}

void Engine::Init() {
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
			TextureManager::GetInstance()->LoadTextures();
			MapParser::GetInstance()->Load("samplemap");
			player = new Player();
			gameState = 1;
		}
	}
	return;
}

void Engine::HandleEvents() {
	InputListener::GetInstance()->Listen();
	return;
}

void Engine::SetGameState(int i) {
	gameState = i;
	return;
}

void Engine::Update() {
	if (gameState == 0) { // in game
		player->Update();
	}
	else if (gameState == 1) // main menu
		MainMenu::GetInstance()->Update();
	else if (gameState == 2) // settings
		Settings::GetInstance()->Update();
	else if (gameState == 4) { //initialize with new resolution
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
	if (gameState == 0) {  // in game
		player->Render();
	}
	else if (gameState == 1)  // main menu
		MainMenu::GetInstance()->Render();
	else if (gameState == 2)  // settings
		Settings::GetInstance()->Render();
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
