#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H
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
	void Reset();
	void Update();
private:
	ActionManager();
	static ActionManager* s_Instance;
	bool UnitSelected;
	bool moveSelected;
	bool skillSelected;
};

#endif