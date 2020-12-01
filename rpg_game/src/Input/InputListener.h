#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H
#include "../Core/Engine.h"
class InputListener
{
public:
	static InputListener* GetInstance();
	void Listen();
private:
	InputListener();
	static InputListener* s_instance;
};
#endif
