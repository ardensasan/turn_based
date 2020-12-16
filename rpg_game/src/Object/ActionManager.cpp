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
	skill.name = "";
	skill.range = NULL;
}

void ActionManager::UpdatePosition(Position2D unitPosition) {
	this->unitPosition = unitPosition;
}


void ActionManager::SetSkillDetails(Skill skill) {
	this->skill = skill;
}