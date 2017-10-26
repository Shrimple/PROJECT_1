#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include <SFML/Graphics.hpp>
#include "TileMap.h"

class MNEngine;
class Camera{
private:
	MNEngine* enginePtr;

public:
	sf::Font* dFont;
	sf::View* camera;
	sf::RenderWindow* window;
	sf::Vector2f getMousePos();
	void init(MNEngine* const);
	void moveCam2P();
	Camera();
	~Camera();
};
#endif

