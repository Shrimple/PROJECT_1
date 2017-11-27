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
	static bool drawTrajectories;
	static bool drawHitboxes;

	static char entVec_1[32];
	static char entVec_2[32];
	static char time[32];
	static char tiles_1[32];
	static char tiles_2[32];
	static char tiles_3[32];
	static char player_1[32];
	static char player_2[32];

	static std::vector<std::array<sf::Vertex, 2>> getTrajectories(MNEngine* const);
	static std::vector<std::array<sf::Vertex, 4>> getHitboxes(MNEngine* const);
public:
	Debug();
	~Debug();

	static bool isActive();

	static void drawInGame(MNEngine* const);
	static void printPPos(MNEngine* const);
	static void updateOSD(MNEngine* const, TileMap *);
	static void setState(bool);
	static void printEntVec(std::vector<boost::shared_ptr<Entity>>);
	static void init();
	static void draw();

};
#endif

