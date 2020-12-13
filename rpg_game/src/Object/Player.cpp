#include "Player.h"
#include "../Input/InputListener.h"
#include "../Interface/Camera.h"
#include "../Interface/Cursor/Cursor.h"
static bool moveSelect = 0;
Player::Player(){
	position.x = 0;
	position.y = 0;
	animation = new Animation("fighter4");
	isSelected = false;
	keyPressed = false;
	moveSelected = false;
	skillSelected = false;
	unitAction = new UnitAction();
}

void Player::Update() {
	if (isSelected) {
		if (moveSelected = unitAction->IsMoveSelected()) {
			Cursor::GetInstance()->IsMoveSelect(moveSelected);
			position = Cursor::GetInstance()->GetCursorPosition();
			if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed)
			{
				keyPressed = true;
				Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
				if (cursorPosition.x == position.x && cursorPosition.y == position.y) {
					isSelected = false;
					Cursor::GetInstance()->DeSelect();                              
					unitAction->SetAction();
				}
			}
			if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed)
			{
				keyPressed = false;
			}
		}
		else {
			unitAction->Update();
		}
		animation->Idle();
	}
	else {
		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed)
		{
			keyPressed = true;
			Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
			if (cursorPosition.x == position.x && cursorPosition.y == position.y && !isSelected) {
				isSelected = true;
				Cursor::GetInstance()->IsUnitSelected(isSelected);
				unitAction->SetAction();
			}
		}
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed)
		{
			keyPressed = false;
		}
		animation->Update();
	}
	return;
}

void Player::Render() {
	animation->Render(position.x, position.y);
	if (isSelected && !moveSelected && !skillSelected) {
		unitAction->Render();
	}
}
void Player::Clean() {
	return;
}