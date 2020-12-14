#ifndef UNITACTION_H
#define UNITACTION_H
#include "../../Core/Engine.h"
#include <vector>
class UnitAction
{
public:
	static UnitAction* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new UnitAction();
		return s_Instance;
	}
	void Update();
	void Render();
	void ResetState(); // reset state of action menu
	bool IsInActionMenu() { return isInActionMenu; }
	bool IsMoveSelected() { return isMoveSelected; }
	bool IsSkillSelected() { return isSkillSelected; }
	bool IsEndSelected() { return isEndSelected; }
	void SetIsInAction(bool b) { isInActionMenu = b; }
	void SetHasMoved(bool b) { hasMoved = b; isMoveSelected = false; }
private:
	UnitAction();
	static UnitAction* s_Instance;
	bool isInActionMenu; // is in the action menu
	bool isMoveSelected; // move is selected
	bool isSkillSelected; // skill is selected
	bool isEndSelected; // end is selected
	bool hasMoved; // unit has used move in current turn
	std::vector<SDL_Color> colorList;
	std::vector<std::string> actionList;
	int currentChoice; 
	TTF_Font* font;
	int fontSize;
	std::string fontFile;
	bool keyPressed;
};
#endif