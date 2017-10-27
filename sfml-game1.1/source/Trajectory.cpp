#include "Trajectory.h"
#include "Entity.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "MNEngine.h"


void Trajectory::calculateYaw(){
}

void Trajectory::destroy(){
	complete = true;
	destination = origin;
}

void Trajectory::calculateVelXY(){
	//(y2-y1)/(x2-x1) = m | f(x)y=mx+b x = (y - b)/m
	sf::Vector2f newVel;

	if (!complete) {
		lastPos = origin;
		origin = parent->getPos();

		if (origin == lastPos)
			stuck++;

		//calculateYaw();

		if ((origin.x != destination.x) || (origin.y != destination.y)) {

			newVel = sf::Vector2f(destination.x, destination.y) - (origin);

			if (newVel.x < -2){ newVel.x = -2;	}

			if (newVel.x > 2) {newVel.x = 2;	}

			if (newVel.y < -2){newVel.y = -2;	}

			if (newVel.y > 2) {newVel.y = 2;	}

			parent->setVelocity(newVel.x, newVel.y);

			if ((abs(destination.x - origin.x) < 1) && (abs(destination.y - origin.y) < 1)) {
				complete = true;
				parent->setVelocity(0, 0);
			}

			stuck = 0;
		}

		if (stuck == 5) {
			stuck = 0;
			target->kill();
			complete = true;
		}

		if ((parent->getVelVector().x == 0) && (parent->getVelVector().y == 0)) {
			target->kill();
		}
	}

	return;
}

void Trajectory::setTarget(sf::Vector2f dest){
	destination = dest;
	parent->getEnginePtr()->EM.newEntity(4, dest.x, dest.y);
	if (target != nullptr)
		target->kill();

	target = parent->getEnginePtr()->EM.getVec().back();
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
