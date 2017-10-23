#pragma once
#ifndef DEBUG_H
#define DEBUG_H
#include "TileMap.h"
#include <SFML/Graphics.hpp>
#include <boost\shared_ptr.hpp>
#include <vector>
class Entity;
class MNEngine;
class Debug{
private:
	static bool os_debug;
	static sf::Text cur, right, top, left, bot, topRight, topLeft, botRight, botLeft, x, y, xV, yV;

public:
	static void printPPos(MNEngine* const);
	static void init();
	static bool isActive();
	static void setState(bool);
	static void updateOSD(MNEngine* const, TileMap *);
	static void printEntVec(std::vector<boost::shared_ptr<Entity>>);
	Debug();
	~Debug();
};
#endif

