#ifndef ACTION_H
#define ACTION_H
#include "../Core/Engine.h"
#include <vector>
class Actions
{
public:
	Actions();
	bool HasMoved() { return hasMoved; }
	bool TurnEnded() { return turnEnded; }
	void Update();
	void Render();
private:
	std::vector<SDL_Color> colorList;
	std::vector<std::string> actionList;
	int currentChoice;
	TTF_Font* font;
	int fontSize;
	std::string fontFile;

	bool moveSelected;
	bool hasMoved;
	bool skillSelected;
	bool turnEnded;

	bool keyPressed;
};
#endif