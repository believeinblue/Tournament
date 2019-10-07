#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "game.h"
#include "gameList.h"
#include "teamList.h"
#include "league.h"

using namespace std;

gameList::gameList()
{
	head = NULL;
	tail = NULL;
}
void gameList::addGame(game newGame)
{
	game * newerGame = new game;
	if (newGame.getSC2()>newGame.getSC1())
		newerGame->setGame(newGame.getDate(), newGame.getSC2(), newGame.getSC1(), newGame.getTeam2(), newGame.getTeam1());
	else
		newerGame->setGame(newGame.getDate(), newGame.getSC1(), newGame.getSC2(), newGame.getTeam1(), newGame.getTeam2());
	if (getNumGames() == 0)
	{
		newerGame->next = head;
		head = newerGame;
		tail = newerGame;
	}
	else
	{
		tail->next = newerGame;
		tail = newerGame;
	}
}
void gameList::readGames(teamList teams)
{
	ifstream f;
	f.open("games.txt");
	if (f.fail())
	{
		cout << "failed to read";
	}
	else
	{
		
		while (!f.eof())
		{
			game nGame;
			string team1, team2, date;
			int s1, s2;
			team* t1;
			team* t2;
			f >> date >> team1 >> s1 >> team2 >> s2;
			t1 = teams.getTeamRef(team1);
			t2 = teams.getTeamRef(team2);


			if (t1 == NULL || t2 == NULL)
				cout << "NOT FOUND";
			else
			{
				nGame.setGame(date, s1, s2, t1, t2);
				addGame(nGame);
			}
		}
	}
	f.close();
}
int gameList::getNumGames()
{
	game * look = head;
	int count = 0;
	while (look != NULL)
	{
		count++;
		look = look->next;
	}
	return count;
}
int gameList::getNumWins(team* favTeam)
{
	game * look = head;
	int count = 0;
	while (look != NULL)
	{
		if (look->team1->getTeamID() == favTeam->getTeamID() && look->getSC1() > look->getSC2())
		{
			count++;
		}
		if (look->team2->getTeamID() == favTeam->getTeamID() && look->getSC2() > look->getSC1())
		{
			count++;
		}
		look = look->next;
	}
	return count;
}
int gameList::getNumLosses(team* favTeam)
{
	game * look = head;
	int count = 0;
	while (look != NULL)
	{
		if (look->team1->getTeamID() == favTeam->getTeamID() && look->getSC1() < look->getSC2())
		{
			count++;
		}
		if (look->team2->getTeamID() == favTeam->getTeamID() && look->getSC2() < look->getSC1())
		{
			count++;
		}
		look = look->next;
	}
	return count;
}
void gameList::printGames(team* finder)
{
	
	if (finder == NULL)
	{
		int games = getNumGames();
		cout << "-------- Games (" << games << ") ----------\n";
		cout << "Date        TEAM  SC   TEAM  SC\n";
		cout << "----------  ----  ---  ----  ---\n";
		game* look = head;
		while (look != NULL)
		{
			cout << setw(10) << left << look->getDate() << "  " << setw(4) << left << look->team1->getTeamID() << "  " << setw(3) << look->getSC1() << "  " << setw(4) << left << look->team2->getTeamID() << "  " << setw(3) << look->getSC2() << endl;
			look=look->next;
		}
		cout << endl;
		system("pause");
	}
	else
	{
		int counter = 0;
		game* look = head;
		while (look != NULL)
		{
			if (look->getTeam1() == finder || look->getTeam2() == finder)
				counter++;
			look = look->next;
		}
		look = head;
		cout << "-------- Games (" << counter << ") ----------\n";
		cout << "Date        TEAM  SC  TEAM  SC\n";
		cout << "----------  ----  --  ----  --\n";
		while (look != NULL)
		{
			if (look->getTeam1() == finder || look->getTeam2() == finder)
				cout << setw(10) << left << look->getDate() << "  " << setw(4) << left << look->team1->getTeamID() << "  " << setw(2) << look->getSC1() << "  " << setw(4) << left << look->team2->getTeamID() << "  " << setw(2) << look->getSC2() << endl;
			look=look->next;
		}
		system("pause");
	}
}
void gameList::writeGames()
{
	ofstream f;
	f.open("games2.txt");
	if (f.fail())
	{
		cout << "failed to write";
	}
	else
	{
		game* now = head;
		while(now!=NULL)\
		{
			f << setw(10) << left << now->getDate() << "  " << setw(4) << left << now->team1->getTeamID() << "  " << setw(2) << now->getSC1() << "  " << setw(4) << left << now->team2->getTeamID() << "  " << setw(2) << now->getSC2() << endl;
			now = now->next;
		}
	}
	f.close();
}