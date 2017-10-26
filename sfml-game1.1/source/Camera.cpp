#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include <iostream>
#include "Namespace.h"
#include "MNEngine.h"
#include "EntityManager.h"
#include "SFML\Window.hpp"

using namespace csp;

void Camera::init(MNEngine* const ptr){
	enginePtr = ptr;

	std::cout << "-Screen init." << std::endl;

	dFont = new sf::Font();

	if (!dFont->loadFromFile("INFO56_0.ttf")) {
		std::cout << "Failed to load font!" << std::endl;
	}else {
		std::cout << "Loaded default 'INFO56_0.ttf' font." << std::endl;
	}

	window = new sf::RenderWindow(sf::VideoMode(1000, 800), "wat");
	camera = new sf::View();

	camera->reset(sf::FloatRect(0, 0, 200, 200));
	camera->zoom(2);

	std::cout << "Camera properties set." << std::endl;

	window->setFramerateLimit(50);
	window->setView(*camera);

	std::cout << "Window set to camera." << std::endl;
	std::cout << "Camera init @ " << boost::addressof(*this) << "." << std::endl;
	std::cout << "Engine ptr @ " << enginePtr << "." << std::endl;
	std::cout << "-Screen initialized" << std::endl;
}

sf::Vector2f Camera::getMousePos(){
	sf::Vector2f winMax(window->getSize().x, window->getSize().y),
				 camMax(camera->getCenter().x + camera->getSize().x / 2, camera->getCenter().y + camera->getSize().y / 2),
				 camMin(camera->getCenter().x - camera->getSize().x / 2, camera->getCenter().y - camera->getSize().y / 2);
				
	
	float percentX = sf::Mouse::getPosition(*window).x / winMax.x;
	float percentY = sf::Mouse::getPosition(*window).y / winMax.y;

	return sf::Vector2f(percentX * (camMax.x-camMin.x) + camMin.x,
						percentY * (camMax.y-camMin.y) + camMin.y);
}

void Camera::moveCam2P(){
	sf::Vector2f pVec = sf::Vector2f(enginePtr->EM.player->getPos().x, enginePtr->EM.player->getPos().y);
		sf::Vector2f rVec = pVec - camera->getCenter();

		if ((pVec.x - (camera->getSize().x / 2) < 0) || (pVec.x + (camera->getSize().x / 2) >window->getSize().x)){
			rVec.x = 0;
		}

		if ((pVec.y - (camera->getSize().y / 2) < 0) || (pVec.y + (camera->getSize().y / 2) > window->getSize().y)) {
			rVec.y = 0;
		}

		if ((rVec.x != 0) || (rVec.y != 0)) {
			camera->move(rVec.x, rVec.y);
			//cout << "cam move -> pPos-x" << Screen::camera->getCenter().x << " y" << Screen::camera->getCenter().y << endl;
		}	
}

Camera::Camera(){
	
}

Camera::~Camera(){
}
