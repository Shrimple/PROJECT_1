#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include "AnimType.h"

class MNEngine;
class Entity;
class Animation{
private:
	bool loop;
	int frames;
	int currentFrame;
	AnimType type;
	Entity* parent;

public:
	Animation(const Animation &);
	Animation(Entity* const, int);
	Animation();
	~Animation();

	bool hasParent();

	void setParentNULL();
	void incFrame();
	void decFrame();
	void applyRect();
	sf::IntRect getRect(int texIndex);
};
#endif
