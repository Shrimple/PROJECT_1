#include "Debug.h"
#include "EntityManager.h"
#include "Camera.h"
#include "MNEngine.h"
#include "Entity.h"

bool Debug::os_debug;
char Debug::tiles_1[32];
char Debug::tiles_2[32];
char Debug::tiles_3[32];
char Debug::player_1[32];
char Debug::player_2[32];

void Debug::init() {
	os_debug = false;
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


void Debug::draw()
{
	if (isActive())
	{
	ImGui::SetNextWindowSize(ImVec2(160, 350));
	char buf[128];
	sprintf_s(buf, "Debug %c %d###AnimatedTitle", "|/-\\"[(int)(ImGui::GetTime() / 0.25f) & 3], rand());
	ImGui::Begin(buf);

	if (ImGui::Button("Console"))
		MNEngine::console.isEnable = !MNEngine::console.isEnable;

	if (MNEngine::console.isEnable)
		MNEngine::console.Draw("Console");
	
	ImGui::Separator();


	//Nic Stuff

	ImGui::Text("Nic Stuff");
	ImGui::NewLine();

	ImGui::Text(tiles_1);
	ImGui::Text(tiles_2);
	ImGui::Text(tiles_3);
	ImGui::Text(player_1);
	ImGui::Text(player_2);

	ImGui::Separator();

	ImGui::Text("Sim Stuff");
	ImGui::NewLine();
	ImGui::Text("Rip =(");

	ImGui::End();
	}
}

void Debug::updateOSD(MNEngine* const ePtr, TileMap * map) {
	if (os_debug) {
		int cT = map->getTile(ePtr->EM.player->getPos().x, ePtr->EM.player->getPos().y).type,
			rT = map->getTile((ePtr->EM.player->getPos().x + ePtr->TILE_SIZE), ePtr->EM.player->getPos().y).type,
			tT = map->getTile(ePtr->EM.player->getPos().x, (ePtr->EM.player->getPos().y - ePtr->TILE_SIZE)).type,
			lT = map->getTile((ePtr->EM.player->getPos().x - ePtr->TILE_SIZE), ePtr->EM.player->getPos().y).type,
			bT = map->getTile(ePtr->EM.player->getPos().x, (ePtr->EM.player->getPos().y + ePtr->TILE_SIZE)).type,
			trT = map->getTile((ePtr->EM.player->getPos().x + ePtr->TILE_SIZE), ePtr->EM.player->getPos().y - ePtr->TILE_SIZE).type,
			brT = map->getTile(ePtr->EM.player->getPos().x + ePtr->TILE_SIZE, (ePtr->EM.player->getPos().y + ePtr->TILE_SIZE)).type,
			tlT = map->getTile((ePtr->EM.player->getPos().x - ePtr->TILE_SIZE), ePtr->EM.player->getPos().y - ePtr->TILE_SIZE).type,
			blT = map->getTile(ePtr->EM.player->getPos().x - ePtr->TILE_SIZE, (ePtr->EM.player->getPos().y + ePtr->TILE_SIZE)).type;

		sprintf_s(tiles_1, "%d %d %d", tlT , tT  , trT);
		sprintf_s(tiles_2, "%d %d %d", lT  , cT  , rT);
		sprintf_s(tiles_3, "%d %d %d", blT , bT  , brT);
		sprintf_s(player_1, "X: %.0f Y: %.0f", ePtr->EM.player->getPos().x, ePtr->EM.player->getPos().y);
		sprintf_s(player_2, "vX: %.2f vY: %.2f", ePtr->EM.player->getVX(), ePtr->EM.player->getVY());
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
