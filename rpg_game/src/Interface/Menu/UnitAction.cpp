#include "UnitAction.h"
#include "../../Input/InputListener.h"
UnitAction* UnitAction::s_Instance = nullptr;
UnitAction::UnitAction() {
	isInActionMenu = false;
	isMoveSelected = false;
	isSkillSelected = false;
	isEndSelected = false;
	hasMoved = false;
	currentChoice = 0;
	fontFile = "Assets/Fonts/Ancient Modern Tales.otf";
	fontSize = 100;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	currentChoice = 0;
	actionList = { "Move", "Skill", "End" };
	colorList = { {255, 255, 255} , {255, 0, 0} };
	keyPressed = true;
}

void UnitAction::ResetState() {
	isInActionMenu = false;
	isMoveSelected = false;
	isSkillSelected = false;
	isEndSelected = false;
	hasMoved = false;
	currentChoice = 0;
	keyPressed = true;
}

void UnitAction::Update() {
	if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
		keyPressed = false;
	}

	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
		keyPressed = true;
		if (actionList[currentChoice] == "Move") {
			isMoveSelected = true;
			currentChoice++;
		}
		else if (actionList[currentChoice] == "Skill") {
			//skill menu here
		}
		else if (actionList[currentChoice] == "End") {
			isEndSelected = true;
		}
	}
	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_DOWN)) &&
		!keyPressed) {
		if (currentChoice > int(actionList.size() - 2)) {
			currentChoice = hasMoved ? 1 : 0;
		}
		else {
			currentChoice++;
		}
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
		if (currentChoice < 1 || (hasMoved && currentChoice < 2)) {
			currentChoice = actionList.size() - 1;
		}
		else {
			currentChoice--;
		}
		keyPressed = true;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_UP)) &&
		keyPressed) {
		keyPressed = false;
	}
}

void UnitAction::Render() {
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

