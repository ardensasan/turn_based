#include "InputListener.h"
InputListener* InputListener::s_Instance = nullptr;
InputListener::InputListener() {
	return;
}

void InputListener::Listen() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				Engine::GetInstance()->Quit();
				break;
			case SDL_KEYDOWN:
				KeyState = NULL;
				KeyDown();
				break;
			case SDL_KEYUP:
				KeyUp(event.key.keysym.scancode);
				break;
		}
	}
	return;
}

bool InputListener::GetKeyDown(SDL_Scancode key) {
	return (KeyState != NULL && KeyState[key]);
}

bool InputListener::GetKeyUp(SDL_Scancode key) {
	if (keyUp == key) {
		keyUp = SDL_SCANCODE_ALTERASE;
		return true;
	}
	else
		return false;
}


void InputListener::KeyDown() {
	KeyState = SDL_GetKeyboardState(NULL);
	return;
}

void InputListener::KeyUp(SDL_Scancode key) {
	keyUp = key;
	return;
}