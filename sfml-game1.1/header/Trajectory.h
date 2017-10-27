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
	sf::Vector2f origin; //x1, y1
	sf::Vector2f destination; //x2, y2
	float m;
	float x;
	float b;
	
public:
	//facing completely right
	float yaw = 0;
	bool complete;
	int stuck = 0;
	sf::Vector2f lastPos;

	Trajectory(Entity* const);
	Trajectory();
	~Trajectory();

	void calculateYaw();
	void destroy();
	void calculateVelXY();
	void setTarget(sf::Vector2f);
	bool isComplete();
};
#endif


