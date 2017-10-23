#include "Entity.h"
#include "TileMap.h"
#include "AnimationManager.h"
#include "TextureManager.h"
#include "MNEngine.h"
using namespace csp;

Entity::Entity(MNEngine* const ptr){
	printf("new entity with INIT settings.");
	enginePtr = ptr;
	tex = 0;
	type = EntityType::AI_ENEMY;
	pos.setXY(0, 0);
	sprite.setTexture(enginePtr->TM.get(tex));
	sprite.setPosition(pos.getX(), pos.getY());
	yaw = 0;
	animation = Animation(ptr, tex);
}

Entity::Entity(MNEngine* const ptr,int textureVectorIndex, EntityType pType) {
	printf("new entity with textureId #%d\n", textureVectorIndex);
	enginePtr = ptr;
	tex = textureVectorIndex;
	type = pType;
	pos.setXY(0, 0);
	sprite.setTexture(enginePtr->TM.get(tex));
	yaw = 0;
	animation = Animation(ptr, tex);
}

Entity::Entity(MNEngine* const ptr, int textureVectorIndex, EntityType pType, int xOff, int yOff) {
	printf("new entity with textureId #%d\n @offset x=%d, y=%d\n", textureVectorIndex, xOff, yOff);
	enginePtr = ptr;
	tex = textureVectorIndex;
	type = pType;
	pos.setXY(xOff + (enginePtr->TILE_SIZE / 2), yOff + (enginePtr->TILE_SIZE / 2));
	sprite.setTexture(enginePtr->TM.get(tex));
	sprite.setPosition(xOff, yOff);
	yaw = 0;
	animation = Animation(ptr, tex);
}

void Entity::update(TileMap * map) {
	//limit velocity to speed in X
	if ((vX > speed) || (vX < -speed)) {
		if (vX > 0)
			vX = speed;
		else
			vX = -speed;
	}

	//limit velocity to speed in Y
	if ((vY > speed) || (vY < -speed)) {
		if (vY > 0)
			vY = speed;
		else
			vY = -speed;
	}

	isColliding(map);

	//move virtual XY coordinates
	setEntPos(pos.getX()+vX, pos.getY() + vY);

	//set animation rect
	sprite.setTextureRect(animation.getRect(tex));

	if ((enginePtr->AM.counter % enginePtr->AM.mod) == 0) {
		animation.incFrame();
	}

	if (vX > 0) vX--; else if (vX < 0) vX++;
	if (vY > 0) vY--; else if (vY < 0) vY++;

}

bool Entity::isColliding(TileMap *map) {
	bool	collidesX	= false,
			collidesY	= false;

	float	pposX		= pos.getX(),
			pposY		= pos.getY();

	sf::Vector2f topTile	= { pposX , pposY - enginePtr->TILE_SIZE },
			bottomTile  = { pposX , pposY + enginePtr->TILE_SIZE },
			leftTile	= { pposX - enginePtr->TILE_SIZE, pposY },
			rightTile	= { pposX + enginePtr->TILE_SIZE, pposY },
			topRight	= { pposX + enginePtr->TILE_SIZE, pposY - enginePtr->TILE_SIZE },
			topLeft		= { pposX - enginePtr->TILE_SIZE, pposY - enginePtr->TILE_SIZE },
			botRight	= { pposX + enginePtr->TILE_SIZE, pposY + enginePtr->TILE_SIZE },
			botLeft		= { pposX - enginePtr->TILE_SIZE, pposY + enginePtr->TILE_SIZE };

	int		offsetX		= (int) pposX % (enginePtr->TILE_SIZE),
			offsetY		= (int) pposY % (enginePtr->TILE_SIZE);

	if (vX > 0 || vY > 0) {
		//right
		if (map->getTile(rightTile.x, rightTile.y).hasCollision) {
			if (offsetX + vX < 10) {
			}
			else if (offsetX + vX == 10) {
			}
			else if (offsetX + vX > 10) {
				vX = vX - ((offsetX + vX) - 10);
				collidesX = true;
			}
		}
		//down
		if (map->getTile(bottomTile.x, bottomTile.y).hasCollision) {
			if (offsetY + vY < 10) {
			}
			else if (offsetY + vY == 10) {
			}
			else if (offsetY + vY > 10) {
				vY = vY - ((offsetY + vY) - 10);
				collidesY = true;
			}
		}
	}

	if (vX < 0 || vY < 0) {
		//up
		if (map->getTile(topTile.x, topTile.y).hasCollision) {
			if (offsetY + vY > 10) {
			}
			else if (offsetY + vY == 10) {
			}
			else if (offsetY + vY < 10) {
				vY = vY - ((offsetY + vY) - 10);
				collidesY = true;
			}
		}

		//left
		if (map->getTile(leftTile.x, leftTile.y).hasCollision) {
			if (offsetX + vX > 10) {
			}
			else if (offsetX + vX == 10) {
			}
			else if (offsetX + vX < 10) {
				vX = vX - ((offsetX + vX) - 10);
				collidesX = true;
			}
		}
	}

	return (collidesX || collidesY) ? true : false;
}

void Entity::setAnim(Animation a) {
	animation = a;
}

void Entity::setDirection(int dir) {
	if (dir < 8)
		yaw = dir;
	else {
		yaw = 0;
	}
}

void Entity::setEntPos(int x, int y) {
	pos.setXY(x, y);
	sprite.setPosition(x- enginePtr->TILE_SIZE / 2, y- enginePtr->TILE_SIZE / 2);
}


void Entity::setTexture(int texIndex) {
	tex = texIndex;
	sprite.setTexture(enginePtr->TM.get(texIndex));
}



Entity::~Entity() {
}
