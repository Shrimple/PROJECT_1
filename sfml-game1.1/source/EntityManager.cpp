#include "EntityManager.h"
#include "AnimationManager.h"
#include "MNEngine.h"
using namespace csp;

bool EntityManager::init(MNEngine* const ptr){
	enginePtr = ptr;
	std::cout << "-EntityManager init @ " << boost::addressof(*this) << "." << std::endl;
	return true;
}

void EntityManager::updateEnts(TileMap * map){
	cleanVector();

	for (boost::shared_ptr<Entity> e : ent_ptrVec)
		e->update();

	if (player != NULL) {
		player->pollMove();
		player->update();
	}
}

std::vector<boost::shared_ptr<Entity>> EntityManager::getVec(){
	return ent_ptrVec;
}

void EntityManager::newPlayerEnt(){
	player = new Player(enginePtr, uuid);
	uuid++;
}

void EntityManager::newEntity(int texIndex, int xOff, int yOff){
	boost::shared_ptr<Entity> newEnt(new Entity(enginePtr, texIndex, csp::AI_ENEMY, xOff, yOff, uuid));
	std::cout << "new entity | texIndex=" << texIndex << ", x=" << xOff << ", =" << yOff << std::endl;
	ent_ptrVec.push_back(std::move(newEnt));
	uuid++;
}

void EntityManager::annouceEntDeath(int sender){
	deadEntities.push_back(sender);
}

void EntityManager::cleanVector() {
	if (deadEntities.size() > 0){
		for (int id : deadEntities) {
			auto iter = std::find_if(ent_ptrVec.begin(), ent_ptrVec.end(),
				[id](boost::shared_ptr<Entity> f) { return (f->getId() == id); });

			if (iter != ent_ptrVec.end()) {
				ent_ptrVec.erase(iter);
			}
		}
		deadEntities.clear();
	}
}



int EntityManager::getLastId(){
	return uuid;
}

Entity &EntityManager::getEnt(int i){
	return *ent_ptrVec.at(i);
}

EntityManager::EntityManager(){
}


EntityManager::~EntityManager(){
}
