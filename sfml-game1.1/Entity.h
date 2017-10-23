#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Coord.h"
#include "Namespace.h"
#include "Animation.h"

class MNEngine;
class Entity
{
protected:
	MNEngine* enginePtr;
	int speed = 2, tex, yaw,
		vX = 0, vY = 0;
	//0-7 diagonals count

	Coord pos;
	Animation animation;
	sf::Sprite sprite;
	csp::EntityType type;
	bool isColliding(TileMap *);

public:
	Entity(MNEngine* const);
	Entity(MNEngine* const, int textureVectorIndex, csp::EntityType type);
	Entity(MNEngine* const, int textureVectorIndex, csp::EntityType type, int xOff, int yOff);
	~Entity();
	void update(TileMap *);
	void setAnim(Animation);
	int getTexIndex() { return this->tex; };
	sf::Sprite getSprite() { return this->sprite; };
	void setDirection(int dir);
	int getYaw() { return this->yaw; };
	Coord getPos() { return this->pos; };
	int getVX() { return this->vX; };
	int getVY() { return this->vY; };
	int getSpeed() { return this->speed; };
	Animation getAnim() { return this->animation; };
	csp::EntityType getType() { return this->type; };
	void setSpeed(int sp) { this->speed = sp; };
	void setEntPos(int x, int y);
	void setTexture(int texIndex);
};
#endif