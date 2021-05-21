#include "stdafx.h"
#include "LargemonGenerator.h"
#include "Battle.h"
#include "Trainer.h"

string LargemonGenerator::randomLargemonGenerator()
{
	{
		srand(time(NULL));
		string monsterName;


		vector <string> names =
		{
			"Charredlizard", "Bulbdino", "Squirturtle", "Pidgeon", "Peekingchu",
			"Sansrew", "Zoobot", "Menkey", "Abbool", "Fishboi",
			"Foxpupper", "El Ratto", "Volpian", "Manteena", "Kirby Ripoff",
			"Rockboi", "StoneySnake", "Dio Brando - Za Waurdo", "Fat Cunt", "Mewchu",
			"Spaghetti Monster", "S L U G G O", "A literal Husky with an antler strapped on", "CHARREDDRAGON", "SHEER HEART ATTACK",
			"Missingno."
		};

		monsterName = names[rand() % 26];
		return monsterName;
	}

}

LargemonGenerator::LargemonGenerator(string name)
	{
		setName(name);
	}


	LargemonGenerator::~LargemonGenerator()
	{
	}

	void LargemonGenerator::setName(string name)
	{
		_name = name;
	}

	int LargemonGenerator::GetCombatPower()
	{
		return _combatPower;
	}
}
