#pragma once
#ifndef TRAJECTORY_H
#define TRAJECTORY_H
#include "SFML\Graphics.hpp"
#include "boost\shared_ptr.hpp"

class Entity;
class Trajectory
{
private:
	Entity* parent;
	boost::shared_ptr<Entity> target;
	//           x1, y1    x2, y2
	sf::Vector2f origin, destination, lastPos; 
	bool hasTarget;
	float m;
	float x;
	float b;

	//facing completely right
	float yaw = 0;
	
public:
	bool complete;
	int stuck = 0;

	Trajectory(Entity* const);
	Trajectory();
	~Trajectory();

	void destroyTarget();
	void calculateYaw();
	void destroy();
	void calculateVelXY();
	void setTarget(sf::Vector2f);
};
#endif


