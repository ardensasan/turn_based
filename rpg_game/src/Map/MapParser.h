#ifndef MAPPARSER_H
#define MAPPARSER_H
#include <string>
#include "../Vendor/tinyxml2.h"
#include "GameMap.h"
#include "TileParser.h"
struct MapDetails {
	int mapWidth, mapHeight;
	int tileWidth, tileHeight;
};

class MapParser
{
public:
	inline static MapParser* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new MapParser();
		return s_Instance;
	}
	void Load(std::string mapID);
	MapDetails GetMapDetails() { return mapDetails; }
private:
	MapParser();
	void Error();
	void Parse(std::string source);
	Tileset ParseTileSets(tinyxml2::XMLElement* ts);
	Layer ParseTileLayers(tinyxml2::XMLElement* l);
	static MapParser* s_Instance;
	std::string mapList;
	MapDetails mapDetails;
	std::string mapFolder;
};
#endif

