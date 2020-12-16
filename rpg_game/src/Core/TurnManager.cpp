#include "TurnManager.h"
#include <string>
TurnManager* TurnManager::s_Instance = nullptr;

TurnManager::TurnManager() {
	turnCount = 1;
	fontFile = "Assets/Fonts/Ancient Modern Tales.otf";
	fontSize = 100;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	color = { 255, 0, 0 };
	return;
}

void TurnManager::Update(std::vector<GameObject*> unitList) {
	std::vector<GameObject*>::iterator it;
	bool turnsEnded = true;
	for (it = unitList.begin();it != unitList.end();++it) {
		if (!(*it)->HasTurnEnded()) {
			turnsEnded = false;
		}
	}
	if (turnsEnded) {
		turnCount++;
		for (it = unitList.begin();it != unitList.end();++it) {
			(*it)->Reset();
			break;
		}
	}
}

void TurnManager::Render() {
	SDL_Surface* textSurface;
	SDL_Texture* texture;
	int textWidth = 100;
	int textHeight = 50;
	SDL_Renderer* renderer = Engine::GetInstance()->GetRenderer();
	SDL_Rect rect = { Engine::GetInstance()->GetScreenWidth() - textWidth, 0, textWidth, textHeight };
	std::string str = "Turn: " + std::to_string(turnCount);
	textSurface = TTF_RenderText_Solid(font, str.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textSurface);
	return;
}