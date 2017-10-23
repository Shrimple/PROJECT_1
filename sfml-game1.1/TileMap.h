#pragma once
#ifndef TILEMAP_H
#define TILEMAP_H
#include <array>
#include <tuple>
#include <string>
#include <SFML\Graphics.hpp>
#include "Namespace.h"

using namespace csp;

class MNEngine;
class TileMap : public sf::Drawable, public sf::Transformable {
private:
	MNEngine* enginePtr;
	std::array<int, 2048> map;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices;
	std::string tileset_filename;
	Tile readTile(int tile);

public:
	Tile getTile(int i, int y);
	void setMap(std::array<int, 2048> pMap);
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	TileMap(MNEngine* const);
	~TileMap();
};
#endif
