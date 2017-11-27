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
	MapManager();
	~MapManager();
	void init(MNEngine*);
	bool loadMap(std::string mapPath, std::string tileSetPath);
	TileMap* getMap();
};
#endif
