#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "TileMap.h"
#include "SFML\Window.hpp"

class Player : public Entity{
private:
	int dir;
public:
	Player(MNEngine* const e, int id) :Entity(e, 1, csp::EntityType::PLAYER, 220, 220, id) {};
	~Player();
	void pollMove();
};
#endif
