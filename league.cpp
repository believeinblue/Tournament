//-------------------------------------------------------------------------
//                                league.cpp
//         Complete the methods where //TO DO: comments are found
//-------------------------------------------------------------------------
#include <iostream>
#include "league.h"
#include "game.h"
using namespace std;

//-------------------------------------------------------------------------
//                               askTeamId
//-------------------------------------------------------------------------
team * league::askTeamId(string prompt) {
	string teamId;		// id entered by the user
	team * tid;			// pointer to the found team in the team list

	// print the given question and let the user enter an answer
	cout << prompt;
	cin >> teamId;

	// TO DO: search the team list by teamId to get a pointer to it (tid)
	tid = teams.getTeamRef(teamId);

	while (tid == NULL) { // TO DO: repeat while the team ID was NOT found in the team list
		cout << "Invalid entry! Please choose from the list above.\n";
		cout << prompt;
		cin >> teamId;
		tid = teams.getTeamRef(teamId);
	}
	return tid;
} // askTeamId()

//-------------------------------------------------------------------------
//                               addGame
//-------------------------------------------------------------------------
void league::addGame() {
	team * t1, *t2;		// pointers to the 2 teams in the team list
	int pts1, pts2;		// points scored by the 2 teams
	string date;		// date the new game was played
	game g;				// a game object: populate and use to add a game

	// TO DO: print the teams in the team List
	teams.printTeams();

	t1 = askTeamId("Enter Team Id for team 1: ");
	t2 = askTeamId("Enter Team Id for team 2: ");
	cout << "Enter points for team 1:  ";
	cin >> pts1;
	cout << "Enter points for team 2:  ";
	cin >> pts2;
	cout << "Enter date (YYYY-MM-DD):  ";
	cin >> date;

	// TO DO: populate the g object with the data entered/searched
	//        and add the game to the game list
	g.setGame(date, pts1, pts2, t1, t2);
	games.addGame(g);

	cout << "Game added.\n\n";
} // addGame()

//-------------------------------------------------------------------------
//                               queryTeam
//-------------------------------------------------------------------------
void league::queryTeam() {
	// TO DO: print the teams and use askTeamId to get the pointer to the team
	teams.printTeams();
	team * t = askTeamId("Enter Team Id: ");

	// TO DO: finish the cout using getWhatever from the found team (replace _WHATEVERs)
	teams.getTeamRef(t->getTeamID());
	cout << "NAME: " << t->getName() << "  COACH: " << t->getCoach()
		<< "  WINS: " << games.getNumWins(t) << "  LOSSES: "
		<< games.getNumLosses(t) << endl;

	// TO DO: print the game list for THIS team
	games.printGames(t);

} // queryTeam()

//-------------------------------------------------------------------------
//                               getMenuOption
//-------------------------------------------------------------------------
char league::getMenuOption() {
	string userInput;
	char opt;

	cout << "\n+----------------------------------------+\n";
	cout << "|             LEAGUE STATS PRO           |\n";
	cout << "|            by <YOUR NAME HERE>         |\n";
	cout << "+----------------------------------------+\n";
	cout << "T - List all Teams       Q - Query Team\n";
	cout << "G - List all Games       A - Add Game \n";
	cout << "X - Exit   \n";
	cout << "Enter Menu Option ===> ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin, userInput);
	opt = toupper(userInput[0]);
	while (opt != 'T' && opt != 'G' && opt != 'Q' && opt != 'A' && opt != 'X') {
		cout << "Invalid entry, enter T,G,Q,A or X!\n";
		cout << "Enter Menu Option ===> ";
		if (cin.peek() == '\n') cin.ignore();
		getline(cin, userInput);
		opt = toupper(userInput[0]);
	}
	return opt;
} // getMenuOption()

//-------------------------------------------------------------------------
//                               go - the "main"
//-------------------------------------------------------------------------
void league::go() {
	// TO DO: read the teams and games from input files
	teams.readData();
	games.readGames(teams);

	char opt = '?';

	while (opt != 'X') {
		opt = getMenuOption();
		switch (opt) {
		case 'T': teams.printTeams(); break;
		case 'G': games.printGames(NULL); break; // NULL means "all games"
		case 'A': addGame(); break;
		case 'Q': queryTeam(); break;
		case 'X': games.writeGames(); break;
		}
	}
} // go()

league::league()
{
	teamList teams;
	gameList games;
}