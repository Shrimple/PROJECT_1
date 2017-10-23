#include "Namespace.h"
#include "Camera.h"
#include "Animation.h"
#include "Debug.h"
#include "EntityManager.h"
#include "SFML\Graphics.hpp"

using namespace csp;


Player::~Player(){
}

void Player::pollMoveE(sf::Event &e, TileMap * map){
	//sprite origin is now middle
	this->yaw = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->yaw += 0;
		this->vX += (this->speed - this->vX);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->yaw += 2;
		this->vX -= (this->speed + this->vX);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->yaw += 1;
		this->vY -= (this->speed + this->vY);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->yaw += 3;
		this->vY += (this->speed - this->vY);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		std::cout << "spacebar" << std::endl;
	}

	//debug key

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Insert)) {
		if (Debug::isActive()) {
			Debug::setState(false);
		} else {
			Debug::setState(true);
		}

	}


	/*cout << "pposX:" << pposX << " pposY:" << pposY << " ppos_tileX:" << pposTileX << " ppos_tileY:" << pposTileY << endl;
	cout << "    " << topTile << endl;
	cout << leftTile << " " << currentTile << " " << rightTile << endl;
	cout << "    " << bottomTile << endl;*/
}