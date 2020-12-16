#include "ActionManager.h"
ActionManager* ActionManager::s_Instance = nullptr;

ActionManager::ActionManager() {
	UnitSelected = false;
	moveSelected = false;
	skillSelected = false;
}

void ActionManager::Reset() {
	moveSelected = false;
	skillSelected = false;
}

void ActionManager::Update() {

}