#include "Cursor.h"
#include "../../Input/InputListener.h"
#include "../Camera.h"
#include "../../Graphics/TextureManager.h"
#include "../../Core/Engine.h"
#include "../../Map/GameMap.h"
Cursor::Cursor(int x, int y){
	cursorRect.x = x;
	cursorRect.y = y;
	cursorRect.w = 32;
	cursorRect.h = 32;
	keyPressed = false;
	keyPressTimer = 0;
	pixelSize = 32;
}

void Cursor::Update() {
	if (((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_UP)) &&
		!keyPressed) || (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W) ||
			InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_UP)) &&
		keyPressTimer > 10){
		cursorRect.y -= cursorRect.y > 0 ? pixelSize : 0;
		keyPressed = true;
		keyPressTimer = 0;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_UP)) &&
		keyPressed) {
		keyPressed = false;
		keyPressTimer = 0;
	}
	if (((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_DOWN)) &&
		!keyPressed) || (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S) ||
			InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_DOWN)) &&
		keyPressTimer > 10)
	{
		cursorRect.y += cursorRect.y < GameMap::GetInstance()->GetMapHeight()-pixelSize ? pixelSize : 0;
		keyPressed = true;
		keyPressTimer = 0;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_S) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_DOWN)) &&
		keyPressed) {
		keyPressed = false;
	}
	if (((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_A) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_LEFT)) &&
		!keyPressed) || (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_A) ||
			InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_LEFT)) &&
		keyPressTimer > 10)
	{
		cursorRect.x -= cursorRect.x > 0 ? pixelSize:0;
		keyPressed = true;
		keyPressTimer = 0;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_A) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_LEFT)) &&
		keyPressed) {
		keyPressed = false;
		keyPressTimer = 0;
	}
	if (((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_D) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RIGHT)) &&
		!keyPressed) || (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_D) ||
			InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RIGHT)) &&
		keyPressTimer > 10)
	{
		cursorRect.x += cursorRect.x < GameMap::GetInstance()->GetMapWidth()-pixelSize ? pixelSize : 0;
		keyPressed = true;
		keyPressTimer = 0;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_D) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RIGHT)) &&
		keyPressed) {
		keyPressed = false;
		keyPressTimer = 0;
	}
	keyPressTimer++;
	Camera::GetInstance()->Update(cursorRect.x, cursorRect.y);
	return;
}

void Cursor::Render() {
	TextureManager::GetInstance()->DrawRect(cursorRect);
}