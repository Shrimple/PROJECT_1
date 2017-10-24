#include "Trajectory.h"
#include "Entity.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"


void Trajectory::calculateYaw(){
}

void Trajectory::calculateVelXY(){
	//(y2-y1)/(x2-x1) = m | f(x)y=mx+b x = (y - b)/m
	sf::Vector2f newVel;

	if (!complete) {
		lastPos = origin;
		origin = parent->getPos();
		if (origin == lastPos)
			stuck++;
		calculateYaw();
	/**float m = (destination.y - origin.y) / (destination.x - origin.x),
		  b = origin.y,
		  x = ((parent->getPos().y + ((destination.y - origin.y) / parent->getSpeed())) - b) / m,
		  y = m*x + b;
		  **/

		if ((origin.x != destination.x) || (origin.y != destination.y)) {

			std::cout << "trajectory : originvec=(" << origin.x << ", " << origin.y << ")" << std::endl;
			std::cout << "           : destvec=(" << destination.x << ", " << destination.y << ") yaw=" << yaw << std::endl;
			newVel = sf::Vector2f(destination.x, destination.y) - (origin);
			//newVel = {newVel.x-(newVel.x-parent->getSpeed()),newVel.y - (newVel.y - parent->getSpeed()) };
			std::cout << "           : newVel=(" << newVel.x << ", " << newVel.y << ")" << std::endl;
			parent->setVelocity(newVel.x, newVel.y);

			if ((origin.x == destination.x) && (origin.y == destination.y)) {
				complete = true;
			}

			//complete = true;
		}

		if (stuck == 5) {
			stuck = 0;
			complete = true;
		}
	}

	return;
}

void Trajectory::setTarget(sf::Vector2i dest){
	destination = dest;
}

bool Trajectory::isComplete(){
	return complete;
}

Trajectory::Trajectory(Entity * const parentEnt){
	complete = true;
	lastPos = parentEnt->getPos();
	parent = parentEnt;
	origin = parentEnt->getPos();
	destination.x = parentEnt->getPos().x;
	destination.y = parentEnt->getPos().y;
}

Trajectory::Trajectory(){
	complete = true;
	parent = NULL;
	lastPos = { 0,0 };
	origin = { 0,0 };
	destination = {0,0};
}


Trajectory::~Trajectory()
{
}
