#include "Cursor.h"
#include "../../Input/InputListener.h"
#include "../Camera.h"
#include "../../Graphics/TextureManager.h"
#include "../../Core/Engine.h"
#include "../../Map/GameMap.h"
Cursor* Cursor::s_Instance = nullptr;
Cursor::Cursor(){
	position.x = 32;
	position.y = 32;
	keyPressed = false;
	keyPressTimer = 0;
	selectPressed = false;
	unitSelected = false;
	moveSelected = false;
}
void Cursor::SetCursorPosition(int x, int y) {
	position.x = x;
	position.y = y;
}
void Cursor::DeSelect() {
	unitSelected = false;
	moveSelected = false;
}
void Cursor::Update() {
	if (!unitSelected && !moveSelected || unitSelected && moveSelected) {
		if (((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W) ||
			InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_UP)) &&
			!keyPressed) || (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W) ||
				InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_UP)) &&
			keyPressTimer > 10) {
			position.y -= position.y > 0 ? TextureManager::GetInstance()->GetPixelSize() : 0;
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
			position.y += position.y < GameMap::GetInstance()->GetMapHeight() - TextureManager::GetInstance()->GetPixelSize() ? TextureManager::GetInstance()->GetPixelSize() : 0;
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
			position.x -= position.x > 0 ? TextureManager::GetInstance()->GetPixelSize() : 0;
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
			position.x += position.x < GameMap::GetInstance()->GetMapWidth() - TextureManager::GetInstance()->GetPixelSize() ? TextureManager::GetInstance()->GetPixelSize() : 0;
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
		Camera::GetInstance()->Update(position.x, position.y);
	}
	return;
}

void Cursor::Render() {
	if(!unitSelected)
		TextureManager::GetInstance()->DrawRect(position.x, position.y);
}