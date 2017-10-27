#pragma once
#include "Item.h"


enum WeaponType { DAGGER, SHORT_SWORD, LONG_SWORD, SHIELD, WAND, STAFF, BOW, CROSSBOW };

struct Weapon : public Item
{
	unsigned int damage_max;
	unsigned int damage_min;
	WeaponType weapon_type;
};