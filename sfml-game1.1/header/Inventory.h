#pragma once

#include "Item.h"
#include <string>
#include <vector>



class Inventory
{
public:
	Inventory();

	//Slots
	std::vector <Item *> items;

	//Effets (equiped items)
	std::vector <int> scripts;
	
	unsigned int invSize;

	bool addItem(Item* item);
	bool removeItem(Item* item);


};