#ifndef HITBOX_H
#define HITBOX_H
#include <vector>
#include "SFML\Graphics.hpp"
class Entity;
class Hitbox {
private:
	Entity * parent;

public:
	std::vector<sf::Vector2f> points;

	Hitbox(Entity * const, std::vector<sf::Vector2f>);
	Hitbox(Entity * const);
	Hitbox();
	~Hitbox();

	void update();
	sf::Vector2f getTopLeft();
	sf::Vector2f getTopRight();
	sf::Vector2f getBotRight();
	sf::Vector2f getBotLeft();
	std::vector<sf::Vector2f> getVPoints();
};
#endif
