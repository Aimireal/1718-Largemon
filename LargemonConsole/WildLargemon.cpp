#include "stdafx.h"
#include "WildLargemon.h"
#include <vector>



WildLargemon::WildLargemon(string name)
{
	setName(name);
}


WildLargemon::~WildLargemon()
{
}

void WildLargemon::setName(string name)
{
	_name = name;
}

int WildLargemon::GetCombatPower()
{
	return _combatPower;
}


vector <string> WildLargemon::SetName() 
{
	string names[] =
			{
				"Charredlizard", "Bulbdino", "Squirturtle", "Pidgeon", "Peekingchu",
				"Sansrew", "Zoobot", "Menkey", "Manchop", "Magicfish",
				"Ardoggo", "Ratartar", "Volpian", "Manteena", "Wigglypoof",
				"Stareyu", "Grabbler", "Dio Brando - Za Waurdo", "Rapidosh", "Mewchu",
				"Spaghetti Monster", "Zappdoes", "A literal Husky with an antler strapped on", "CHARREDDRAGON", "SHEER HEART ATTACK",
				"Missingno."
			};

	vector <string> opponentName;
	for (int i = 0; i < 26; i++)
	{
		opponentName.push_back(names[rand() % 26]);
	}
	return opponentName;
}

vector <string> WildLargemon::SetType()
{
	vector <string> types =
	{
		"Fire", "Water", "Air", "Pidgeon", "Peekingchu",
	};

	vector <string> opponentType;
	for (int i = 0; i < 26; i++)
	{
		opponentType.push_back(types[rand() % 26]);
	}
	return opponentType;
}

vector <string> WildLargemon::SetAttack1()
{
	vector <string> attack1 =
	{
	"Bite", "Crush", "Scrach", "Tackle", "Headbutt", "Lick", "Kick", "Tear", "Punch", "Ram"
	};

	vector <string> opponentAttack1;
	for (int i = 0; i < 26; i++)
	{
		opponentAttack1.push_back(attack1[rand() % 26]);
	}
	return opponentAttack1;
}

vector <string> WildLargemon::SetAttack2()
{
	vector <string> attack2 =
		{
		"Flame", "Watergun", "Electrocute", "Slam", "Flail", "Energy Burst", "Rapid Punch", "Break", "Yeet", "Smash"
		};
	
	vector <string> opponentAttack2;
	for (int i = 0; i < 26; i++)
	{
		opponentAttack2.push_back(attack2[rand() % 26]);
	}
	return opponentAttack2;
}
