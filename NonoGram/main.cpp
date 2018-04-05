#pragma once
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "view.h"
#include "model.h"

using namespace std;

// valid choices for commands
// This is a C++11 feature, so you do need
// to set your project options accordingly

int main() {
	view View;
	Model m;
	bool win = false;
	char choose, userin;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "Enter 'P' to play Picross\nEnter 'R' to play Rullo. \n"
			<< "Enter 'Q' to quit. \n";

		cout << "What would you like to play? ";
		cin >> choose;

		if (choose == 'R' || choose == 'r')
		{
			cout << "\nWelcome to Rullo! \n";
			cout << "To win you'll need to deavtivate/activate appropriate numbers to fulfill the correct sum \n";
			cout << "for all Vertical and Horizontal sums. ";
			cout << "Each Horizontal & Vertical section has it's own sum. \n";
			cout << "NOTE: All numbers are currently activated for you. \n";
			cout << "Yellow = Active \n";
			cout << "Light Green = Not Active \n";
			cout << "Light Blue = Sum is fulfilled \n";

			View.printRullo();
			do
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << " 'R' remove numbes from grid \n";
				cout << " 'A' to add numbers back to grid.\n";
				cout << " 'Q' to quit game.\n";

				cout << "What would you like to do? ";
				cin >> userin;

				switch (userin) {

				case 'R': //If A or a selectd, user input coordinates to add X.
				case 'r':
					View.rulloInput(); //you're deactivating the number
					m.CheckMath();
					View.printRullo();
					win = m.CheckWin();
					break;
				case 'A': //If R or r selected, user input coordinates to remove X
				case 'a':
					View.removeRullo(); //you're adding the number back
					m.CheckMath();
					View.printRullo();
					win = m.CheckWin();
					break;
				case 'Q':	// If Q or q is selected the program is exited.
				case 'q':
					break;
				default:
					cout << "Invalid Option" << endl;
				}
			} while (userin != 'Q' && userin != 'q' && win != true); //&& checkWin() != true);
		}

		if (choose == 'P' || choose == 'p')
		{
			SetConsoleTextAttribute(hConsole, 10);
			cout << "\nWelcome to Picross\n"
				<< "To win the game you must find the hidden letter that is printed in the grid with X's\n"
				<< "Each input you pick will print an X to the square of your choice\n"
				<< "For example if you want to put an X on the top left hand side you will put 0 for row, and 0 for column\n"
				<< "\nNOTE: You may be close to winning at one point, but the game will only consider it a win if it's exact! GOOD LUCK \n";
			View.printPicross();
			do
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << " 'A' to add your 'X'.\n";
				cout << " 'R' to remove your 'X'.\n";
				cout << " 'Q' to quit game.\n";
				//cout << " 'L' to Load previous game\n";
				//cout << " 'S' to Save game\n";
				cout << "What would you like to do? ";
				cin >> userin;

				switch (userin) {

				case 'A': //If A or a selectd, user input coordinates to add X.
				case 'a':
					View.picrossInput();
					win = View.checkWinPicross();
					break;
				case 'R': //If R or r selected, user input coordinates to remove X
				case 'r':
					View.removePicross();
					win = View.checkWinPicross();
					break;
				case 'Q':	// If Q or q is selected the program is exited.
				case 'q':
					break;

				default:
					cout << "Invalid Option" << endl;
				}
			} while (userin != 'Q' && userin != 'q'&& win != true); 
		}

	} while (choose != 'Q' && choose != 'q');

};
