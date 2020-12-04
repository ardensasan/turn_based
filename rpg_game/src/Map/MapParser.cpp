#include "MapParser.h"
#include "../Core/Engine.h"
#include "TileParser.h"
#include "GameMap.h"
#include <sstream>
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
		std::vector<Tileset> _tilesets;
		tinyxml2::XMLElement* root = xml.RootElement();
		for (tinyxml2::XMLElement* e = root->FirstChildElement();e != nullptr;e = e->NextSiblingElement()) { // get tileset details
			if (e->Value() == std::string("tileset"))
				_tilesets.push_back(ParseTileSets(e));
		}
		if (!_tilesets.empty()) {
			TileParser::GetInstance()->tilesets.clear();
			TileParser::GetInstance()->tilesets = _tilesets;
			std::vector<Layer> _mapLayers;
			tinyxml2::XMLElement* root = xml.RootElement();
			for (tinyxml2::XMLElement* e = root->FirstChildElement();e != nullptr;e = e->NextSiblingElement()) { // get layer matrix
				if (e->Value() == std::string("layer")) {
					_mapLayers.push_back(ParseTileLayers(e));
				}
			}
			if (!_mapLayers.empty()) {
				GameMap::GetInstance()->mapLayers.clear();
				GameMap::GetInstance()->mapLayers = _mapLayers;
				TileParser::GetInstance()->Update();
			}
			else {
				Error();
			}
		}
		else {
			Error();
		}
	}
}

Tileset MapParser::ParseTileSets(tinyxml2::XMLElement* tileset) {
	Tileset _tileset;
	_tileset.firstID = tileset->Attribute("firstgid") ? atoi(tileset->Attribute("firstgid")) : NULL;
	_tileset.tileCount = tileset->Attribute("tilecount") ? atoi(tileset->Attribute("tilecount")) : NULL;
	_tileset.lastID = _tileset.firstID + _tileset.tileCount - 1;
	_tileset.colCount = tileset->Attribute("columns") ? atoi(tileset->Attribute("columns")) : NULL;
	_tileset.rowCount = _tileset.tileCount / _tileset.colCount;
	_tileset.tileWidth = tileset->Attribute("tilewidth") ? atoi(tileset->Attribute("tilewidth")) : NULL;
	_tileset.tileHeight = tileset->Attribute("tileheight") ? atoi(tileset->Attribute("tileheight")) : NULL;
	_tileset.source = tileset->Attribute("name");
	if (!_tileset.firstID || !_tileset.lastID || !_tileset.tileCount || !_tileset.colCount || !_tileset.rowCount || !_tileset.tileWidth || !_tileset.tileHeight)
		Error();
	return _tileset;
}

Layer MapParser::ParseTileLayers(tinyxml2::XMLElement* layer) {
	Layer _layer;
	_layer.layerWidth = atoi(layer->Attribute("width"));
	_layer.layerHeight = atoi(layer->Attribute("height"));
	_layer.data.resize(_layer.layerWidth, std::vector<int>(_layer.layerHeight));
	for (tinyxml2::XMLElement* e = layer->FirstChildElement();e!= nullptr;e = e->NextSiblingElement()) {
		if (e->Value() == std::string("data")) {
			int x, y;
			x = y = 0;
			std::istringstream ss(e->GetText());
			std::string token;
			//store into vector
			while (std::getline(ss, token, ',')) {
				_layer.data[x][y] = stoi(token);
				x++;
				if (x >= _layer.layerWidth) {
					x = 0;
					y++;
				}
				if (y >= _layer.layerHeight)
					break;
			}
		}
	}
	return _layer;
}

void MapParser::Error() {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
		"Map Error",
		"Error loading map. Please reinstall the program.",
		NULL);
	Engine::GetInstance()->Quit();
}