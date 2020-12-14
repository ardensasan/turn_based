#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "Animation.h"
#include "Position2D.h"
class Player : public GameObject
{
public:
	Player();
	void Update();
	void Render();
	void Clean();
private:
	Animation* animation;
	Position2D position;
	bool isSelected; //unit is selected
	bool keyPressed;
	bool moveSelected; //move is selected in the list of unit actions
	bool skillSelected; //skill is selected in the list of unit actions
};
#endif

