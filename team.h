#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class team
{
private:
	string teamID;
	string name;
	string coach;
	team * next;
public:
	friend class teamList;
	string getTeamID();
	string getName();
	string getCoach();
	void setName(string newName);
	void setTeamID(string newID);
	void setCoach(string newCoach);
	team();
};