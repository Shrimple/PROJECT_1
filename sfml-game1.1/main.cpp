#include "Debug.h"
#include "MNEngine.h"
#include <iostream>
#include <chrono>
#include <thread>
MNEngine MNE;

void main() {
	MNE.init();
	MNE.loadTestTextures();

	Debug::setState(true);

	//setup dev zone
	if (!MNE.MM.loadMap("maptest.txt", "tileset1.png"))
		std::cout << "map has failed to load." << std::endl;

	MNE.spawnPlayer();
	MNE.spawnEntity("testen.png", 20, 0);
	MNE.spawnEntity("testen.png", 40, 0);
	MNE.spawnEntity("testen.png", 60, 20);
	MNE.spawnEntity("testen.png", 80, 40);
	

	Debug::printEntVec(MNE.EM.getVec());

	//main loop
	while (MNE.Cam.window->isOpen()){
		MNE.pollEvent();
		MNE.update();
		MNE.render();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));;
	}
	return;
}


