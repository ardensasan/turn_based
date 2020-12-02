#include "MainMenu.h"
#include "../../Input/InputListener.h"
MainMenu* MainMenu::s_Instance = nullptr;
MainMenu* MainMenu::GetInstance() {
	if (s_Instance == nullptr)
		s_Instance = new MainMenu();
	return s_Instance;
}

MainMenu::MainMenu() {
	colorList = { {255, 255, 255} , {255, 0, 0} };
	MainMenuString = { "Continue", "New Game", "Settings", "Exit"};
	fontFile = "Assets/Fonts/Ancient Modern Tales.otf";
	fontSize = 100;
	font = TTF_OpenFont(fontFile.c_str(),fontSize);
	currentChoice = 1;
	keyPressed = false;
	return;
}

void MainMenu::Update() {
	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S) || 
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_DOWN)) && 
		!keyPressed) {
		currentChoice = currentChoice > 2 ? 0 : currentChoice+1;
		keyPressed = true;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_S)||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_DOWN))
		&& keyPressed) {
		keyPressed = false;
	}

	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_UP)) &&
		!keyPressed) {
		currentChoice = currentChoice < 1 ? 3 : currentChoice - 1;
		keyPressed = true;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_UP)) && 
		keyPressed) {
		keyPressed = false;
	}

	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
		if (currentChoice == 3) //exit
			Engine::GetInstance()->Quit();
		if (currentChoice == 2) //settings
			Engine::GetInstance()->SetMenuState(2);
		keyPressed = true;
	}

	if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
		keyPressed = false;
	}

}

void MainMenu::Render() {
	int textWidth = 200;
	int textHeight = 50;
	int screenWidth = Engine::GetInstance()->GetScreenWidth();
	int screenHeight = Engine::GetInstance()->GetScreenHeight();
	SDL_Renderer* renderer = Engine::GetInstance()->GetRenderer();
	SDL_Rect rect = { int((screenWidth - textWidth) / 2),int((screenHeight - textHeight) / 2),textWidth,textHeight };
	std::vector<std::string>::iterator it;
	int counter = 0;
	for (it = MainMenuString.begin();it != MainMenuString.end();++it) {
		if (it == MainMenuString.end() - 1) {
			textWidth /= 2;
			rect.x = int((screenWidth - textWidth) / 2);
			rect.w = textWidth;
		}
		SDL_Color color = (counter == currentChoice) ? colorList[1] : colorList[0]; // set red color for current choice
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, it->c_str(), color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, texture, NULL, &rect);
		rect.y += rect.h + 4;
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(textSurface);
		counter++;
	}
}

void MainMenu::Clean() {
	TTF_CloseFont(font); 
	font = nullptr;
}