#ifndef TILEPARSER_H
#define TILEPARSER_H
#include <vector>
#include <string>
struct Tileset {
	int firstID; 
	int lastID;
	int tileWidth;
	int tileHeight;
	std::string source;
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
private:
	TileParser();
	static TileParser* s_Instance;
	std::vector<Tileset> tilesets;
};
#endif

