// NonoGram.cpp : Defines the entry point for the console application.
//

#include "TAMonog.h"
#include "VeronicaLopezNanogram.h"
#include "ecdev456.h"



int main()
{
DefaultArray();
char userin;
freshBoard();

	bool checkwin = false;
	do {

	//	cout << "Enter: \n";
		cout << " 'A' to add your 'X'.\n";
		cout << " 'R' to remove your 'X'.\n";
		cout << " 'Q' to quit game.\n";
		cout << " 'L' to Load previous game\n";
		cout << " 'S' to Save game\n";
		cout << "What would you like to do? ";
		cin >> userin;
		switch (userin) {

		case 'A':
		case 'a':
		//	cout << " Where would you like to add your 'X'? ";
			userInput();
			break;
		case 'R':
		case 'r':
			cout << " Which 'X' would you like to remove? ";
			//input Veronica's function
			remove();
			break;
		case 'Q':
		case 'q':
			break;
			//Edwin's Quit function
		case 'L':
		case 'l':
			cout << "Loading previous game. ";
			ReadSpecialFile();
			break;
		case 'S':
		case 's':
			cout << "Saving the board";
			SaveToSpecialFile();
			break;
		}
	} while (userin != 'Q' && userin != 'q' && checkWin() != true);

	if (checkWin() == true)
	{
		cout << "YOU WON!!!" << endl;
	}
    return 0;
}

