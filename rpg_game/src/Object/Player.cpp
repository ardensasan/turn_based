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
	turnEnded = false;
	skills = new Skills();
	actions = new Actions();
}

void Player::Reset() {
	isSelected = false;
	keyPressed = false;
	turnEnded = false;
}

void Player::Update() {
	if (!isSelected && !turnEnded) {
		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
			Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
			if (position.x == cursorPosition.x && position.y == cursorPosition.y) {
				keyPressed = true;
				isSelected = true;
				Cursor::GetInstance()->UnitSelected(true);
			}
		}
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
			keyPressed = false;
		}
	}
	else if (isSelected) {
		actions->Update();
		if (Cursor::GetInstance()->MoveSelected()) {
			Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
			position = cursorPosition;
		}
		if (actions->TurnEnded()) {
			turnEnded = true;
			isSelected = false;
			Cursor::GetInstance()->UnitSelected(false);
		}
		//position = Cursor::GetInstance()->GetCursorPosition();
		//if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
		//	keyPressed = true;
		//	isSelected = false;
		//}
		//if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
		//	keyPressed = false;
		//}
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
	if (isSelected) {
		actions->Render();
	}
}
void Player::Clean() {
	return;
}