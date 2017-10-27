#include "PlayerInventory.h"

PlayerInventory::~PlayerInventory(){}

//getRightWeapon[0] = Left
//getRightWeapon[1] = Right


std::vector<Armor*> PlayerInventory::getArmorContents()
{
	std::vector <Armor*> result;
	for (auto const& value : getEquippedItems()) {
		if (value->item_type == ARMOR && dynamic_cast<Armor*>(value)->armor_type != SHIELD)
			result.push_back(dynamic_cast<Armor*>(value));
	}

	return result;
}

std::vector<Item*> PlayerInventory::getHandsContents()
{
	std::vector <Item*> result;
	for (auto const& value : getEquippedItems()) {
		if (value->item_type == WEAPON)
			result.push_back(value);
		if (value->item_type == ARMOR && dynamic_cast<Armor*>(value)->armor_type == SHIELD)
			result.push_back(value);
	}

	return result;
}

Armor* PlayerInventory::getBoots()
{
	for (auto const& value : getArmorContents()) {
		if (value->item_type == BOOTS)
			return value;
	}
}

Armor* PlayerInventory::getLeggings()
{
	for (auto const& value : getArmorContents()) {
		if (value->item_type == LEGGINGS)
			return value;
	}
}

Armor* PlayerInventory::getChestplate()
{
	for (auto const& value : getArmorContents()) {
		if (value->item_type == CHESTPLATE)
			return value;
	}
}

Armor* PlayerInventory::getHelmet()
{
	for (auto const& value : getArmorContents()) {
		if (value->item_type == HELMET)
			return value;
	}
}

Weapon* PlayerInventory::getLeftWeapon()
{
	return dynamic_cast<Weapon*>(getHandsContents()[0]);
}

Armor* PlayerInventory::getRightWeapon()
{
	return dynamic_cast<Armor*>(getHandsContents()[1]);
}

bool PlayerInventory::setBoots(Armor* item)
{
	if (getBoots() != 0)
		addItem(getBoots());

	equipped.push_back(item);


	//If item still in Inventory, removed it.
	//Since he can grap it when it's on the ground and place inside the armor container
	//and if it is inside, we do not need it anymore there.
	if (contains(item))
		remove(item);
}

bool PlayerInventory::setChestplate(Armor* item)
{
	if (getChestplate() != 0)
		addItem(getChestplate());

	equipped.push_back(item);

	if (contains(item))
		remove(item);
}

bool PlayerInventory::setLeggings(Armor* item)
{
	if (getLeggings() != 0)
		addItem(getLeggings());

	equipped.push_back(item);

	if (contains(item))
		remove(item);
}

bool PlayerInventory::setHelmet(Armor* item)
{
	if (getHelmet() != 0)
		addItem(getHelmet());

	equipped.push_back(item);

	if (contains(item))
		remove(item);
}

bool PlayerInventory::setLeftWeapon(Weapon* item)
{
	if (getLeftWeapon() != 0)
		addItem(getLeftWeapon());

	equipped.push_back(item);

	if (contains(item))
		remove(item);

	getHandsContents()[0] = item;
}

bool PlayerInventory::setRightWeapon(Armor* item)
{
	if (getRightWeapon() != 0)
		addItem(getRightWeapon());

	equipped.push_back(item);

	if (contains(item))
		remove(item);

	getHandsContents()[1] = item;
}




