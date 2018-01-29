#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "view.h"

using namespace std;

// valid choices for commands
// This is a C++11 feature, so you do need
// to set your project options accordingly

view View;

void handleDisplay()
{
	//Veronica's view function for displaying Grid
}
void handleQuit() {
	exit(0);
};

void handleGame() {

};

int main() {
	char choose;
	cout << "Menu: \n" << "Choose your game (Rullo or Picross) \n"
		<< " Enter 'P' or 'p' to play Picross or 'R' or 'r' to play Rullo. \n"
		<< " Enter 'D' or 'd' to display Picross Grid. \n"
		<< " Enter 'Q' or 'q' to quit game. \n";


	
	do
	{
		string input;
		cout << "What would you like to do? ";
		cin >> choose;
		switch (choose) {
		

		case 'R':
		case 'r':
			cout << "Getting Grid ready for Rullo..." << endl;
			View.printRullo(); //same grid so user see's it first and then adds their input
			View.rulloInput();
			cout << endl; //rullo input second
			//Model check Math functions
			break;


		case 'P':
		case 'p':
			cout << "Getting Grid ready for Picross.."<< endl;
			View.printPicross(); //same picross grid so that the user see's int first and then adds 
								//their input
			View.picrossInput();  //Picross input second
			cout << endl;
			
			//Load Game option (Think about how to implement this function after user
			//quits their Picross Game
			//Save game option

			break;

		case 'D':
		case 'd':
			cout << "Which Game grid would you like to display? Picross or Rullo? ";//if  user just wants to see the game grids
			cin >> input;
			if (input == "Rullo" || input == "rullo")
				View.printRullo();
			else if (input == "picross" || input == "Picross")
				View.printPicross();
			else
			cout << "Invalid option!"<< endl;
			break;			


		case 'Q':
		case 'q':
			cout << "... Quitting game" << endl;
			handleQuit();
			break;
		default:
			cout << "Invalid Option" << endl;
		}
	} while (choose!= 'Q' || choose != 'q');

	if (choose != 'Q' || choose != 'q' || choose != 'P' || choose != 'p')
		cout << "Invalid Option";
	// continue code
	else if (choose != 'D' || choose != 'd' || choose!= 'Q' || choose!= 'q')
		cout << "Invalid Option ";
	//continue code.



};
