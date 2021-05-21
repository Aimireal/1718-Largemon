#pragma once
#include "Monster.h"
#include "Items.h"

class Trainer
{
private:
	string _name;
public:
	Trainer(string _name);
	~Trainer();

	Items Inventory[2] = { Items("Potion", 3), Items("Largeball", 5) };

	Monster Largemon = Monster();

	string GetName();

};

