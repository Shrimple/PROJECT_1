#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>
#include <boost\shared_ptr.hpp>
#include "Player.h"
#include "Entity.h"
#include "TileMap.h"

class MNEngine;
class EntityManager
{
private:
	std::vector<boost::shared_ptr<Entity>> ent_ptrVec;
	MNEngine* enginePtr;

public:
	bool init(MNEngine* const);
	void updateEnts(TileMap*);
	Player * player;
	std::vector<boost::shared_ptr<Entity>> getVec();
	void newPlayerEnt();
	void newEntity(int texIndex, int xOff, int yOff);
	Entity &getEnt(int i);
	EntityManager();
	~EntityManager();
};
#endif

 