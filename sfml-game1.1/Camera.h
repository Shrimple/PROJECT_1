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
	void moveCam2P();
	void init(MNEngine* const);
	sf::Vector2i getMousePos();
	Camera();
	~Camera();
};
#endif

