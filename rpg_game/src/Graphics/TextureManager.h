#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
class TextureManager
{
public:
	inline static TextureManager* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new TextureManager();
		return s_Instance;
	}
	void LoadTextures();
	void Draw(int row, int col, int x, int y, std::string textureID);
	void DrawTile(SDL_Rect srcRect, SDL_Rect dstRect, std::string textureID);
	void DrawTile(std::string id, int row, int col, int width, int height, int srcX, int srcY);
	void Clean();
private:
	TextureManager();
	static TextureManager* s_Instance;
	std::map<std::string, SDL_Texture*> textureMap;
	int pixelSize;
	std::string assetList; //list of assets in xml format
};
#endif // ! TEXTUREMANAGER_H
