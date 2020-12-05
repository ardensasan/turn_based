#include "Animation.h"
#include "../Core/Engine.h"
SDL_Rect rect = { 0,0,32,32 };
Animation::Animation(std::string textureid) {
	currentFrameRow = 0;
	currentFrameCol = 0;
	animationDelay = 200;
	frameColCount = 3;
	frameRowCount = 3;
	textureID = textureid;
}
void Animation::Idle() {
	currentFrameRow = 1;
}

void Animation::UpdateCol(int col) {
	currentFrameCol = col;
}
void Animation::Update() {
	currentFrameRow = (SDL_GetTicks() / animationDelay) % frameRowCount;
}

void Animation::Render(int xPosition, int yPosition) {
	TextureManager::GetInstance()->Draw(currentFrameRow, currentFrameCol, xPosition, yPosition, textureID);
}