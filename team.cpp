#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "team.h"

using namespace std;

string team::getTeamID()
{
	return teamID;
}

string team::getName()
{
	return name;
}
string team::getCoach()
{
	return coach;
}
void team::setName(string newName)
{
	name = newName;
}
void team::setTeamID(string newID)
{
	teamID = newID;
}
void team::setCoach(string newCoach)
{
	coach = newCoach;
}
team::team()
{
	coach = "";
	teamID = "";
	name = "";
	next = NULL;
}