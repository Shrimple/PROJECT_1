#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include "AnimType.h"

class MNEngine;
class AnimationManager;
class Animation{
private:
	bool loop;
	int frames;
	int currentFrame;
	AnimType type;
	AnimationManager* parent;

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
