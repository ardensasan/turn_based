#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "Animation.h"
#include "Position2D.h"
#include "../Unit/Skills.h"
#include "../Unit/Actions.h"
class Player : public GameObject
{
public:
	Player(int i);
	void Update();
	void Reset(); // reset the unit state
	bool HasTurnEnded() { return turnEnded; }
	void Render();
	void Clean();
private:
	Animation* animation;
	Position2D position;
	bool isSelected; //unit is selected
	bool keyPressed;
	bool turnEnded; //unit turn ended
	Skills* skills;
	Actions* actions;
};
#endif

