#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "game.h"

using namespace std;

game::game()
{
	date = "";
	scoreT1 = 0;
	scoreT2 = 0;
	team1 = NULL;
	team2 = NULL;
	next = NULL;
}
void game::setGame(string newDate, int score1, int score2, team* newTeam1, team* newTeam2)
{
	date = newDate;
	scoreT1 = score1;
	scoreT2 = score2;
	team1 = newTeam1;
	team2 = newTeam2;
}
int game::getSC1()
{
	return scoreT1;
}
int game::getSC2()
{
	return scoreT2;
}
string game::getDate()
{
	return date;
}
team* game::getTeam1()
{
	return team1;
}
team* game::getTeam2()
{
	return team2;
}