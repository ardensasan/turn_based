#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "Animation.h"
#include "Position2D.h"
#include "../Unit/Skills.h"
class Player : public GameObject
{
public:
	Player();
	void Update();
	void Reset(); // reset the unit state
	void Render();
	void Clean();
private:
	Animation* animation;
	Position2D position;
	bool isSelected; //unit is selected
	bool keyPressed;
	bool isTurnEnded; //unit turn ended
	Skills* skills;
};
#endif

