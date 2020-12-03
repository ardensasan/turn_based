#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
class GameObject
{
public:
	GameObject() {}
	virtual void Update() {}
	virtual void Render(){}
	virtual void Clean() {}
};
#endif

