#include "Actions.h"
#include "../Input/InputListener.h"
#include "../Interface/Cursor/Cursor.h"
#include "../Object/ActionManager.h"
Actions::Actions() {
	currentChoice = 0;
	fontFile = "Assets/Fonts/Ancient Modern Tales.otf";
	fontSize = 100;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	currentChoice = 0;
	actionList = { "Move", "Skill", "End" };
	colorList = { {255, 255, 255} , {255, 0, 0} };
	skillSelected = false;
	moveSelected = false;
	hasMoved = false;
	turnEnded = false;
	keyPressed = true;
	return;
}

void Actions::Reset() {
	skillSelected = false;
	moveSelected = false;
	hasMoved = false;
	turnEnded = false;
	keyPressed = true;
	currentChoice = 0;
	return;
}

void Actions::Update() {
		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
			keyPressed = true;
			if (actionList[currentChoice] == "Move") {
				moveSelected = true;
				ActionManager::GetInstance()->SetMoveSelected(true);
				Cursor::GetInstance()->SetMoveSelected(true);
			}
			else if (actionList[currentChoice] == "Skill") {
				skillSelected = true;
			}
			else if (actionList[currentChoice] == "End") {
				turnEnded = true;
				ActionManager::GetInstance()->Reset();
			}
		}
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
			keyPressed = false;
		}

		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W) && !keyPressed) {
			keyPressed = true;
			if (currentChoice < 1 || (hasMoved && currentChoice < 2)) {
				currentChoice = actionList.size() - 1;
			}
			else {
				currentChoice--;
			}
		}
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_W) && keyPressed) {
			keyPressed = false;
		}

		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S) && !keyPressed) {
			keyPressed = true;
			if (currentChoice > int(actionList.size() - 2)) {
				currentChoice = hasMoved ? 1 : 0;
			}
			else {
				currentChoice++;
			}
		}
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_S) && keyPressed) {
			keyPressed = false;
		}
	return;
}

void Actions::Render() {
	SDL_Surface* textSurface;
	SDL_Texture* texture;
	int textWidth = 30;
	int textHeight = 20;
	SDL_Renderer* renderer = Engine::GetInstance()->GetRenderer();
	SDL_Rect rect = { 0, 0, textWidth, textHeight };
	std::vector<std::string>::iterator it;
	int counter = 0;
	for (it = actionList.begin();it != actionList.end();++it) {
		if (*it == "Move" && hasMoved) {
			//dont display move command
		}
		else {
			SDL_Color color = (counter == currentChoice) ? colorList[1] : colorList[0]; // set red color for current choice or white color
			textSurface = TTF_RenderText_Solid(font, it->c_str(), color);
			texture = SDL_CreateTextureFromSurface(renderer, textSurface);
			SDL_RenderCopy(renderer, texture, NULL, &rect);
			rect.y += rect.h + 4;
			SDL_DestroyTexture(texture);
			SDL_FreeSurface(textSurface);
		}
		counter++;
	}
	return;
}