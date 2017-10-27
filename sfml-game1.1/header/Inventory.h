#pragma once

#include "Item.h"
#include "MiscItem.h"
#include <string>
#include <vector>


enum InventoryType { PLAYER_INVENTORY, CHEST_INVENTORY, SHOP_INVENTORY };



class Inventory
{
private:

	/*
		hmmm...
		should I set the inventory as a pointer. 
	*/

	//Slots
	std::vector <Item *> inventory;
	InventoryType invType;
	unsigned int invSize;

public:
	Inventory(int slots, InventoryType type);
	virtual ~Inventory();
	//Exemple = scripts.push_back<INCREASED_PLAYER_HEALTH>

	//clear all
	void clear();
	//clear specific slot
	void clear(int i);
	//remove specific item
	void remove(Item* item);

	bool addItem(Item* item);

	//if has specific Item:
	bool contains(Item* item);
	//if has X of a specific Item; (exemple 400 Gold)
	bool containsAtLeast(Item* item, int amount);

	//Return every slots of the inventory
	std::vector<Item*> getContents() { return inventory; };

	//return InvType
	InventoryType getType() { return invType; };

	//bool removeAmount(Item* item, int amount);

	//draw inventory to player;
	void draw();

private:
	auto findItem(Item* item);
};