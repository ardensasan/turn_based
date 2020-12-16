#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
class GameObject
{
public:
	GameObject() {}
	virtual void Update() {}
	virtual bool HasTurnEnded() { return true; }
	virtual void Reset(){}
	virtual void Render(){}
	virtual void Clean() {}
};
#endif

