#include "TextureManager.h"
#include "../Core/Engine.h"
TextureManager* TextureManager::s_Instance = nullptr;
TextureManager::TextureManager() {}

void TextureManager::LoadTextures() {
	SDL_Texture* texture = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(), "Assets/Character/Male/Male 01-1.png");
	if (!texture) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Texture Error",
			"Invalid texture. Please reinstall the program.",
			NULL);
		Engine::GetInstance()->Quit();
	}
	textureMap["player"] = texture;
	pixelSize = 32;
	return;
}

void TextureManager::Draw(int row, int col, int x, int y, std::string textureID) {
	SDL_Rect srcRect = { row * 32, col * 32, pixelSize, pixelSize };
	SDL_Rect dstRect = { x, y, pixelSize, pixelSize };
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), textureMap[textureID],&srcRect, &dstRect);
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