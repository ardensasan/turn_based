#include "Player.h"
#include "../Input/InputListener.h"

Player::Player(){
	pixelSize = Engine::GetInstance()->GetPixelSize();
	rect = { 0,0,pixelSize,pixelSize };
}

void Player::Update() {
	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W)) {
		rect.y--;
	}
	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S)) {
		rect.y++;
	}
	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		rect.x--;
	}
	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		rect.x++;
	}
	return;
}

void Player::Render() {
	SDL_Texture* texture = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(), "Assets/Character/Male/Male 01-1.png");
	SDL_Rect r = { 0,0,32,32 };
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), texture, &r, &rect);
}
void Player::Clean() {
	return;
}