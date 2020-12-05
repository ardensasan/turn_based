#include "Camera.h"
#include "../Core/Engine.h"
Camera* Camera::s_Instance = nullptr;
Camera::Camera() {
	screenWidth = Engine::GetInstance()->GetScreenWidth();
	screenHeight = Engine::GetInstance()->GetScreenHeight();
	mapDetails = MapParser::GetInstance()->GetMapDetails();
}

void Camera::Set() {
	screenWidth = Engine::GetInstance()->GetScreenWidth();
	screenHeight = Engine::GetInstance()->GetScreenHeight();
	cameraRect.w = screenWidth / 2;
	cameraRect.h = screenHeight / 2;
	mapDetails = MapParser::GetInstance()->GetMapDetails();
}

void Camera::Update(int x, int y) {
	cameraRect.x = x - cameraRect.w;
	cameraRect.y = y - cameraRect.h;
	int mapSizeX = mapDetails.mapWidth * mapDetails.tileWidth;
	int mapSizeY = mapDetails.mapHeight * mapDetails.tileHeight;
	if (cameraRect.x < 0 && screenWidth < mapSizeX)
		cameraRect.x = 0;
	if (cameraRect.y < 0 && screenHeight < mapSizeY)
		cameraRect.y = 0;
	if ((screenWidth + cameraRect.x > mapSizeX) && screenWidth < mapSizeX)
		cameraRect.x = mapSizeX - screenWidth;
	if ((screenHeight + cameraRect.y > mapSizeY) && screenHeight < mapSizeY)
		cameraRect.y = mapSizeY - screenHeight;
}