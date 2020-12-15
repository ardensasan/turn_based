#include "Skills.h"

Skills::Skills() {
	currentChoice = 0;
	fontFile = "Assets/Fonts/Ancient Modern Tales.otf";
	fontSize = 100;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	currentChoice = 0;
	colorList = { {255, 255, 255} , {255, 0, 0} };
	keyPressed = true;
	skillList = { "Attack" };
	return;
}

void Skills::Update() {

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