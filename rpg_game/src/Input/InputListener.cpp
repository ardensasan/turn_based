#include "InputListener.h"
InputListener* InputListener::s_Instance = nullptr;
InputListener::InputListener() {
	return;
}

InputListener* InputListener::GetInstance() {
	if (s_Instance == nullptr)
		s_Instance = new InputListener();
	return s_Instance;
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
}

void InputListener::KeyUp(SDL_Scancode key) {
	keyUp = key;
}