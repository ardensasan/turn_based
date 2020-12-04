#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <vector>
struct Layer {
	int layerWidth;
	int layerHeight;
	std::vector<std::vector<int> > data;
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
private:
	GameMap();
	static GameMap* s_Instance;
	std::vector<Layer> mapLayers;
};
#endif