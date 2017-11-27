#include "Hitbox.h"
#include "Entity.h"
#include "MNEngine.h"

Hitbox::Hitbox(Entity * const ePtr, std::vector<sf::Vector2f> pointz){
	parent = ePtr;
	points = pointz;
}

Hitbox::Hitbox(Entity * const e){
	parent = e;
	if (parent != nullptr) {
		points.push_back(sf::Vector2f(0, 0));
		points.push_back(sf::Vector2f(parent->getEnginePtr()->TILE_SIZE, 0));
		points.push_back(sf::Vector2f(parent->getEnginePtr()->TILE_SIZE, parent->getEnginePtr()->TILE_SIZE));
		points.push_back(sf::Vector2f(0, parent->getEnginePtr()->TILE_SIZE));
	}
}

Hitbox::Hitbox(){
	parent = nullptr;
}

Hitbox::~Hitbox() {
}

sf::Vector2f Hitbox::getTopLeft() {
	return sf::Vector2f(parent->getPos().x - (points[0].x / 2), parent->getPos().y - (points[0].y / 2)); 
}

sf::Vector2f Hitbox::getTopRight() { 
	return sf::Vector2f(parent->getPos().x - (points[1].x / 2), parent->getPos().y - (points[1].y / 2)); 
}

sf::Vector2f Hitbox::getBotRight() {
	return sf::Vector2f(parent->getPos().x - (points[2].x / 2), parent->getPos().y - (points[2].y / 2));
}

sf::Vector2f Hitbox::getBotLeft() { 
	return sf::Vector2f(parent->getPos().x - (points[3].x / 2), parent->getPos().y - (points[3].y / 2)); 
}

void Hitbox::update(){
}

std::vector<sf::Vector2f> Hitbox::getVPoints(){
	std::vector<sf::Vector2f> vPoints;

	vPoints.push_back(getTopLeft());
	vPoints.push_back(getTopRight());
	vPoints.push_back(getBotRight());
	vPoints.push_back(getBotLeft());

	return vPoints;
}
