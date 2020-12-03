#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player();
	void Update();
	void Render();
	void Clean();
private:
	int pixelSize;
	SDL_Rect rect;
};
#endif

