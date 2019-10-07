#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "team.h"

using namespace std;

class teamList
{
private:
	team * head;
	team * tail;
public:
	teamList();
	void addTeam(team newTeam);
	void readData();
	void printTeams();
	team* getTeamRef(string findTeamID);
	int getNumTeams();
};