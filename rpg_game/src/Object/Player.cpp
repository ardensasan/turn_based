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
}

void Player::Update() {
	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed)
	{
		keyPressed = true;
		Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
		if (cursorPosition.x == position.x && cursorPosition.y == position.y && !isSelected)
			isSelected = true;
		else if (cursorPosition.x == position.x && cursorPosition.y == position.y && isSelected)
			isSelected = false;
	}
	if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed)
	{
		keyPressed = false;
	}
	if (isSelected) {
		position = Cursor::GetInstance()->GetCursorPosition();
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