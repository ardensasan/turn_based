#include "Player.h"
#include "../Input/InputListener.h"
#include "../Interface/Camera.h"
Player::Player(){
	xPosition = 2;
	yPosition = 2;
	animation = new Animation("fighter4");
}

void Player::Update() {
	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W)) {
		animation->UpdateCol(3);
		Camera::GetInstance()->Update(xPosition, yPosition);
		yPosition--;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S)) {
		animation->UpdateCol(0);
		Camera::GetInstance()->Update(xPosition, yPosition);
		yPosition++;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		animation->UpdateCol(1);
		Camera::GetInstance()->Update(xPosition, yPosition);
		xPosition--;
	}
	else if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		animation->UpdateCol(2);
		Camera::GetInstance()->Update(xPosition, yPosition);
		xPosition++;
	}
	animation->Update();
	Camera::GetInstance()->Update(xPosition, yPosition);
	return;
}

void Player::Render() {
	animation->Render(xPosition, yPosition);
}
void Player::Clean() {
	return;
}