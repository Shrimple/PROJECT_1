#include "EntityManager.h"
#include "AnimationManager.h"
#include "MNEngine.h"
#include <memory>
using namespace csp;

bool EntityManager::init(MNEngine* const ptr){
	enginePtr = ptr;
	std::cout << "-EntityManager init @ " << boost::addressof(*this) << "." << std::endl;
	return true;
}

void EntityManager::updateEnts(TileMap * map){
	for (boost::shared_ptr<Entity> e : ent_ptrVec)
		e->update(map);

	if(player != NULL)
		player->update(map);
}

std::vector<boost::shared_ptr<Entity>> EntityManager::getVec(){
	return ent_ptrVec;
}

void EntityManager::newPlayerEnt(){
	player = new Player(enginePtr);
	enginePtr->AM.loadAnimFromP(player);
}

void EntityManager::newEntity(int texIndex, int xOff, int yOff){
	boost::shared_ptr<Entity> newEnt(new Entity(enginePtr, texIndex, csp::AI_ENEMY, xOff, yOff));
	ent_ptrVec.push_back(std::move(newEnt));
	enginePtr->AM.loadAnimFromEnt(ent_ptrVec.back());
}

Entity &EntityManager::getEnt(int i){
	return *ent_ptrVec.at(i);
}

EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}
