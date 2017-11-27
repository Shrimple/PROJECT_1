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

void Player::pollMove() {
	//sprite origin is now middle
	yaw = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		yaw += 0;
		velocity.x += (speed - velocity.x);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		yaw += 2;
		velocity.x -= (speed + velocity.x);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		yaw += 1;
		velocity.y -= (speed + velocity.y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		yaw += 3;
		velocity.y += (speed - velocity.y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		std::cout << "spacebar" << std::endl;
	}

	//debug key

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		//If mouse is  in the debug menu - > cancel event for the game.
		if (!ImGui::GetIO().WantCaptureMouse){
			sf::Vector2f mousePosGame = sf::Vector2f(enginePtr->Cam.getMousePos().x*(enginePtr->Cam.camera->getSize().x / enginePtr->Cam.window->getSize().y), enginePtr->Cam.getMousePos().x*(enginePtr->Cam.camera->getSize().y / enginePtr->Cam.window->getSize().y));
			enginePtr->EM.player->setTrajectory();

			if (enginePtr->console.mouseDebug)
				enginePtr->console.AddLog("Mouse -> X: '%.0f' Y: '%.0f' ", mousePosGame.x, mousePosGame.y);
		}
	}

	/*cout << "pposX:" << pposX << " pposY:" << pposY << " ppos_tileX:" << pposTileX << " ppos_tileY:" << pposTileY << endl;
	cout << "    " << topTile << endl;
	cout << leftTile << " " << currentTile << " " << rightTile << endl;
	cout << "    " << bottomTile << endl;*/
}