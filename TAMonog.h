#ifndef Assignment1_H
#define Assignment1_H
#include <iostream>
#include "ecdev456.h"
using namespace std;

void Menu(char choice) {
	bool checkwin = false;
	do {
		switch (choice) {

		case 'A':
			cout << " Where would you like to add your 'X'? ";
			//input Veronica's function 
			break;
		case 'a':
			cout << " Where would you like to add your 'X'? ";
			//input Veronica's function
			break;
		case 'R':
			cout << " Which 'X' would you like to remove? ";
			//input Veronica's function
			break;
		case 'r':
			cout << " Which 'X' would you like to remove? ";
			//input Veronica's function
			break;
		case 'Q':
			break;
			//Edwin's Quit function
		case 'q':
			break;
			//Edwin's Quit function
		case 'L': 
			cout << "Loading previous game. ";
			ReadSpecialFile();
			break;
		case 'l':
			cout << "Loading previous game.";
			ReadSpecialFile();
			break;
		case 'S':
			cout << "Saving the board";
			SaveToSpecialFile();
			break;
		case 's':
			cout << "Saving the board";
			SaveToSpecialFile();
			break;
		}
	}while (choice != 'Q' && choice != 'q' && checkwin != true);
	cout << "Goodbye" << endl;
}
#endif