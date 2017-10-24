#include "Debug.h"
#include "EntityManager.h"
#include "Camera.h"
#include "MNEngine.h"
#include "Entity.h"

sf::Text Debug::cur, Debug::right, Debug::top, Debug::left, Debug::bot,
		 Debug::topRight, Debug::topLeft, Debug::botRight, Debug::botLeft,
		 Debug::x, Debug::y, Debug::xV, Debug::yV;

bool Debug::os_debug;

void Debug::init() {
	os_debug = true;
}

void Debug::printPPos(MNEngine* const ePtr) {
	printf("player pos : x->%d y->%d/n ", ePtr->EM.player->getPos().x, ePtr->EM.player->getPos().y);
}

bool Debug::isActive() {
	return os_debug;
}

void Debug::setState(bool state){
	os_debug = state;
}

void Debug::updateOSD(MNEngine* const ePtr, TileMap * map) {
	if (os_debug) {
		int cT = map->getTile(ePtr->EM.player->getPos().x, ePtr->EM.player->getPos().y).type,
			rT = map->getTile((ePtr->EM.player->getPos().x + ePtr->TILE_SIZE), ePtr->EM.player->getPos().y).type,
			tT = map->getTile(ePtr->EM.player->getPos().x, (ePtr->EM.player->getPos().y - ePtr->TILE_SIZE)).type,
			lT = map->getTile((ePtr->EM.player->getPos().x - ePtr->TILE_SIZE), ePtr->EM.player->getPos().y).type,
			bT = map->getTile(ePtr->EM.player->getPos().x , (ePtr->EM.player->getPos().y + ePtr->TILE_SIZE)).type,
			trT = map->getTile((ePtr->EM.player->getPos().x + ePtr->TILE_SIZE), ePtr->EM.player->getPos().y - ePtr->TILE_SIZE).type,
			brT = map->getTile(ePtr->EM.player->getPos().x + ePtr->TILE_SIZE, (ePtr->EM.player->getPos().y + ePtr->TILE_SIZE)).type,
			tlT = map->getTile((ePtr->EM.player->getPos().x - ePtr->TILE_SIZE), ePtr->EM.player->getPos().y - ePtr->TILE_SIZE).type,
			blT = map->getTile(ePtr->EM.player->getPos().x - ePtr->TILE_SIZE, (ePtr->EM.player->getPos().y + ePtr->TILE_SIZE)).type;

		//center tile
		cur.setFont(*ePtr->Cam.dFont); cur.setCharacterSize(20);
		cur.setPosition({ ePtr->Cam.camera->getCenter().x - 140.f, ePtr->Cam.camera->getCenter().y - 140.f });
		cur.setString(std::to_string(cT)); cur.setFillColor(sf::Color::Black);
		cur.setOutlineThickness(1); cur.setOutlineColor(sf::Color::White);

		//right tile
		right.setFont(*ePtr->Cam.dFont); right.setCharacterSize(20);
		right.setPosition({ ePtr->Cam.camera->getCenter().x - 120.f,ePtr->Cam.camera->getCenter().y - 140.f});
		right.setString(std::to_string(rT)); right.setFillColor(sf::Color::Black);
		right.setOutlineThickness(1); right.setOutlineColor(sf::Color::White);

		//top tile
		top.setFont(*ePtr->Cam.dFont); top.setCharacterSize(20);
		top.setPosition({ ePtr->Cam.camera->getCenter().x - 140, ePtr->Cam.camera->getCenter().y - 160.f});
		top.setString(std::to_string(tT)); top.setFillColor(sf::Color::Black);
		top.setOutlineThickness(1); top.setOutlineColor(sf::Color::White);

		//left tile
		left.setFont(*ePtr->Cam.dFont); left.setCharacterSize(20);
		left.setPosition({ ePtr->Cam.camera->getCenter().x - 160.f,ePtr->Cam.camera->getCenter().y - 140.f });
		left.setString(std::to_string(lT)); left.setFillColor(sf::Color::Black);
		left.setOutlineThickness(1); left.setOutlineColor(sf::Color::White);

		//bottom tile
		bot.setFont(*ePtr->Cam.dFont); bot.setCharacterSize(20);
		bot.setPosition({ ePtr->Cam.camera->getCenter().x - 140.f,ePtr->Cam.camera->getCenter().y - 120.f });
		bot.setString(std::to_string(bT)); bot.setFillColor(sf::Color::Black);
		bot.setOutlineThickness(1); bot.setOutlineColor(sf::Color::White);

		//top right tile
		topRight.setFont(*ePtr->Cam.dFont); topRight.setCharacterSize(20);
		topRight.setPosition({ ePtr->Cam.camera->getCenter().x - 120.f,ePtr->Cam.camera->getCenter().y - 160.f });
		topRight.setString(std::to_string(trT)); topRight.setFillColor(sf::Color::Black);
		topRight.setOutlineThickness(1); topRight.setOutlineColor(sf::Color::White);

		//top left tile
		topLeft.setFont(*ePtr->Cam.dFont); topLeft.setCharacterSize(20);
		topLeft.setPosition({ ePtr->Cam.camera->getCenter().x - 160.f, ePtr->Cam.camera->getCenter().y - 160.f });
		topLeft.setString(std::to_string(tlT)); topLeft.setFillColor(sf::Color::Black);
		topLeft.setOutlineThickness(1); topLeft.setOutlineColor(sf::Color::White);

		//bot left tile
		botLeft.setFont(*ePtr->Cam.dFont); botLeft.setCharacterSize(20);
		botLeft.setPosition({ ePtr->Cam.camera->getCenter().x - 160.f,ePtr->Cam.camera->getCenter().y - 120.f });
		botLeft.setString(std::to_string(blT)); botLeft.setFillColor(sf::Color::Black);
		botLeft.setOutlineThickness(1); botLeft.setOutlineColor(sf::Color::White);

		//bot right tile
		botRight.setFont(*ePtr->Cam.dFont); botRight.setCharacterSize(20);
		botRight.setPosition({ ePtr->Cam.camera->getCenter().x - 120.f,ePtr->Cam.camera->getCenter().y - 120.f });
		botRight.setString(std::to_string(brT)); botRight.setFillColor(sf::Color::Black);
		botRight.setOutlineThickness(1); botRight.setOutlineColor(sf::Color::White);


		x.setFont(*ePtr->Cam.dFont); x.setCharacterSize(20);
		x.setPosition({ ePtr->Cam.camera->getCenter().x - 160.f,ePtr->Cam.camera->getCenter().y - 200.f });
		x.setString("x:" + std::to_string(ePtr->EM.player->getPos().x)); x.setFillColor(sf::Color::Black);
		x.setOutlineThickness(1); x.setOutlineColor(sf::Color::White);

		y.setFont(*ePtr->Cam.dFont); y.setCharacterSize(20);
		y.setPosition({ ePtr->Cam.camera->getCenter().x - 60, ePtr->Cam.camera->getCenter().y - 200.f });
		y.setString("y:" + std::to_string(ePtr->EM.player->getPos().y)); y.setFillColor(sf::Color::Black);
		y.setOutlineThickness(1); y.setOutlineColor(sf::Color::White);

		xV.setFont(*ePtr->Cam.dFont); xV.setCharacterSize(20);
		xV.setPosition({ ePtr->Cam.camera->getCenter().x - 160.f,ePtr->Cam.camera->getCenter().y - 180.f });
		xV.setString("vX:" + std::to_string(ePtr->EM.player->getVX())); xV.setFillColor(sf::Color::Black);
		xV.setOutlineThickness(1); xV.setOutlineColor(sf::Color::White);

		yV.setFont(*ePtr->Cam.dFont); yV.setCharacterSize(20);
		yV.setPosition({ ePtr->Cam.camera->getCenter().x - 60.f, ePtr->Cam.camera->getCenter().y - 180.f});
		yV.setString("vY:" + std::to_string(ePtr->EM.player->getVY())); yV.setFillColor(sf::Color::Black);
		yV.setOutlineThickness(1); yV.setOutlineColor(sf::Color::White);

		ePtr->Cam.window->draw(cur);
		ePtr->Cam.window->draw(right);
		ePtr->Cam.window->draw(top);
		ePtr->Cam.window->draw(left);
		ePtr->Cam.window->draw(bot);
		ePtr->Cam.window->draw(botRight);
		ePtr->Cam.window->draw(botLeft);
		ePtr->Cam.window->draw(topRight);
		ePtr->Cam.window->draw(topLeft);
		ePtr->Cam.window->draw(x);
		ePtr->Cam.window->draw(y);
		ePtr->Cam.window->draw(xV);
		ePtr->Cam.window->draw(yV);
	}
}

void Debug::printEntVec(std::vector<boost::shared_ptr<Entity>> vec){
	if (os_debug) {
		int i = 0;
		std::cout << "-Entity Vector-" << std::endl;
		for (boost::shared_ptr<Entity> e : vec) {
			std::cout << i << ". EntAdr: " << e << " | EntType: " << e->getType() << std::endl;
			i++;
		}
		std::cout << "- end -" << std::endl;
	}
}

Debug::Debug()
{
}


Debug::~Debug()
{
}
