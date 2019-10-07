#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "team.h"
#include "teamList.h"

using namespace std;

teamList::teamList()
{

}
void teamList::addTeam(team newTeam)
{
	team * tempT = new team;
	tempT->coach = newTeam.getCoach();
	tempT->name = newTeam.getName();
	tempT->teamID = newTeam.getTeamID();
	tempT->next = head;
	head = tempT;
}
void teamList::readData()
{
	ifstream f;
	f.open("teams.txt");
	if (f.fail())
		cout << "failed to open";
	else
	{
		string name, coach, teamID;
		while (!f.eof())
		{
			team * t = new team;
			if (f.peek() == '\n') { f.ignore(); }
			f >> teamID;
			if (f.peek() == '\n') { f.ignore(); }
			getline(f, name);
			getline(f, coach);
			t->setTeamID(teamID);
			t->setCoach(coach);
			t->setName(name);
			t->next = head;
			head = t;
		}
	}
	f.close();
}
void teamList::printTeams()
{
	cout << "---------------------teams(" << getNumTeams() << ")-----------------------\n";
	cout << "TID   TEAM                       COACH\n";
	cout << "-----------------------------------------------------\n";
	team *look = head;
	while (look != NULL)
	{
		cout << setw(4) << left << look->getTeamID() << "  " << setw(25) << left << look->getName() << "  " << setw(20) << left << look->getCoach() << endl;
		look = look->next;
	}
}
team* teamList::getTeamRef(string findTeamID)
{
	team *look = head;
	while (look != NULL)
	{
		
		if (look->getTeamID() == findTeamID)
		{
			return look;
		}
		look = look->next;
	}
	return NULL;
}
int teamList::getNumTeams()
{
	team * look = head;
	int count = 0;
	while (look != NULL)
	{
		count++;
		look = look->next;
	}
	return count;
}