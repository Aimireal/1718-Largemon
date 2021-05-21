#include "stdafx.h"
#include <iostream>
#include <memory>
#include "Trainer.h"
#include "mapmain.h"
#include "Battle.h"
#include "WildLargemon.h"
#include "Location.h"
#include "Monster.h"

string nameValidate();

void NewGame();
void Battle(Trainer * Player, Trainer * Opponent);
bool BattleRecursionPrompt(Trainer * playerPTR, Trainer * opponentPTR);
bool CheckWinCondition(Trainer * playerPTR, Trainer * opponentPTR);

//Choose the switch to run for New/Load/Exit game
int main() 
{
	cout << "Largemon: Obtain all of them" << "Please choose an option:\n\n" << "N- New Game\n" << "L- Load Game\n" << "E- Exit\n";

	char playerChoice = 'z';
	cin >> playerChoice;
	playerChoice = toupper(playerChoice);

	switch (playerChoice)
	{
	case 'N': system("cls"); NewGame(); break;
	case 'E': return 0;
	}

	system("pause");
	return 0;
}

string nameValidate()
{
	string setname;
	getline(cin, setname);
	while (setname.empty())
	{
		cout << "Jeff: I CANNAE HER YA, WHAT'S YER NAME?" << endl;
		getline(cin, setname);
	}
	return setname;
}

//Newgame - This contains everything we need to run on a first game to ennsure the player has a Largemon starter and get's a name and rival.
void NewGame()
{
	int playerchoice = 0;
	string NameSet = "DEFAULT";

	cout << "Jeff: Hello, welcome to the world of Largemon!" << endl
		<< "My name Jeff! People call me a Largemon Professor!\n Truth is no such thing exists \n" << endl
		<< "What about you? What is your name?\n\n"
		<< "Name: ";

	cin.ignore();
	NameSet = nameValidate();

	//This sets the player name
	Trainer * Player = new Trainer(NameSet);

	cout << "\nJeff: " << Player->GetName() << ", huh? That's not what I'd call you, but maybe what I would isn't safe for this!\n\n";
	system("pause");
	system("cls");
	cout << "Jeff: DIdn't you come with my Grandson? What was his name again? I forget...\n\n"
		<< "Name: ";

	NameSet = nameValidate();
	Trainer * Opponent = new Trainer(NameSet);

	//This sets the rival name
	cout << "Jeff: Oh, that's right! His name is " << Opponent->GetName() << "!\n\n" << "I wish his mother aborted him \n";

	system("pause");
	system("cls");

	//This let's the player pick their starter Largemon
	cout << "Jeff: " << Player->GetName() << "! I have a number of Largemon here!" << endl
		<< "You can choose one for a starter!\n\n";
	getchar();
	cout << Opponent->GetName() << ": Hey, what about me?" << endl;
	getchar();
	cout << "\nJeff: " << Opponent->GetName() << "! I forgot you were here! Pick the type that beats " << Player->GetName() << " so it's more interesting\n\n";

	system("pause");
	system("cls");

	enum largemon { Bulbdino, Charredlizard, Squirturtle, Peekingchu, Eevee, Pidgeon, Dio_Brando };
	cout << Player->GetName() << ", choose a Largemon:" << endl
		<< "(1) Bulbdino - Grass Type" << endl
		<< "(2) Charredlizard - Fire Type" << endl
		<< "(3) Squirturtle - Water Type" << endl
		<< "(4) Peekingchu - Electric Type" << endl
		<< "(5) Dio Brando - Normal Type" << endl;

	cin >> playerchoice;
	while (playerchoice < 1 || playerchoice > 5)
	{
		cout << "\nJeff: You can't choose a Largemon that I don't have!\n";
		cin >> playerchoice;
	}

	//Switch for the Largmon choices
	switch (playerchoice)
	{
	case 1:
		Player->Largemon.SetIDNum(Bulbdino);
		Opponent->Largemon.SetIDNum(Charredlizard);
		break;
	case 2:
		Player->Largemon.SetIDNum(Charredlizard);
		Opponent->Largemon.SetIDNum(Squirturtle);
		break;
	case 3:
		Player->Largemon.SetIDNum(Squirturtle);
		Opponent->Largemon.SetIDNum(Bulbdino);
		break;
	case 4:
		Player->Largemon.SetIDNum(Peekingchu);
		Opponent->Largemon.SetIDNum(Eevee);
		break;
	case 5:
		Player->Largemon.SetIDNum(Dio_Brando);
		Opponent->Largemon.SetIDNum(Pidgeon);
		break;
	}

	Player->Largemon.SetInfo();
	Opponent->Largemon.SetInfo();


	cout << "\n\n" << Player->GetName() << " chose " << Player->Largemon.GetName() << "!" << endl;
	cout << "\n\n" << Opponent->GetName() << ": Then I'll choose this one!\n\n";
	cout << Opponent->GetName() << " chose " << Opponent->Largemon.GetName() << "!\n\n";

	system("pause");
	system("cls");

	cout << Opponent->GetName() << ": Hey, " << Player->GetName() << "! Let's have a Largemon battle!" << endl;

	getchar();

	Battle(Player, Opponent);

	system("cls");
	cout << "Jeff: Well done, you two. Now go catch some new Largemon those are just rentals :^)" << endl;
	system("pause");
	system("cls");
	MapMovement(*Player);


}

//This is the code that runs each time there is a battle
void Battle(Trainer * playerPTR, Trainer * opponentPTR) //void Battle(Trainer * playerPTR, Trainer * opponentPTR)
{
	int playerchoice;
	//auto playerPTR = make_shared<Trainer>(Player); //AI test
	//auto opponentPTR = make_shared<Trainer>(Opponent); //AI test
	bool check = false;

	srand(time(NULL));
	cin.ignore();  

	//Set up the battle
	cout << "Trainer " << opponentPTR->GetName() << " challenges Trainer " << playerPTR->GetName() << " to a battle!\n\n";
	getchar();
	cout << "Trainer " << opponentPTR->GetName() << " sends out " << opponentPTR->Largemon.GetName() << "!" << endl;

	getchar();

	cout << "Go! " << playerPTR->Largemon.GetName() << "!\n\n";

	system("pause");
	system("cls");

	//Check that the Largemon are alive
	while (playerPTR->Largemon.Health > 0 && playerPTR->Largemon.Health > 0)
	{
		cout << opponentPTR->Largemon.GetName() << endl
			<< "Health: " << opponentPTR->Largemon.Health
			<< "/" << opponentPTR->Largemon.GetMaxHealth() << "\n\n";

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
				opponentPTR->Largemon.Health -= playerPTR->Largemon.Attack1.calculateAttackDamage();
				if (playerPTR->Largemon.Attack1.GetAttackName() == "MudaMudaMuda")
				{
					playerPTR->Largemon.Attack1.RestoreFurySwipes();
				}
			}
			else
			{
				cout << playerPTR->Largemon.GetName() << " used " << playerPTR->Largemon.Attack2.GetAttackName() << "!";
				opponentPTR->Largemon.Health -= playerPTR->Largemon.Attack2.calculateAttackDamage();
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
		//Check for player win condition
		check = CheckWinCondition(playerPTR, opponentPTR);
		if (check == true)
		{
			return;
		}

		//Opponent's Turn, basic "AI" for battle
		playerchoice = rand() % 5;
		switch (playerchoice)
		{
		case 0:
			if (opponentPTR->Inventory[0].GetItemCount() > 0 && opponentPTR->Largemon.Health + 5 <= opponentPTR->Largemon.GetMaxHealth())
			{
				opponentPTR->Largemon.Health += 5;
				opponentPTR->Inventory[0].UseItem();
				cout << opponentPTR->GetName() << " used a " << opponentPTR->Inventory[0].GetItemName() << endl;
				break;
			}
			else if (opponentPTR->Inventory[0].GetItemCount() > 0 && opponentPTR->Largemon.Health + 5 >= opponentPTR->Largemon.GetMaxHealth())
			{
				opponentPTR->Largemon.Health = opponentPTR->Largemon.GetMaxHealth();
				opponentPTR->Inventory[0].UseItem();
				cout << opponentPTR->GetName() << " used a " << opponentPTR->Inventory[0].GetItemName() << endl;
				break;
			}
			else if (opponentPTR->Inventory[0].GetItemCount() <= 0)
			{
				playerchoice = 1;
			}
		default:
			playerchoice = rand() % 2 + 1;

			if (playerchoice == 1)
			{
				cout << opponentPTR->Largemon.GetName() << " used " << opponentPTR->Largemon.Attack1.GetAttackName() << "!";
				playerPTR->Largemon.Health -= opponentPTR->Largemon.Attack1.calculateAttackDamage();
			}
			else
			{
				cout << opponentPTR->Largemon.GetName() << " used " << opponentPTR->Largemon.Attack2.GetAttackName() << "!";
				playerPTR->Largemon.Health -= opponentPTR->Largemon.Attack2.calculateAttackDamage();
			}

			break;
		}

		//Check for Opponent Win Condition
		check = CheckWinCondition(playerPTR, opponentPTR);
		if (check == true)
		{
			return;
		}
	}
}

//Rematching battles
bool BattleRecursionPrompt(Trainer * playerPTR, Trainer * opponentPTR)
{
	system("cls");

	char playerchoice = 'z';

	cout << "Battle Trainer " << opponentPTR->GetName() << " again? <Y/N>";

	cin.ignore();
	cin >> playerchoice;
	playerchoice = toupper(playerchoice);

	while (playerchoice != 'Y' && playerchoice != 'N')
	{
		cout << "Choice must be 'Y' or 'N'" << endl;
		cin.ignore();
		cin >> playerchoice;
		playerchoice = toupper(playerchoice);
	}
	if (playerchoice == 'Y')
	{
		playerPTR->Largemon.Health = playerPTR->Largemon.GetMaxHealth();
		opponentPTR->Largemon.Health = opponentPTR->Largemon.GetMaxHealth();
		return true;
	}
	return false;
}

//Code to check if the wincondition has been met
bool CheckWinCondition(Trainer * playerPTR, Trainer * opponentPTR)
{
	system("pause");
	system("cls");

	if (opponentPTR->Largemon.Health <= 0)
	{
		cout << opponentPTR->Largemon.GetName() << " has fainted." << endl
			<< "Trainer " << playerPTR->GetName() << " defeated Trainer " << opponentPTR->GetName() << "!\n\n";

		cout << opponentPTR->GetName() << ": Whatever... My Largemon is weak. I'm going to force it to get stronger!\n\n";

		system("pause");

		bool battleRecursion = BattleRecursionPrompt(playerPTR, opponentPTR);
		if (battleRecursion == true)
		{
			Battle(playerPTR, opponentPTR);
		}
		return true;
	}
	else if (playerPTR->Largemon.Health <= 0)
	{
		cout << endl << playerPTR->Largemon.GetName() << " has fainted." << endl
			<< playerPTR->GetName() << " blacked out.\n\n";

		system("pause");

		bool battleRecursion = BattleRecursionPrompt(playerPTR, opponentPTR);
		if (battleRecursion == true)
		{
			Battle(playerPTR, opponentPTR);
		}
		return true;
	}
	return false;
}

