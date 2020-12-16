#ifndef SKILLS_H
#define SKILLS_H
#include <vector>
#include <string>
#include "../Core/Engine.h"
class Skills
{
public:
	Skills();
	void Update();
	void SetSelected(bool b) { selected = b; }
	bool Selected() { return selected; }
	void Render();
private:
	std::vector<std::string> skillList;
	std::vector<SDL_Color> colorList;
	int currentChoice;
	TTF_Font* font;
	int fontSize;
	std::string fontFile;
	bool keyPressed;
	bool selected; // skill is selected
};
#endif