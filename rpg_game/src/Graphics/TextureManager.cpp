#include "TextureManager.h"
#include "../Core/Engine.h"
#include "../Vendor/tinyxml2.h"
#include "../Interface/Camera.h"
TextureManager* TextureManager::s_Instance = nullptr;
TextureManager::TextureManager() {
	pixelSize = 0;
	assetList = "Assets/assetList.xml";
}

void TextureManager::LoadTextures() {
	tinyxml2::XMLDocument xml;
	xml.LoadFile(assetList.c_str());
	if (xml.Error()) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Asset Error",
			"Error loading asset list. Please reinstall the program.",
			NULL);
		Engine::GetInstance()->Quit();
	}
	tinyxml2::XMLElement* root = xml.RootElement();

	for (tinyxml2::XMLElement* e = root->FirstChildElement();e != nullptr;e = e->NextSiblingElement()) {
		if (e->Value() == std::string("asset")) {
			textureMap[e->Attribute("name")] = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(), e->Attribute("source"));
		}
	}
	pixelSize = 32;
	return;
}

void TextureManager::LoadTileset(std::string name, std::string source) {
	textureMap[name] = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(), source.c_str());
}
void TextureManager::Draw(int row, int col, int x, int y, std::string textureID) {
	SDL_Rect cameraRect = Camera::GetInstance()->GetCameraRect();
	SDL_Rect srcRect = { row * pixelSize, col * pixelSize, pixelSize, pixelSize };
	SDL_Rect dstRect = { x - cameraRect.x, y- cameraRect.y, pixelSize, pixelSize };
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), textureMap[textureID],&srcRect, &dstRect);
	return;
}

void TextureManager::DrawTile(std::string id, int row, int col, int width, int height, int srcX, int srcY) {
	SDL_Rect srcRect = { srcY* 32,srcX * 32,32,32 };
	SDL_Rect dstRect = { (row * 32),(col * 32),32,32 };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), textureMap[id], &srcRect, &dstRect, 0, 0, SDL_FLIP_NONE);
}


void TextureManager::DrawTile(SDL_Rect srcRect, SDL_Rect dstRect, std::string textureID) {
	SDL_Rect cameraRect = Camera::GetInstance()->GetCameraRect();
	dstRect.x -= cameraRect.x;
	dstRect.y -= cameraRect.y;
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), textureMap[textureID], &srcRect, &dstRect);
	return;
}

void TextureManager::DrawRect(int x, int y) {
	SDL_Rect cameraRect = Camera::GetInstance()->GetCameraRect();
	SDL_Rect rect = { x - cameraRect.x , y - cameraRect.y, pixelSize, pixelSize };
	SDL_SetRenderDrawColor(Engine::GetInstance()->GetRenderer(), 255, 255, 255, 255);
	SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(),&rect);
	SDL_SetRenderDrawColor(Engine::GetInstance()->GetRenderer(), 0, 0, 0, 0);
	return;
}

void TextureManager::DrawSkillRange(int x, int y, int range) {
	SDL_Rect cameraRect = Camera::GetInstance()->GetCameraRect();
	SDL_Rect rect = { x - cameraRect.x , y - cameraRect.y, pixelSize, pixelSize }; // left side
	SDL_SetRenderDrawColor(Engine::GetInstance()->GetRenderer(), 255, 255, 255, 255);
	for (int i = 0;i < range;i++) { // left side
		rect.x -= pixelSize;
		SDL_RenderFillRect(Engine::GetInstance()->GetRenderer(), &rect);
	}
	rect = { x - cameraRect.x , y - cameraRect.y, pixelSize, pixelSize }; // left side
	for (int i = 0; i < range;i++) { // right side
		rect.x += pixelSize;
		SDL_RenderFillRect(Engine::GetInstance()->GetRenderer(), &rect);
	}
	rect = { x - cameraRect.x , y - cameraRect.y, pixelSize, pixelSize }; // left side
	for (int i = 0; i < range;i++) { // up
		rect.y -= pixelSize;
		SDL_RenderFillRect(Engine::GetInstance()->GetRenderer(), &rect);
	}
	rect = { x - cameraRect.x , y - cameraRect.y, pixelSize, pixelSize }; // left side
	for (int i = 0; i < range;i++) { // down
		rect.y += pixelSize;
		SDL_RenderFillRect(Engine::GetInstance()->GetRenderer(), &rect);
	}
	SDL_SetRenderDrawColor(Engine::GetInstance()->GetRenderer(), 0, 0, 0, 0);
	return;
}

void TextureManager::CleanTilesets(std::string name) {
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = textureMap.begin();it != textureMap.end(); ++it) {
		if (it->first == name)
			SDL_DestroyTexture(it->second);
	}
	textureMap.erase(name);	
	return;
}

void TextureManager::Clean(){
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = textureMap.begin();it != textureMap.end(); ++it) {
		SDL_DestroyTexture(it->second);
	}
	textureMap.clear();
	return;
}