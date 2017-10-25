#include "Namespace.h"
#include "Camera.h"
#include "Animation.h"
#include "Debug.h"
#include "EntityManager.h"
#include "MNEngine.h"
#include "SFML\Graphics.hpp"

using namespace csp;


Player::~Player() {
}

void Player::pollMoveE(sf::Event &e, TileMap * map) {
	//sprite origin is now middle
	yaw = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		yaw += 0;
		velocity.x += (speed - velocity.x);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		yaw += 2;
		velocity.x -= (speed + velocity.x);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		yaw += 1;
		velocity.y -= (speed + velocity.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		yaw += 3;
		velocity.y += (speed - velocity.y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		std::cout << "spacebar" << std::endl;
	}

	//debug key

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Insert)) {
		if (Debug::isActive()) {
			Debug::setState(false);
		}
		else {
			Debug::setState(true);
		}
	}

	/*cout << "pposX:" << pposX << " pposY:" << pposY << " ppos_tileX:" << pposTileX << " ppos_tileY:" << pposTileY << endl;
	cout << "    " << topTile << endl;
	cout << leftTile << " " << currentTile << " " << rightTile << endl;
	cout << "    " << bottomTile << endl;*/
}