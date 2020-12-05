#include "TileParser.h"
#include "GameMap.h"
#include <iostream>
#include "../Graphics/TextureManager.h"
TileParser* TileParser::s_Instance = nullptr;
TileParser::TileParser() {
}
#include <conio.h>
void TileParser::Update() {
	tiles.clear();
	std::vector<Layer> mapLayer = GameMap::GetInstance()->GetMapLayers();
	std::vector<Layer>::iterator layerIterator;
	std::vector<Tileset>::iterator tilesetIterator;
	for (layerIterator = mapLayer.begin();layerIterator != mapLayer.end();++layerIterator) {
		std::vector<std::vector<int> > map = layerIterator->data;
		for (int y = 0;y < layerIterator->layerHeight;y++) {
			for (int x = 0;x < layerIterator->layerWidth;x++) {
				if (map[x][y] != 0) {
					for (tilesetIterator = tilesets.begin();tilesetIterator != tilesets.end();++tilesetIterator) {
						if (tilesetIterator->firstID <= map[x][y] && map[x][y] <= tilesetIterator->lastID) {
							int tileID = (map[x][y] + tilesetIterator->lastID) - (tilesetIterator->firstID + tilesetIterator->lastID);
							int tileRow = tileID / tilesetIterator->colCount;
							int tileCol = tileID - tileRow * tilesetIterator->colCount;
							Tile _tile;
							_tile.srcRect = { tileCol * tilesetIterator->tileWidth,tileRow * tilesetIterator->tileHeight, tilesetIterator->tileWidth, tilesetIterator->tileHeight };
							_tile.dstRect = { x * tilesetIterator->tileWidth,y * tilesetIterator->tileHeight, tilesetIterator->tileWidth, tilesetIterator->tileHeight };
							_tile.name = tilesetIterator->name;
							tiles.push_back(_tile);
							break;
						}
					}
				}
			}
		}
	}
	for (tilesetIterator = tilesets.begin();tilesetIterator != tilesets.end();++tilesetIterator) { // load tilesets in texture map
		TextureManager::GetInstance()->LoadTileset(tilesetIterator->name, tilesetIterator->source);
	}
	tilesets.clear();
}

void TileParser::Render() {
	std::vector<Tile>::iterator it;
	for (it = tiles.begin();it != tiles.end();++it) {
		TextureManager::GetInstance()->DrawTile(it->srcRect, it->dstRect, it->name);
	}
}

