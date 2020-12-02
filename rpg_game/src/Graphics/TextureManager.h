#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
class TextureManager
{
public:
	static TextureManager* GetInstance();
	void LoadTexture(std::string id, std::string filename);
	void Draw();
	void Clean();
private:
	TextureManager();
	static TextureManager* s_Instance;
	std::map<std::string, SDL_Texture*> textureMap;
};
#endif // ! TEXTUREMANAGER_H
