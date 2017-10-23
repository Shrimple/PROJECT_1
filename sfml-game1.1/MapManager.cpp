#include "MapManager.h"
#include <iostream>
#include <fstream>
#include <SFML\Graphics.hpp>
#include "MNEngine.h"

using namespace csp;

void MapManager::init(MNEngine * ptr){
	enginePtr = ptr;
	map = new TileMap(ptr);
	std::cout << "-MapManager init @ " << boost::addressof(*this) << "." << std::endl;
	std::cout << "Engine ptr @ " << enginePtr << "." << std::endl;

}

TileMap* MapManager::getMap(){
	return map;
}

bool MapManager::loadMap(std::string mapPath, std::string tileSetPath){
	std::cout << "-----------MAP LOADING---------." << std::endl;
	std::array<int, 2048> rawMap;
	char tileData;
	std::ifstream fp(mapPath);

	if (fp.is_open()) {
		std::cout << " --------- tile data file loaded : " + mapPath << std::endl << "{" << std::endl;;

		int i = 0;
		while (fp >> tileData) {
			std::cout << tileData;
			rawMap[i] = ((int)tileData - '0');
			i++;
		}

		std::cout << "}" << std::endl;
	}
	else {
		std::cout << "could not open " + mapPath + "!" << std::endl;
		return -1;
	}

	fp.close();
	map->setMap(rawMap);

	if (!map->load(tileSetPath, sf::Vector2u(enginePtr->TILE_SIZE, 
		enginePtr->TILE_SIZE), rawMap.data(),
		enginePtr->Cam.window->getSize().x / enginePtr->TILE_SIZE,
		enginePtr->Cam.window->getSize().y / enginePtr->TILE_SIZE)) {
		std::cout << "failed to load map." << std::endl;
		return -1;
	}

	return 1;
}

MapManager::MapManager()
{
}


MapManager::~MapManager()
{
}
