#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <vector>
struct Layer {
	int layerWidth;
	int layerHeight;
	std::vector<std::vector<int> > data;
};

struct MapDetails {
	int mapWidth, mapHeight;
	int tileWidth, tileHeight;
};


class GameMap 
{
	friend class MapParser;
public:
	static GameMap* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new GameMap();
		}
		return s_Instance;
	}
	std::vector<Layer> GetMapLayers() { return mapLayers; }
	MapDetails GetMapDetails() { return mapDetails; }
	int GetMapHeight() { return mapDetails.mapHeight; }
	int GetMapWidth() { return mapDetails.mapWidth; }
private:
	GameMap();
	static GameMap* s_Instance;
	std::vector<Layer> mapLayers;
	MapDetails mapDetails;
};
#endif