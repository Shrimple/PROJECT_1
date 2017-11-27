#include "AnimationManager.h"
#include <boost\utility.hpp>
#include "TextureManager.h"
#include "Camera.h"
#include "EntityManager.h"
#include "Animation.h"
#include "Entity.h"
#include "MNEngine.h"

void AnimationManager::init(MNEngine* const ptr) {
	enginePtr = ptr;
	std::cout << "-AnimationManager init @ " << boost::addressof(*this) << "." << std::endl;
	std::cout << "Engine ptr @ " << enginePtr << "." << std::endl;
}

Animation * AnimationManager::loadNewAnimation(Entity * e, int f){
	activeAnimations.push_back(new Animation(e, f));
	return activeAnimations.back();
}

void AnimationManager::update(){
	cleanVector();

	for (Animation* a : activeAnimations) {
		a->applyRect();
	}
}

void AnimationManager::cleanVector(){
	auto iter = std::find_if(activeAnimations.begin(), activeAnimations.end(),
		[](Animation* a) { return (a->hasParent() == false); });

		if(iter != activeAnimations.end()){
			activeAnimations.erase(iter);
		}

}

void AnimationManager::incCtr(){
	counter++;

	if (counter > 500000)
		counter = 0;
}

void AnimationManager::incAnimFrames(){
	for (Animation* a : activeAnimations)
		a->incFrame();
}

AnimationManager::AnimationManager(){
	enginePtr = NULL;
	counter = 0;
}


AnimationManager::~AnimationManager(){
	for (Animation* a : activeAnimations) {
		delete a;
	}
}
