#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Namespace.h"
#include "Animation.h"
#include "Trajectory.h"

class MNEngine;
class Entity{
protected:
	MNEngine* enginePtr;
	int speed = 2, tex, yaw;
	//0-7 diagonals count
	sf::Vector2f pos, velocity;
	sf::Sprite sprite;
	csp::EntityType type;
	Animation animation;
	//linear trajectory
	Trajectory trajectory;
	bool isColliding(TileMap *);

public:
	Entity(MNEngine* const);
	Entity(MNEngine* const, int textureVectorIndex, csp::EntityType type);
	Entity(MNEngine* const, int textureVectorIndex, csp::EntityType type, float xOff, float yOff);
	~Entity();

	void update(TileMap *);
	void setAnim(Animation);
	void setDirection(int);
	void setSpeed(int sp) { speed = sp; };
	void setEntPos(float, float);
	void setTexture(int);
	void setVelocity(float, float);
	void setTrajectory();

	int getTexIndex() { return tex; };
	int getSpeed() { return speed; };
	float getYaw() { return yaw; };
	float getVX() { return velocity.x; };
	float getVY() { return velocity.y; };

	sf::Sprite getSprite() { return sprite; };
	sf::Vector2f getPos() { return pos; };
	sf::Vector2f getVelVector() { return velocity; };
	csp::EntityType getType() { return type; };
	Animation getAnim() { return animation; };
};
#endif