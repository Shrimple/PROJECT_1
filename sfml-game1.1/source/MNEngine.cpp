#include "MNEngine.h"
#include "Debug.h"
#include "boost\shared_ptr.hpp"

bool MNEngine::init(){
	std::cout << "Engine init @ " << boost::addressof(*this) << "." << std::endl;
	TM.init(this);
	EM.init(this);
	MM.init(this);
	AM.init(this);
	Cam.init(this);
	return true;
}

void MNEngine::loadTestTextures(){
	TM.loadTex("tileset1.png");
	TM.loadTex("testtex.png");
	TM.loadTex("testen.png");
	TM.loadTex("bridgetile.png");
	TM.loadTex("target.png");
}

void MNEngine::render(){
	Cam.window->clear();

	Cam.window->draw(*MM.getMap());

	if (EM.getVec().size() >= 1) {
		for (boost::shared_ptr<Entity> e : EM.getVec()) {
			Cam.window->draw(e->getSprite());
		}
	}

	Cam.window->draw(EM.player->getSprite());

	Debug::updateOSD(this, MM.getMap());

	Cam.window->display();
}

void MNEngine::pollEvent(){
	sf::Event e;

	while (Cam.window->pollEvent(e)) {

		if (e.type == sf::Event::Closed)
			Cam.window->close();

		if (e.type == sf::Event::KeyPressed) {
			EM.player->pollMoveE(e, MM.getMap());
		}

		if (e.type == sf::Event::MouseButtonPressed) {
			EM.player->setTrajectory();
		}
	}
}

void MNEngine::moveScreen(){
	if (Cam.camera->getCenter() != sf::Vector2f(EM.player->getPos().x, EM.player->getPos().y)) {
		Cam.moveCam2P();
		Cam.window->setView(*Cam.camera);
	}
}

void MNEngine::spawnEntity(char * fileName, int xoff, int yoff){
	int index = TM.loadTex(fileName);
	EM.newEntity(index, xoff, yoff);
}

void MNEngine::update(){
	AM.incCtr();
	AM.incAnimFrames();
	EM.cleanVector();
	EM.updateEnts(MM.getMap());
	moveScreen();
}

void MNEngine::onScreenDebug(bool)
{
}

void MNEngine::spawnPlayer(){
	EM.newPlayerEnt();
}

MNEngine::MNEngine()
{
}


MNEngine::~MNEngine()
{
}
