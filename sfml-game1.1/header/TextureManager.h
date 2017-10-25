#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include "Entity.h"
#include "Namespace.h"
#include "TextureData.h"

class MNEngine;
class TextureManager{
private:
	MNEngine* enginePtr;
	std::vector<TextureData> textureVector;

public:
	bool init(MNEngine* const);
	int loadTex(std::string fileName);
	sf::Texture &get(int i);
	sf::Texture &get(std::string filename);
	TextureManager();
	~TextureManager();
};
#endif
