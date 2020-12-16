#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H
#include "Position2D.h"
#include "../Unit/Skills.h"
class ActionManager
{
public:
	static ActionManager* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new ActionManager();
		return s_Instance;
	}
	void SetMoveSelected(bool b) { moveSelected = b; }
	void SetSkillSelected(bool b) { skillSelected = b; }
	bool MoveSelected() { return moveSelected; }
	bool SkillSelected() { return skillSelected; }
	Position2D GetUnitPosition() { return unitPosition; }
	Skill GetSkillDetails() { return skill; }
	void Reset();
	void UpdatePosition(Position2D unitPosition); // position of the unit
	void SetSkillDetails(Skill skill);
private:
	ActionManager();
	static ActionManager* s_Instance;
	Position2D unitPosition;
	bool UnitSelected;
	bool moveSelected;
	bool skillSelected;
	Skill skill;
};

#endif