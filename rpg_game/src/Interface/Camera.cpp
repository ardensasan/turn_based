#include "Camera.h"
#include "../Core/Engine.h"
Camera* Camera::s_Instance = nullptr;
Camera::Camera() {
	screenWidth = Engine::GetInstance()->GetScreenWidth();
	screenHeight = Engine::GetInstance()->GetScreenHeight();
	mapDetails = GameMap::GetInstance()->GetMapDetails();
	cameraRect = { 0, 0, 0, 0 };
}

void Camera::Set() {
	screenWidth = Engine::GetInstance()->GetScreenWidth();
	screenHeight = Engine::GetInstance()->GetScreenHeight();
	cameraRect.w = screenWidth / 2;
	cameraRect.h = screenHeight / 2;
	mapDetails = GameMap::GetInstance()->GetMapDetails();
}

void Camera::Update(int x, int y) {
	cameraRect.x = x - cameraRect.w;
	cameraRect.y = y - cameraRect.h;
	if (cameraRect.x < 0 && screenWidth < mapDetails.mapWidth)
		cameraRect.x = 0;
	if (cameraRect.y < 0 && screenHeight < mapDetails.mapHeight)
		cameraRect.y = 0;
	if ((screenWidth + cameraRect.x > mapDetails.mapWidth) && screenWidth < mapDetails.mapWidth)
		cameraRect.x = mapDetails.mapWidth - screenWidth;
	if ((screenHeight + cameraRect.y > mapDetails.mapHeight) && screenHeight < mapDetails.mapHeight)
		cameraRect.y = mapDetails.mapHeight - screenHeight;
}