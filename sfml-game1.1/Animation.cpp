#include "Animation.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include "Camera.h"
#include <array>
#include "MNEngine.h"

Animation::Animation(MNEngine* const ptr, const Animation &a){
	this->enginePtr = ptr;
	this->currentFrame = a.currentFrame;
	this->frames = a.frames;
}


Animation::Animation(MNEngine* const ptr, int frames){
	this->enginePtr = ptr;
	this->currentFrame = 0;
	this->frames = frames;
}

Animation::Animation(MNEngine* const ptr){
	this->enginePtr = ptr;
	this->currentFrame = 0;
	this->frames = 0;
}

Animation::Animation() {
	this->enginePtr = NULL;
	this->currentFrame = 0;
	this->frames = 0;
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
	sf::Texture tex = enginePtr->TM.get(texIndex);
	int x = (enginePtr->TILE_SIZE*this->currentFrame) % tex.getSize().x;
	int y = 0;
	return sf::IntRect(x, y, enginePtr->TILE_SIZE, enginePtr->TILE_SIZE);
}

