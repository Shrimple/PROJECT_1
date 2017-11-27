#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>
#include "boost\shared_ptr.hpp"
#include "Player.h"
#include "Entity.h"
#include "TileMap.h"

class MNEngine;
class EntityManager
{
private:
	std::vector<boost::shared_ptr<Entity>> ent_ptrVec;
	std::vector<int> deadEntities;
	MNEngine* enginePtr;
	int uuid;
	int TEMP_CTR;

	void cleanVector();
public:
	Player * player;

	EntityManager();
	~EntityManager();

	std::vector<boost::shared_ptr<Entity>> getVec();
	Entity &getEnt(int i);
	bool init(MNEngine* const);
	void updateEnts(TileMap*);
	void newPlayerEnt();
	void newEntity(int texIndex, int xOff, int yOff);
	void annouceEntDeath(int);

	int getLastId();
};
#endif

 