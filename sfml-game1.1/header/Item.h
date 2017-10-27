#pragma once
#include <string>

enum ItemType {ARMOR, WEAPON, MISC};

struct Item
{
	Item();
	virtual ~Item();
	ItemType item_type;
	unsigned int itemID;
	int cost;
	int value;
	std::string itemName;
};