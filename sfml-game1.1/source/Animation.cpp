#include "Animation.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include "Camera.h"
#include <array>
#include "MNEngine.h"

Animation::Animation(MNEngine* const ptr, const Animation &a){
	parent = &ptr->AM;
	currentFrame = a.currentFrame;
	frames = a.frames;
}


Animation::Animation(MNEngine* const ptr, int framez){
	parent = &ptr->AM;
	currentFrame = 0;
	frames = framez;
}

Animation::Animation(MNEngine* const ptr){
	parent = &ptr->AM;
	currentFrame = 0;
	frames = 0;
}

Animation::Animation() {
	parent = NULL;
	currentFrame = 0;
	frames = 0;
}

Animation::~Animation(){
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

sf::IntRect Animation::getRect(int texIndex){
	sf::Texture tex = parent->enginePtr->TM.get(texIndex);
	int x = (parent->enginePtr->TILE_SIZE*this->currentFrame) % tex.getSize().x;
	int y = 0;
	return sf::IntRect(x, y, parent->enginePtr->TILE_SIZE, parent->enginePtr->TILE_SIZE);
}

