#pragma once
#include "Monster.h"
#include <string>
#include <vector>
using namespace std;
using std::string;

class WildLargemon :
	public Monster
{
private:
	int _combatPower;
public:
	Attacks Attack1 = Attacks("ORAORAORA", 9001);
	Attacks Attack2 = Attacks("MUDAMUDAMUDA", 6);

	WildLargemon(string name);
	~WildLargemon();

	void setName(string name);
	int GetCombatPower();

	vector <string> SetName();
	vector <string> SetType();
	vector <string> SetAttack1();
	vector <string> SetAttack2();
};

