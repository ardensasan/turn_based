#include "Menu.h"
Menu* Menu::s_Instance = nullptr;
Menu* Menu::GetInstance() {
	if (s_Instance == nullptr)
		s_Instance = new Menu();
	return s_Instance;
}

Menu::Menu() {
	menuString = { "Continue", "New Game", "Settings", "Exit"};
	fontFile = "Assets/Fonts/Ancient Modern Tales.otf";
	fontSize = 100;
	font = TTF_OpenFont(fontFile.c_str(),fontSize);
}

void Menu::Render() {
	int textWidth = 200;
	int textHeight = 50;
	int screenWidth = Engine::GetInstance()->GetScreenWidth();
	int screenHeight = Engine::GetInstance()->GetScreenHeight();
	SDL_Renderer* renderer = Engine::GetInstance()->GetRenderer();
	SDL_Color color = { 255, 255, 255 };
	SDL_Rect rect = { int((screenWidth - textWidth) / 2),int((screenHeight - textHeight) / 2),textWidth,textHeight };
	std::vector<std::string>::iterator it;
	for (it = menuString.begin();it != menuString.end();it++) {
		if (it == menuString.end() - 1) {
			textWidth /= 2;
			rect.x = int((screenWidth - textWidth) / 2);
			rect.w = textWidth;
		}
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, it->c_str(), color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, texture, NULL, &rect);
		rect.y += rect.h + 4;
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(textSurface);
	}
	std::cout << SDL_GetError();
}

void Menu::Clean() {
	TTF_CloseFont(font); 
	font = nullptr;
}