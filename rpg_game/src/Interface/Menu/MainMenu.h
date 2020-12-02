#ifndef MAINMENU_H
#define MAINMENU_H
#include "../../Core/Engine.h"
#include <iostream>
#include <vector>
class MainMenu
{
public:
	inline static MainMenu* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new MainMenu();
		return s_Instance;
	}
	void ReInitialize(); //reinitialize values
	void Update();
	void Render();
	void Clean();
private:
	MainMenu();
	static MainMenu* s_Instance;
	TTF_Font* font;
	int fontSize;
	std::string fontFile;
	std::vector<std::string> MainMenuString;
	std::vector<SDL_Color> colorList;
	int currentChoice;
	bool keyPressed;
};
#endif

