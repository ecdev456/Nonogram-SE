// Assignment1.cpp : Defines the entry point for the console application.
//

#include "Assignment1.h"


int main()
{
	char userin;
	cout << "Enter: \n";
	cout << " -'A' or 'a' to add your 'X'.\n";
	cout << " -'R' or 'r' to remove your 'X'.\n";
	cout << "-'Q' or 'q' to quit game.\n";
	cout << "What would you like to do? ";
	cin >> userin;
	Menu(userin);
    return 0;
}
