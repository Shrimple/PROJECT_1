#pragma once
#ifndef TRAJECTORY_H
#define TRAJECTORY_H
#include "SFML\Graphics.hpp"

class Entity;
class Trajectory
{
private:
	Entity* parent;
	sf::Vector2f origin; //x1, y1
	sf::Vector2i destination; //x2, y2
	
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
	void calculateVelXY();
	void setTarget(sf::Vector2i);
	bool isComplete();
};
#endif


