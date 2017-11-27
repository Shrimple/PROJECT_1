#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Namespace.h"
#include "Animation.h"
#include "Trajectory.h"
#include "Hitbox.h"

class MNEngine;
class Entity{
friend class Animation;
protected:
	MNEngine* enginePtr;
	Animation* animation;
	int health = 100, speed = 2, tex, yaw, id;
	//useful states (states finish with _s)
	bool visible_s = true, colliding_s = false;
	//0-7 diagonals count(old)
	sf::Vector2f pos, velocity;
	sf::Sprite sprite;
	csp::EntityType type;
	Hitbox hitbox;
	//linear trajectory (for now)
	Trajectory trajectory;

public:
	bool isDead = false;

	Entity(MNEngine* const, int);
	Entity(MNEngine* const, int textureVectorIndex, csp::EntityType type, int);
	Entity(MNEngine* const, int textureVectorIndex, csp::EntityType type, float xOff, float yOff, int);
	virtual ~Entity();

	void update();
	void kill();
	void setAnim(Animation*);
	void setSpeed(int sp) { speed = sp; };
	void setEntPos(float, float);
	void setTexture(int);
	void setVelocity(float, float);
	void setTrajectory();
	void setVisibility(bool);
	void setRect(sf::IntRect);
	void setYaw(int);

	int getTexIndex() { return tex; };
	int getSpeed() { return speed; };
	int getId() { return id; };
	int getYaw() { return yaw; };
	float getVX() { return velocity.x; };
	float getVY() { return velocity.y; };
	Trajectory getTrajectory() { return trajectory; };
	Hitbox getHitbox() { return hitbox; };
	bool isVisible() { return visible_s; };
	bool detectCollision();
	bool isColliding();
	MNEngine* getEnginePtr() {return enginePtr; };


	sf::Sprite getSprite() { return sprite; };
	sf::Vector2f getPos() { return pos; };
	sf::Vector2f getVelVector() { return velocity; };
	csp::EntityType getType() { return type; };
	Animation* getAnim() { return animation; };
};
#endif