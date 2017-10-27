#pragma once
#include <string>

enum WeaponClass { DAGGER, SHORT_SWORD, LONG_SWORD, SHIELD, WAND, STAFF, BOW, CROSSBOW };


struct Item
{
	Item();
	virtual ~Item();
	unsigned int itemType;
	unsigned int minDamage;
	unsigned int maxDamage;
	WeaponClass itemClass;
	unsigned int itemID;
	int cost;
	int value;
	std::string itemName;
};