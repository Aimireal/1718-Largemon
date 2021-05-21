#pragma once

#include "stdafx.h"
#include "Battle.h"
#include "Trainer.h"
#include "WildLargemon.h"


bool CheckWinCondition(Trainer * playerPTR, Trainer * opponentPTR);
void WildBattle(Trainer * PlayerPTR, Trainer * opponentPTR);

string name;
string type;
string attack1;
string attack2;

WildLargemon opponentPTR;
Battle BattleTest;

WildLargemon Battle::generateOpponent()//Create method for this
{
	opponentPTR.SetName();
	opponentPTR.SetType();
	opponentPTR.SetAttack1();
	opponentPTR.SetAttack2();
}

void WildEncounter(Trainer * playerPTR, WildLargemon * generateOpponent)
{
	string playerMonster;
	char input;
	bool didCatch;
	int pokeballs = 5;

	WildLargemon opponentPTR = BattleTest.generateOpponent();
	//WildLargemon opponentPTR = WildLargemon(randomNameGenerator());
	didCatch = captureAttempt(opponentPTR.GetCombatPower());


	cout << "!" << endl;
	cout << "A wild " << opponentPTR.GetName() << " appeared!" << endl;
	cout << "Battle it? <Y/N>" << endl;
	cin >> input;
	input = tolower(input);

	if (input == 'y')
	{
		//Battle Code from main replaced with taking the object of the created Largemon instance, which is generated upon starting the game
		//and random instances are generated at the start of the battle if one is not already made
		BattleTest.WildBattle(playerPTR, &opponentPTR);
	}
}

void Battle::WildBattle(Trainer * playerPTR, WildLargemon * opponentPTR)
{
	int playerchoice;
	//auto playerPTR = make_shared<Trainer>(Player); //AI test
	//auto opponentPTR = make_shared<Trainer>(Opponent); //AI test
	bool check = false;

	/////////////////////////
	//Testing Enemy Largemon
	string opponentPTR = "Tester";
	int opponentHealth = 10;
	int opponentMaxHealth = 10;
	int opponentDamage = 4;
	//Testing Enemy Largemon
	/////////////////////////

	srand(time(NULL));
	cin.ignore();
	getchar();

	cout << "Go! " << playerPTR->Largemon.GetName() << "!\n\n";

	system("pause");
	system("cls");

	//Check that the Largemon are alive
	while (playerPTR->Largemon.Health > 0 && playerPTR->Largemon.Health > 0)
	{
		cout << opponentPTR << endl
			<< "Health: " << opponentHealth
			<< "/" << opponentMaxHealth << "\n\n";

		cout << playerPTR->Largemon.GetName() << endl
			<< "Health: " << playerPTR->Largemon.Health
			<< "/" << playerPTR->Largemon.GetMaxHealth() << "\n\n";

		//Start Player's Turn
		cout << "(1) Attack / (2) Items" << endl
			<< "Your Choice: ";
		cin >> playerchoice;

		system("cls");

		//Switch for the combat choices
		switch (playerchoice)
		{
			//Case 1 - Attack a Largemon
		case 1:
			cout << playerPTR->Largemon.GetName() << "'s attacks:" << endl
				<< "(1)" << playerPTR->Largemon.Attack1.GetAttackName() << endl
				<< "(2)" << playerPTR->Largemon.Attack2.GetAttackName() << endl
				<< "Your Choice: \n";
			cin >> playerchoice;

			if (playerchoice == 1)
			{
				cout << playerPTR->Largemon.GetName() << " used " << playerPTR->Largemon.Attack1.GetAttackName() << "!";
				opponentHealth -= playerPTR->Largemon.Attack1.calculateAttackDamage();
				if (playerPTR->Largemon.Attack1.GetAttackName() == "MudaMudaMuda")
				{
					playerPTR->Largemon.Attack1.RestoreFurySwipes();
				}
			}
			else
			{
				cout << playerPTR->Largemon.GetName() << " used " << playerPTR->Largemon.Attack2.GetAttackName() << "!";
				opponentHealth -= playerPTR->Largemon.Attack2.calculateAttackDamage();
			}

			break;

			//Case 2 - Use an item (Heals or Largeballs)
		case 2:
			int itemNumber = 1;
			for (int i = 0; i < sizeof(playerPTR->Inventory) / sizeof(*playerPTR->Inventory); i++)
			{
				if (playerPTR->Inventory[i].GetItemCount() >= 0)
				{
					cout << "(" << itemNumber << ") " << playerPTR->Inventory[i].GetItemName()
						<< " x" << playerPTR->Inventory[i].GetItemCount() << endl;
					itemNumber++;
				}
			}
			cin >> playerchoice;
			switch (playerchoice)
			{
			case 2:
				cout << "Largeball! Go!" << endl;
				cout << "Jeff: " << playerPTR->GetName() << "! You can't steal another trainer's Largemon!" << endl;
				playerPTR->Inventory[1].UseItem();
				break;
			case 1:
				if (playerPTR->Inventory[0].GetItemCount() > 0 && playerPTR->Largemon.Health + 5 <= playerPTR->Largemon.GetMaxHealth())
				{
					playerPTR->Inventory[0].UseItem();
					playerPTR->Largemon.Health += 5;
					cout << playerPTR->GetName() << " used a " << playerPTR->Inventory[0].GetItemName() << endl;
					break;
				}
				else if (playerPTR->Inventory[0].GetItemCount() > 0 && playerPTR->Largemon.Health + 5 >= playerPTR->Largemon.GetMaxHealth())
				{
					playerPTR->Inventory[0].UseItem();
					playerPTR->Largemon.Health = playerPTR->Largemon.GetMaxHealth();
					cout << playerPTR->GetName() << " used a " << playerPTR->Inventory[0].GetItemName() << endl;
					break;
				}
				else
				{
					cout << "You do not have any " << playerPTR->Inventory[0].GetItemName() << "s left!" << endl;
					break;
				}


			}
			break;
		}
	}
}




bool captureAttempt(int combatPower)
{
	int captureChance;

	if (combatPower < 10)
	{
		captureChance = rand() % 2;
	}
	else if (combatPower >= 10 && combatPower <= 20)
	{
		captureChance = rand() % 4;
	}
	else if (combatPower > 20)
	{
		captureChance = rand() % 8;
	}

	if (captureChance == 0)
	{
		return true;
	}

	return false;
}

string randomNameGenerator() //A fake largemon generator, in emergency just give this to the old battle class
{
	srand(time(NULL));
	string opponentPTRName;


	vector <string> names =
	{
		"Charmander", "Bulbasaur", "Squirtle", "Pidgey", "Pikachu",
		"Sandshrew", "Zubat", "Mankey", "Abra", "Magikarp",
		"Eevee", "Rattata", "Vulpix", "Scyther", "Jigglypuff",
		"Geodude", "Onix", "Staryu", "Snorlax", "Mewtwo",
		"Oddish", "Caterpie", "Spearow", "Charizard", "Zapdos",
		"Missingno."
	};

	opponentPTRName = names[rand() % 26];

	return opponentPTRName;
}


//Logic from old WildEncounter
//
//playerMonster = Player.Largemon.GetName();
//cout << endl << "Go! " << playerMonster << "!\n\n";
//cout << "Opponent:\n" << opponentPTR.GetName() << endl;
//cout << "Player:\n" << playerMonster << "\n\n";
//cout << playerMonster << " attacked " << opponentPTR.GetName() << "! It is critically weakened!\n\n";
//cout << "You have " << pokeballs << " Largeballs. Do you want to attempt to capture " << opponentPTR.GetName() << "? <Y/N>" << endl;
//cin >> input;
//input = tolower(input);
//
//while (pokeballs > 0 && input == 'y')
//{
//	system("cls");
//	if (input == 'y')
//	{
//		pokeballs--;
//		cout << endl << "Threw a pokeball at " << opponentPTR.GetName() << "! It shook once... twice..." << endl;
//		if (didCatch)
//		{
//			cout << "\nYES! " << opponentPTR.GetName() << " was caught!" << endl;
//			cout << "Added " << opponentPTR.GetName() << " to the Pokedex!" << endl;
//			cout << opponentPTR.GetName() << " was sent to Bill's PC!\n\n";
//
//			return;
//		}
//		else
//		{
//			cout << "Darn! " << opponentPTR.GetName() << " broke free! It was so close!" << endl;
//			cout << "You have " << pokeballs << " Largeballs left." << endl;
//			if (pokeballs > 0)
//			{
//				cout << endl << "Throw another Largeball? <Y/N>" << endl;
//				cin >> input;
//				input = tolower(input);
//				didCatch = captureAttempt(opponentPTR.GetCombatPower());
//			}
//		}
//	}
//	else
//	{
//		cout << endl << "Got away safely...\n\n";
//		return;
//	}
//}
//cout << endl << "You ran out of Largeballs! Got away safely..." << endl;




////LargemonGeneration
//string randomLargemonGenerator()
//{
//	srand(time(NULL));
//	string opponentPTRName;
//	string attack1;
//	string attack2;
//
//	//Largemon Names
//	vector <string> names =
//	{
//		"Charredlizard", "Bulbdino", "Squirturtle", "Pidgeon", "Peekingchu",
//		"Sansrew", "Zoobot", "Menkey", "Manchop", "Magicfish",
//		"Ardoggo", "Ratartar", "Volpian", "Manteena", "Wigglypoof",
//		"Stareyu", "Grabbler", "Dio Brando - Za Waurdo", "Rapidosh", "Mewchu",
//		"Spaghetti Monster", "Zappdoes", "A literal Husky with an antler strapped on", "CHARREDDRAGON", "SHEER HEART ATTACK",
//		"Missingno."
//	};
//
//	//Largemon Base
//	vector <string> baseattack =
//	{
//		"Bite", "Crush", "Scrach", "Tackle", "Headbutt", "Lick", "Kick", "Tear", "Punch", "Ram"
//	};
//
//	//Largemon Specials
//	vector <string> specialattack =
//	{
//		"Flame", "Watergun", "Electrocute", "Slam", "Flail", "Energy Burst", "Rapid Punch", "Break", "Yeet", "Smash"
//	};
//
//	opponentPTRName = names[rand() % 26];
//	attack1 = baseattack[rand() % 10];
//	attack2 = specialattack[rand() % 10];
//
//}