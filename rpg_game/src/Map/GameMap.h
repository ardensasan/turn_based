#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <vector>
struct Layer {
	std::vector<std::vector<int> > layer;
};
class GameMap {
public:
	static GameMap* GetInstance() {

	}
private:
	GameMap();
	static GameMap* s_Instance;
	std::vector<Layer> mapLayer;
};
#endif