#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "teamList.h"
#include "game.h"

using namespace std;

class gameList
{
private:
	game * head;
	game * tail;
public:
	gameList();
	void addGame(game newGame);
	void readGames(teamList teams);
	int getNumGames();
	int getNumWins(team* favTeam);
	int getNumLosses(team* favTeam);
	void printGames(team* finder);
	void writeGames();
};
