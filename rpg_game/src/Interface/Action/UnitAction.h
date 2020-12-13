#ifndef UNITACTION_H
#define UNITACTION_H
#include "../../Core/Engine.h"
#include <vector>
class UnitAction
{
public:
	UnitAction();
	void Update();
	void Render();
	void SetAction(); // set action to default and ignore multiple key press
	bool IsMoveSelected() { return isMoveSelected; }
private:
	TTF_Font* font;
	int fontSize;
	std::string fontFile;
	std::vector<SDL_Color> colorList;
	std::vector<std::string> actionList;
	int currentChoice;
	bool keyPressed;
	bool isInSkill;
	bool isMoveSelected; //move is selected as action
};
#endif

