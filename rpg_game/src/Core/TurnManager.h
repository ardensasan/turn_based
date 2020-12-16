#ifndef TURNMANAGER_H
#define TURNMANAGER_H
#include "../Object/GameObject.h"
#include "../Core/Engine.h"
#include <vector>
class TurnManager
{
public:
	static TurnManager* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new TurnManager();
		}
		return s_Instance;
	}
	void Update(std::vector<GameObject*> unitList);
	void Render();
private:
	TurnManager();
	static TurnManager* s_Instance;
	unsigned int turnCount;
	TTF_Font* font;
	int fontSize;
	std::string fontFile;
	SDL_Color color;
};
#endif