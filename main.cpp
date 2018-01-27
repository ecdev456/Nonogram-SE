#pragma once
#include <iostream>
#include <cstdlib>
#include "model.h"
#include "view.h"
using namespace std;

// valid choices for commands
// This is a C++11 feature, so you do need
// to set your project options accordingly
Model model("hello");
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
	char chose;
	cout << "Menu: \n" << "Choose your game (Rullo or Picross) \n"
		<< " Enter 'P' or 'p' to play Picross or 'R' or 'r' to play Rullo. \n"
		<< " Enter 'D' or 'd' to display Picross Grid. \n"
		<< " Enter 'Q' or 'q' to quit game. \n";


	cout << "What would you like to do? "
		cin >> choose;
	do
	{
		switch (choose)
			char input
				case 'R':
				case 'r':
					cout << "Opening Rullo..." << endl;
					//Veronicas view functions

				case 'P' :
				case 'p' :
						cout << "Opening Picross Grid";
						//Veronica's view functions here
						break;
				case 'D' :
				case 'd' :
						cout << "Pulling up Grid..."

				case 'Q' :
				case 'q' :
						cout << "... Quitting game" << endl;

						//edwin's load function(?)
						break;

					case (int(Choice::QUIT)):
						//Edwin's Exit Function
						break;
					default:
						cout << "Invalid Option" << endl;
	}; while (input != 'Q' || input != 'q');

	if (input != 'Q' || input != 'q' || input != 'P' || input != 'p')
		cout << "Invalid Option";
	// continue code
	else (input != 'D' || input != 'd' || input != 'Q' || input != 'q')
		cout << "Invalid Option ";
	//continue code.



};
