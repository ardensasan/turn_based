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
		}
	}
}