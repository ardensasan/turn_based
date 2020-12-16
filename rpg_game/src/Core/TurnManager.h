#ifndef TURNMANAGER_H
#define TURNMANAGER_H
class TurnManager
{
public:
	static TurnManager* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new TurnManager();
		}
		return s_Instance;
	}
	void Update();
	void Render();
private:
	static TurnManager* s_Instance;
	unsigned int turnCount;
};
#endif