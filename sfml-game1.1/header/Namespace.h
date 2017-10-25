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