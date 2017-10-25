#include "AnimationManager.h"
#include <boost\utility.hpp>
#include "TextureManager.h"
#include "Camera.h"
#include "EntityManager.h"
#include "Animation.h"
#include "Entity.h"
#include "MNEngine.h"

void AnimationManager::init(MNEngine* const ptr) {
	enginePtr = ptr;
	std::cout << "-AnimationManager init @ " << boost::addressof(*this) << "." << std::endl;
	std::cout << "Engine ptr @ " << enginePtr << "." << std::endl;
}

void AnimationManager::loadAnimFromEnt(boost::shared_ptr<Entity> e){
	sf::Texture tex = enginePtr->TM.get(e->getTexIndex()); 
	int frames = (tex.getSize().x / enginePtr->TILE_SIZE) * (tex.getSize().y / enginePtr->TILE_SIZE);
	Animation anim(enginePtr, frames);
	e->setAnim(anim);
}

void AnimationManager::loadAnimFromP(Player * e) {
	sf::Texture tex = enginePtr->TM.get(e->getTexIndex());
	int frames = (tex.getSize().x / enginePtr->TILE_SIZE) * (tex.getSize().y / enginePtr->TILE_SIZE);

	Animation anim(enginePtr, frames);
	e->setAnim(anim);
}

void AnimationManager::loadWorldAnim(TileMap * t) 
{
}

void AnimationManager::incCtr(){
	counter++;

	if (counter > 500000)
		counter = 0;
}

void AnimationManager::incAnimFrames(){
	for (boost::shared_ptr<Entity> e : enginePtr->EM.getVec())
		e->getAnim().incFrame();
}

AnimationManager::AnimationManager(){
}


AnimationManager::~AnimationManager(){
}
