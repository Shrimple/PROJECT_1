#include "TileMap.h"
#include "MNEngine.h"
#include "Namespace.h"
using namespace csp;

void TileMap::setMap(std::array<int, 2048> pMap){
		this->map = pMap;
}

void TileMap::draw(sf::RenderTarget & target, sf::RenderStates states) const{	
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &enginePtr->TM.get(tileset_filename);

		// draw the vertex array
		target.draw(m_vertices, states);
}

Tile TileMap::readTile(int tile){
	switch (tile) {
	case 0: return Tile{ csp::AIR ,0,1,0,5 };
	case 1: return Tile{ csp::WALL,1,0,0,1 };
	case 2: return Tile{ csp::DOOR,1,1,1,1 };
	case 3: return Tile{ csp::WALLBRIDGE, 1,1,1,1 };
 	default:return Tile{ csp::AIR ,0,1,0,5 };
	}
}

Tile TileMap::getTile(int x, int y){
	int i = (x / enginePtr->TILE_SIZE) + ((y / enginePtr->TILE_SIZE) * (enginePtr->Cam.window->getSize().x / enginePtr->TILE_SIZE));

	if (i < map.size())
		return readTile(map[i]);
	else
		return readTile(map[0]);
}

bool TileMap::load(const std::string & tileset, sf::Vector2u tileSize, const int * tiles, unsigned int width, unsigned int height){
	// load the tileset texture
	this->tileset_filename = tileset;

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width];

			// find its position in the tileset texture
			int tu = tileNumber % (enginePtr->TM.get(tileset).getSize().x / tileSize.x);
			int tv = tileNumber / (enginePtr->TM.get(tileset).getSize().x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}

TileMap::TileMap(MNEngine* const ptr){
	enginePtr = ptr;
}


TileMap::~TileMap(){
}
