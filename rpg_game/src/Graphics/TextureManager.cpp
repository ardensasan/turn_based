#include "TextureManager.h"
#include "../Core/Engine.h"
TextureManager* TextureManager::s_Instance = nullptr;
TextureManager::TextureManager() {}

void TextureManager::LoadTexture(std::string id, std::string filename) {
	SDL_Texture* texture = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(),filename.c_str());
	if (texture == nullptr) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Texture Error",
			"Failed to load Texture. Please reinstall the program.",
			NULL);
		Engine::GetInstance()->Quit();
	}
	else {
		textureMap[id] = texture;
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	return;
}

void TextureManager::Draw() {
	SDL_Texture* texture = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(), "Assets/fantasy_weapons_pack1_noglow.png");
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), texture, NULL, NULL);
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