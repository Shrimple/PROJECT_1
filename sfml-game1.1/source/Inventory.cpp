#include "Inventory.h"


Inventory::Inventory(int size, InventoryType type)
	: invSize(size), invType(type){}

Inventory::~Inventory() {}


auto Inventory::findItem(Item* item)
{
	auto it = std::find(inventory.begin(), inventory.end(), item);
	if (it != inventory.end())
		return it;

}

bool Inventory::contains(Item* item)
{
	return (std::find(inventory.begin(), inventory.end(), item) != inventory.end());
}

void Inventory::clear()
{
	inventory.clear();
}

void Inventory::clear(int i)
{
	inventory.erase(inventory.begin + i);
}

void Inventory::remove(Item* item)
{
	if(contains(item))
		inventory.erase(findItem(item));
}

bool Inventory::containsAtLeast(Item* item, int amount)
{
	if(item->item_type == MISC)
		return (contains(item) && dynamic_cast<MiscItem*>(item)->amount >= amount);
}

bool Inventory::addItem(Item* item)
{
	/*
		Impossible to have 2 addresses. Since we stock the Item via pointer.
		I don't think we have to
			~~ if(!contains(item)) ~~
		to avoid duplicating or other problem.
	*/

	if (inventory.size >= invSize)
		return false;
	else
		inventory.push_back(item);
}

/*
bool Inventory::removeAmount(Item* item, int amount)
{
	bool success = false;

	if (containsAtLeast(item, amount))
	{
		item->amount = (item->amount - amount);
		success = true;
	}

	return success;
}
*/

void Inventory::draw()
{
	/*
	TODO:
		- Gui Drwaning
		otherwise can use ImGui as temporary UI
	*/
}
