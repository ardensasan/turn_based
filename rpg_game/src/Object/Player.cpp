#include "Player.h"
#include "../Input/InputListener.h"
#include "../Interface/Camera.h"
#include "../Interface/Cursor/Cursor.h"
#include "../Object/ActionManager.h"
Player::Player(int i){
	if (i == 0) {
		position.x = 0;
		position.y = 0;
	}
	else {
		position.x = 64;
		position.y = 64;
	}

	animation = new Animation("fighter4");
	isSelected = false;
	keyPressed = false;
	turnEnded = false;
	skills = new Skills();
	actions = new Actions();
}

void Player::Reset() {
	isSelected = false;
	keyPressed = true;
	turnEnded = false;
	actions->Reset();
}

void Player::Update() {
	if (!isSelected && !turnEnded) {
		if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
			keyPressed = false;
		}
		if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
			Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
			if (position.x == cursorPosition.x && position.y == cursorPosition.y) {
				keyPressed = true;
				isSelected = true;
				ActionManager::GetInstance()->Reset();
				Cursor::GetInstance()->UnitSelected(true);
			}
		}
	}
	else if (isSelected) {
		if (ActionManager::GetInstance()->MoveSelected()) {
			Position2D cursorPosition = Cursor::GetInstance()->GetCursorPosition();
			position = cursorPosition;
			ActionManager::GetInstance()->UpdatePosition(position);
			if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
				keyPressed = true;
				ActionManager::GetInstance()->Reset();
				actions->SetHasMoved(true);
			}
			if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
				keyPressed = false;
			}
		}
		else if (ActionManager::GetInstance()->SkillSelected()) {
			skills->Update();
			ActionManager::GetInstance()->UpdatePosition(position);
		}
		else if(actions->TurnEnded()){
			isSelected = false;
			turnEnded = true;
			ActionManager::GetInstance()->Reset();
			Cursor::GetInstance()->DeSelect();
		}
		else {
			actions->Update();
		}
	}
	animation->Update();
	return;
}

void Player::Render() {
	animation->Render(position.x, position.y);
	if (isSelected) {
		if (!ActionManager::GetInstance()->MoveSelected() && !ActionManager::GetInstance()->SkillSelected()) {
			actions->Render();
		}
		else if (ActionManager::GetInstance()->SkillSelected()) {
			skills->Render();
		}
	}
}
void Player::Clean() {
	return;
}