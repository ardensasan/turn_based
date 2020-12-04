#include "TextureManager.h"
#include "../Core/Engine.h"
#include "../Vendor/tinyxml2.h"
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

void TextureManager::Draw(int row, int col, int x, int y, std::string textureID) {
	SDL_Rect srcRect = { row * pixelSize, col * pixelSize, pixelSize, pixelSize };
	SDL_Rect dstRect = { x, y, pixelSize, pixelSize };
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), textureMap[textureID],&srcRect, &dstRect);
	return;
}

void TextureManager::DrawTile(std::string id, int row, int col, int width, int height, int srcX, int srcY) {
	SDL_Rect srcRect = { srcY* 32,srcX * 32,32,32 };
	SDL_Rect dstRect = { (row * 32),(col * 32),32,32 };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), textureMap[id], &srcRect, &dstRect, 0, 0, SDL_FLIP_NONE);
}


void TextureManager::DrawTile(SDL_Rect srcRect, SDL_Rect dstRect, std::string textureID) {
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), textureMap[textureID], &srcRect, &dstRect);
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