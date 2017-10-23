#pragma once
#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H
#include <vector>
#include <boost\shared_ptr.hpp>
#include "Player.h"

class MNEngine;
class AnimationManager{
private:
	MNEngine* enginePtr;

public:
	void init(MNEngine* const);
	const int mod = 2;
	int counter;
	AnimationManager();
	~AnimationManager();
	void loadAnimFromEnt(boost::shared_ptr<Entity>);
	void loadAnimFromP(Player *);
	void loadWorldAnim(TileMap *);
	void incCtr();
	void incAnimFrames();
};
#endif

