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
	bool isSelected;
	bool keyPressed;
};
#endif

