#include "Player.h"
#include "../Input/InputListener.h"

Player::Player(){
	xPosition = 0;
	yPosition = 0;
	animation = new Animation("fighter4");
}

void Player::Update() {
	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W)) {
		animation->UpdateCol(3);
		yPosition--;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S)) {
		animation->UpdateCol(0);
		yPosition++;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		animation->UpdateCol(1);
		xPosition--;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		animation->UpdateCol(2);
		xPosition++;
	}
	animation->Update();
	return;
}

void Player::Render() {
	animation->Render(xPosition, yPosition);
}
void Player::Clean() {
	return;
}