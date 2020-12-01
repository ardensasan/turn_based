#ifndef MENU_H
#define MENU_H
#include "../Core/Engine.h"
#include <iostream>
#include <vector>
class Menu
{
public:
	static Menu* GetInstance();
	void Update();
	void Render();
	void Clean();
private:
	Menu();
	static Menu* s_Instance;
	TTF_Font* font;
	int fontSize;
	std::string fontFile;
	std::vector<std::string> menuString;
	std::vector<SDL_Color> colorList;
	int currentChoice;
	bool keyPressed;
};
#endif

