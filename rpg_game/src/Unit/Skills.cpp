#include "Skills.h"
#include "../Input/InputListener.h"
Skills::Skills() {
	currentChoice = 0;
	fontFile = "Assets/Fonts/Ancient Modern Tales.otf";
	fontSize = 100;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	currentChoice = 0;
	colorList = { {255, 255, 255} , {255, 0, 0} };
	keyPressed = true;
	skillList = { "Attack" , "Cancel"};
	return;
}

void Skills::Update() {
	if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
		keyPressed = false;
	}

	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
		keyPressed = true;
		if (skillList[currentChoice] == "Attack") {

		}
		else if (skillList[currentChoice] == "Cancel") {

		}
	}

	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_DOWN)) &&
		!keyPressed) {
		currentChoice = currentChoice > int(skillList.size() - 2) ? 0 : currentChoice + 1;
		keyPressed = true;
	}

	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_S) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_DOWN))
		&& keyPressed) {
		keyPressed = false;
	}

	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_UP)) &&
		!keyPressed) {
		currentChoice = currentChoice < 1 ? skillList.size() - 1 : currentChoice - 1;
		keyPressed = true;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_UP)) &&
		keyPressed) {
		keyPressed = false;
	}
}

void Skills::Render() {
	SDL_Surface* textSurface;
	SDL_Texture* texture;
	int textWidth = 30;
	int textHeight = 20;
	SDL_Renderer* renderer = Engine::GetInstance()->GetRenderer();
	SDL_Rect rect = { 0, 0, textWidth, textHeight };
	std::vector<std::string>::iterator it;
	int counter = 0;
	for (it = skillList.begin();it != skillList.end();++it) {
		SDL_Color color = (counter == currentChoice) ? colorList[1] : colorList[0]; // set red color for current choice or white color
		textSurface = TTF_RenderText_Solid(font, it->c_str(), color);
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, texture, NULL, &rect);
		rect.y += rect.h + 4;
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(textSurface);
		counter++;
	}
	return;
}