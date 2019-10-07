#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "team.h"

using namespace std;

class game
{
	friend class gameList;
private:
	string date;
	int scoreT1, scoreT2;
	team * team1;
	team * team2;
	game * next;
public:
	game();
	void setGame(string newDate, int score1, int score2, team* newTeam1, team* newTeam2);
	int getSC1();
	int getSC2();
	string getDate();
	team* getTeam1();
	team* getTeam2();
};