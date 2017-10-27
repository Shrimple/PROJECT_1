#pragma once
#include "Item.h"


enum ArmorType { HELMET, CHESTPLATE, LEGGINGS, BOOTS, SHIELD};

struct Armor : public Item
{
	unsigned int defense_raw;
	unsigned int defense_fire;
	unsigned int defense_ice;
	unsigned int defense_poison;
	ArmorType armor_type;
};