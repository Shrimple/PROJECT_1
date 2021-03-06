#include "Entity.h"
#include "TileMap.h"
#include "AnimationManager.h"
#include "TextureManager.h"
#include "MNEngine.h"
using namespace csp;

Entity::Entity(MNEngine* const ptr, int uid){
	id = uid;
	trajectory = Trajectory(this);
	enginePtr = ptr;
	tex = 0;
	type = EntityType::AI_ENEMY;
	pos.x = (enginePtr->TILE_SIZE / 2), pos.y = (enginePtr->TILE_SIZE / 2);
	sprite.setTexture(enginePtr->TM.get(tex));
	sprite.setPosition(pos.x - (enginePtr->TILE_SIZE / 2), pos.y - (enginePtr->TILE_SIZE / 2));
	yaw = 0;
	animation = Animation(ptr, tex);
}

Entity::Entity(MNEngine* const ptr,int textureVectorIndex, EntityType pType, int uid) {
	id = uid;
	trajectory = Trajectory(this);
	enginePtr = ptr;
	tex = textureVectorIndex;
	type = pType;
	pos.x = (enginePtr->TILE_SIZE / 2), pos.y = (enginePtr->TILE_SIZE / 2);
	sprite.setTexture(enginePtr->TM.get(tex));
	sprite.setPosition(pos.x - (enginePtr->TILE_SIZE / 2), pos.y -(enginePtr->TILE_SIZE / 2));
	yaw = 0;
	animation = Animation(ptr, tex);
}

Entity::Entity(MNEngine* const ptr, int textureVectorIndex, EntityType pType, float xOff, float yOff, int uid) {
	id = uid;
	trajectory = Trajectory(this);
	enginePtr = ptr;
	tex = textureVectorIndex;
	type = pType;
	pos.x = xOff;
	pos.y = yOff;
	sprite.setTexture(enginePtr->TM.get(tex));
	sprite.setPosition(xOff - (enginePtr->TILE_SIZE / 2), yOff - (enginePtr->TILE_SIZE / 2));
	yaw = 0;
	animation = Animation(ptr, tex);
}

void Entity::update() {
	//limit velocity to speed in X
	//if there is no active trajectory enable wasd movement
	if (trajectory.complete) {
		if ((velocity.x > speed) || (velocity.x < -speed)) {
			if (velocity.x > 0)
				velocity.x = speed;
			else
				velocity.x = -speed;
		}

		//limit velocity to speed in Y
		if ((velocity.y > speed) || (velocity.y < -speed)) {
			if (velocity.y > 0)
				velocity.y = speed;
			else
				velocity.y = -speed;
		}
	} else {
		trajectory.calculateVelXY();
	}

	isColliding(enginePtr->MM.getMap());

	if ((health <= 0)&&(!isDead))
		kill();
	//move virtual XY coordinates
	setEntPos(pos.x + velocity.x, pos.y + velocity.y);

	//set animation rect
	sprite.setTextureRect(animation.getRect(tex));

	if ((enginePtr->AM.counter % enginePtr->AM.mod) == 0) {
		animation.incFrame();
	}

	if (velocity.x > 0) velocity.x--; else if (velocity.x < 0) velocity.x++;
	if (velocity.y > 0) velocity.y--; else if (velocity.y < 0) velocity.y++;

}

void Entity::kill(){
	enginePtr->EM.annouceEntDeath(this);
	isDead = true;
}

bool Entity::isColliding(TileMap *map) {
	bool	collidesX	= false,
			collidesY	= false;

	float	pposX		= pos.x,
			pposY		= pos.y;

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

	if (velocity.x > 0 || velocity.y > 0) {
		//right
		if (map->getTile(rightTile.x, rightTile.y).hasCollision) {
			if (offsetX + velocity.x < 10) {
			}
			else if (offsetX + velocity.x == 10) {
			}
			else if (offsetX + velocity.x > 10) {
				velocity.x = velocity.x - ((offsetX + velocity.x) - 10);
				collidesX = true;
			}
		}
		//down
		if (map->getTile(bottomTile.x, bottomTile.y).hasCollision) {
			if (offsetY + velocity.y < 10) {
			}
			else if (offsetY + velocity.y == 10) {
			}
			else if (offsetY + velocity.y > 10) {
				velocity.y = velocity.y - ((offsetY + velocity.y) - 10);
				collidesY = true;
			}
		}
	}

	if (velocity.x < 0 || velocity.y < 0) {
		//up
		if (map->getTile(topTile.x, topTile.y).hasCollision) {
			if (offsetY + velocity.y > 10) {
			}
			else if (offsetY + velocity.y == 10) {
			}
			else if (offsetY + velocity.y < 10) {
				velocity.y = velocity.y - ((offsetY + velocity.y) - 10);
				collidesY = true;
			}
		}

		//left
		if (map->getTile(leftTile.x, leftTile.y).hasCollision) {
			if (offsetX + velocity.x > 10) {
			}
			else if (offsetX + velocity.x == 10) {
			}
			else if (offsetX + velocity.x < 10) {
				velocity.x = velocity.x - ((offsetX + velocity.x) - 10);
				collidesX = true;
			}
		}
	}

	(collidesX || collidesY) ? colliding_s = true : colliding_s = false;

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

void Entity::setEntPos(float x, float y) {
	pos.x = x, pos.y = y;
	sprite.setPosition(x - enginePtr->TILE_SIZE / 2, y - enginePtr->TILE_SIZE / 2);
}


void Entity::setTexture(int texIndex) {
	tex = texIndex;
	sprite.setTexture(enginePtr->TM.get(texIndex));
}

void Entity::setVelocity(float xVel, float yVel) {
	velocity.x = xVel;
	velocity.y = yVel;
}

void Entity::setTrajectory(){
	trajectory.complete = false;
	trajectory.setTarget(enginePtr->Cam.getMousePos());
	trajectory.calculateVelXY();
}

void Entity::setVisibility(bool)
{
}



Entity::~Entity() {
	if(!trajectory.complete)
		trajectory.destroy();


}
