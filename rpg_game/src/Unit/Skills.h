#ifndef SKILLS_H
#define SKILLS_H
#include <vector>
#include <string>
#include "../Core/Engine.h"
struct Skill
{
	std::string name;
	int range;
};
class Skills
{
public:
	Skills();
	void Reset();
	void Update();
	void SetSelected(bool b) { selected = b; }
	bool Selected() { return selected; }
	void Render();
private:
	std::vector<SDL_Color> colorList;
	int currentChoice;
	TTF_Font* font;
	int fontSize;
	std::string fontFile;
	bool keyPressed;
	bool selected; // skill command is selected
	bool skillSelected; // certain skill is selected
	std::vector<Skill> skillList;
};
#endif