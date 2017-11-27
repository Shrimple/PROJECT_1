#include "Animation.h"
#include <array>
#include "TextureManager.h"
#include "EntityManager.h"
#include "Camera.h"
#include "Entity.h"
#include "MNEngine.h"

Animation::Animation(const Animation &a){
	parent = a.parent;
	currentFrame = a.currentFrame;
	frames = a.frames;
}


Animation::Animation(Entity* const ptr, int f){
	parent = ptr;
	currentFrame = 0;
	frames = f;
}

Animation::Animation() {
	parent = NULL;
	currentFrame = 0;
	frames = 0;
}

Animation::~Animation(){
}

bool Animation::hasParent(){
	return (parent == nullptr) ? false : true;
}

void Animation::setParentNULL(){
	parent = nullptr;
	frames = 0;
	currentFrame = 0;
}

void Animation::incFrame(){
	currentFrame++;

	if (currentFrame > frames - 1) {
		currentFrame = 0;
	}
}

void Animation::decFrame(){
	currentFrame--;

	if (currentFrame < 0) {
		currentFrame = frames - 1;
	}
}

void Animation::applyRect(){
	parent->setRect(getRect(parent->getTexIndex()));
}

sf::IntRect Animation::getRect(int texIndex){
	sf::Texture tex = parent->enginePtr->TM.get(texIndex);
	int x = (parent->enginePtr->TILE_SIZE*currentFrame) % tex.getSize().x;
	int y = 0;
	return sf::IntRect(x, y, parent->enginePtr->TILE_SIZE, parent->enginePtr->TILE_SIZE);
}

