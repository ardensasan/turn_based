#ifndef TILEPARSER_H
#define TILEPARSER_H
#include <vector>
#include <string>
#include <SDL.h>
struct Tileset {
	int firstID; 
	int lastID;
	int tileCount;
	int colCount;
	int rowCount;
	int tileWidth;
	int tileHeight;
	std::string source;
	std::string name;
};

struct Tile {
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	std::string name;
};
class TileParser
{
	friend class MapParser;
public:
	static TileParser* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new TileParser();
		}
		return s_Instance;
	}
	void Update();
	void Render();
	void Clean();
private:
	TileParser();
	static TileParser* s_Instance;
	std::vector<Tileset> tilesets;
	std::vector<Tile> tiles;
};
#endif

