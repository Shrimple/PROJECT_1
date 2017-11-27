#pragma once
#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H
#include <vector>
#include <boost\shared_ptr.hpp>
#include "Player.h"

class Entity;
class MNEngine;

class AnimationManager{
	friend class Animation;
private:
	MNEngine* enginePtr;
	std::vector<Animation*> activeAnimations;

public:
	const int mod = 2;
	int counter;

	AnimationManager();
	~AnimationManager();

	Animation* loadNewAnimation(Entity*, int);
	void init(MNEngine* const);
	void update();
	void cleanVector();
	void incCtr();
	void incAnimFrames();
};
#endif

