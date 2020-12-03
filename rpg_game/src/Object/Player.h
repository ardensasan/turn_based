#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "Animation.h"
class Player : public GameObject
{
public:
	Player();
	void Update();
	void Render();
	void Clean();
private:
	SDL_Rect rect;
	Animation* animation;
	int xPosition;
	int yPosition;
};
#endif

