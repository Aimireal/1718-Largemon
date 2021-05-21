#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Trainer.h"
using namespace std;



class Battle {
public:
	string randomMonster;
	//string randomNameGenerator();
	//bool captureAttempt(int);
	WildLargemon generateOpponent();
	void WildBattle(Trainer * playerPTR, WildLargemon * opponentPTR);
};