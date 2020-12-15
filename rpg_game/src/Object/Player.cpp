#include "Player.h"
#include "../Input/InputListener.h"
#include "../Interface/Camera.h"
#include "../Interface/Cursor/Cursor.h"
#include "../Interface/Menu/UnitAction.h"
Player::Player(){
	position.x = 0;
	position.y = 0;
	animation = new Animation("fighter4");
	isSelected = false;
	keyPressed = false;
	isTurnEnded = false;
	skills = new Skills();
}

void Player::Reset() {
	isSelected = false;
	keyPressed = false;
	isTurnEnded = false;
}

void Player::Update() {
	if (!isSelected && !isTurnEnded) {
		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
			Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
			if (position.x == cursorPosition.x && position.y == cursorPosition.y) {
				keyPressed = true;
				isSelected = true;
				UnitAction::GetInstance()->ResetState();
				UnitAction::GetInstance()->SetIsInAction(true);
			}
		}
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
			keyPressed = false;
		}
	}
	else if (isSelected) {
		if (UnitAction::GetInstance()->IsMoveSelected()) {
			position = Cursor::GetInstance()->GetCursorPosition();
			if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
				UnitAction::GetInstance()->SetHasMoved(true);
			}
			if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
				keyPressed = false;
			}
		}
		else if (UnitAction::GetInstance()->IsSkillSelected()) {
			// skill menu
			skills->Update();
		}
		if (UnitAction::GetInstance()->IsEndSelected()) {
			isSelected = false;
			UnitAction::GetInstance()->ResetState();
			keyPressed = true;
			isTurnEnded = true;
			//turn ended
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
	if (isSelected && UnitAction::GetInstance()->IsSkillSelected()) {
		skills->Render();
	}
}
void Player::Clean() {
	return;
}