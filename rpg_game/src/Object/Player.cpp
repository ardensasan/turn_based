#include "Player.h"
#include "../Input/InputListener.h"
#include "../Interface/Camera.h"
Player::Player(){
	xPosition = 0;
	yPosition = 0;
	animation = new Animation("fighter4");
}

void Player::Update() {
	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W)) {
		animation->UpdateCol(3);
		animation->Update();
		yPosition--;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S)) {
		animation->UpdateCol(0);
		animation->Update();
		yPosition++;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		animation->UpdateCol(1);
		animation->Update();
		xPosition--;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		animation->UpdateCol(2);
		animation->Update();
		xPosition++;
	}
	else 
		animation->Idle(); // sprite standing still 
	Camera::GetInstance()->Update(xPosition, yPosition);
	return;
}

void Player::Render() {
	animation->Render(xPosition, yPosition);
}
void Player::Clean() {
	return;
}