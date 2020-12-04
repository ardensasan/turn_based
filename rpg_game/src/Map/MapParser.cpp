#include "MapParser.h"
#include "../Core/Engine.h"
#include "TileParser.h"
#include "GameMap.h"
MapParser* MapParser::s_Instance = nullptr;

MapParser::MapParser() {
	mapList = "Assets/Maps/maps.xml";
}

void MapParser::Load(std::string mapID) {
	tinyxml2::XMLDocument xml;
	xml.LoadFile(mapList.c_str());
	if (xml.Error()) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Map Error",
			"Map missing. Please reinstall the program.",
			NULL);
		Engine::GetInstance()->Quit();
	}
	else {
		tinyxml2::XMLElement* root = xml.RootElement();
		for (tinyxml2::XMLElement* e = root->FirstChildElement();e != nullptr;e = e->NextSiblingElement()) {
			if (e->Value() == std::string("map")) {
				if (mapID == e->Attribute("id")) {
					std::string source = e->Attribute("source");
					Parse(source);
				}
			}
		}
	}
}

void MapParser::Parse(std::string source) {
	tinyxml2::XMLDocument xml;
	xml.LoadFile(source.c_str());
	if (xml.Error()) {
		Error();
	}
	else {
		std::vector<Tileset> tilesets;
		tinyxml2::XMLElement* root = xml.RootElement();
		for (tinyxml2::XMLElement* e = root->FirstChildElement();e != nullptr;e = e->NextSiblingElement()) { // get tileset details
			if (e->Value() == std::string("tileset"))
				tilesets.push_back(ParseTileSets(e));
		}
		if (!tilesets.empty()) {
			TileParser::GetInstance()->tilesets = tilesets;
			tinyxml2::XMLElement* root = xml.RootElement();
			for (tinyxml2::XMLElement* e = root->FirstChildElement();e != nullptr;e = e->NextSiblingElement()) { // get layer matrix
				if (e->Value() == std::string("layer")) {
				}
			}
		}
		else {
			Error();
		}
	}
}

Tileset MapParser::ParseTileSets(tinyxml2::XMLElement* e) {
	Tileset tileset;
	tileset.firstID = e->Attribute("firstgid") ? atoi(e->Attribute("firstgid")) : NULL;
	tileset.lastID = e->Attribute("tilecount") ? atoi(e->Attribute("tilecount")) : NULL;
	tileset.tileWidth = e->Attribute("tilewidth") ? atoi(e->Attribute("tilewidth")) : NULL;
	tileset.tileHeight = e->Attribute("tileheight") ? atoi(e->Attribute("tileheight")) : NULL;
	if (!tileset.firstID || !tileset.lastID || !tileset.tileWidth || !tileset.tileHeight)
		Error();
	return tileset;
}
void MapParser::Error() {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
		"Map Error",
		"Error loading map. Please reinstall the program.",
		NULL);
	Engine::GetInstance()->Quit();
}