#pragma once
#ifndef NAMESPACE_H
#define NAMESPACE_H
namespace csp {
	enum EntityType {
		PLAYER, AI_ENEMY,
	};

	enum TileType {
		AIR, WALL, DOOR, WALLBRIDGE
	};

	struct Tile {
		TileType	type;
		bool	hasCollision;
		bool	isAnimated;
		bool	hasInteraction;
		int		frames;
	};
}
#endif
/*#include <SFML/Graphics.hpp>
		#include <SFML/System.hpp>
		#include "TileMap.h"
		#include "Namespace.h"
		#include "MapManager.h"
		#include "TextureManager.h"
		#include "EntityManager.h"
		#include "TextureData.h"
		#include "AnimationManager.h"
		#include "Entity.h"
		#include "Debug.h"
		#include "Camera.h"*/