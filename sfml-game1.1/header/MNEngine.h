#pragma once
#ifndef MNENGINE_H
#define MNENGINE_H
#include "Namespace.h"
#include "AnimationManager.h"
#include "EntityManager.h"
#include "MapManager.h"
#include "TextureManager.h"
#include "SFML\Window.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include "Console.h"

using namespace csp;

class MNEngine
{
private:
	sf::Clock deltaClock;
public:
	const int TILE_SIZE = 20;
	TextureManager TM;
	EntityManager EM;
	AnimationManager AM;
	MapManager MM;
	Camera Cam;
	static Console console;

	MNEngine();
	~MNEngine();
	bool init();
	void loadTestTextures();
	void render();
	void pollEvent();
	void moveScreen();
	void spawnEntity(char *, int, int);
	void update();
	void onScreenDebug(bool);
	void spawnPlayer();
};
#endif

