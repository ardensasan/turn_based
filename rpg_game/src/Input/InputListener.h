#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H
#include "../Core/Engine.h"
class InputListener
{
public:
	inline static InputListener* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new InputListener();
		return s_Instance;
	}
	void Listen();
	bool GetKeyDown(SDL_Scancode key);
	bool GetKeyUp(SDL_Scancode key);
	void KeyDown();
	void KeyUp(SDL_Scancode key);
private:
	InputListener();
	static InputListener* s_Instance;
	const Uint8* KeyState;
	SDL_Scancode keyUp;
};
#endif
