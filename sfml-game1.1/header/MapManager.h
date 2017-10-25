#pragma once
#ifndef MAPMANAGER_H
#define MAPMANAGER_H
#include "Namespace.h"
#include "TileMap.h"
#include <string>

using namespace csp;

class MNEngine;
class MapManager
{
private:
	TileMap* map;
	MNEngine* enginePtr;

public:
	void init(MNEngine*);
	TileMap* getMap();
	bool loadMap(std::string mapPath, std::string tileSetPath);
	MapManager();
	~MapManager();
};
#endif
