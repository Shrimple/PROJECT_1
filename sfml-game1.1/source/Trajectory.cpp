#include "Trajectory.h"
#include "Entity.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "MNEngine.h"
#define _USE_MATH_DEFINES
#include <math.h>


void Trajectory::check(){
	if (hasTarget) {
		if (lastPos == parent->getPos()) {
			stuck++;
			if (stuck == 10) {
				destroyTarget();
				stuck = 0;
			}
		}


		bool xreach = false, yreach = false;

		if ((parent->getPos().x >= target->getPos().x) && parent->getVelVector().x > 0) {
			xreach = true;
		}
		if ((parent->getPos().y >= target->getPos().y) && parent->getVelVector().y > 0) {
			yreach = true;
		}
		if ((parent->getPos().x <= target->getPos().x) && parent->getVelVector().x < 0) {
			xreach = true;
		}
		if ((parent->getPos().y <= target->getPos().y) && parent->getVelVector().y < 0) {
			yreach = true;
		}

		if (!parent->isColliding()) {
			if (interrupted) {
				origin = parent->getPos();
				calculateVelXY();
				xreach = false;
				yreach = false;
				interrupted = false;
			}
		}else{
			interrupted = true;
		}

		if (xreach) {
			parent->setVelocity(0, parent->getVelVector().y);
		}

		if (yreach) {
			parent->setVelocity(parent->getVelVector().y, 0);
		}

		if (xreach && yreach) {
			destroyTarget();
		}

		lastPos = parent->getPos();
	}
}

void Trajectory::destroyTarget(){
	target->kill();
	parent->setVelocity(0, 0);
	complete = true;
	hasTarget = false;
}

void Trajectory::calculateYaw(){
	if (hasTarget) {
		double theta = atan2(target->getPos().y - origin.y, target->getPos().x - origin.x);
		double angle = (theta * 180) / M_PI;

		if (angle < 0) {
			angle += 360;
		}

		parent->setYaw(angle);
		//std::cout << "yaw: " << angle << std::endl;
	}
}

void Trajectory::destroy(){
	complete = true;
	target->kill();
	hasTarget = false;
}

void Trajectory::calculateVelXY(){
	//(y2-y1)/(x2-x1) = m | f(x)y=mx+b x = (y - b)/m
	sf::Vector2f newVel;
	float speed = parent->getSpeed();

	if (hasTarget) {
		sf::Vector2f deltaD = target->getPos() - origin ;
		float distance = sqrt(pow(deltaD.x, 2) + pow(deltaD.y, 2));
		sf::Vector2f dir = { (target->getPos().x - origin.x) / distance, (target->getPos().y - origin.y) / distance };

		newVel = sf::Vector2f(dir.x * speed, dir.y * speed);
	//	std::cout << "dist=" << distance << ", deltaDis=x" << deltaD.x << "|y" << deltaD.y
	//			  << ", dir=x" << dir.x << "|y" << dir.y << std::endl << "newVel=x" << newVel.x << "|y" << newVel.y << std::endl;
		parent->setVelocity(newVel.x, newVel.y);
		trajVel = newVel;
	}

	return;
}

void Trajectory::setTarget(sf::Vector2f dest){
	if (!hasTarget) {
		hasTarget = true;
		parent->getEnginePtr()->EM.newEntity(4, dest.x, dest.y);
		origin = parent->getPos();
		target = parent->getEnginePtr()->EM.getVec().back();
	} else {
		origin = parent->getPos();
		target->setEntPos(dest.x, dest.y);
	}

	calculateYaw();
	calculateVelXY();
	
}

Trajectory::Trajectory(Entity * const parentEnt){
	complete = true;
	hasTarget = false;
	lastPos = parentEnt->getPos();
	parent = parentEnt;
	origin = parentEnt->getPos();
}

Trajectory::Trajectory(){
	complete = true;
	hasTarget = false;
	parent = NULL;
	lastPos = { 0,0 };
	origin = { 0,0 };
}


Trajectory::~Trajectory(){
}

sf::Vector2f Trajectory::getTarget(){
	return target->getPos();
}
