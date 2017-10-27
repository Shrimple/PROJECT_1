#pragma once
#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"

class  PlayerInventory :  public Inventory
{
private:
	std::vector <Item *> equipped;
	
	//Effets (equiped items)
	std::vector <int> scripts;

public:
	PlayerInventory() : Inventory(36, PLAYER_INVENTORY) {};
	PlayerInventory(int size) : Inventory(size, PLAYER_INVENTORY) {};

	~PlayerInventory();

	//Functions:
	std::vector <Item *> getEquippedItems() { return equipped; };
	std::vector <int> getScripts() { return scripts; };
	
	//get Armors
	std::vector <Armor*> getArmorContents();
	Armor* getBoots(); 
	Armor* getLeggings();
	Armor* getChestplate();
	Armor* getHelmet();

	//get Weapon
	std::vector <Item*> getHandsContents();
	Weapon* getLeftWeapon();
	Armor* getRightWeapon();

	//set armors
	bool setBoots(Armor* item);
	bool setLeggings(Armor* item);
	bool setChestplate(Armor* item);
	bool setHelmet(Armor* item);

	//set Weapon
	bool setLeftWeapon(Weapon* item);
	bool setRightWeapon(Armor* item);


};