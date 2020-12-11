#ifndef CURSOR_H
#define CURSOR_H
#include <SDL.h>
#include "../../Object/Position2D.h"
class Cursor
{
public:
	static Cursor* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new Cursor();
		return s_Instance;
	}
	void SetCursorPosition(int x, int y);
	void Update();
	void SetUnitSelected(bool b) { unitSelected = b; }
	bool IsUnitSelected() { return unitSelected; }
	void SelectUnit(int x, int y);
	bool SelectPressed() { return selectPressed; }
	Position2D GetCursorPosition() { return position; }
	void Render();
private:
	static Cursor* s_Instance;
	Cursor();
	Position2D position;
	bool keyPressed; //
	unsigned int keyPressTimer; //timer before program reads hold button key
	bool selectPressed;
	bool unitSelected;
};

#endif