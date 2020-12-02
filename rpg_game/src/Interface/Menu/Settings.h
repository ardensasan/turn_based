#ifndef SETTINGS_H
#define SETTINGS_H
#include "../../Core/Engine.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
class Settings
{
public:
	static Settings* GetInstance();
	void SetCurrentChoice(int i);
	void Update();
	void Render();
	void Clean();
private:
	Settings();
	static Settings* s_Instance;
	TTF_Font* font;
	int fontSize;
	std::string fontFile;
	std::vector<std::string> settingStrings;
	std::vector<std::string> resolutionStrings;
	std::vector< std::vector<int> > resolutions;
	std::vector<SDL_Color> colorList;
	int currentChoice;
	int resolutionChoice;
	int screenHeight;
	int screenWidth;
	bool keyPressed;
	bool fullScreen;
};
#endif

