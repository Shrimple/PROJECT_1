#pragma once
#include "Item.h"

enum MiscType { FOOD, POTION, ARROW};

struct MiscItem : public Item
{
	MiscType misc_type;
	unsigned int amount;
};