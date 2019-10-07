//----------------------------------------------------------------------------
//                  CS 215 - Project 3/4
//----------------------------------------------------------------------------
// Author:  David Pippen
// Date:  4/15/19
// Description:  A league of basket-ball
// Assistance: I received help from the following: Isabella Bowling and Aaron Bussell
//-----------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "league.h"

using namespace std;

int doAbort(string message)
{
	cout << message << endl;
	system("pause");
	exit(1);
}

int main()
{
	league test;
	test.go();
	system("pause");
	return 0;
}