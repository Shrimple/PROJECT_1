#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include "AnimType.h"

class MNEngine;
class Animation{
private:
	bool loop;
	AnimType type;
	int frames;
	int currentFrame;
	MNEngine* enginePtr;

public:
	Animation(MNEngine* const, const Animation &);
	Animation(MNEngine* const, int i);
	Animation(MNEngine* const);
	Animation();
	~Animation();
	void incFrame();
	void decFrame();
	sf::IntRect getRect(int texIndex);
};
#endif
