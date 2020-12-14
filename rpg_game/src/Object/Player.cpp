#include "Player.h"
#include "../Input/InputListener.h"
#include "../Interface/Camera.h"
#include "../Interface/Cursor/Cursor.h"

Player::Player(){
	position.x = 0;
	position.y = 0;
	animation = new Animation("fighter4");
	isSelected = false;
	keyPressed = false;
	moveSelected = false;
	skillSelected = false;
}

void Player::Update() {
	if (!isSelected) {
		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
			Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
			if (position.x == cursorPosition.x && position.y == cursorPosition.y) {
				keyPressed = true;
				isSelected = true;
			}
		}
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
			keyPressed = false;
		}
	}
	else if (isSelected) {
		position = Cursor::GetInstance()->GetCursorPosition();
		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
			Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
			if (position.x == cursorPosition.x && position.y == cursorPosition.y) {
				keyPressed = true;
				isSelected = false;
			}
		}
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
			keyPressed = false;
		}
	}
	if (isSelected) {
		animation->Idle();
	}
	else {
		animation->Update();
	}
	return;
}

void Player::Render() {
	animation->Render(position.x, position.y);
}
void Player::Clean() {
	return;
}