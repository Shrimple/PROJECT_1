#include "MNEngine.h"
#include "Debug.h"
#include "boost\shared_ptr.hpp"

Console MNEngine::console;

bool MNEngine::init(){
	std::cout << "Engine init @ " << boost::addressof(*this) << "." << std::endl;
	TM.init(this);
	EM.init(this);
	MM.init(this);
	AM.init(this);
	Cam.init(this);
	ImGui::SFML::Init(*Cam.window);
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

	ImGui::SFML::Render(*Cam.window);
	Cam.window->display();
}

void MNEngine::pollEvent(){
	sf::Event e;

	while (Cam.window->pollEvent(e)) {
		ImGui::SFML::ProcessEvent(e);

		if (e.type == sf::Event::Closed)
			Cam.window->close();

		if (e.type == sf::Event::KeyPressed) {
			//If Keyboard is in the debug menu - > Cancel event for the game.
			if (!ImGui::GetIO().WantCaptureKeyboard)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
					Debug::setState(!Debug::isActive());

				EM.player->pollMoveE(e, MM.getMap());
			}
		}

		if (e.type == sf::Event::MouseButtonPressed) {

			//If mouse is  in the debug menu - > cancel event for the game.
			if (!ImGui::GetIO().WantCaptureMouse)
			{
			sf::Vector2f mousePosGame = sf::Vector2f(Cam.getMousePos().x*(Cam.camera->getSize().x/Cam.window->getSize().y), Cam.getMousePos().x*(Cam.camera->getSize().y / Cam.window->getSize().y));
			EM.player->setTrajectory();

			if (console.mouseDebug)
				console.AddLog("Mouse -> X: '%.0f' Y: '%.0f' ", mousePosGame.x, mousePosGame.y);
			}
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
	ImGui::SFML::Update(*Cam.window, deltaClock.restart());
	AM.incCtr();
	AM.incAnimFrames();
	EM.updateEnts(MM.getMap());
	EM.cleanVector();
	moveScreen();
	Debug::draw();
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
