// NonoGram.cpp : Defines the entry point for the console application.
//

#include "TAMonog.h"
#include "VeronicaLopezNanogram.h"
#include "ecdev456.h"
#include "picross.h"



int main()
{

//include picross display
	picross game;
	game.Description();
//DefaultArray();
char userin;
freshBoard();

	bool checkwin = false;
	do {
		cout << " 'A' to add your 'X'.\n";
		cout << " 'R' to remove your 'X'.\n";
		cout << " 'Q' to quit game.\n";
		cout << " 'L' to Load previous game\n";
		cout << " 'S' to Save game\n";
		cout << "What would you like to do? ";
		cin >> userin;
		switch (userin) {

		case 'A': //If A or a selectd, user input coordinates to add X.
		case 'a':
			userInput();
			break;
		case 'R': //If R or r selected, user input coordinates to remove X
		case 'r':
			remove();
			printBoard();
			break;
		case 'Q':	// If Q or q is selected the program is exited.
		case 'q':
			break;
		case 'L':	// If L or l is selected a previous game will be loaded if available
		case 'l':
			cout << "Loading previous game.\n ";
			ReadSpecialFile();
			printBoard();
			break;
		case 'S':	// If S or s is selected then their current game will be saved.
		case 's':
			cout << "Saving the board\n";
			SaveToSpecialFile();
			printBoard();
			break;
		}
	} while (userin != 'Q' && userin != 'q' && checkWin() != true);

	cout << "Bye!" << endl;
	if (checkWin() == true)
	{
		cout << "YOU WON!!!" << endl;
	}
    return 0;
}

