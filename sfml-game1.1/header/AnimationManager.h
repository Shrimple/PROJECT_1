#pragma once
#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H
#include <vector>
#include <boost\shared_ptr.hpp>
#include "Player.h"

class MNEngine;

class AnimationManager{
	friend class Animation;
private:
	MNEngine* enginePtr;

public:
	const int mod = 2;
	int counter;

	AnimationManager();
	~AnimationManager();
	void init(MNEngine* const);
	void loadAnimFromEnt(boost::shared_ptr<Entity>);
	void loadAnimFromP(Player *);
	void loadWorldAnim(TileMap *);
	void incCtr();
	void incAnimFrames();
};
#endif

