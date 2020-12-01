#include "InputListener.h"
#include "../Core/Engine.h"
InputListener* InputListener::s_instance = nullptr;
InputListener::InputListener() {
	return;
}

InputListener* InputListener::GetInstance() {
	if (s_instance == nullptr)
		s_instance = new InputListener();
	return s_instance;
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