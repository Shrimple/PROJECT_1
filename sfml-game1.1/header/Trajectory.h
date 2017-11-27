#pragma once
#ifndef TRAJECTORY_H
#define TRAJECTORY_H
#include "SFML\Graphics.hpp"
#include "boost\shared_ptr.hpp"

class Entity;
class Trajectory{
private:
	Entity* parent;
	boost::shared_ptr<Entity> target;
	//           x1, y1    x2, y2
	sf::Vector2f origin, lastPos; 
	
public:
	bool hasTarget;
	bool complete;
	int stuck = 0;

	Trajectory(Entity* const);
	Trajectory();
	~Trajectory();

	sf::Vector2f getTarget();
	sf::Vector2f getOrigin() { return origin; };

	void check();
	void destroy();
	void destroyTarget();
	void calculateYaw();
	void calculateVelXY();
	void setTarget(sf::Vector2f);
};
#endif


